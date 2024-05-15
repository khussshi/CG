#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1, y = y1;

    putpixel(x, y, WHITE);

    if (dx > dy) {
        int p = 2 * dy - dx;
        for (int i = 0; i < dx; i++) {
            if (p < 0) {
                x++;
                p += 2 * dy;
            } else {
                x++;
                y++;
                p += 2 * (dy - dx);
            }
            putpixel(x, y, WHITE);
        }
    } else {
        int p = 2 * dx - dy;
        for (int i = 0; i < dy; i++) {
            if (p < 0) {
                y++;
                p += 2 * dx;
            } else {
                x++;
                y++;
                p += 2 * (dx - dy);
            }
            putpixel(x, y, WHITE);
        }
    }

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2;

    cout << "Enter the coordinates of the starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the ending point (x2 y2): ";
    cin >> x2 >> y2;

    drawLine(x1, y1, x2, y2);

    return 0;
}
