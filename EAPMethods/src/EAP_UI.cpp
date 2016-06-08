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


//////////////////////////////////////////////////////////////////////
// wxEAPBannerPanel
//////////////////////////////////////////////////////////////////////

wxEAPBannerPanel::wxEAPBannerPanel(wxWindow* parent) : wxEAPBannerPanelBase(parent)
{
    m_title->SetLabelText(wxT(PRODUCT_NAME_STR));
}


//////////////////////////////////////////////////////////////////////
// wxPasswordCredentialsPanel
//////////////////////////////////////////////////////////////////////

wxPasswordCredentialsPanel::wxPasswordCredentialsPanel(eap::config_pass &cfg, wxWindow* parent) :
    m_cfg(cfg),
    wxPasswordCredentialsPanelBase(parent)
{
    // Load and set icon.
    if (m_shell32.load(_T("shell32.dll"), NULL, LOAD_LIBRARY_AS_DATAFILE | LOAD_LIBRARY_AS_IMAGE_RESOURCE))
        wxSetIconFromResource(m_credentials_icon, m_icon, m_shell32, MAKEINTRESOURCE(269));
}


bool wxPasswordCredentialsPanel::TransferDataToWindow()
{
    wxCHECK(wxPasswordCredentialsPanelBase::TransferDataToWindow(), false);

    // TODO: Read credentials from Windows Credential Manager.
    m_remember      ->SetValue(false);
    m_identity_label->Enable(false);
    m_identity      ->Enable(false);
    m_password_label->Enable(false);
    m_password      ->Enable(false);

    return true;
}


bool wxPasswordCredentialsPanel::TransferDataFromWindow()
{
    // TODO: Save credentials to Windows Credential Store.

    return wxPasswordCredentialsPanelBase::TransferDataFromWindow();
}


void wxPasswordCredentialsPanel::OnRemember(wxCommandEvent& event)
{
    if (event.IsChecked()) {
        m_identity_label->Enable(true);
        m_identity      ->Enable(true);
        m_password_label->Enable(true);
        m_password      ->Enable(true);
    } else {
        m_identity_label->Enable(false);
        m_identity      ->Enable(false);
        m_password_label->Enable(false);
        m_password      ->Enable(false);
    }
}
