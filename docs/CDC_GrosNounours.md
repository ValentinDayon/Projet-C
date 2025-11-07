# Cahier des charges — Gros Nounours 2D (style rétro Adibou)

## 1. Contexte & objectif
Jeu éducatif 2D en C (C11/C17), univers bienveillant inspiré d’Adibou, mettant en scène Gros Nounours. Mélange d’exploration et de mini‑jeux pédagogiques simples, accessibles à un jeune public.
- Plateforme: Windows 10/11 (x64)
- Livraison: ZIP → extraction → EXE jouable immédiatement (standalone)

## 2. Vision & pitch
« Accompagne Gros Nounours dans un monde joyeux et éducatif : explore différents lieux, découvre des mini‑jeux amusants, apprends en t’amusant et partage un moment de douceur dans un univers inspiré d’Adibou. »

## 3. Structure générale
Hub principal composé de zones 2D reliées (Jardin, Chambre, Grenier, Cuisine). Chaque zone inclut interactions, collectibles et accès à un mini‑jeu.
- Mini‑jeux prévus:
  1) Pousse‑Pousse (logique/réflexes, pousser des blocs jusqu’à l’objectif)
  2) Création du gâteau (choix ingrédients/étapes, formes/couleurs/ordre)
  3) Traffic Racer Nounours (adresse/coordination, route d’obstacles mignons)
  4) Mini‑jeu T.B.D. (musique/puzzle/mémoire) pour compléter la variété éducative

## 4. Mécaniques générales
- Déplacements: gauche/droite/saut, interaction (E/Entrée)
- Collectibles: étoiles/boutons/jouets pour débloquer zones ou bonus
- Obstacles « doux »: flaques, jouets roulants, bulles (ralentissement, perte légère)
- Interface: HUD simple (étoiles, zone, vie), menus lisibles

## 5. Direction artistique (rétro « Adibou »)
- Pixel‑art doux: couleurs pastel, formes rondes, esthétique 1990s
- Animations simples: marche, saut, interaction, émotions de Nounours
- Univers positif et apaisant, zéro violence/peur

## 6. Audio
- Musiques chiptune/lo‑fi légères, une par mini‑jeu + hub
- Effets: clics, bulles, jouets, cuisine, petit moteur pour mini‑jeu voiture
- Volume réglable (global et éventuellement musique/effets)

## 7. Contraintes techniques
- Langage: C pur (C11/C17)
- Libs: raylib (recommandé) ou SDL2 (avec image/mixer/ttf si besoin)
- 60 FPS stables en 1080p
- Standalone: toutes DLL/fichiers inclus dans le ZIP
- Entrées: clavier obligatoire, manette PS4 Bluetooth optionnelle

## 8. Contrôles
- Déplacements: ← →
- Saut: Espace / A
- Interaction: E / Entrée
- Pause: Échap
- Mini‑jeux: contrôles contextuels affichés à l’écran

## 9. Performances & ressources
- 60 FPS constants
- Chargement < 2 s entre écrans
- Mémoire < 300 Mo
- ZIP < 200 Mo

## 10. Packaging & livraison
- Fichier: `GrosNounours_vX.Y.zip`
- Contenu:
  - `/bin/GrosNounours.exe` (+ DLL nécessaires)
  - `/assets/` (sprites, sons, polices)
  - `/config/` (paramètres par défaut)
  - `/docs/` (README, manuel court, crédits/licences)
  - `/src/` (code C) + Makefile/guide build
- Lancement: dézipper → double‑cliquer `GrosNounours.exe`

## 11. Critères d’acceptation
- Démarrage: exécutable sans installation ni erreurs
- UI/UX: menus clairs, navigation fluide; HUD lisible (≥ recommandations de contraste)
- Contenu: 3–4 mini‑jeux accessibles via le hub
- Perf: 60 FPS stables sur machine standard
- Audio/DA: cohérentes, agréables, volumes réglables
- Contrôles: réactifs, adaptés à l’âge cible
- Packaging: complet, < 200 Mo, jouable immédiatement

## 12. Planning (indicatif)
- S1: moteur principal (fenêtre, rendu), hub, déplacements, intégration raylib/SDL2
- S2: mini‑jeux 1 (Pousse‑Pousse) et 2 (Gâteau)
- S3: mini‑jeu 3 (Traffic Racer Nounours) + concept 4ᵉ mini‑jeu
- S4: polish, audio, interface, QA, packaging final

## 13. Risques & mitigations
- Volume d’art: palettes limitées, réutilisation de tuiles/sprites, scope contrôlé
- Cohérence DA: charte graphique commune dès le début, gabarits UI
- Manette PS4: support optionnel, clavier prioritaire
- Multi mini‑jeux: livrer 2 finis + 1 jouable avant d’ajouter le 4ᵉ

## 14. Documentation livrée
- `README.md` (build & run), manuel utilisateur (contrôles, mini‑jeux)
- Changelog, crédits, licences (libs + assets)

## 15. Notes techniques (implémentation ciblée)
- Moteur: raylib (fenêtre, rendu 2D, audio, inputs)
- Structure: état de jeu (hub, zones, mini‑jeux, menus), chargeur d’assets
- Sauvegarde simple: `config.ini/json` (volume, plein écran, progression basique)
- Journalisation: `--log` activant `log.txt` (Info/Warning/Error)
- Tests: stabilité 15 min, absence de fuites majeures (valgrind équivalent sous MinGW si possible)
