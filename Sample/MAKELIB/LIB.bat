@ECHO OFF

REM ******************************************************************************
REM
REM   This file needs to be changed.
REM
REM ******************************************************************************

REM ****************************************
REM   Link
REM ****************************************

ECHO /nologo /out:Library\GUI.lib>>Temp\Output\OBJ.DAT
LINK -lib @Temp\Output\OBJ.DAT
IF ERRORLEVEL 1 PAUSE

