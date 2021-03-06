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

namespace eap
{
    ///
    /// TTLS UI peer
    ///
    class peer_ttls_ui;
}

#pragma once

#include "../../TTLS/include/Config.h"
#include "../../TTLS/include/Credentials.h"
#include "../../EAPBase_UI/include/Module.h"


namespace eap
{
    class peer_ttls_ui : public peer_ui
    {
    public:
        ///
        /// Constructs a EAP TTLS UI peer module
        ///
        peer_ttls_ui();

        ///
        /// Makes a new method config
        ///
        virtual config_method* make_config_method();

        ///
        /// Converts XML into the configuration BLOB.
        ///
        /// \sa [EapPeerConfigXml2Blob function](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363602.aspx)
        ///
        virtual void config_xml2blob(
            _In_    DWORD       dwFlags,
            _In_    IXMLDOMNode *pConfigRoot,
            _Inout_ BYTE        **pConnectionDataOut,
            _Inout_ DWORD       *pdwConnectionDataOutSize);

        ///
        /// Converts the configuration BLOB to XML.
        ///
        /// The configuration BLOB is returned in the `ppConnectionDataOut` parameter of the `EapPeerInvokeConfigUI` function.
        ///
        /// \sa [EapPeerConfigBlob2Xml function](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363601.aspx)
        ///
        virtual void config_blob2xml(
            _In_                                   DWORD           dwFlags,
            _In_count_(dwConnectionDataSize) const BYTE            *pConnectionData,
            _In_                                   DWORD           dwConnectionDataSize,
            _In_                                   IXMLDOMDocument *pDoc,
            _In_                                   IXMLDOMNode     *pConfigRoot);

        ///
        /// Raises the EAP method's specific connection configuration user interface dialog on the client.
        ///
        /// \sa [EapPeerInvokeConfigUI function](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363614.aspx)
        ///
        virtual void invoke_config_ui(
            _In_                                     HWND  hwndParent,
            _In_count_(dwConnectionDataInSize) const BYTE  *pConnectionDataIn,
            _In_                                     DWORD dwConnectionDataInSize,
            _Inout_                                  BYTE  **ppConnectionDataOut,
            _Inout_                                  DWORD *pdwConnectionDataOutSize);

        ///
        /// Raises a custom interactive user interface dialog to obtain user identity information for the EAP method on the client.
        ///
        /// \sa [EapPeerInvokeIdentityUI function](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363615.aspx)
        ///
        virtual void invoke_identity_ui(
            _In_                                   HWND   hwndParent,
            _In_                                   DWORD  dwFlags,
            _In_count_(dwConnectionDataSize) const BYTE   *pConnectionData,
            _In_                                   DWORD  dwConnectionDataSize,
            _In_count_(dwUserDataSize)       const BYTE   *pUserData,
            _In_                                   DWORD  dwUserDataSize,
            _Inout_                                BYTE   **ppUserDataOut,
            _Inout_                                DWORD  *pdwUserDataOutSize,
            _Inout_                                LPWSTR *ppwszIdentity);

        ///
        /// Raises a custom interactive user interface dialog for the EAP method on the client.
        ///
        /// \sa [EapPeerInvokeInteractiveUI function](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363616.aspx)
        ///
        virtual void invoke_interactive_ui(
            _In_                                  HWND  hwndParent,
            _In_count_(dwUIContextDataSize) const BYTE  *pUIContextData,
            _In_                                  DWORD dwUIContextDataSize,
            _Inout_                               BYTE  **ppDataFromInteractiveUI,
            _Inout_                               DWORD *pdwDataFromInteractiveUISize);
    };
}
