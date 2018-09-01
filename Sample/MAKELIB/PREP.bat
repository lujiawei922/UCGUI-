@ECHO OFF

ECHO Prep.bat:            Preparing environment

REM ******************************************************************************
REM
REM   The following sample sets all environment variables needed by
REM
REM   Microsoft Visual C++
REM
REM ******************************************************************************

IF "%_PREP_VC60_%" == "_PREP_VC60_" GOTO END

SET _PREP_VC60_=_PREP_VC60_
SET VSCommonDir=C:\Program Files\Microsoft Visual Studio\Common
SET MSDevDir=C:\Program Files\Microsoft Visual Studio\Common\msdev98
SET MSVCDir=C:\Program Files\Microsoft Visual Studio\VC98
SET VcOsDir=WIN95

IF "%OS%" == "Windows_NT" SET VcOsDir=WINNT
IF "%OS%" == "Windows_NT" SET PATH=Temp;%MSDevDir%\BIN;%MSVCDir%\BIN;%VSCommonDir%\TOOLS\%VcOsDir%;%VSCommonDir%\TOOLS;%PATH%
IF "%OS%" == ""           SET PATH="%MSDevDir%\BIN";"%MSVCDir%\BIN";"%VSCommonDir%\TOOLS\%VcOsDir%";"%VSCommonDir%\TOOLS";"%windir%\SYSTEM";"%PATH%"

SET INCLUDE=%MSVCDir%\INCLUDE
SET INCLUDE=%INCLUDE%;Temp\Source

SET VcOsDir=
SET VSCommonDir=

:END

