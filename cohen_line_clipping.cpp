#include <iostream>
#include <graphics.h>

using namespace std;

// Define region codes for each region
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define the clipping window coordinates
const int X_MIN = 100;
const int Y_MIN = 100;
const int X_MAX = 400;
const int Y_MAX = 400;

// Get the region code for a point
int getRegionCode(int x, int y) {
    int code = INSIDE;

    if (x < X_MIN)       // to the left of rectangle
        code |= LEFT;
    else if (x > X_MAX)  // to the right of rectangle
        code |= RIGHT;
    if (y < Y_MIN)       // below the rectangle
        code |= BOTTOM;
    else if (y > Y_MAX)  // above the rectangle
        code |= TOP;

    return code;
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = getRegionCode(x1, y1);
    int code2 = getRegionCode(x2, y2);
    bool accept = false;

    while (true) {
        // If both endpoints are inside the rectangle
        if (code1 == 0 && code2 == 0) {
            accept = true;
            break;
        } else if (code1 & code2) {
            // If both endpoints are outside same side of rectangle
            break;
        } else {
            // Calculate intersection point
            int x, y;

            // Select endpoint to clip
            int code_outside = (code1 != 0) ? code1 : code2;

            // Clip the line from outside to inside
            if (code_outside & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (code_outside & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (code_outside & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (code_outside & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Update the endpoint outside the rectangle
            if (code_outside == code1) {
                x1 = x;
                y1 = y;
                code1 = getRegionCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = getRegionCode(x2, y2);
            }
        }
    }

    // If line is accepted, draw the clipped line
    if (accept) {
        initwindow(500, 500);
        setcolor(WHITE);
        line(x1, y1, x2, y2);
        delay(500000);
        closegraph();
    }
}

int main() {
    int x1, y1, x2, y2;

    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cohenSutherland(x1, y1, x2, y2);

    return 0;
}
