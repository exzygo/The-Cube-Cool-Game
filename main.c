#include "raylib.h"
#include "eyes_player.h"
#include "cursor.h"

#define SPEED 4.0f
#define CURSOR_X 32
#define CURSOR_Y 32
#define P_X 25
#define P_Y 25

// ASM extern input key parameter for hierarchy
extern int input_key(unsigned char *keys);

int main(void) {
    const int screen_width = 800;
    const int screen_height = 450;
    const float gravity = 0.5f;
    const float jump_force = -10.0f;

    InitWindow(screen_width, screen_height, "THE CUBE COOL GAME");
    InitAudioDevice();
    SetTargetFPS(60);

    Rectangle player = { 100, 300, P_X, P_Y };
    Rectangle floor = { 0, 400, screen_width, 50 };

    Sound fx_jump = LoadSound("assets/sounds/jump.wav");

    Cursor cursor;
    Vector2 hotspot = { (float)CURSOR_X / 2, (float)CURSOR_Y / 2 }; 
    LoadCursor(&cursor, "assets/cursors/c1.png", hotspot);

    float velocity_y = 0.0f;
    int is_on_ground = 1;

    while (!WindowShouldClose()) {
        unsigned char keys[5];
        keys[0] = IsKeyDown(KEY_A);
        keys[1] = IsKeyDown(KEY_D);
        keys[2] = IsKeyDown(KEY_SPACE);
        keys[3] = IsKeyDown(KEY_LEFT);
        keys[4] = IsKeyDown(KEY_RIGHT);

        int key = input_key(keys);

        velocity_y += gravity;
        player.y += velocity_y;

        if (GetScreenWidth() != screen_width || GetScreenHeight() != screen_height) 
            SetWindowSize(screen_width, screen_height);

        if (player.y + player.height >= floor.y) {
            player.y = floor.y - player.height;
            velocity_y = 0;
            is_on_ground = 0;
        } else {
            is_on_ground = 1;
        }

        (player.x < 0) ? player.x = 0 : 0;
        (player.x + player.width > screen_width) ? player.x = screen_width - player.width : 0;
        if (player.y < 0) {
            player.x = 0;
            velocity_y = 0;
        }

        player.x += (key == KEY_RIGHT || key == KEY_D) ? SPEED : 0;
        player.x -= (key == KEY_LEFT || key == KEY_A) ? SPEED : 0;
        if (IsKeyDown(KEY_SPACE) && is_on_ground == 0) {
            velocity_y = jump_force;
            PlaySound(fx_jump);
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

    UnloadSound(fx_jump);
    UnloadCursor(&cursor);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
