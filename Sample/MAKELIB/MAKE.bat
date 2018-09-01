@ECHO OFF

ECHO Make.bat:            Building library

REM ******************************************************************************
REM
REM   This file needs not to be changed.
REM
REM   Usage:
REM
REM   %1: Source path for GUI-files
REM   %2: Source path for config-files
REM
REM ******************************************************************************

REM ****************************************
REM   Prepare environment
REM ****************************************

CALL PREP.BAT

REM ****************************************
REM   Prepare working folders
REM ****************************************

IF "%OS%" == "Windows_NT" GOTO WinNT_0
DELTREE /Y Temp
DELTREE /Y Library
GOTO CONT_0
:WinNT_0
IF EXIST Temp    RD Temp    /S/Q
IF EXIST Library RD Library /S/Q
:CONT_0
MD Temp
MD Temp\Source
MD Temp\Output
MD Library

REM ****************************************
REM   Copy source files
REM ****************************************

IF NOT "%1" == "" SET SOURCE_PATH=%1
IF     "%1" == "" SET SOURCE_PATH=GUI
FOR %%i IN (C, H, BAT) DO IF EXIST %SOURCE_PATH%\Core\*.%%i         XCOPY %SOURCE_PATH%\Core\*.%%i         Temp\Source /Q
FOR %%i IN (C, H, BAT) DO IF EXIST %SOURCE_PATH%\LCDDriver\*.%%i    XCOPY %SOURCE_PATH%\LCDDriver\*.%%i    Temp\Source /Q
FOR %%i IN (C, H, BAT) DO IF EXIST %SOURCE_PATH%\Widget\*.%%i       XCOPY %SOURCE_PATH%\Widget\*.%%i       Temp\Source /Q
FOR %%i IN (C, H, BAT) DO IF EXIST %SOURCE_PATH%\WM\*.%%i           XCOPY %SOURCE_PATH%\WM\*.%%i           Temp\Source /Q
FOR %%i IN (C, BAT)    DO IF EXIST %SOURCE_PATH%\AntiAlias\*.%%i    XCOPY %SOURCE_PATH%\AntiAlias\*.%%i    Temp\Source /Q
FOR %%i IN (C, BAT)    DO IF EXIST %SOURCE_PATH%\ConvertColor\*.%%i XCOPY %SOURCE_PATH%\ConvertColor\*.%%i Temp\Source /Q
FOR %%i IN (C, BAT)    DO IF EXIST %SOURCE_PATH%\ConvertMono\*.%%i  XCOPY %SOURCE_PATH%\ConvertMono\*.%%i  Temp\Source /Q
FOR %%i IN (C, BAT)    DO IF EXIST %SOURCE_PATH%\Font\*.%%i         XCOPY %SOURCE_PATH%\Font\*.%%i         Temp\Source /Q
FOR %%i IN (C, BAT)    DO IF EXIST %SOURCE_PATH%\MemDev\*.%%i       XCOPY %SOURCE_PATH%\MemDev\*.%%i       Temp\Source /Q
FOR %%i IN (C, BAT)    DO IF EXIST %SOURCE_PATH%\Touch\*.%%i        XCOPY %SOURCE_PATH%\Touch\*.%%i        Temp\Source /Q
SET SOURCE_PATH=

REM ****************************************
REM   Copy configuration files
REM ****************************************

IF NOT "%2" == "" SET CONFIG_PATH=%2
IF     "%2" == "" SET CONFIG_PATH=Config
FOR %%i IN (GUIConf, LCDConf, GUITouchConf) DO IF EXIST %CONFIG_PATH%\%%i.h XCOPY %CONFIG_PATH%\%%i.h Temp\Source /Q
SET CONFIG_PATH=

REM ****************************************
REM   Compile source files
REM ****************************************

FOR %%i IN (Temp\Source\CC*.bat) DO CALL %%i

REM ****************************************
REM   Link
REM ****************************************

CALL LIB.bat

REM ****************************************
REM   Delete working folders
REM ****************************************

IF "%OS%" == "Windows_NT" GOTO WinNT_1
DELTREE /Y Temp
GOTO READY
:WinNT_1
IF EXIST Temp RD Temp /S/Q
:READY

