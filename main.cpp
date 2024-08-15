#include <raylib.h>

int main(){
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    while(WindowShouldClose() == false){
        BeginDrawing();

        DrawCircle(screenWidth / 2, screenHeight / 2, 20, WHITE);
        DrawRectangle(0, 0, 25, 120, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}