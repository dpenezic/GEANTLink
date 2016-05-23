/*
    Copyright 2015-2016 Amebis
    Copyright 2016 GÉANT

    This file is part of GÉANTLink.

    GÉANTLink is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GÉANTLink is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GÉANTLink. If not, see <http://www.gnu.org/licenses/>.
*/

#include <StdAfx.h>

#pragma comment(lib, "Comctl32.lib")
#pragma comment(lib, "Msi.lib")
#pragma comment(lib, "msxml6.lib")

using namespace std;
using namespace winstd;


//////////////////////////////////////////////////////////////////////
// eap::config_ttls
//////////////////////////////////////////////////////////////////////

eap::config_ttls::config_ttls(_In_ module &mod) :
    m_outer(mod),
    m_inner(NULL),
    config(mod)
{
}


eap::config_ttls::~config_ttls()
{
    if (m_inner)
        delete m_inner;
}


DWORD eap::config_ttls::save(_In_ IXMLDOMDocument2 *pDoc, _Inout_ IXMLDOMNode *pConfigRoot, _Out_ EAP_ERROR **ppEapError) const
{
    const variant varNodeTypeEl(NODE_ELEMENT);
    const bstr bstrNamespace(L"urn:ietf:params:xml:ns:yang:ietf-eap-metadata");
    DWORD dwResult;
    HRESULT hr;

    if (!m_outer_identity.empty()) {
        // <ClientSideCredential>
        com_obj<IXMLDOMNode> pXmlElClientSideCredential;
        if (FAILED(hr = pDoc->createNode(varNodeTypeEl, bstr(L"ClientSideCredential"), bstrNamespace, &pXmlElClientSideCredential))) {
            *ppEapError = m_module.make_error(dwResult = HRESULT_CODE(hr), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error creating <ClientSideCredential> element."), NULL);
            return dwResult;
        }

        // <ClientSideCredential>/<AnonymousIdentity>
        if ((dwResult = eapxml::put_element_value(pDoc, pXmlElClientSideCredential, bstr(L"AnonymousIdentity"), bstrNamespace, bstr(m_outer_identity.c_str()))) != ERROR_SUCCESS) {
            *ppEapError = m_module.make_error(dwResult, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error creating <AnonymousIdentity> element."), NULL);
            return dwResult;
        }

        if (FAILED(hr = pConfigRoot->appendChild(pXmlElClientSideCredential, NULL))) {
            *ppEapError = m_module.make_error(dwResult = HRESULT_CODE(hr), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error appending <pXmlElClientSideCredential> element."), NULL);
            return dwResult;
        }
    }

    // <ServerSideCredential>
    com_obj<IXMLDOMNode> pXmlElServerSideCredential;
    if (FAILED(hr = pDoc->createNode(varNodeTypeEl, bstr(L"ServerSideCredential"), bstrNamespace, &pXmlElServerSideCredential))) {
        *ppEapError = m_module.make_error(dwResult = HRESULT_CODE(hr), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error creating <ServerSideCredential> element."), NULL);
        return dwResult;
    }

    // <ServerSideCredential>/...
    if ((dwResult = m_outer.save(pDoc, pXmlElServerSideCredential, ppEapError)) != ERROR_SUCCESS)
        return dwResult;

    if (FAILED(hr = pConfigRoot->appendChild(pXmlElServerSideCredential, NULL))) {
        *ppEapError = m_module.make_error(dwResult = HRESULT_CODE(hr), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error appending <ServerSideCredential> element."), NULL);
        return dwResult;
    }

    // <InnerAuthenticationMethod>
    com_obj<IXMLDOMNode> pXmlElInnerAuthenticationMethod;
    if (FAILED(hr = pDoc->createNode(varNodeTypeEl, bstr(L"InnerAuthenticationMethod"), bstrNamespace, &pXmlElInnerAuthenticationMethod))) {
        *ppEapError = m_module.make_error(dwResult = HRESULT_CODE(hr), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error creating <InnerAuthenticationMethod> element."), NULL);
        return dwResult;
    }

    if (dynamic_cast<const config_pap*>(m_inner)) {
        // <InnerAuthenticationMethod>/<NonEAPAuthMethod>
        if ((dwResult = eapxml::put_element_value(pDoc, pXmlElInnerAuthenticationMethod, bstr(L"NonEAPAuthMethod"), bstrNamespace, bstr(L"PAP"))) != ERROR_SUCCESS) {
            *ppEapError = m_module.make_error(dwResult, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error creating <NonEAPAuthMethod> element."), NULL);
            return dwResult;
        }

        // <InnerAuthenticationMethod>/...
        if ((dwResult = m_inner->save(pDoc, pXmlElInnerAuthenticationMethod, ppEapError)) != ERROR_SUCCESS)
            return dwResult;
    } else
        return dwResult = ERROR_NOT_SUPPORTED;

    if (FAILED(hr = pConfigRoot->appendChild(pXmlElInnerAuthenticationMethod, NULL))) {
        *ppEapError = m_module.make_error(dwResult = HRESULT_CODE(hr), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error appending <InnerAuthenticationMethod> element."), NULL);
        return dwResult;
    }

    return config::save(pDoc, pConfigRoot, ppEapError);
}


DWORD eap::config_ttls::load(_In_ IXMLDOMNode *pConfigRoot, _Out_ EAP_ERROR **ppEapError)
{
    assert(ppEapError);
    DWORD dwResult;

    // Load outer identity (<ClientSideCredential><AnonymousIdentity>).
    if (eapxml::get_element_value(pConfigRoot, bstr(L"eap-metadata:ClientSideCredential/eap-metadata:AnonymousIdentity"), m_outer_identity) != ERROR_SUCCESS)
        m_outer_identity.clear();

    // Load TLS configuration (<ServerSideCredential>).
    com_obj<IXMLDOMElement> pXmlElServerSideCredential;
    if (eapxml::select_element(pConfigRoot, bstr(L"eap-metadata:ServerSideCredential"), &pXmlElServerSideCredential) == ERROR_SUCCESS) {
        if ((dwResult = m_outer.load(pXmlElServerSideCredential, ppEapError)) != ERROR_SUCCESS)
            return dwResult;
    }

    // Load inner authentication configuration (<InnerAuthenticationMethod>).
    com_obj<IXMLDOMElement> pXmlElInnerAuthenticationMethod;
    if ((dwResult = eapxml::select_element(pConfigRoot, bstr(L"eap-metadata:InnerAuthenticationMethod"), &pXmlElInnerAuthenticationMethod)) != ERROR_SUCCESS) {
        *ppEapError = m_module.make_error(dwResult, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error selecting <InnerAuthenticationMethod> element."), NULL);
        return dwResult;
    }

    // Determine inner authentication type (<EAPMethod> and <NonEAPAuthMethod>).
    //DWORD dwMethodID;
    bstr bstrMethod;
    /*if (eapxml::get_element_value(pXmlElInnerAuthenticationMethod, bstr(L"eap-metadata:EAPMethod"), &dwMethodID) == ERROR_SUCCESS &&
        dwMethodID == EAP_TYPE_MSCHAPV2)
    {
        // MSCHAPv2
        // TODO: Add MSCHAPv2 support.
        return ERROR_NOT_SUPPORTED;
    } else*/ if (eapxml::get_element_value(pXmlElInnerAuthenticationMethod, bstr(L"eap-metadata:NonEAPAuthMethod"), &bstrMethod) == ERROR_SUCCESS &&
        CompareStringEx(LOCALE_NAME_INVARIANT, NORM_IGNORECASE, bstrMethod, bstrMethod.length(), L"PAP", -1, NULL, NULL, 0) == CSTR_EQUAL)
    {
        // PAP
        assert(!m_inner);
        m_inner = new eap::config_pap(m_module);
        if ((dwResult = m_inner->load(pXmlElInnerAuthenticationMethod, ppEapError)) != ERROR_SUCCESS)
            return dwResult;
    } else {
        *ppEapError = m_module.make_error(dwResult = ERROR_NOT_SUPPORTED, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Unsupported inner authentication method."), NULL);
        return dwResult;
    }

    return config::load(pConfigRoot, ppEapError);
}



//////////////////////////////////////////////////////////////////////
// eap::session_ttls
//////////////////////////////////////////////////////////////////////

eap::session_ttls::session_ttls() : session()
{
}


//////////////////////////////////////////////////////////////////////
// eap::peer_ttls
//////////////////////////////////////////////////////////////////////

eap::peer_ttls::peer_ttls() : peer()
{
}


DWORD eap::peer_ttls::initialize(_Out_ EAP_ERROR **ppEapError)
{
    // Perform the Microsoft Installer's feature completeness check manually.
    // If execution got this far in the first place (dependent DLLs are present and loadable).
    // Furthermore, this increments program usage counter.
    if (MsiQueryFeatureState(_T(PRODUCT_VERSION_GUID), _T("featEAPTTLS")) != INSTALLSTATE_UNKNOWN)
        MsiUseFeature(_T(PRODUCT_VERSION_GUID), _T("featEAPTTLS"));

    return peer::initialize(ppEapError);
}


//////////////////////////////////////////////////////////////////////
// eap::peer_ttls_ui
//////////////////////////////////////////////////////////////////////

eap::peer_ttls_ui::peer_ttls_ui() : peer_ui()
{
}


DWORD eap::peer_ttls_ui::config_blob_to_xml(
    _In_                             DWORD            dwFlags,
    _In_count_(dwConfigInSize) const BYTE             *pConfigIn,
    _In_                             DWORD            dwConfigInSize,
    _Out_                            IXMLDOMDocument2 **ppConfigDoc,
    _Out_                            EAP_ERROR        **ppEapError)
{
    UNREFERENCED_PARAMETER(dwFlags);
    assert(ppEapError);
    DWORD dwResult = ERROR_SUCCESS;
    ETW_FN_DWORD(dwResult);

    // Unpack configuration.
    eap::config_ttls cfg(*this);
    if (pConfigIn || !dwConfigInSize) {
        const unsigned char *cursor = pConfigIn;
        eapserial::unpack(cursor, cfg);
        assert(cursor - pConfigIn <= dwConfigInSize);
    }

    HRESULT hr;
    com_obj<IXMLDOMDocument2> pDoc;
    if (FAILED(hr = pDoc.create(CLSID_DOMDocument60, NULL, CLSCTX_INPROC_SERVER))) {
        *ppEapError = make_error(dwResult = HRESULT_CODE(hr), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error creating XML document."), NULL);
        return dwResult;
    }

    pDoc->put_async(VARIANT_FALSE);
    pDoc->setProperty(bstr(L"SelectionNamespaces"), variant(L"xmlns:eap-metadata=\"urn:ietf:params:xml:ns:yang:ietf-eap-metadata\""));

    // Load empty configuration.
    VARIANT_BOOL isSuccess = VARIANT_FALSE;
    if (FAILED((hr = pDoc->loadXML(L"<Config xmlns=\"http://www.microsoft.com/provisioning/EapHostConfig\"><EAPIdentityProviderList xmlns=\"urn:ietf:params:xml:ns:yang:ietf-eap-metadata\"><EAPIdentityProvider></EAPIdentityProvider></EAPIdentityProviderList></Config>", &isSuccess))))
        return dwResult = HRESULT_CODE(hr);
    if (!isSuccess) {
        *ppEapError = make_error(dwResult = ERROR_XML_PARSE_ERROR, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Loading XML template failed."), NULL);
        return dwResult;
    }

    // Select <Config><EAPIdentityProviderList><EAPIdentityProvider> node.
    com_obj<IXMLDOMNode> pXmlElIdentityProvider;
    if ((dwResult = eapxml::select_node(pDoc, bstr(L"//eap-metadata:EAPIdentityProviderList/eap-metadata:EAPIdentityProvider"), &pXmlElIdentityProvider)) != ERROR_SUCCESS) {
        *ppEapError = make_error(dwResult = ERROR_NOT_FOUND, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error selecting <EAPIdentityProviderList>/<EAPIdentityProvider> element."), NULL);
        return dwResult;
    }

    if ((dwResult = cfg.save(pDoc, pXmlElIdentityProvider, ppEapError)) != ERROR_SUCCESS)
        return dwResult;

    assert(ppConfigDoc);
    *ppConfigDoc = pDoc.detach();

    return dwResult;
}


DWORD eap::peer_ttls_ui::config_xml_to_blob(
    _In_  DWORD            dwFlags,
    _In_  IXMLDOMDocument2 *pConfigDoc,
    _Out_ BYTE             **ppConfigOut,
    _Out_ DWORD            *pdwConfigOutSize,
    _Out_ EAP_ERROR        **ppEapError)
{
    UNREFERENCED_PARAMETER(dwFlags);
    assert(ppEapError);
    DWORD dwResult = ERROR_SUCCESS;
    ETW_FN_DWORD(dwResult);

    assert(pConfigDoc);
    pConfigDoc->setProperty(bstr(L"SelectionNamespaces"), variant(L"xmlns:eap-metadata=\"urn:ietf:params:xml:ns:yang:ietf-eap-metadata\""));

    com_obj<IXMLDOMNode> pConfigRoot;
    if ((dwResult = eapxml::select_node(pConfigDoc, bstr(L"//eap-metadata:EAPIdentityProvider"), &pConfigRoot)) != ERROR_SUCCESS) {
        *ppEapError = make_error(dwResult = ERROR_NOT_FOUND, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error selecting <EAPIdentityProvider> element."), NULL);
        return dwResult;
    }

    // Iterate authentication methods (<AuthenticationMethods>).
    com_obj<IXMLDOMNodeList> pXmlListMethods;
    if ((dwResult = eapxml::select_nodes(pConfigRoot, bstr(L"eap-metadata:AuthenticationMethods/eap-metadata:AuthenticationMethod"), &pXmlListMethods)) != ERROR_SUCCESS) {
        *ppEapError = make_error(dwResult = ERROR_NOT_FOUND, 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" Error selecting <AuthenticationMethods>/<AuthenticationMethod> elements."), NULL);
        return dwResult;
    }

    long lCount = 0;
    pXmlListMethods->get_length(&lCount);
    for (long i = 0; ; i++) {
        if (*ppEapError) {
            // If an error condition exist from before, delete it; we shall return only the last one.
            free_error_memory(*ppEapError);
            *ppEapError = NULL;
        }

        if (i >= lCount) {
            *ppEapError = make_error(dwResult = ERROR_NOT_FOUND, 0, NULL, NULL, NULL, tstring_printf(_T(__FUNCTION__) _T(" No <AuthenticationMethod> with <EAPMethod>%u</EAPMethod> authentication method found or successfuly loaded."), EAP_TYPE_TTLS).c_str(), NULL);
            break;
        }

        com_obj<IXMLDOMNode> pXmlElMethod;
        pXmlListMethods->get_item(i, &pXmlElMethod);

        // Check EAP method type (<EAPMethod>).
        DWORD dwMethodID;
        if (eapxml::get_element_value(pXmlElMethod, bstr(L"eap-metadata:EAPMethod"), &dwMethodID) == ERROR_SUCCESS) {
            if (dwMethodID != EAP_TYPE_TTLS) {
                // Not TTLS.
                continue;
            }
        }

        // Load TTLS configuration.
        eap::config_ttls cfg(*this);
        dwResult = cfg.load(pXmlElMethod, ppEapError);
        if (dwResult != ERROR_SUCCESS)
            continue;

        // Allocate BLOB for configuration.
        assert(ppConfigOut);
        assert(pdwConfigOutSize);
        *pdwConfigOutSize = (DWORD)eapserial::get_pk_size(cfg);
        *ppConfigOut = alloc_memory(*pdwConfigOutSize);
        if (!*ppConfigOut) {
            *ppEapError = make_error(dwResult = ERROR_OUTOFMEMORY, 0, NULL, NULL, NULL, tstring_printf(_T(__FUNCTION__) _T(" Error allocating memory for configuration BLOB (%uB)."), *pdwConfigOutSize).c_str(), NULL);
            return dwResult;
        }

        // Pack BLOB to output.
        unsigned char *cursor = *ppConfigOut;
        eapserial::pack(cursor, cfg);
        assert(cursor - *ppConfigOut <= *pdwConfigOutSize);

        break;
    }

    return dwResult;
}


DWORD eap::peer_ttls_ui::invoke_config_ui(
    _In_                                     HWND            hwndParent,
    _In_                                     DWORD           dwFlags,
    _In_                                     DWORD           dwConnectionDataInSize,
    _In_count_(dwConnectionDataInSize) const BYTE            *pConnectionDataIn,
    _Out_                                    DWORD           *pdwConnectionDataOutSize,
    _Out_                                    BYTE            **ppConnectionDataOut,
    _Out_                                    EAP_ERROR       **ppEapError)
{
    UNREFERENCED_PARAMETER(dwFlags);
    assert(ppEapError);
    DWORD dwResult = ERROR_SUCCESS;
    ETW_FN_DWORD(dwResult);

    // Unpack configuration.
    eap::config_ttls cfg(*this);
    if (pConnectionDataIn || !dwConnectionDataInSize) {
        const unsigned char *cursor = pConnectionDataIn;
        eapserial::unpack(cursor, cfg);
        assert(cursor - pConnectionDataIn <= dwConnectionDataInSize);
    }

    InitCommonControls();
    MessageBox(hwndParent, _T(PRODUCT_NAME_STR) _T(" configuration goes here!"), _T(PRODUCT_NAME_STR) _T(" Settings"), MB_OK);

    // Allocate BLOB for configuration.
    assert(ppConnectionDataOut);
    assert(pdwConnectionDataOutSize);
    *pdwConnectionDataOutSize = (DWORD)eapserial::get_pk_size(cfg);
    *ppConnectionDataOut = alloc_memory(*pdwConnectionDataOutSize);
    if (!*ppConnectionDataOut) {
        *ppEapError = make_error(dwResult = ERROR_OUTOFMEMORY, 0, NULL, NULL, NULL, tstring_printf(_T(__FUNCTION__) _T(" Error allocating memory for configuration BLOB (%uB)."), *pdwConnectionDataOutSize).c_str(), NULL);
        return dwResult;
    }

    // Pack BLOB to output.
    unsigned char *cursor = *ppConnectionDataOut;
    eapserial::pack(cursor, cfg);
    assert(cursor - *ppConnectionDataOut <= *pdwConnectionDataOutSize);

    return dwResult;
}


DWORD eap::peer_ttls_ui::invoke_identity_ui(
            _In_                                   DWORD           dwFlags,
            _In_                                   HWND            hwndParent,
            _In_                                   DWORD           dwConnectionDataSize,
            _In_count_(dwConnectionDataSize) const BYTE            *pConnectionData,
            _In_                                   DWORD           dwUserDataSize,
            _In_count_(dwUserDataSize)       const BYTE            *pUserData,
            _Out_                                  DWORD           *pdwUserDataOutSize,
            _Out_                                  BYTE            **ppUserDataOut,
            _Out_                                  LPWSTR          *ppwszIdentity,
            _Out_                                  EAP_ERROR       **ppEapError)
{
    UNREFERENCED_PARAMETER(dwFlags);
    UNREFERENCED_PARAMETER(dwConnectionDataSize);
    UNREFERENCED_PARAMETER(pConnectionData);
    UNREFERENCED_PARAMETER(dwUserDataSize);
    UNREFERENCED_PARAMETER(pUserData);
    UNREFERENCED_PARAMETER(pdwUserDataOutSize);
    UNREFERENCED_PARAMETER(ppUserDataOut);
    UNREFERENCED_PARAMETER(ppwszIdentity);
    UNREFERENCED_PARAMETER(ppEapError);

    InitCommonControls();
    MessageBox(hwndParent, _T(PRODUCT_NAME_STR) _T(" credential prompt goes here!"), _T(PRODUCT_NAME_STR) _T(" Credentials"), MB_OK);

    return ERROR_SUCCESS;
}


DWORD eap::peer_ttls_ui::invoke_interactive_ui(
    _In_                                  HWND            hwndParent,
    _In_                                  DWORD           dwUIContextDataSize,
    _In_count_(dwUIContextDataSize) const BYTE            *pUIContextData,
    _Out_                                 DWORD           *pdwDataFromInteractiveUISize,
    _Out_                                 BYTE            **ppDataFromInteractiveUI,
    _Out_                                 EAP_ERROR       **ppEapError)
{
    UNREFERENCED_PARAMETER(dwUIContextDataSize);
    UNREFERENCED_PARAMETER(pUIContextData);
    UNREFERENCED_PARAMETER(pdwDataFromInteractiveUISize);
    UNREFERENCED_PARAMETER(ppDataFromInteractiveUI);
    UNREFERENCED_PARAMETER(ppEapError);

    InitCommonControls();
    MessageBox(hwndParent, _T(PRODUCT_NAME_STR) _T(" interactive UI goes here!"), _T(PRODUCT_NAME_STR) _T(" Prompt"), MB_OK);

    return ERROR_SUCCESS;
}
