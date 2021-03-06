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


//////////////////////////////////////////////////////////////////////
// eap::credentials_mschapv2
//////////////////////////////////////////////////////////////////////

eap::credentials_mschapv2::credentials_mschapv2(_In_ module &mod) : credentials_pass(mod)
{
}


eap::credentials_mschapv2::credentials_mschapv2(_In_ const credentials_mschapv2 &other) :
    credentials_pass(other)
{
}


eap::credentials_mschapv2::credentials_mschapv2(_Inout_ credentials_mschapv2 &&other) :
    credentials_pass(std::move(other))
{
}


eap::credentials_mschapv2& eap::credentials_mschapv2::operator=(_In_ const credentials_mschapv2 &other)
{
    if (this != &other)
        (credentials_pass&)*this = other;

    return *this;
}


eap::credentials_mschapv2& eap::credentials_mschapv2::operator=(_Inout_ credentials_mschapv2 &&other)
{
    if (this != &other)
        (credentials_pass&&)*this = std::move(other);

    return *this;
}
