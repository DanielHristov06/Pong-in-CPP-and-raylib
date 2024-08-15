#include <raylib.h>
#include <raymath.h>

class Ball{
    public:
        float x, y;
        int speedX, speedY;
        int radius;

        void Draw(){
            DrawCircle(x, y, radius, WHITE);
        }

        void Update(){
            x += speedX;
            y += speedY;

            if (y + radius >= GetScreenHeight() || y - radius <= 0){
                speedY *= -1;
            }
            if (x + radius >= GetScreenWidth() || x - radius <= 0){
                speedX *= -1;
            }
        }
};

class Paddle{
    protected:
        void ClampMovement(){
            y = Clamp(y, 0, GetScreenHeight() - h);
        }

    public:
        float x, y;
        float w, h;
        int speed;

        void Draw(){
            DrawRectangle(x, y, w, h, WHITE);
        }

        void Update(){
            if (IsKeyDown(KEY_W)){
                y = y - speed;
            }
            if (IsKeyDown(KEY_S)){
                y = y + speed;
            }

            ClampMovement();
        }
};

class CpuPaddle: public Paddle{
    public:
        void Update(float ballY){
            if (y + h / 2 > ballY){
                y = y - speed;
            }
            if (y + h / 2 <= ballY){
                y = y + speed;
            }

            ClampMovement();
        }
};

Ball ball;
Paddle player;
CpuPaddle bot;

int main(){
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    // Object variables
    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speedX = 7;
    ball.speedY = 7;

    player.w = 25;
    player.h = 120;
    player.x = 20;
    player.y = screenHeight / 2 - player.h / 2;
    player.speed = 6;

    bot.w = 25;
    bot.h = 120;
    bot.x = screenWidth - 20 - bot.w;
    bot.y = screenHeight / 2 - bot.h / 2;
    bot.speed = 6;

    while(WindowShouldClose() == false){
        BeginDrawing();

        // Updating
        player.Update();
        ball.Update();
        bot.Update(ball.y);

        //Drawing
        ClearBackground(BLACK);
        ball.Draw();
        player.Draw();
        bot.Draw();
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}