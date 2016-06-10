﻿/*
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

#include "StdAfx.h"

using namespace std;
using namespace winstd;


//////////////////////////////////////////////////////////////////////
// eap::credentials_tls
//////////////////////////////////////////////////////////////////////

eap::credentials_tls::credentials_tls(_In_ module &mod) : credentials(mod)
{
}


eap::credentials_tls::credentials_tls(_In_ const credentials_tls &other) :
    m_cert_hash(other.m_cert_hash),
    credentials(other)
{
}


eap::credentials_tls::credentials_tls(_Inout_ credentials_tls &&other) :
    m_cert_hash(std::move(m_cert_hash)),
    credentials(std::move(other))
{
}


eap::credentials_tls& eap::credentials_tls::operator=(_In_ const credentials_tls &other)
{
    if (this != &other) {
        (credentials&)*this = other;
        m_cert_hash         = other.m_cert_hash;
    }

    return *this;
}


eap::credentials_tls& eap::credentials_tls::operator=(_Inout_ credentials_tls &&other)
{
    if (this != &other) {
        (credentials&)*this = std::move(other);
        m_cert_hash         = std::move(other.m_cert_hash);
    }

    return *this;
}



void eap::credentials_tls::clear()
{
    credentials::clear();
    m_cert_hash.clear();
}


bool eap::credentials_tls::empty() const
{
    return credentials::empty() && m_cert_hash.empty();
}



DWORD eap::credentials_tls::load(_In_ IXMLDOMNode *pConfigRoot, _Out_ EAP_ERROR **ppEapError)
{
    assert(pConfigRoot);
    UNREFERENCED_PARAMETER(ppEapError);

    eapxml::get_element_hex(pConfigRoot, bstr(L"CertHash"), m_cert_hash);

    return ERROR_SUCCESS;
}


DWORD eap::credentials_tls::store(_In_ LPCTSTR pszTargetName, _Out_ EAP_ERROR **ppEapError) const
{
    assert(pszTargetName);
    assert(ppEapError);
    DWORD dwResult;

    tstring target(target_name(pszTargetName));

    // Write credentials.
    assert(m_cert_hash.size()*sizeof(char) < CRED_MAX_CREDENTIAL_BLOB_SIZE);
    assert(m_identity.length()             < CRED_MAX_USERNAME_LENGTH     );
    CREDENTIAL cred = {
        0,                                      // Flags
        CRED_TYPE_GENERIC,                      // Type
        (LPTSTR)target.c_str(),                 // TargetName
        _T(""),                                 // Comment
        { 0, 0 },                               // LastWritten
        (DWORD)m_cert_hash.size()*sizeof(char), // CredentialBlobSize
        (LPBYTE)m_cert_hash.data(),             // CredentialBlob
        CRED_PERSIST_ENTERPRISE,                // Persist
        0,                                      // AttributeCount
        NULL,                                   // Attributes
        NULL,                                   // TargetAlias
        (LPTSTR)m_identity.c_str()              // UserName
    };
    if (!CredWrite(&cred, 0)) {
        *ppEapError = m_module.make_error(dwResult = GetLastError(), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" CredWrite failed."), NULL);
        return dwResult;
    }

    return ERROR_SUCCESS;
}


DWORD eap::credentials_tls::retrieve(_In_ LPCTSTR pszTargetName, _Out_ EAP_ERROR **ppEapError)
{
    assert(pszTargetName && _tcslen(pszTargetName) < CRED_MAX_GENERIC_TARGET_NAME_LENGTH);
    DWORD dwResult;

    // Read credentials.
    unique_ptr<CREDENTIAL, CredFree_delete<CREDENTIAL> > cred;
    if (!CredRead(target_name(pszTargetName).c_str(), CRED_TYPE_GENERIC, 0, (PCREDENTIAL*)&cred)) {
        *ppEapError = m_module.make_error(dwResult = GetLastError(), 0, NULL, NULL, NULL, _T(__FUNCTION__) _T(" CredRead failed."), NULL);
        return dwResult;
    }

    if (cred->UserName)
        m_identity = cred->UserName;
    else
        m_identity.clear();

    m_cert_hash.assign(cred->CredentialBlob, cred->CredentialBlob + cred->CredentialBlobSize);

    return ERROR_SUCCESS;
}
