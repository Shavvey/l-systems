#include "../include/raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

#define WINDOW_TITLE "l-systems"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  Texture2D texture = LoadTexture(ASSETS_PATH "test.png");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
    const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
    // draw the background of the window
    DrawTexture(texture, texture_x, texture_y, WHITE);

    const char *text = "BOTTOM TEXT";
    const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
    DrawText(text, (int) SCREEN_WIDTH / 2 -  (int) text_size.x / 2,
             texture_y + texture.height + text_size.y + 10, 20, BLACK);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
