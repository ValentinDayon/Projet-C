Gros Nounours 2D (C + raylib) — Squelette jouable

Prérequis (Windows) :
- Installer raylib (choisir UNE option) :
  - MSYS2 : `pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-raylib`
  - vcpkg : `vcpkg install raylib:x64-windows`
  - Précompilé : utiliser les binaires raylib Windows et configurer LIB/INCLUDE

Compilation (MSYS2 MinGW64 recommandé) :
1) Ouvrir "MSYS2 MinGW x64"
2) cd à la racine du projet
3) `make -f Makefile.mingw`
4) Lancer : `bin/GrosNounours.exe` (option `--log` disponible)

Compilation (vcpkg + MSVC cl) :
1) Vérifier `VCPKG_ROOT`
2) `cl /I%VCPKG_ROOT%\installed\x64-windows\include src\main.c /Fe:bin\GrosNounours.exe /link /LIBPATH:%VCPKG_ROOT%\installed\x64-windows\lib raylib.lib Winmm.lib gdi32.lib user32.lib shell32.lib ole32.lib advapi32.lib uuid.lib`

Contrôles :
- Déplacements: ← →
- Saut: Espace / A
- Interaction: E / Entrée (portails du hub)
- Pause: Échap

Remarques :
- Squelette 2D minimal: hub avec 4 zones (Jardin, Chambre, Grenier, Cuisine), mini‑jeu placeholder.
- À compléter: assets pixel‑art, audio chiptune, mini‑jeux pédagogiques.

Icône Windows (barre des tâches)
- Windows utilise l’icône embarquée dans l’EXE (ressource .ico), pas seulement l’icône de fenêtre.
- Étapes :
  1) Convertir votre PNG en `assets/icon.ico` (taille 16/32/48/256 incluses recommandé).
  2) `resources/icon.rc` pointe vers `assets/icon.ico` (VERSIONINFO inclus).
  3) `make -f Makefile.mingw` reconstruit et embarque l’icône.

Scripts Windows (un clic)
- `scripts\build_msys2.bat` : build via MSYS2/MinGW.
- `scripts\build_msvc.bat` : build via MSVC + vcpkg.
- `scripts\run_game.bat` : lance le jeu (construit si nécessaire).
- `scripts\package_zip.bat` : crée `GrosNounours_v1.0.zip` (bin/assets/config/docs).
