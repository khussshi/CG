#include <iostream>
#include <graphics.h>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

// Function to return the clipped polygon
vector<Point> sutherlandHodgmanClip(vector<Point>& polygon, Point clipper[], int clipperSize) {
    vector<Point> outputList = polygon;
    // Each stage of the algorithm clips the polygon against one edge of the clipping window
    for (int i = 0; i < clipperSize; i++) {
        int k = (i + 1) % clipperSize;
        vector<Point> inputList = outputList;
        outputList.clear();
        Point A = clipper[i], B = clipper[k];
        for (int j = 0; j < inputList.size(); j++) {
            int k = (j + 1) % inputList.size();
            Point P = inputList[j], Q = inputList[k];
            // TODO: Add the clipping logic here
            // You will need to calculate intersections and determine if points are inside or outside the clipping edge
        }
    }
    return outputList;
}

// Function to draw the polygon
void drawPolygon(vector<Point>& polygon) {
    for (int i = 0; i < polygon.size(); i++) {
        int k = (i + 1) % polygon.size();
        line(polygon[i].x, polygon[i].y, polygon[k].x, polygon[k].y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // Initialize graphics mode

    int numSides;
    cout << "Enter the number of sides for the polygon: ";
    cin >> numSides;

    vector<Point> polygon(numSides);
    cout << "Enter the coordinates of the polygon in clockwise order:" << endl;
    for (int i = 0; i < numSides; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    // Define the clipper polygon (example: a square clipper)
    Point clipper[] = {{100, 100}, {100, 200}, {200, 200}, {200, 100}};
    int clipperSize = sizeof(clipper) / sizeof(clipper[0]);

    // Perform clipping
    vector<Point> clippedPolygon = sutherlandHodgmanClip(polygon, clipper, clipperSize);

    // Draw the original polygon
    setcolor(RED);
    drawPolygon(polygon);

    // Draw the clipped polygon
    setcolor(GREEN);
    drawPolygon(clippedPolygon);

    getch();
    closegraph();
    return 0;
}
