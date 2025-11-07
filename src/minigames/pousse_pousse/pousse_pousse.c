// Pousse-Pousse 10x10 (Sokoban léger)
#include "pousse_pousse.h"

typedef enum { T_EMPTY=0, T_WALL, T_BOX, T_TARGET, T_BOX_ON_TARGET } Tile;

static int gridW = 10, gridH = 10;
static Tile grid[10][10];
static int playerX, playerY;
static bool levelWon;

static void loadLevel(void) {
    // Niveau simple 10x10
    int map[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,0,0,0,1,0,1},
        {1,0,0,1,0,3,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,1,0,0,4,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1},
    };
    for (int y=0;y<gridH;y++) for (int x=0;x<gridW;x++) {
        int v = map[y][x];
        grid[y][x] = (v==1)?T_WALL:(v==3?T_BOX:(v==4?T_TARGET:T_EMPTY));
    }
    playerX = 2; playerY = 2;
    levelWon = false;
}

static bool isBlocked(int x, int y) {
    if (x<0||y<0||x>=gridW||y>=gridH) return true;
    Tile t = grid[y][x];
    return t==T_WALL;
}

static bool isFree(int x, int y) {
    if (x<0||y<0||x>=gridW||y>=gridH) return false;
    Tile t = grid[y][x];
    return t==T_EMPTY || t==T_TARGET;
}

static void tryMove(int dx, int dy) {
    if (levelWon) return;
    int nx = playerX + dx;
    int ny = playerY + dy;
    if (isBlocked(nx, ny)) return;
    // Box push
    if (grid[ny][nx]==T_BOX || grid[ny][nx]==T_BOX_ON_TARGET) {
        int bx = nx + dx, by = ny + dy;
        if (!isFree(bx, by)) return; // cannot push
        // Move box
        bool intoTarget = (grid[by][bx]==T_TARGET);
        grid[by][bx] = intoTarget ? T_BOX_ON_TARGET : T_BOX;
        // Clear old box tile (if was on target, leave target)
        grid[ny][nx] = (grid[ny][nx]==T_BOX_ON_TARGET) ? T_TARGET : T_EMPTY;
    }
    // Move player
    playerX = nx; playerY = ny;
    // Win check: any BOX left not on target?
    bool anyBoxOff = false;
    for (int y=0;y<gridH;y++) for (int x=0;x<gridW;x++) if (grid[y][x]==T_BOX) anyBoxOff = true;
    if (!anyBoxOff) levelWon = true;
}

static void mg_init(void) { loadLevel(); }

static void mg_update(float dt) {
    (void)dt;
    if (IsKeyPressed(KEY_LEFT)) tryMove(-1,0);
    if (IsKeyPressed(KEY_RIGHT)) tryMove(1,0);
    if (IsKeyPressed(KEY_UP)) tryMove(0,-1);
    if (IsKeyPressed(KEY_DOWN)) tryMove(0,1);
    if (IsKeyPressed(KEY_R)) loadLevel();
}

static void drawCell(int x, int y, Tile t) {
    int marginTop = 120;
    int cell = 48; // 10x10 fits 480px
    int px = 100 + x*cell;
    int py = marginTop + y*cell;
    Color base = (t==T_WALL)?(Color){70,70,90,255}:(t==T_TARGET? (Color){90,140,90,255}: (Color){40,40,50,255});
    DrawRectangle(px, py, cell-2, cell-2, base);
    if (t==T_BOX || t==T_BOX_ON_TARGET) DrawRectangle(px+8, py+8, cell-18, cell-18, (Color){200,160,80,255});
}

static void mg_draw(void) {
    DrawText("Pousse-Pousse 10x10 — Flèches pour bouger, R pour reset, Backspace retour", 20, 20, 18, LIGHTGRAY);
    for (int y=0;y<gridH;y++) for (int x=0;x<gridW;x++) drawCell(x,y,grid[y][x]);
    int cell = 48; int px = 100 + playerX*cell; int py = 120 + playerY*cell;
    DrawCircle(px + cell/2, py + cell/2, 14, (Color){240,200,120,255});
    if (levelWon) DrawText("Bravo! Niveau réussi.", 100, 640, 28, (Color){255,230,120,255});
}

static void mg_unload(void) {}

MinigameAPI GetMinigamePoussePousse(void) {
    MinigameAPI api = { mg_init, mg_update, mg_draw, mg_unload };
    return api;
}


