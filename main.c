#include "raylib.h"
#include "raymath.h"

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

    Sound fxJump = LoadSound("assets/sounds/jump.wav");

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

            Vector2 mousePos = GetMousePosition();

            float eyeWidth = 12.0f;
            float eyeHeight = 10.0f;
            float pupilWidth = 5.0f;
            float pupilHeight = 5.0f;
            float maxOffset = 3.0f;

            Vector2 leftEyeCenter = { player.x + 10, player.y + 12 };
            Vector2 rightEyeCenter = { player.x + 30, player.y + 12 };

            Vector2 leftDir = Vector2Subtract(mousePos, leftEyeCenter);
            Vector2 rightDir = Vector2Subtract(mousePos, rightEyeCenter);

            leftDir = Vector2Normalize(leftDir);
            rightDir = Vector2Normalize(rightDir);

            Vector2 leftPupil = {
                leftEyeCenter.x + leftDir.x * maxOffset,
                leftEyeCenter.y + leftDir.y * maxOffset
            };

            Vector2 rightPupil = {
                rightEyeCenter.x + rightDir.x * maxOffset,
                rightEyeCenter.y + rightDir.y * maxOffset
            };

            DrawRectangleRec((Rectangle){
                leftEyeCenter.x - eyeWidth / 2,
                leftEyeCenter.y - eyeHeight / 2,
                eyeWidth, eyeHeight
            }, BLACK);

            DrawRectangleRec((Rectangle){
                rightEyeCenter.x - eyeWidth / 2,
                rightEyeCenter.y - eyeHeight / 2,
                eyeWidth, eyeHeight
            }, BLACK);

            DrawRectangleRec((Rectangle){
                leftPupil.x - pupilWidth / 2,
                leftPupil.y - pupilHeight / 2,
                pupilWidth, pupilHeight
            }, RAYWHITE);

            DrawRectangleRec((Rectangle){
                rightPupil.x - pupilWidth / 2,
                rightPupil.y - pupilHeight / 2,
                pupilWidth, pupilHeight
            }, RAYWHITE);
        EndDrawing();
    }

    UnloadSound(fxJump);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
