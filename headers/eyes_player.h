#ifndef EYES_PLAYER_H
#define EYES_PLAYER_H

#include "raylib.h"
#include "raymath.h"

static inline void DrawEyes(Rectangle player, Vector2 mousePos) {
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

    DrawRectangleRec((Rectangle) {
        leftEyeCenter.x - eyeWidth / 2,
        leftEyeCenter.y - eyeHeight / 2,
        eyeWidth, eyeHeight
    }, BLACK);

    DrawRectangleRec((Rectangle) {
        rightEyeCenter.x - eyeWidth / 2,
        rightEyeCenter.y - eyeHeight / 2,
        eyeWidth, eyeHeight
    }, BLACK);

    DrawRectangleRec((Rectangle) {
        leftPupil.x - pupilWidth / 2,
        leftPupil.y - pupilHeight / 2,
        pupilWidth, pupilHeight
    }, RAYWHITE);

    DrawRectangleRec((Rectangle) {
        rightPupil.x - pupilWidth / 2,
        rightPupil.y - pupilHeight / 2,
        pupilWidth, pupilHeight
    }, RAYWHITE);
}

#endif // EYES_PLAYER_H
