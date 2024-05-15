
#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define ROUND(a) ((int)(a+0.5))

void lineDDA (int xa, int ya, int xb, int yb){

    int dx = xb - xa, dy = yb - ya;
    int steps;
    int k;
    float xIncrement;
    float yIncrement, x = xa, y = ya;

    if (abs(dx) > abs(dy)) steps = abs(dx);
    else steps = abs(dy);

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    putpixel(ROUND(x), ROUND(y), WHITE);

    for (k=0; k<steps; k++){
	x += xIncrement;
	y += yIncrement;
	putpixel( ROUND(x), ROUND(y), WHITE);
    }
}



int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int a = getmaxx()/2;
    int b = getmaxy();
    int c = getmaxx();
    int d = getmaxy()/2;
    lineDDA(a,0,a,b);
    lineDDA(0,d,c,d);
    lineDDA(a+20,d-30,a+100,d-150);
    lineDDA(a-20,d-30,a-100,d-150);
    lineDDA(a-20,d+30,a-100,d+150);
    lineDDA(a+20,d+30,a+100,d+150);

    getch();
    closegraph();
    return 0;
}