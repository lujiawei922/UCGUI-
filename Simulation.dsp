# Microsoft Developer Studio Project File - Name="SimulationShip" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SimulationShip - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Simulation.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Simulation.mak" CFG="SimulationShip - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SimulationShip - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "SimulationShip - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SimulationShip - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /G5 /ML /W3 /Gm /GX /ZI /Od /I "Config" /I "GUI\Core" /I "GUI\Widget" /I "GUI\WM" /I "Simulation" /D "LCD_USE_WINSIM" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Simulation\GUISim.lib Simulation\Simulation.res winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"libcmt.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "SimulationShip - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G5 /MT /W3 /GX /O1 /I "Config" /I "GUI\Core" /I "GUI\Widget" /I "GUI\WM" /I "Simulation" /D "LCD_USE_WINSIM" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 libcmt.lib libc.lib Simulation\GUISim.lib Simulation\Simulation.res winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /pdb:none /map /machine:I386 /out:"Exe/GUISimulation.exe"
# SUBTRACT LINK32 /debug /nodefaultlib

!ENDIF 

# Begin Target

# Name "SimulationShip - Win32 Debug"
# Name "SimulationShip - Win32 Release"
# Begin Group "Application"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Application\main.c
# End Source File
# Begin Source File

SOURCE=.\Application\MicriumLogo.C
# End Source File
# Begin Source File

SOURCE=.\Application\MicriumLogo_1bpp.c
# End Source File
# End Group
# Begin Group "Config"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=.\Config\GUICONF.H
# End Source File
# Begin Source File

SOURCE=.\Config\GUITouchConf.h
# End Source File
# Begin Source File

SOURCE=.\Config\LCDConf.H
# End Source File
# End Group
# Begin Group "GUI"

# PROP Default_Filter "*.*"
# Begin Group "ConvertColor"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP111.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP222.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP233.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP323.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP332.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP444.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP555.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP565.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDP8666.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDPM233.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDPM323.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDPM332.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDPM555.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertColor\LCDPM565.c
# End Source File
# End Group
# Begin Group "ConvertMono"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gui\ConvertMono\LCDP0.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertMono\LCDP1.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertMono\LCDP2.c
# End Source File
# Begin Source File

SOURCE=.\gui\ConvertMono\LCDP4.c
# End Source File
# End Group
# Begin Group "Core"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Gui\Core\GUI.H
# End Source File
# Begin Source File

SOURCE=.\gui\Core\gui2dlib.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI__AddSpaceHex.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI__DivideRound.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI__IntersectRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI__IntersectRects.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI__ReduceRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_AddBin.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_AddDec.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_AddHex.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_Color2VisColor.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DispBin.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DispHex.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DispStringInRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawBitmap.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawBitmapExp.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawBitmapMag.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawFocusRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawGraph.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawHLine.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawPie.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawPixel.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawPolyline.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawRectEx.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_DrawVLine.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_ErrorOut.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_Exec.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_FillPolygon.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_FillRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_FillRectEx.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_GetClientRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_GetColor.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_GetFontInfo.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_GetTextExtend.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_GetVersionString.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_InitLUT.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_InvertRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_Log.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_MergeRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_MOUSE.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_MouseArrow.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_MouseNoDrop.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_MoveRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_OnKey.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_Pen.c
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\GUI_Private.h
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\GUI_Protected.h
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_RectsIntersect.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SaveContext.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SelLCD.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SetColorIndex.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SetDecChar.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SetDefault.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SetLUTEntry.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SetOrg.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_SetPhysColor.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_StreamBMP.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_TOUCH.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_WaitKey.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUI_Warn.c
# End Source File
# Begin Source File

SOURCE=.\gui\core\GUI_X.h
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIAlloc.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\guiarc.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIChar.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIChar0.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUICharM.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUICharP.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUICirc.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIColor2Index.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUICore.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUICurs.c
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\guidebug.h
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIEncJS.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIIndex2Color.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIPolyE.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIPolyM.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIPolyR.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIStream.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\guitask.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUITime.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\guitimer.c
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\GUITYPE.H
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIUC0.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIUC1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIVal.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\GUIValf.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCD.c
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\LCD.H
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\LCD_ConfDefaults.h
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCD_GetColorIndex.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCD_GetNumDisplays.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCD_GetPixelColor.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCD_L0_Generic.c
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\LCD_Private.h
# End Source File
# Begin Source File

SOURCE=.\Gui\Core\LCD_Protected.h
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDAA.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDColor.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDGetP.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDInfo.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDInfo0.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDInfo1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDL0Mag.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDRLE4.c
# End Source File
# Begin Source File

SOURCE=.\gui\Core\LCDRLE8.c
# End Source File
# End Group
# Begin Group "Font"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gui\Font\F08_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F08_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F10_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F10_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F10S_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F10S_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13B_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13B_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13H_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13H_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13HB_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F13HB_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F16_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F16_1HK.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F16_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F16_HK.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F16B_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F16B_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F24_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F24_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F24B_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F24B_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F32_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F32_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F32B_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F32B_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F4x6.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F6x8.C
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x10_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x12_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x13.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x13_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x13_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x15B.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x15B_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x15B_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x16.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\F8x8.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\FComic18B_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\FComic18B_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\FComic24B_1.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\FComic24B_ASCII.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\FD24x32.c
# End Source File
# Begin Source File

SOURCE=.\gui\Font\FD32.c
# End Source File
# End Group
# Begin Group "LCDDriver"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Gui\LCDDriver\LCDWin.c
# End Source File
# End Group
# Begin Group "MemDev"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_AA.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_Auto.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_Banding.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_Clear.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_CmpWithLCD.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_CopyFromLCD.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_GetYSize.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_Measure.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_ReduceYSize.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_SetOrg.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_Usage.c
# End Source File
# Begin Source File

SOURCE=.\gui\MemDev\GUIDEV_UsageBM.c
# End Source File
# End Group
# Begin Group "Widget"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gui\Widget\button.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\button.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Checkbox.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Checkbox.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Dialog.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Dialog.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Dialog_Intern.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\edit.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Edit.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Edit_Private.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\EditBin.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\EditDec.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\EditFloat.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\EditHex.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\framewin.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\FrameWin.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\GUI_EditBin.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\GUI_EditDec.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\GUI_EditFloat.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\GUI_EditHex.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\GUI_EditString.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\listbox.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\LISTBOX.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\marquee.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Marquee.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\messagebox.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\progbar.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\ProgBar.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Radio.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Radio.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Scrollbar.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Scrollbar.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Slider.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Slider.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Terminal.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Terminal.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Text.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Text.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Widget.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Widget.h
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Widget_3D.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Widget_None.c
# End Source File
# Begin Source File

SOURCE=.\gui\Widget\Widget_Simple.c
# End Source File
# End Group
# Begin Group "WM"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\gui\WM\wm.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM.H
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM__GetFirstSibling.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM__GetHasFocus.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM__GetLastSibling.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM__GetPrevSibling.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM__Screen2Client.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM__SendMessage.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM__SendMessageNoPara.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_BringToBottom.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_BringToTop.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_Broadcast.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_EnableWindow.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetBkColor.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetClientRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetClientWindow.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetDialogItem.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetFirstChild.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetFocussedChild.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetId.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetInsideRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetNextSibling.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetOrg.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetParent.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetScrollState.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetWindowRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_GetWindowSize.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_HasCaptured.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_Hide.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_Intern.h
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_IsWindow.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_Move.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_NotifyParent.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_OnKey.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_Paint.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_ResizeWindow.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_Screen2Win.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SendToParent.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetCallback.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetCapture.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetCreateFlags.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetDesktopColor.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetFocus.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetFocusOnNextChild.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetScrollState.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetSize.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetTrans.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_SetUserClipRect.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_Validate.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WM_ValidateWindow.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WMMemDev.c
# End Source File
# Begin Source File

SOURCE=.\gui\WM\WMTouch.c
# End Source File
# End Group
# End Group
# Begin Group "Simulation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Simulation\SIM_X.c
# End Source File
# End Group
# End Target
# End Project
