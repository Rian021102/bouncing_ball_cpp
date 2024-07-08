#include <iostream>
#include <cmath> // use <cmath> instead of <math.h> in C++
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

int width = 80; 
int height = 80; // Canvas size
int ballX = 40; // Ellipse x-axis
int ballY = 40; // Ellipse y-axis
int forceX = 1; // Change the direction of ellipse
int forceY = 1;

int distance(int x1, int y1, int x2, int y2){ 
    int xDelta = x1 - x2;
    int yDelta = y1 - y2;
    return sqrt(xDelta * xDelta + yDelta * yDelta); // Calculate the half radius of the ellipse
}

void updatePhysics(){
    if(ballX >= width - 2 || ballX <= 0){ // Keep the ellipse inside the canvas
        forceX = -forceX; // Change the direction
    }
    if(ballY >= height - 1 || ballY <= 0){
        forceY = -forceY;
    }
    // Keep bouncing
    ballX += forceX;
    ballY += forceY;
}

void drawFrame(){
    for(int y = 0; y < height; y ++){
        for(int x = 0; x < width; x ++){
            if(distance(x, y * 2, ballX, ballY) < 4){
                cout << ' ';
            } else {
                cout << "x";
            }
        }
        cout << endl;
    }
}

int main(){
    while (true) {
        updatePhysics();
        drawFrame();
        // Adding a small delay for better visualization
        this_thread::sleep_for(chrono::milliseconds(100));
        // Clear the screen
        system("clear");
    }
    return 0;
}
