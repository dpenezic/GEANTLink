#
#    Copyright 1991-2016 Amebis
#    Copyright 2016 GÉANT
#
#    This file is part of GÉANTLink.
#
#    GÉANTLink is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    GÉANTLink is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with GÉANTLink. If not, see <http://www.gnu.org/licenses/>.
#

!INCLUDE "..\..\include\MSIBuildCfg.mak"

!IFNDEF MSIBUILD_PRODUCT_NAME
!ERROR Parameter MSIBUILD_PRODUCT_NAME is undefined.
!ENDIF

!IFNDEF MSIBUILD_PRODUCT_NAME_UC
!ERROR Parameter MSIBUILD_PRODUCT_NAME_UC is undefined.
!ENDIF

MSIBUILD_IS_LOCALIZEABLE=1


######################################################################
# AppSearch

All :: "$(LANG).$(PLAT).$(CFG).AppSearch-1.idt"

"$(LANG).$(PLAT).$(CFG).AppSearch-1.idt" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
Property	Signature_
s$(MSIBUILD_LENGTH_ID)	s$(MSIBUILD_LENGTH_ID)
AppSearch	Property	Signature_
OLD$(MSIBUILD_PRODUCT_NAME_UC)DIR	clEAPTTLS.dll.$(PLAT)
OLD$(MSIBUILD_PRODUCT_NAME_UC)DIR	clEAPTTLSUI.dll.$(PLAT)
<<NOKEEP


######################################################################
# CompLocator

All :: "$(LANG).$(PLAT).$(CFG).CompLocator-1.idt"

"$(LANG).$(PLAT).$(CFG).CompLocator-1.idt" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
Signature_	ComponentId	Type
s$(MSIBUILD_LENGTH_ID)	s38	I2
CompLocator	Signature_
!IF "$(PLAT)" == "Win32"
clEAPTTLS.dll.Win32	{A4A62D2F-DA90-4765-BD8C-D59EA2C01DFE}	1
clEAPTTLSUI.dll.Win32	{1EBA30DA-69D1-4EB5-B353-65F9BD8164EF}	1
!ENDIF
!IF "$(PLAT)" == "x64"
clEAPTTLS.dll.x64	{A1F62401-03F1-4D4E-A1FA-0FD4858D90B6}	1
clEAPTTLSUI.dll.x64	{01C9F45C-9B29-4C1A-9FF2-856F8799C2D0}	1
!ENDIF
<<NOKEEP


######################################################################
# Component

All :: "$(LANG).$(PLAT).$(CFG).Component-1.idt"

"$(LANG).$(PLAT).$(CFG).Component-1.idt" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
Component	ComponentId	Directory_	Attributes	Condition	KeyPath
s$(MSIBUILD_LENGTH_ID)	S38	s$(MSIBUILD_LENGTH_ID)	i2	S255	S$(MSIBUILD_LENGTH_ID)
Component	Component
compEAPHostAuthor	{086E042A-6741-459D-92F0-F5CCFA4E34D4}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPHostAuthor
!IF "$(PLAT)" == "Win32"
compEAPTTLS.dll.Win32	{A4A62D2F-DA90-4765-BD8C-D59EA2C01DFE}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	0		fileEAPTTLS.dll.Win32
compEAPTTLSUI.dll.Win32	{1EBA30DA-69D1-4EB5-B353-65F9BD8164EF}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	0		fileEAPTTLSUI.dll.Win32
!ENDIF
!IF "$(PLAT)" == "x64"
compEAPTTLS.dll.x64	{A1F62401-03F1-4D4E-A1FA-0FD4858D90B6}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	256		fileEAPTTLS.dll.x64
compEAPTTLSUI.dll.x64	{01C9F45C-9B29-4C1A-9FF2-856F8799C2D0}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	256		fileEAPTTLSUI.dll.x64
!ENDIF
compEAPTTLSPeerDllPath	{29FD2FDC-9289-47F0-96A3-C21AEE587B5B}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSPeerDllPath
compEAPTTLSPeerConfigUIPath	{2516BB92-0C14-4157-A136-3A713D459D08}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSPeerConfigUIPath
compEAPTTLSPeerIdentityPath	{3E1F0068-863C-4CFB-8D95-A66995443D19}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSPeerIdentityPath
compEAPTTLSPeerInteractiveUIPath	{256F1256-C085-4EA3-8D7E-FF4BBCCC3C7D}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSPeerInteractiveUIPath
compEAPTTLSPeerFriendlyName	{E3250ECE-E59F-4693-B290-925B80929EAE}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSPeerFriendlyName
compEAPTTLSPeerInvokePasswordDialog	{9A426E96-6E79-4BA9-83DD-7A205CA43810}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSPeerInvokePasswordDialog
compEAPTTLSPeerInvokeUsernameDialog	{92E9B700-3D91-4C6F-BBD8-99888D7A2387}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSPeerInvokeUsernameDialog
compEAPTTLSProperties	{266DE96B-8115-407A-B69C-1D2FDC8FEF42}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	$(MSIBUILD_COMPONENT_ATTRIB_REGISTRY)		regEAPTTLSProperties
compEAPTTLSUI.mo.bg_BG	{D04D464C-AEDB-4164-96D9-1553B3AB4AB8}	$(MSIBUILD_PRODUCT_NAME_UC)LOCBGBGDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.bg_BG
compEAPTTLSUI.mo.ca_ES	{C0FFADEA-DBE1-4710-B7D4-B44C4B388600}	$(MSIBUILD_PRODUCT_NAME_UC)LOCCAESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.ca_ES
compEAPTTLSUI.mo.cs_CZ	{2B7BE956-F064-4C85-BE76-BA8CDA0E037B}	$(MSIBUILD_PRODUCT_NAME_UC)LOCCSCZDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.cs_CZ
compEAPTTLSUI.mo.cy_UK	{F02D2D8C-9B9B-4506-8AC8-48E0A0E09BA9}	$(MSIBUILD_PRODUCT_NAME_UC)LOCCYUKDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.cy_UK
compEAPTTLSUI.mo.de_DE	{0508F73C-6FDF-4D1A-8E70-E6CB227FD3E5}	$(MSIBUILD_PRODUCT_NAME_UC)LOCDEDEDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.de_DE
compEAPTTLSUI.mo.el_GR	{EE86401E-F313-44ED-9569-8BA17AF8EEF4}	$(MSIBUILD_PRODUCT_NAME_UC)LOCELGRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.el_GR
compEAPTTLSUI.mo.es_ES	{1C1A594F-F324-436C-B849-69EFB2938534}	$(MSIBUILD_PRODUCT_NAME_UC)LOCESESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.es_ES
compEAPTTLSUI.mo.eu_ES	{97148C80-1826-4D08-9524-969C0272B453}	$(MSIBUILD_PRODUCT_NAME_UC)LOCEUESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.eu_ES
compEAPTTLSUI.mo.fi_FI	{3D95EA54-34D7-411B-833B-D2C0EB67AAFE}	$(MSIBUILD_PRODUCT_NAME_UC)LOCFIFIDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.fi_FI
compEAPTTLSUI.mo.fr_CA	{C3BD2DB1-D234-4669-84A1-595F416A0D62}	$(MSIBUILD_PRODUCT_NAME_UC)LOCFRCADIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.fr_CA
compEAPTTLSUI.mo.fr_FR	{DC845DDA-C386-4E1E-837A-AF323A17E0A3}	$(MSIBUILD_PRODUCT_NAME_UC)LOCFRFRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.fr_FR
compEAPTTLSUI.mo.gl_ES	{86FD2721-6BEF-471C-AF72-B00916593241}	$(MSIBUILD_PRODUCT_NAME_UC)LOCGLESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.gl_ES
compEAPTTLSUI.mo.hr_HR	{5A535697-CC07-4582-AEEE-FBBD53A95BF8}	$(MSIBUILD_PRODUCT_NAME_UC)LOCHRHRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.hr_HR
compEAPTTLSUI.mo.hu_HU	{14BFC9B7-05A9-486B-B7E5-598C248860B3}	$(MSIBUILD_PRODUCT_NAME_UC)LOCHUHUDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.hu_HU
compEAPTTLSUI.mo.is_IS	{8A34CE39-DC52-41F3-B038-9E94717B227F}	$(MSIBUILD_PRODUCT_NAME_UC)LOCISISDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.is_IS
compEAPTTLSUI.mo.it_IT	{FA59E746-4CAB-4530-9C3C-1E8A58ACE822}	$(MSIBUILD_PRODUCT_NAME_UC)LOCITITDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.it_IT
compEAPTTLSUI.mo.ko_KR	{E1DF308C-26DF-47B5-8FEC-9443340D75A5}	$(MSIBUILD_PRODUCT_NAME_UC)LOCKOKRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.ko_KR
compEAPTTLSUI.mo.lt_LT	{8FEAE819-D777-4837-9B2C-98C53A1BBCC1}	$(MSIBUILD_PRODUCT_NAME_UC)LOCLTLTDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.lt_LT
compEAPTTLSUI.mo.nb_NO	{5BA7F9D7-D556-4D33-9FD8-2EE7200BABC8}	$(MSIBUILD_PRODUCT_NAME_UC)LOCNBNODIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.nb_NO
compEAPTTLSUI.mo.nl_NL	{47EC1173-B997-4674-A798-573C2423D4A7}	$(MSIBUILD_PRODUCT_NAME_UC)LOCNLNLDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.nl_NL
compEAPTTLSUI.mo.pl_PL	{77D9BF28-5481-4302-8C0D-75A752D0A9D5}	$(MSIBUILD_PRODUCT_NAME_UC)LOCPLPLDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.pl_PL
compEAPTTLSUI.mo.pt_PT	{CBBC0BEB-C2E9-4C29-8FF8-48F1D30066BC}	$(MSIBUILD_PRODUCT_NAME_UC)LOCPTPTDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.pt_PT
compEAPTTLSUI.mo.ru_RU	{9338349A-D2C0-48EE-A0B4-2735EEA716B8}	$(MSIBUILD_PRODUCT_NAME_UC)LOCRURUDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.ru_RU
compEAPTTLSUI.mo.sk_SK	{717CA21C-B4A4-499C-866D-1674BBF0BBE7}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSKSKDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.sk_SK
compEAPTTLSUI.mo.sl_SI	{E894E133-A5DD-4422-8CEA-70A3F6C0B763}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSLSIDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.sl_SI
compEAPTTLSUI.mo.sr_RS	{A16D1C48-3C1A-482F-A08F-962A5C63655A}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSRRSDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.sr_RS
compEAPTTLSUI.mo.sv_SE	{4B355A03-EB07-4594-A1DE-A824E20DED6C}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSVSEDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.sv_SE
compEAPTTLSUI.mo.tr_TR	{E675BC56-7C98-44DE-A424-BEB5CB503301}	$(MSIBUILD_PRODUCT_NAME_UC)LOCTRTRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.tr_TR
compEAPTTLSUI.mo.vi_VN	{1D5AA0B3-3B63-4A81-8B3E-843F50E3F5A4}	$(MSIBUILD_PRODUCT_NAME_UC)LOCVIVNDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEAPTTLSUI.mo.vi_VN
<<NOKEEP


######################################################################
# Feature

All :: "$(LANG).$(PLAT).$(CFG).Feature-2.idt"

"en_US.$(PLAT).$(CFG).Feature-2.idtx" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
Feature	Feature_Parent	Title	Description	Display	Level	Directory_	Attributes
s$(MSIBUILD_LENGTH_ID)	S$(MSIBUILD_LENGTH_ID)	L64	L255	I2	i2	S$(MSIBUILD_LENGTH_ID)	i2
1252	Feature	Feature
featEAPMethods		EAP Methods	Modules to support individual EAP methods	1	3	$(MSIBUILD_PRODUCT_NAME_UC)DIR	0
featEAPTTLS	featEAPMethods	TTLS	Tunneled Transport Layer Security	1	3	$(MSIBUILD_PRODUCT_NAME_UC)DIR	8
<<NOKEEP

!IF "$(LANG)" == "en_US"
"en_US.$(PLAT).$(CFG).Feature-2.idt" : "en_US.$(PLAT).$(CFG).Feature-2.idtx"
	copy /y $** $@ > NUL
!ELSE
"$(LANG).$(PLAT).$(CFG).Feature-2.idt" : "en_US.$(PLAT).$(CFG).Feature-2.idtx" "..\locale\$(LANG).po"
	cscript.exe "..\..\MSI\MSIBuild\MSI.wsf" //Job:IDTTranslate //Nologo $@ $** /CP:$(MSIBUILD_CODEPAGE)
!ENDIF


######################################################################
# FeatureComponents

All :: "$(LANG).$(PLAT).$(CFG).FeatureComponents-1.idt"

"$(LANG).$(PLAT).$(CFG).FeatureComponents-1.idt" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
Feature_	Component_
s$(MSIBUILD_LENGTH_ID)	s$(MSIBUILD_LENGTH_ID)
FeatureComponents	Feature_	Component_
featEAPTTLS	compEvents.dll.$(PLAT)
featEAPTTLS	compEvents1
featEAPTTLS	compEvents2
featEAPTTLS	compEvents3
featEAPTTLS	compEAPHostAuthor
featEAPTTLS	compEAPTTLS.dll.$(PLAT)
featEAPTTLS	compEAPTTLSUI.dll.$(PLAT)
featEAPTTLS	compEAPTTLSPeerDllPath
featEAPTTLS	compEAPTTLSPeerConfigUIPath
featEAPTTLS	compEAPTTLSPeerIdentityPath
featEAPTTLS	compEAPTTLSPeerInteractiveUIPath
featEAPTTLS	compEAPTTLSPeerFriendlyName
featEAPTTLS	compEAPTTLSPeerInvokePasswordDialog
featEAPTTLS	compEAPTTLSPeerInvokeUsernameDialog
featEAPTTLS	compEAPTTLSProperties
featEAPTTLS	compLocalizationRepositoryPath
featEAPTTLS	compLanguage
featEAPTTLS	compwxstd.mo.ca_ES
featEAPTTLS	compwxstd.mo.cs_CZ
featEAPTTLS	compwxstd.mo.de_DE
featEAPTTLS	compwxstd.mo.el_GR
featEAPTTLS	compwxstd.mo.es_ES
featEAPTTLS	compwxstd.mo.eu_ES
featEAPTTLS	compwxstd.mo.fi_FI
featEAPTTLS	compwxstd.mo.fr_CA
featEAPTTLS	compwxstd.mo.fr_FR
featEAPTTLS	compwxstd.mo.gl_ES
featEAPTTLS	compwxstd.mo.hu_HU
featEAPTTLS	compwxstd.mo.it_IT
featEAPTTLS	compwxstd.mo.ko_KR
featEAPTTLS	compwxstd.mo.lt_LT
featEAPTTLS	compwxstd.mo.nb_NO
featEAPTTLS	compwxstd.mo.nl_NL
featEAPTTLS	compwxstd.mo.pl_PL
featEAPTTLS	compwxstd.mo.pt_PT
featEAPTTLS	compwxstd.mo.ru_RU
featEAPTTLS	compwxstd.mo.sk_SK
featEAPTTLS	compwxstd.mo.sl_SI
featEAPTTLS	compwxstd.mo.sv_SE
featEAPTTLS	compwxstd.mo.tr_TR
featEAPTTLS	compwxstd.mo.vi_VN
featEAPTTLS	compwxExtend.mo.bg_BG
featEAPTTLS	compwxExtend.mo.ca_ES
featEAPTTLS	compwxExtend.mo.cs_CZ
featEAPTTLS	compwxExtend.mo.cy_UK
featEAPTTLS	compwxExtend.mo.de_DE
featEAPTTLS	compwxExtend.mo.el_GR
featEAPTTLS	compwxExtend.mo.es_ES
featEAPTTLS	compwxExtend.mo.eu_ES
featEAPTTLS	compwxExtend.mo.fi_FI
featEAPTTLS	compwxExtend.mo.fr_CA
featEAPTTLS	compwxExtend.mo.fr_FR
featEAPTTLS	compwxExtend.mo.gl_ES
featEAPTTLS	compwxExtend.mo.hr_HR
featEAPTTLS	compwxExtend.mo.hu_HU
featEAPTTLS	compwxExtend.mo.is_IS
featEAPTTLS	compwxExtend.mo.it_IT
featEAPTTLS	compwxExtend.mo.ko_KR
featEAPTTLS	compwxExtend.mo.lt_LT
featEAPTTLS	compwxExtend.mo.nb_NO
featEAPTTLS	compwxExtend.mo.nl_NL
featEAPTTLS	compwxExtend.mo.pl_PL
featEAPTTLS	compwxExtend.mo.pt_PT
featEAPTTLS	compwxExtend.mo.ru_RU
featEAPTTLS	compwxExtend.mo.sk_SK
featEAPTTLS	compwxExtend.mo.sl_SI
featEAPTTLS	compwxExtend.mo.sr_RS
featEAPTTLS	compwxExtend.mo.sv_SE
featEAPTTLS	compwxExtend.mo.tr_TR
featEAPTTLS	compwxExtend.mo.vi_VN
featEAPTTLS	compEAPTTLSUI.mo.bg_BG
featEAPTTLS	compEAPTTLSUI.mo.ca_ES
featEAPTTLS	compEAPTTLSUI.mo.cs_CZ
featEAPTTLS	compEAPTTLSUI.mo.cy_UK
featEAPTTLS	compEAPTTLSUI.mo.de_DE
featEAPTTLS	compEAPTTLSUI.mo.el_GR
featEAPTTLS	compEAPTTLSUI.mo.es_ES
featEAPTTLS	compEAPTTLSUI.mo.eu_ES
featEAPTTLS	compEAPTTLSUI.mo.fi_FI
featEAPTTLS	compEAPTTLSUI.mo.fr_CA
featEAPTTLS	compEAPTTLSUI.mo.fr_FR
featEAPTTLS	compEAPTTLSUI.mo.gl_ES
featEAPTTLS	compEAPTTLSUI.mo.hr_HR
featEAPTTLS	compEAPTTLSUI.mo.hu_HU
featEAPTTLS	compEAPTTLSUI.mo.is_IS
featEAPTTLS	compEAPTTLSUI.mo.it_IT
featEAPTTLS	compEAPTTLSUI.mo.ko_KR
featEAPTTLS	compEAPTTLSUI.mo.lt_LT
featEAPTTLS	compEAPTTLSUI.mo.nb_NO
featEAPTTLS	compEAPTTLSUI.mo.nl_NL
featEAPTTLS	compEAPTTLSUI.mo.pl_PL
featEAPTTLS	compEAPTTLSUI.mo.pt_PT
featEAPTTLS	compEAPTTLSUI.mo.ru_RU
featEAPTTLS	compEAPTTLSUI.mo.sk_SK
featEAPTTLS	compEAPTTLSUI.mo.sl_SI
featEAPTTLS	compEAPTTLSUI.mo.sr_RS
featEAPTTLS	compEAPTTLSUI.mo.sv_SE
featEAPTTLS	compEAPTTLSUI.mo.tr_TR
featEAPTTLS	compEAPTTLSUI.mo.vi_VN
<<NOKEEP


######################################################################
# File

All :: "$(LANG).$(PLAT).$(CFG).File-1.idt"

"$(LANG).$(PLAT).$(CFG).File-1.idt" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
File	Component_	FileName	FileSize	Version	Language	Attributes	Sequence
s$(MSIBUILD_LENGTH_ID)	s$(MSIBUILD_LENGTH_ID)	l255	i4	S$(MSIBUILD_LENGTH_ID)	S20	I2	i2
File	File
fileEAPTTLS.dll.$(PLAT)	compEAPTTLS.dll.$(PLAT)	EAPTTLS.dll	0		0	1536	1
fileEAPTTLSUI.dll.$(PLAT)	compEAPTTLSUI.dll.$(PLAT)	EAPTTL~1.DLL|EAPTTLSUI.dll	0		0	1536	1
fileEAPTTLSUI.mo.bg_BG	compEAPTTLSUI.mo.bg_BG	EAPTTL~1.MO|EAPTTLSUI.mo	0		1026	0	1
fileEAPTTLSUI.mo.ca_ES	compEAPTTLSUI.mo.ca_ES	EAPTTL~1.MO|EAPTTLSUI.mo	0		1027	0	1
fileEAPTTLSUI.mo.cs_CZ	compEAPTTLSUI.mo.cs_CZ	EAPTTL~1.MO|EAPTTLSUI.mo	0		1029	0	1
fileEAPTTLSUI.mo.cy_UK	compEAPTTLSUI.mo.cy_UK	EAPTTL~1.MO|EAPTTLSUI.mo	0		1106	0	1
fileEAPTTLSUI.mo.de_DE	compEAPTTLSUI.mo.de_DE	EAPTTL~1.MO|EAPTTLSUI.mo	0		1031	0	1
fileEAPTTLSUI.mo.el_GR	compEAPTTLSUI.mo.el_GR	EAPTTL~1.MO|EAPTTLSUI.mo	0		1032	0	1
fileEAPTTLSUI.mo.es_ES	compEAPTTLSUI.mo.es_ES	EAPTTL~1.MO|EAPTTLSUI.mo	0		1034	0	1
fileEAPTTLSUI.mo.eu_ES	compEAPTTLSUI.mo.eu_ES	EAPTTL~1.MO|EAPTTLSUI.mo	0		1069	0	1
fileEAPTTLSUI.mo.fi_FI	compEAPTTLSUI.mo.fi_FI	EAPTTL~1.MO|EAPTTLSUI.mo	0		1035	0	1
fileEAPTTLSUI.mo.fr_CA	compEAPTTLSUI.mo.fr_CA	EAPTTL~1.MO|EAPTTLSUI.mo	0		3084	0	1
fileEAPTTLSUI.mo.fr_FR	compEAPTTLSUI.mo.fr_FR	EAPTTL~1.MO|EAPTTLSUI.mo	0		1036	0	1
fileEAPTTLSUI.mo.gl_ES	compEAPTTLSUI.mo.gl_ES	EAPTTL~1.MO|EAPTTLSUI.mo	0		1110	0	1
fileEAPTTLSUI.mo.hr_HR	compEAPTTLSUI.mo.hr_HR	EAPTTL~1.MO|EAPTTLSUI.mo	0		1050	0	1
fileEAPTTLSUI.mo.hu_HU	compEAPTTLSUI.mo.hu_HU	EAPTTL~1.MO|EAPTTLSUI.mo	0		1038	0	1
fileEAPTTLSUI.mo.is_IS	compEAPTTLSUI.mo.is_IS	EAPTTL~1.MO|EAPTTLSUI.mo	0		1039	0	1
fileEAPTTLSUI.mo.it_IT	compEAPTTLSUI.mo.it_IT	EAPTTL~1.MO|EAPTTLSUI.mo	0		1040	0	1
fileEAPTTLSUI.mo.ko_KR	compEAPTTLSUI.mo.ko_KR	EAPTTL~1.MO|EAPTTLSUI.mo	0		1042	0	1
fileEAPTTLSUI.mo.lt_LT	compEAPTTLSUI.mo.lt_LT	EAPTTL~1.MO|EAPTTLSUI.mo	0		1063	0	1
fileEAPTTLSUI.mo.nb_NO	compEAPTTLSUI.mo.nb_NO	EAPTTL~1.MO|EAPTTLSUI.mo	0		1044	0	1
fileEAPTTLSUI.mo.nl_NL	compEAPTTLSUI.mo.nl_NL	EAPTTL~1.MO|EAPTTLSUI.mo	0		1043	0	1
fileEAPTTLSUI.mo.pl_PL	compEAPTTLSUI.mo.pl_PL	EAPTTL~1.MO|EAPTTLSUI.mo	0		1045	0	1
fileEAPTTLSUI.mo.pt_PT	compEAPTTLSUI.mo.pt_PT	EAPTTL~1.MO|EAPTTLSUI.mo	0		2070	0	1
fileEAPTTLSUI.mo.ru_RU	compEAPTTLSUI.mo.ru_RU	EAPTTL~1.MO|EAPTTLSUI.mo	0		1049	0	1
fileEAPTTLSUI.mo.sk_SK	compEAPTTLSUI.mo.sk_SK	EAPTTL~1.MO|EAPTTLSUI.mo	0		1051	0	1
fileEAPTTLSUI.mo.sl_SI	compEAPTTLSUI.mo.sl_SI	EAPTTL~1.MO|EAPTTLSUI.mo	0		1060	0	1
fileEAPTTLSUI.mo.sr_RS	compEAPTTLSUI.mo.sr_RS	EAPTTL~1.MO|EAPTTLSUI.mo	0		2074	0	1
fileEAPTTLSUI.mo.sv_SE	compEAPTTLSUI.mo.sv_SE	EAPTTL~1.MO|EAPTTLSUI.mo	0		1053	0	1
fileEAPTTLSUI.mo.tr_TR	compEAPTTLSUI.mo.tr_TR	EAPTTL~1.MO|EAPTTLSUI.mo	0		1055	0	1
fileEAPTTLSUI.mo.vi_VN	compEAPTTLSUI.mo.vi_VN	EAPTTL~1.MO|EAPTTLSUI.mo	0		1066	0	1
<<NOKEEP


######################################################################
# Registry

All :: "$(LANG).$(PLAT).$(CFG).Registry-1.idt"

"$(LANG).$(PLAT).$(CFG).Registry-1.idt" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
Registry	Root	Key	Name	Value	Component_
s$(MSIBUILD_LENGTH_ID)	i2	l255	L255	L0	s$(MSIBUILD_LENGTH_ID)
Registry	Registry
regEAPHostAuthor	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532		$(MSIBUILD_PRODUCT_NAME)	compEAPHostAuthor
regEAPTTLSPeerDllPath	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	PeerDllPath	[$(MSIBUILD_PRODUCT_NAME_UC)BINDIR]EAPTTLS.dll	compEAPTTLSPeerDllPath
regEAPTTLSPeerConfigUIPath	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	PeerConfigUIPath	[$(MSIBUILD_PRODUCT_NAME_UC)BINDIR]EAPTTLSUI.dll	compEAPTTLSPeerConfigUIPath
regEAPTTLSPeerIdentityPath	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	PeerIdentityPath	[$(MSIBUILD_PRODUCT_NAME_UC)BINDIR]EAPTTLSUI.dll	compEAPTTLSPeerIdentityPath
regEAPTTLSPeerInteractiveUIPath	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	PeerInteractiveUIPath	[$(MSIBUILD_PRODUCT_NAME_UC)BINDIR]EAPTTLSUI.dll	compEAPTTLSPeerInteractiveUIPath
regEAPTTLSPeerFriendlyName	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	PeerFriendlyName	@[$(MSIBUILD_PRODUCT_NAME_UC)BINDIR]EAPTTLS.dll,-1	compEAPTTLSPeerFriendlyName
regEAPTTLSPeerInvokePasswordDialog	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	PeerInvokePasswordDialog	#0	compEAPTTLSPeerInvokePasswordDialog
regEAPTTLSPeerInvokeUsernameDialog	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	PeerInvokeUsernameDialog	#0	compEAPTTLSPeerInvokeUsernameDialog
regEAPTTLSProperties	2	SYSTEM\CurrentControlSet\services\EapHost\Methods\67532\21	Properties	#389871807	compEAPTTLSProperties
<<NOKEEP


######################################################################
# Build MSM module!
######################################################################

!INCLUDE "..\..\MSI\MSIBuild\MSM.mak"
