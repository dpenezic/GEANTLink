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
// eap::session
//////////////////////////////////////////////////////////////////////

eap::session::session()
{
}


eap::session::~session()
{
}


DWORD eap::session::begin(
    _In_                                   DWORD         dwFlags,
    _In_                             const EapAttributes *pAttributeArray,
    _In_                                   HANDLE        hTokenImpersonateUser,
    _In_                                   DWORD         dwConnectionDataSize,
    _In_count_(dwConnectionDataSize) const BYTE          *pConnectionData,
    _In_                                   DWORD         dwUserDataSize,
    _In_count_(dwUserDataSize)       const BYTE          *pUserData,
    _In_                                   DWORD         dwMaxSendPacketSize,
    _Out_                                  EAP_ERROR     **ppEapError)
{
    UNREFERENCED_PARAMETER(dwFlags);
    UNREFERENCED_PARAMETER(pAttributeArray);
    UNREFERENCED_PARAMETER(hTokenImpersonateUser);
    UNREFERENCED_PARAMETER(dwConnectionDataSize);
    UNREFERENCED_PARAMETER(pConnectionData);
    UNREFERENCED_PARAMETER(dwUserDataSize);
    UNREFERENCED_PARAMETER(pUserData);
    UNREFERENCED_PARAMETER(dwMaxSendPacketSize);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_SUCCESS;
}


DWORD eap::session::end(_Out_ EAP_ERROR **ppEapError)
{
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_SUCCESS;
}


DWORD eap::session::process_request_packet(
    _In_                                       DWORD               dwReceivedPacketSize,
    _In_bytecount_(dwReceivedPacketSize) const EapPacket           *pReceivedPacket,
    _Out_                                      EapPeerMethodOutput *pEapOutput,
    _Out_                                      EAP_ERROR           **ppEapError)
{
    UNREFERENCED_PARAMETER(dwReceivedPacketSize);
    UNREFERENCED_PARAMETER(pReceivedPacket);
    UNREFERENCED_PARAMETER(pEapOutput);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_NOT_SUPPORTED;
}


DWORD eap::session::get_response_packet(
    _Inout_                            DWORD              *pdwSendPacketSize,
    _Inout_bytecap_(*dwSendPacketSize) EapPacket          *pSendPacket,
    _Out_                              EAP_ERROR          **ppEapError)
{
    UNREFERENCED_PARAMETER(pdwSendPacketSize);
    UNREFERENCED_PARAMETER(pSendPacket);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_NOT_SUPPORTED;
}


DWORD eap::session::get_result(_In_ EapPeerMethodResultReason reason, _Out_ EapPeerMethodResult *ppResult, _Out_ EAP_ERROR **ppEapError)
{
    UNREFERENCED_PARAMETER(reason);
    UNREFERENCED_PARAMETER(ppResult);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_NOT_SUPPORTED;
}


DWORD eap::session::get_ui_context(
    _Out_ DWORD     *pdwUIContextDataSize,
    _Out_ BYTE      **ppUIContextData,
    _Out_ EAP_ERROR **ppEapError)
{
    UNREFERENCED_PARAMETER(pdwUIContextDataSize);
    UNREFERENCED_PARAMETER(ppUIContextData);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_NOT_SUPPORTED;
}


DWORD eap::session::set_ui_context(
    _In_                                  DWORD               dwUIContextDataSize,
    _In_count_(dwUIContextDataSize) const BYTE                *pUIContextData,
    _In_                            const EapPeerMethodOutput *pEapOutput,
    _Out_                                 EAP_ERROR           **ppEapError)
{
    UNREFERENCED_PARAMETER(dwUIContextDataSize);
    UNREFERENCED_PARAMETER(pUIContextData);
    UNREFERENCED_PARAMETER(pEapOutput);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_NOT_SUPPORTED;
}


DWORD eap::session::get_response_attributes(_Out_ EapAttributes *pAttribs, _Out_ EAP_ERROR **ppEapError)
{
    UNREFERENCED_PARAMETER(pAttribs);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_NOT_SUPPORTED;
}


DWORD eap::session::set_response_attributes(const _In_ EapAttributes *pAttribs, _Out_ EapPeerMethodOutput *pEapOutput, _Out_ EAP_ERROR **ppEapError)
{
    UNREFERENCED_PARAMETER(pAttribs);
    UNREFERENCED_PARAMETER(pEapOutput);
    UNREFERENCED_PARAMETER(ppEapError);

    return ERROR_NOT_SUPPORTED;
}
