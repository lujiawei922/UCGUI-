@ECHO OFF

REM ******************************************************************************
REM
REM   This file needs to be changed.
REM
REM ******************************************************************************

CL /nologo /G5 /W3 /Ox /Oa /Ow /Og /Oi /Os /Op /Ob2 /Gy /c /FoTemp\Output\ /D WIN32 /D _WINDOWS Temp\Source\%1.c
IF ERRORLEVEL 1 PAUSE
ECHO Temp\Output\%1.OBJ>>Temp\Output\OBJ.DAT

