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
OLD$(MSIBUILD_PRODUCT_NAME_UC)DIR	clEventMonitor.exe.$(PLAT)
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
clEventMonitor.exe.Win32	{3E4DDA0E-F8B2-4210-8D8A-90C221670B81}	1
!ENDIF
!IF "$(PLAT)" == "x64"
clEventMonitor.exe.x64	{B813B148-771A-49EB-8BE4-E76A3FA6B455}	1
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
!IF "$(PLAT)" == "Win32"
compEventMonitor.exe.Win32	{3E4DDA0E-F8B2-4210-8D8A-90C221670B81}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	0		fileEventMonitor.exe.Win32
!ENDIF
!IF "$(PLAT)" == "x64"
compEventMonitor.exe.x64	{B813B148-771A-49EB-8BE4-E76A3FA6B455}	$(MSIBUILD_PRODUCT_NAME_UC)BINDIR	256		fileEventMonitor.exe.x64
!ENDIF
compEventMonitor.mo.bg_BG	{289D4CED-93CB-41BC-A1CD-49AAF92A9D34}	$(MSIBUILD_PRODUCT_NAME_UC)LOCBGBGDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.bg_BG
compEventMonitor.mo.ca_ES	{FDD1ADDC-3F46-49D4-BCFA-C34D00BBC7EA}	$(MSIBUILD_PRODUCT_NAME_UC)LOCCAESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.ca_ES
compEventMonitor.mo.cs_CZ	{A6D0F9E8-EBBD-4031-BC51-E1C13048AA18}	$(MSIBUILD_PRODUCT_NAME_UC)LOCCSCZDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.cs_CZ
compEventMonitor.mo.cy_UK	{A6BFD662-C651-44BF-8DFA-C6C21B4A8A87}	$(MSIBUILD_PRODUCT_NAME_UC)LOCCYUKDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.cy_UK
compEventMonitor.mo.de_DE	{DB8AC966-F21F-4A65-B71E-F1E50C25A358}	$(MSIBUILD_PRODUCT_NAME_UC)LOCDEDEDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.de_DE
compEventMonitor.mo.el_GR	{349F3EC9-9ED2-4900-8627-3E24F6E909DD}	$(MSIBUILD_PRODUCT_NAME_UC)LOCELGRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.el_GR
compEventMonitor.mo.es_ES	{D517C721-B99F-4A63-99C3-4F0228C34A72}	$(MSIBUILD_PRODUCT_NAME_UC)LOCESESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.es_ES
compEventMonitor.mo.eu_ES	{972471EE-9BA2-4C1D-B24F-03E9961B1594}	$(MSIBUILD_PRODUCT_NAME_UC)LOCEUESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.eu_ES
compEventMonitor.mo.fi_FI	{5E75DA9D-F6FE-4B7A-B55F-0D2B5D6E6D15}	$(MSIBUILD_PRODUCT_NAME_UC)LOCFIFIDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.fi_FI
compEventMonitor.mo.fr_CA	{F05D46EA-3BC8-4C94-AAE1-EA4294A8F544}	$(MSIBUILD_PRODUCT_NAME_UC)LOCFRCADIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.fr_CA
compEventMonitor.mo.fr_FR	{15C53BF2-292C-42E6-916F-A95CDB9E85F0}	$(MSIBUILD_PRODUCT_NAME_UC)LOCFRFRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.fr_FR
compEventMonitor.mo.gl_ES	{5F091ACF-E1CF-42AA-B9E9-9D1005FFFF15}	$(MSIBUILD_PRODUCT_NAME_UC)LOCGLESDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.gl_ES
compEventMonitor.mo.hr_HR	{45A24BF5-4135-4794-A911-12EDBABBBE14}	$(MSIBUILD_PRODUCT_NAME_UC)LOCHRHRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.hr_HR
compEventMonitor.mo.hu_HU	{4A002325-6EFF-43F9-AA0C-154196D1E516}	$(MSIBUILD_PRODUCT_NAME_UC)LOCHUHUDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.hu_HU
compEventMonitor.mo.is_IS	{B3A54E0F-70DC-4411-816A-D3E0DD0AC489}	$(MSIBUILD_PRODUCT_NAME_UC)LOCISISDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.is_IS
compEventMonitor.mo.it_IT	{E0CE3C8D-7B5B-4DDF-B268-AF8B69B97FA6}	$(MSIBUILD_PRODUCT_NAME_UC)LOCITITDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.it_IT
compEventMonitor.mo.ko_KR	{2EA4170A-AC94-4606-9766-579EE644B671}	$(MSIBUILD_PRODUCT_NAME_UC)LOCKOKRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.ko_KR
compEventMonitor.mo.lt_LT	{D9C9381C-6089-47B2-ACBF-7248482DD476}	$(MSIBUILD_PRODUCT_NAME_UC)LOCLTLTDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.lt_LT
compEventMonitor.mo.nb_NO	{0F8F995C-AF4F-4195-BA03-282352E35439}	$(MSIBUILD_PRODUCT_NAME_UC)LOCNBNODIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.nb_NO
compEventMonitor.mo.nl_NL	{A5D4C79C-7BD1-4343-9D90-DE93CA2C368A}	$(MSIBUILD_PRODUCT_NAME_UC)LOCNLNLDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.nl_NL
compEventMonitor.mo.pl_PL	{F85ECBEB-826A-4274-A90E-D41175EED4B0}	$(MSIBUILD_PRODUCT_NAME_UC)LOCPLPLDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.pl_PL
compEventMonitor.mo.pt_PT	{8091A33D-877C-48CF-BA71-887A0330AADD}	$(MSIBUILD_PRODUCT_NAME_UC)LOCPTPTDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.pt_PT
compEventMonitor.mo.ru_RU	{CB6C4D85-9AC4-49AC-86D3-1C900016D54B}	$(MSIBUILD_PRODUCT_NAME_UC)LOCRURUDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.ru_RU
compEventMonitor.mo.sk_SK	{CF490A41-84EC-4824-BB54-F904F9C6CF6E}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSKSKDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.sk_SK
compEventMonitor.mo.sl_SI	{0DB5E185-F861-40EF-B1CA-231D7206A9F6}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSLSIDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.sl_SI
compEventMonitor.mo.sr_RS	{1D996353-8CA6-4680-96F2-9C79AF2CC2D6}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSRRSDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.sr_RS
compEventMonitor.mo.sv_SE	{0439D0BF-65FD-43FB-AC36-DE53F0382E5C}	$(MSIBUILD_PRODUCT_NAME_UC)LOCSVSEDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.sv_SE
compEventMonitor.mo.tr_TR	{4AAAAABE-D395-4CD7-BB37-31B9438376DD}	$(MSIBUILD_PRODUCT_NAME_UC)LOCTRTRDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.tr_TR
compEventMonitor.mo.vi_VN	{EA02A0D1-932A-46C5-92DA-587C5B297D8A}	$(MSIBUILD_PRODUCT_NAME_UC)LOCVIVNDIR	$(MSIBUILD_COMPONENT_ATTRIB_FILE)		fileEventMonitor.mo.vi_VN
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
featEventMonitor		Event Monitor	Real-time display of internal events	101	3	$(MSIBUILD_PRODUCT_NAME_UC)DIR	8
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
featEventMonitor	compEvents.dll.$(PLAT)
featEventMonitor	compEvents1
featEventMonitor	compEvents2
featEventMonitor	compEvents3
featEventMonitor	compEventMonitor.exe.$(PLAT)
featEventMonitor	compLocalizationRepositoryPath
featEventMonitor	compLanguage
featEventMonitor	compwxstd.mo.ca_ES
featEventMonitor	compwxstd.mo.cs_CZ
featEventMonitor	compwxstd.mo.de_DE
featEventMonitor	compwxstd.mo.el_GR
featEventMonitor	compwxstd.mo.es_ES
featEventMonitor	compwxstd.mo.eu_ES
featEventMonitor	compwxstd.mo.fi_FI
featEventMonitor	compwxstd.mo.fr_CA
featEventMonitor	compwxstd.mo.fr_FR
featEventMonitor	compwxstd.mo.gl_ES
featEventMonitor	compwxstd.mo.hu_HU
featEventMonitor	compwxstd.mo.it_IT
featEventMonitor	compwxstd.mo.ko_KR
featEventMonitor	compwxstd.mo.lt_LT
featEventMonitor	compwxstd.mo.nb_NO
featEventMonitor	compwxstd.mo.nl_NL
featEventMonitor	compwxstd.mo.pl_PL
featEventMonitor	compwxstd.mo.pt_PT
featEventMonitor	compwxstd.mo.ru_RU
featEventMonitor	compwxstd.mo.sk_SK
featEventMonitor	compwxstd.mo.sl_SI
featEventMonitor	compwxstd.mo.sv_SE
featEventMonitor	compwxstd.mo.tr_TR
featEventMonitor	compwxstd.mo.vi_VN
featEventMonitor	compwxExtend.mo.bg_BG
featEventMonitor	compwxExtend.mo.ca_ES
featEventMonitor	compwxExtend.mo.cs_CZ
featEventMonitor	compwxExtend.mo.cy_UK
featEventMonitor	compwxExtend.mo.de_DE
featEventMonitor	compwxExtend.mo.el_GR
featEventMonitor	compwxExtend.mo.es_ES
featEventMonitor	compwxExtend.mo.eu_ES
featEventMonitor	compwxExtend.mo.fi_FI
featEventMonitor	compwxExtend.mo.fr_CA
featEventMonitor	compwxExtend.mo.fr_FR
featEventMonitor	compwxExtend.mo.gl_ES
featEventMonitor	compwxExtend.mo.hr_HR
featEventMonitor	compwxExtend.mo.hu_HU
featEventMonitor	compwxExtend.mo.is_IS
featEventMonitor	compwxExtend.mo.it_IT
featEventMonitor	compwxExtend.mo.ko_KR
featEventMonitor	compwxExtend.mo.lt_LT
featEventMonitor	compwxExtend.mo.nb_NO
featEventMonitor	compwxExtend.mo.nl_NL
featEventMonitor	compwxExtend.mo.pl_PL
featEventMonitor	compwxExtend.mo.pt_PT
featEventMonitor	compwxExtend.mo.ru_RU
featEventMonitor	compwxExtend.mo.sk_SK
featEventMonitor	compwxExtend.mo.sl_SI
featEventMonitor	compwxExtend.mo.sr_RS
featEventMonitor	compwxExtend.mo.sv_SE
featEventMonitor	compwxExtend.mo.tr_TR
featEventMonitor	compwxExtend.mo.vi_VN
featEventMonitor	compEventMonitor.mo.bg_BG
featEventMonitor	compEventMonitor.mo.ca_ES
featEventMonitor	compEventMonitor.mo.cs_CZ
featEventMonitor	compEventMonitor.mo.cy_UK
featEventMonitor	compEventMonitor.mo.de_DE
featEventMonitor	compEventMonitor.mo.el_GR
featEventMonitor	compEventMonitor.mo.es_ES
featEventMonitor	compEventMonitor.mo.eu_ES
featEventMonitor	compEventMonitor.mo.fi_FI
featEventMonitor	compEventMonitor.mo.fr_CA
featEventMonitor	compEventMonitor.mo.fr_FR
featEventMonitor	compEventMonitor.mo.gl_ES
featEventMonitor	compEventMonitor.mo.hr_HR
featEventMonitor	compEventMonitor.mo.hu_HU
featEventMonitor	compEventMonitor.mo.is_IS
featEventMonitor	compEventMonitor.mo.it_IT
featEventMonitor	compEventMonitor.mo.ko_KR
featEventMonitor	compEventMonitor.mo.lt_LT
featEventMonitor	compEventMonitor.mo.nb_NO
featEventMonitor	compEventMonitor.mo.nl_NL
featEventMonitor	compEventMonitor.mo.pl_PL
featEventMonitor	compEventMonitor.mo.pt_PT
featEventMonitor	compEventMonitor.mo.ru_RU
featEventMonitor	compEventMonitor.mo.sk_SK
featEventMonitor	compEventMonitor.mo.sl_SI
featEventMonitor	compEventMonitor.mo.sr_RS
featEventMonitor	compEventMonitor.mo.sv_SE
featEventMonitor	compEventMonitor.mo.tr_TR
featEventMonitor	compEventMonitor.mo.vi_VN
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
fileEventMonitor.exe.$(PLAT)	compEventMonitor.exe.$(PLAT)	EVENTM~1.EXE|EventMonitor.exe	0		0	1536	1
fileEventMonitor.mo.bg_BG	compEventMonitor.mo.bg_BG	EVENTM~1.MO|EventMonitor.mo	0		1026	0	1
fileEventMonitor.mo.ca_ES	compEventMonitor.mo.ca_ES	EVENTM~1.MO|EventMonitor.mo	0		1027	0	1
fileEventMonitor.mo.cs_CZ	compEventMonitor.mo.cs_CZ	EVENTM~1.MO|EventMonitor.mo	0		1029	0	1
fileEventMonitor.mo.cy_UK	compEventMonitor.mo.cy_UK	EVENTM~1.MO|EventMonitor.mo	0		1106	0	1
fileEventMonitor.mo.de_DE	compEventMonitor.mo.de_DE	EVENTM~1.MO|EventMonitor.mo	0		1031	0	1
fileEventMonitor.mo.el_GR	compEventMonitor.mo.el_GR	EVENTM~1.MO|EventMonitor.mo	0		1032	0	1
fileEventMonitor.mo.es_ES	compEventMonitor.mo.es_ES	EVENTM~1.MO|EventMonitor.mo	0		1034	0	1
fileEventMonitor.mo.eu_ES	compEventMonitor.mo.eu_ES	EVENTM~1.MO|EventMonitor.mo	0		1069	0	1
fileEventMonitor.mo.fi_FI	compEventMonitor.mo.fi_FI	EVENTM~1.MO|EventMonitor.mo	0		1035	0	1
fileEventMonitor.mo.fr_CA	compEventMonitor.mo.fr_CA	EVENTM~1.MO|EventMonitor.mo	0		3084	0	1
fileEventMonitor.mo.fr_FR	compEventMonitor.mo.fr_FR	EVENTM~1.MO|EventMonitor.mo	0		1036	0	1
fileEventMonitor.mo.gl_ES	compEventMonitor.mo.gl_ES	EVENTM~1.MO|EventMonitor.mo	0		1110	0	1
fileEventMonitor.mo.hr_HR	compEventMonitor.mo.hr_HR	EVENTM~1.MO|EventMonitor.mo	0		1050	0	1
fileEventMonitor.mo.hu_HU	compEventMonitor.mo.hu_HU	EVENTM~1.MO|EventMonitor.mo	0		1038	0	1
fileEventMonitor.mo.is_IS	compEventMonitor.mo.is_IS	EVENTM~1.MO|EventMonitor.mo	0		1039	0	1
fileEventMonitor.mo.it_IT	compEventMonitor.mo.it_IT	EVENTM~1.MO|EventMonitor.mo	0		1040	0	1
fileEventMonitor.mo.ko_KR	compEventMonitor.mo.ko_KR	EVENTM~1.MO|EventMonitor.mo	0		1042	0	1
fileEventMonitor.mo.lt_LT	compEventMonitor.mo.lt_LT	EVENTM~1.MO|EventMonitor.mo	0		1063	0	1
fileEventMonitor.mo.nb_NO	compEventMonitor.mo.nb_NO	EVENTM~1.MO|EventMonitor.mo	0		1044	0	1
fileEventMonitor.mo.nl_NL	compEventMonitor.mo.nl_NL	EVENTM~1.MO|EventMonitor.mo	0		1043	0	1
fileEventMonitor.mo.pl_PL	compEventMonitor.mo.pl_PL	EVENTM~1.MO|EventMonitor.mo	0		1045	0	1
fileEventMonitor.mo.pt_PT	compEventMonitor.mo.pt_PT	EVENTM~1.MO|EventMonitor.mo	0		2070	0	1
fileEventMonitor.mo.ru_RU	compEventMonitor.mo.ru_RU	EVENTM~1.MO|EventMonitor.mo	0		1049	0	1
fileEventMonitor.mo.sk_SK	compEventMonitor.mo.sk_SK	EVENTM~1.MO|EventMonitor.mo	0		1051	0	1
fileEventMonitor.mo.sl_SI	compEventMonitor.mo.sl_SI	EVENTM~1.MO|EventMonitor.mo	0		1060	0	1
fileEventMonitor.mo.sr_RS	compEventMonitor.mo.sr_RS	EVENTM~1.MO|EventMonitor.mo	0		2074	0	1
fileEventMonitor.mo.sv_SE	compEventMonitor.mo.sv_SE	EVENTM~1.MO|EventMonitor.mo	0		1053	0	1
fileEventMonitor.mo.tr_TR	compEventMonitor.mo.tr_TR	EVENTM~1.MO|EventMonitor.mo	0		1055	0	1
fileEventMonitor.mo.vi_VN	compEventMonitor.mo.vi_VN	EVENTM~1.MO|EventMonitor.mo	0		1066	0	1
<<NOKEEP


######################################################################
# RemoveFile

All :: "$(LANG).$(PLAT).$(CFG).RemoveFile-1.idt"

"$(LANG).$(PLAT).$(CFG).RemoveFile-1.idt" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
FileKey	Component_	FileName	DirProperty	InstallMode
s$(MSIBUILD_LENGTH_ID)	s$(MSIBUILD_LENGTH_ID)	L255	s$(MSIBUILD_LENGTH_ID)	i2
RemoveFile	FileKey
rmfiEventMonitor	compEventMonitor.exe.$(PLAT)		$(MSIBUILD_PRODUCT_NAME_ID)ShortcutDir	2
<<NOKEEP


######################################################################
# Shortcut

All :: "$(LANG).$(PLAT).$(CFG).Shortcut-2.idt"

"en_US.$(PLAT).$(CFG).Shortcut-2.idtx" : "Makefile" "..\..\include\MSIBuildCfg.mak"
	-if exist $@ del /f /q $@
	move /y << $@ > NUL
Shortcut	Directory_	Name	Component_	Target	Arguments	Description	Hotkey	Icon_	IconIndex	ShowCmd	WkDir
s$(MSIBUILD_LENGTH_ID)	s$(MSIBUILD_LENGTH_ID)	l128	s$(MSIBUILD_LENGTH_ID)	s$(MSIBUILD_LENGTH_ID)	S255	L255	I2	S$(MSIBUILD_LENGTH_ID)	I2	I2	S$(MSIBUILD_LENGTH_ID)
1252	Shortcut	Shortcut
shctEventMonitor	$(MSIBUILD_PRODUCT_NAME_ID)ShortcutDir	EVENTM~1|$(MSIBUILD_PRODUCT_NAME) Event Monitor	compEventMonitor.exe.$(PLAT)	featEventMonitor		Real-time display of internal events					$(MSIBUILD_PRODUCT_NAME_UC)BINDIR
<<NOKEEP

!IF "$(LANG)" == "en_US"
"en_US.$(PLAT).$(CFG).Shortcut-2.idt" : "en_US.$(PLAT).$(CFG).Shortcut-2.idtx"
	copy /y $** $@ > NUL
!ELSE
"$(LANG).$(PLAT).$(CFG).Shortcut-2.idt" : "en_US.$(PLAT).$(CFG).Shortcut-2.idtx" "..\locale\$(LANG).po"
	cscript.exe "..\..\MSI\MSIBuild\MSI.wsf" //Job:IDTTranslate //Nologo $@ $** /CP:$(MSIBUILD_CODEPAGE)
!ENDIF


######################################################################
# Build MSM module!
######################################################################

!INCLUDE "..\..\MSI\MSIBuild\MSM.mak"
