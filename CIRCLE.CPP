#include <iostream.h>
#include <graphics.h>
#include <conio.h>
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

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Coordinates of the center of the circle
    int x = 200, y = 200;
    // Radius of the circle
    int radius = 100;

    // Draw circle
    drawCircle(x, y, radius);

    // Wait for user to close the window
    getch();
    closegraph();

    return 0;
}
