#include <iostream>
#include "raylib.h"

using namespace std;

int main() {
    int width{800};
    int height{800};

    int circle_x{400};
    int circle_y{400};
    int circleRadius{25};

    int axe_x{300};
    int axe_y{0};
    int axeLength{50};
    int axeXDirection{8};
    int axeYDirection{10};

    InitWindow(width,height,"Axe Game");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(circle_x,circle_y,circleRadius,BLUE);
        DrawRectangle(axe_x,axe_y,axeLength,axeLength,RED);

        axe_x += axeXDirection;
        if(axe_x >= 750 || axe_x <= 0) {
            axeXDirection = -axeXDirection;
        }

        axe_y += axeYDirection;
        if(axe_y >= 750 || axe_y <= 0) {
            axeYDirection = -axeYDirection;
        }

        if(IsKeyDown(KEY_D) && circle_x <= 765) {
            circle_x += 10;
        }

        if(IsKeyDown(KEY_A) && circle_x >= 35) {
            circle_x -= 10;
        }

        if(IsKeyDown(KEY_S) && circle_y <= 765) {
            circle_y += 10;
        }

        if(IsKeyDown(KEY_W) && circle_y >= 35) {
            circle_y -= 10;
        }
        

        EndDrawing();
    }

    return 0;
}