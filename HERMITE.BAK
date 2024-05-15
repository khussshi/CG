
#include<graphics.h>
#include<conio.h>
#include<iostream.h>


struct Point 
{
	float x,y;
};

void hermite(Point p1, Point r1, Point p4, Point r4)
{
	int max_x = getmaxx();
	int max_y = getmaxy();
	int max_x_2 = max_x / 2;
	int max_y_2 = max_y / 2;
	
	float x_t,y_t;
	
	for(float t = 0; t <= 1; t += 0.001)
	{
		x_t = (2*t*t*t - 3*t*t + 1)*p1.x + (-2*t*t*t + 3*t*t)*p4.x + (t*t*t - 2*t*t + t)*r1.x + (t*t*t - t*t)*r4.x;
		y_t = (2*t*t*t - 3*t*t + 1)*p1.y + (-2*t*t*t + 3*t*t)*p4.y + (t*t*t - 2*t*t + t)*r1.y + (t*t*t - t*t)*r4.y;
		
		x_t = max_x_2 + x_t;
		y_t = max_y_2 - y_t;
	
		putpixel(x_t, y_t, YELLOW);
	}
	
	putpixel(p1.x, p1.y, WHITE);
	putpixel(r1.x, r1.y, WHITE);
	putpixel(p4.x, p4.y, WHITE);
	putpixel(r4.x, r4.y, WHITE);
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
	
	Point p1,r1,p4,r4;
	cout<<"Enter the points (in the form x <space> y): \n";
	cout<<"P1: ";
	cin>>p1.x>>p1.y;
	cout<<"R1: ";
	cin>>r1.x>>r1.y;
	cout<<"P4: ";
	cin>>p4.x>>p4.y;
	cout<<"r4: ";
	cin>>r4.x>>r4.y;	
	
	hermite(p1,r1,p4,r4);
	
	getch();
	closegraph();
	return 0;
}
