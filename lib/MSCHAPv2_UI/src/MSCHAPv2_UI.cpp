/*
    Copyright 2015-2016 Amebis
    Copyright 2016 G�ANT

    This file is part of G�ANTLink.

    G�ANTLink is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    G�ANTLink is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with G�ANTLink. If not, see <http://www.gnu.org/licenses/>.
*/

#include "StdAfx.h"


//////////////////////////////////////////////////////////////////////
// wxMSCHAPv2ConfigPanel
//////////////////////////////////////////////////////////////////////

wxMSCHAPv2ConfigPanel::wxMSCHAPv2ConfigPanel(const eap::config_provider &prov, eap::config_method_mschapv2 &cfg, wxWindow* parent) : wxPanel(parent)
{
    wxBoxSizer* sb_content;
    sb_content = new wxBoxSizer( wxVERTICAL );

    m_credentials = new wxMSCHAPv2CredentialsConfigPanel(prov, cfg, this, _("MSCHAPv2 User ID and Password"));
    sb_content->Add(m_credentials, 0, wxEXPAND, 5);

    this->SetSizer(sb_content);
    this->Layout();

    // Connect Events
    this->Connect(wxEVT_INIT_DIALOG, wxInitDialogEventHandler(wxMSCHAPv2ConfigPanel::OnInitDialog));
}


wxMSCHAPv2ConfigPanel::~wxMSCHAPv2ConfigPanel()
{
    // Disconnect Events
    this->Disconnect(wxEVT_INIT_DIALOG, wxInitDialogEventHandler(wxMSCHAPv2ConfigPanel::OnInitDialog));
}


void wxMSCHAPv2ConfigPanel::OnInitDialog(wxInitDialogEvent& event)
{
    // Forward the event to child panels.
    if (m_credentials)
        m_credentials->GetEventHandler()->ProcessEvent(event);
}
