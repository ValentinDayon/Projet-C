@echo off
cd /d %~dp0\..
if not exist bin\GrosNounours.exe (
  echo Game executable not found. Building with MSYS2...
  call scripts\build_msys2.bat || exit /b 1
)
bin\GrosNounours.exe %*
