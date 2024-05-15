
#include<graphics.h>
#include<conio.h>
#include<iostream.h>

struct Point 
{
	float x,y;
};

void bezier(Point p1, Point p2, Point p3, Point p4)
{
	int max_x = getmaxx();
	int max_y = getmaxy();
	int max_x_2 = max_x / 2;
	int max_y_2 = max_y / 2;
	
	float x_t,y_t;
	
	for(float t = 0; t <= 1; t += 0.001)
	{
		x_t = (1-t)*(1-t)*(1-t)*p1.x + 3*t*(1-t)*(1-t)*p2.x + 3*t*t*(1-t)*p3.x + t*t*t*p4.x;
		y_t = (1-t)*(1-t)*(1-t)*p1.y + 3*t*(1-t)*(1-t)*p2.y + 3*t*t*(1-t)*p3.y + t*t*t*p4.y;
		
		x_t = max_x_2 + x_t;
		y_t = max_y_2 - y_t;
	
		putpixel(x_t, y_t, YELLOW);
	}
	
	putpixel(p1.x, p1.y, WHITE);
	putpixel(p2.x, p2.y, WHITE);
	putpixel(p3.x, p3.y, WHITE);
	putpixel(p4.x, p4.y, WHITE);
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	int max_x = getmaxx();
	int max_y = getmaxy();
	int max_x_2 = max_x / 2;
	int max_y_2 = max_y / 2;
	line(max_x_2,0,max_x_2,max_y);
	line(0,max_y_2,max_x,max_y_2);
	
	Point p1,p2,p3,p4;
	cout<<"Enter the 4 control points (x <space> y): \n";
	cout<<"P1: ";
	cin>>p1.x>>p1.y;
	cout<<"P2: ";
	cin>>p2.x>>p2.y;
	cout<<"P3: ";
	cin>>p3.x>>p3.y;
	cout<<"P4: ";
	cin>>p4.x>>p4.y;	
	
	bezier(p1,p2,p3,p4);
	
	getch();
	closegraph();
	return 0;
}
