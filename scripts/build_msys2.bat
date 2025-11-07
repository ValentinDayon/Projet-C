@echo off
setlocal

REM Root of project
set PROJ_ROOT=%~dp0..
cd /d %PROJ_ROOT%
if not exist bin mkdir bin

REM Stop running instance if any (ignore errors)
taskkill /IM GrosNounours.exe /F >nul 2>nul

REM Default MSYS2 root if not provided
if "%MSYS2_ROOT%"=="" set MSYS2_ROOT=C:\msys64
set BASH_EXE=%MSYS2_ROOT%\usr\bin\bash.exe

if not exist "%BASH_EXE%" (
  echo MSYS2 not found at %MSYS2_ROOT%. Please install MSYS2 or set MSYS2_ROOT.
  pause
  exit /b 1
)

echo Using MSYS2: %BASH_EXE%

REM Ensure MinGW64 toolchain is on PATH inside bash and try to auto-install if gcc missing
"%BASH_EXE%" -lc "source /etc/profile; export PATH=/mingw64/bin:$PATH; which gcc || pacman -Sy --noconfirm --needed mingw-w64-x86_64-gcc >/dev/null 2>&1; which gcc; which windres || pacman -Sy --noconfirm --needed mingw-w64-x86_64-binutils >/dev/null 2>&1; which windres; which make || pacman -Sy --noconfirm --needed make >/dev/null 2>&1; make --version" || goto :fail

"%BASH_EXE%" -lc "source /etc/profile; export PATH=/mingw64/bin:$PATH; cd \"%PROJ_ROOT:\\=/%\" && make -f Makefile.mingw" || goto :fail

echo Build OK: bin\GrosNounours.exe
exit /b 0

:fail
echo.
echo Build failed. Assure-toi que MSYS2 est installe et que le toolchain MinGW64 (gcc, windres) est present.
pause
exit /b 1
