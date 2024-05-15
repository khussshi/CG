#include <iostream>
#include <graphics.h>

using namespace std;

// Function to draw a line using Bresenham's algorithm
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slope_sign = ((x2 - x1) * (y2 - y1) > 0) ? 1 : -1;

    // If the slope is greater than 1, swap the x and y coordinates
    bool steep = abs(dy) > abs(dx);
    if (steep) {
        swap(x1, y1);
        swap(x2, y2);
    }

    // Swap the points if x2 < x1
    if (x2 < x1) {
        swap(x1, x2);
        swap(y1, y2);
    }

    // Recalculate dx and dy after swapping
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    // Calculate the decision parameter
    int decision = 2 * dy - dx;
    int increment_y = 2 * dy;
    int increment_y_x = 2 * (dy - dx);

    // Start from the first point
    int x = x1, y = y1;

    // Draw the first point
    if (steep) {
        putpixel(y, x, WHITE);
    } else {
        putpixel(x, y, WHITE);
    }

    // Draw the line
    while (x < x2) {
        if (decision <= 0) {
            decision += increment_y;
        } else {
            decision += increment_y_x;
            y += slope_sign;
        }

        x++;

        // Plot the point
        if (steep) {
            putpixel(y, x, WHITE);
        } else {
            putpixel(x, y, WHITE);
        }
    }
}

int main() {
    int x1, y1, x2, y2;

    cout << "Enter the coordinates of the starting point (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the ending point (x2, y2): ";
    cin >> x2 >> y2;

    // Initialize the graphics mode
    initwindow(800, 600);

    // Call the drawLine function
    drawLine(x1, y1, x2, y2);

    // Wait for user input before closing the window
    getch();
    closegraph();

    return 0;
}
