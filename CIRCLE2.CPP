#include <iostream.h>
#include <graphics.h>
#include <conio.h>

#define ROUND(a) ((int)(a+0.5))

void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y) {
        // Plot the points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
	    putpixel(xc + y, yc + x, WHITE);
	    putpixel(xc - y, yc + x, WHITE);
	    putpixel(xc + y, yc - x, WHITE);
	    putpixel(xc - y, yc - x, WHITE);

	if (p <= 0) {
	    x++;
	    p += 2 * x + 1;
	} else {
	    y--;
	    x++;
	    p += 2 * (x - y) + 1;
	}
    }
}

void lineDDA(int xa, int ya, int xb, int yb) {
    int dx = xb - xa, dy = yb - ya;
    int steps;
    int k;
    float xIncrement;
    float yIncrement, x = xa, y = ya;

    if (abs(dx) > abs(dy))
	steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    putpixel(ROUND(x), ROUND(y), WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(ROUND(x), ROUND(y), WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Coordinates of the center of the circle
    int x = 250, y = 250;
    // Radius of the circle
    int radius = 100;
    // Draw x-axis
    lineDDA(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

    // Draw y-axis
    lineDDA(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
    // Draw circle
    drawCircle(x, y, radius);

    // Wait for user to close the window
    getch();
    closegraph();

    return 0;
}
