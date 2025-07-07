#include "raylib.h"
#include "raymath.h"
#include "headers/eyes_player.h"
#include "headers/cursor.h"

#define CURSOR_X 32
#define CURSOR_Y 32
#define P_X 25
#define P_Y 25

extern int input_key(unsigned char *keys);

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float gravity = 0.5f;
    const float jumpForce = -10.0f;

    InitWindow(screenWidth, screenHeight, "THE CUBE COOL GAME");
    InitAudioDevice();
    SetTargetFPS(60);

    Rectangle player = { 100, 300, P_X, P_Y };
    Rectangle floor = { 0, 400, screenWidth, 50 };

    Sound fxJump = LoadSound("assets/sounds/jump.wav");
    
    Cursor cursor;
    Vector2 hotspot = {CURSOR_X / 2, CURSOR_Y / 2}; 
    LoadCursor(&cursor, "assets/cursors/c1.png", hotspot);

    float velocityY = 0.0f;
    int isOnGround = 1;

    while (!WindowShouldClose()) {
        unsigned char keys[5];
        keys[0] = IsKeyDown(KEY_A);
        keys[1] = IsKeyDown(KEY_D);
        keys[2] = IsKeyDown(KEY_SPACE);
        keys[3] = IsKeyDown(KEY_LEFT);
        keys[4] = IsKeyDown(KEY_RIGHT);

        int key = input_key(keys);

        velocityY += gravity;
        player.y += velocityY;

        if (GetScreenWidth() != screenWidth || GetScreenHeight() != screenHeight) SetWindowSize(screenWidth, screenHeight);

        if (player.y + player.height >= floor.y) {
            player.y = floor.y - player.height;
            velocityY = 0;
            isOnGround = 0;
        } else {
            isOnGround = 1;
        }

        if (player.x < 0) player.x = 0;
        if (player.x + player.width > screenWidth) player.x = screenWidth - player.width;
        if (player.y < 0) {
            player.x = 0;
            velocityY = 0;
        }

        if (key == KEY_RIGHT || key == KEY_D) player.x += 4.0f;
        if (key == KEY_LEFT || key == KEY_A) player.x -= 4.0f;
        if (IsKeyDown(KEY_SPACE) && isOnGround == 0) {
            velocityY = jumpForce;
            PlaySound(fxJump);
        }

        BeginDrawing();
            ClearBackground(DARKGRAY);

            DrawText("THE CUBE COOL GAME!", 10, 10, 20, LIGHTGRAY);
            DrawRectangleRec(floor, GRAY);
            DrawRectangleRec(player, WHITE);
            DrawEyes(player, GetMousePosition());

            UpdateCursor(&cursor);
            
        EndDrawing();
    }

    UnloadSound(fxJump);
    UnloadCursor(&cursor);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
