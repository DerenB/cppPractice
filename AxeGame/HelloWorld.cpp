#include <iostream>
#include "raylib.h"

using namespace std;

int main() {
    // Window Dimentions
    int width{800};
    int height{800};

    // Circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circleRadius{25};
    int circleVelocity{10};

    // Circle Edges
    int L_Circle_x{circle_x - circleRadius}; // 375
    int R_Circle_x{circle_x + circleRadius}; // 425
    int U_Circle_y{circle_y - circleRadius}; // 375
    int B_Circle_y{circle_y + circleRadius}; // 425

    // Axe Coordinates
    int axe_x{400};
    int axe_y{400};
    int axeLength{50};
    int axeXDirection{8};
    int axeYDirection{10};

    // Axe Edges
    int L_Axe_x{axe_x};             // 0
    int R_Axe_x{axe_x + axeLength}; // 50
    int U_Axe_y{axe_y};             // 0
    int B_Axe_y{axe_y + axeLength}; // 50

    // Initializes the window
    InitWindow(width,height,"Axe Game");

    bool collisionWithAxe = 
        (B_Axe_y >= U_Circle_y) && 
        (U_Axe_y <= B_Circle_y) && 
        (R_Axe_x >= L_Circle_x) && 
        (L_Axe_x <= R_Circle_x);

    // Sets the target FPS
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if(collisionWithAxe) {
            DrawText("Game Over!",300,200,60,RED);
        } else {
            // Update the Circle edges
            L_Circle_x = circle_x - circleRadius;
            R_Circle_x = circle_x + circleRadius;
            U_Circle_y = circle_y - circleRadius;
            B_Circle_y = circle_y + circleRadius;

            // Update the Axe edges
            L_Axe_x = axe_x;
            R_Axe_x = axe_x + axeLength;
            U_Axe_y = axe_y;
            B_Axe_y = axe_y + axeLength;

            // Update the collision with Axe
            collisionWithAxe = 
                (B_Axe_y >= U_Circle_y) && 
                (U_Axe_y <= B_Circle_y) && 
                (R_Axe_x >= L_Circle_x) && 
                (L_Axe_x <= R_Circle_x);

            // Draw the shapes
            DrawCircle(circle_x,circle_y,circleRadius,BLUE);
            DrawRectangle(axe_x,axe_y,axeLength,axeLength,RED);

            axe_x += axeXDirection;
            if(axe_x >= (width - axeLength) || axe_x <= 0) {
                axeXDirection = -axeXDirection;
            }

            axe_y += axeYDirection;
            if(axe_y >= (width - axeLength) || axe_y <= 0) {
                axeYDirection = -axeYDirection;
            }

            if(IsKeyDown(KEY_D) && circle_x <= (width - circleRadius - circleVelocity)) {
                circle_x += circleVelocity;
            }

            if(IsKeyDown(KEY_A) && circle_x >= (circleRadius + circleVelocity)) {
                circle_x -= circleVelocity;
            }

            if(IsKeyDown(KEY_S) && circle_y <= (width - circleRadius - circleVelocity)) {
                circle_y += circleVelocity;
            }

            if(IsKeyDown(KEY_W) && circle_y >= (circleRadius + circleVelocity)) {
                circle_y -= circleVelocity;
            }
        }

        
        

        EndDrawing();
    }

    return 0;
}