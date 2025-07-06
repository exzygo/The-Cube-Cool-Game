#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float gravity = 0.5f;
    const float jumpForce = -10.0f;

    InitWindow(screenWidth, screenHeight, "THE CUBE COOL GAME");
    InitAudioDevice();
    SetTargetFPS(60);

    Rectangle player = { 100, 300, 40, 40 };
    Rectangle floor = { 0, 400, screenWidth, 50 };

    Sound fxJump = LoadSound("assets/jump.wav");

    float velocityY = 0.0f;
    int isOnGround = 1;

    while (!WindowShouldClose()) {
        velocityY += gravity;
        player.y += velocityY;

        if (GetScreenWidth() != 800 || GetScreenHeight() != 450) SetWindowSize(800, 450);

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

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.x += 4.0f;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) player.x -= 4.0f;
        if (IsKeyPressed(KEY_SPACE) && isOnGround == 0) {
            velocityY = jumpForce;
            PlaySound(fxJump);
        }

        BeginDrawing();
            ClearBackground(DARKGRAY);

            DrawText("THE CUBE COOL GAME!", 10, 10, 20, LIGHTGRAY);
            DrawRectangleRec(floor, GRAY);
            DrawRectangleRec(player, WHITE);
        EndDrawing();
    }

    UnloadSound(fxJump);

    CloseAudioDevice();

    CloseWindow();
    return 0;
}
