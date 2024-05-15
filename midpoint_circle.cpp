#include <iostream>
#include <graphics.h>

using namespace std;

// Function to draw a circle using Mid-Point Circle Drawing Algorithm
void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int decision = 1 - radius;

    // Initialize the graphics mode
    initwindow(1000, 1000);

    // Plot the first point
    putpixel(xc + x, yc - y, WHITE);

    // Plot the other points using symmetry
    while (y >= x) {
        x++;

        if (decision > 0) {
            y--;
            decision += 2 * (x - y) + 1;
        } else {
            decision += 2 * x + 1;
        }

        // Plot the points using eight-way symmetry
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
    }

    // Wait for user input before closing the window
    getch();
    closegraph();
}

int main() {
    int xc, yc, radius;

    cout << "Enter the coordinates of the center (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Call the drawCircle function
    drawCircle(xc, yc, radius);



    return 0;
}
