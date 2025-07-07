#ifndef CURSOR_H
#define CURSOR_H

#include "raylib.h"

typedef struct Cursor {
    Texture2D texture;
    Vector2 hotspot;
    int active;
} Cursor;

void LoadCursor(Cursor *cursor, const char *file_path, Vector2 hotspot) {
    cursor->texture = LoadTexture(file_path);
    cursor->hotspot = hotspot;
    cursor->active = 1;
    HideCursor();
}

void UpdateCursor(Cursor *cursor) {
    if (cursor->active) {
        Vector2 mouse = GetMousePosition();
        DrawTexture(cursor->texture, mouse.x - cursor->hotspot.x, mouse.y - cursor->hotspot.y, WHITE);
    }
}

void UnloadCursor(Cursor *cursor) {
    UnloadTexture(cursor->texture);
    ShowCursor();
}

#endif // CURSOR_H
