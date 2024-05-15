#include<iostream>
#include<algorithm>
#include<graphics.h>
#include<conio.h>
#include<vector>


using namespace std;

class ScanLineFill {
public:
    void fillPolygon(vector<pair<int, int>>);

};

void ScanLineFill::fillPolygon(vector<pair<int, int>> points) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw the polygon
    setcolor(WHITE);
    for (int i = 0; i < points.size(); i++) {
        int next = (i + 1) % points.size();
        line(points[i].first, points[i].second, points[next].first, points[next].second);
    }

    // Find ymin, ymax
    int ymin = INT_MAX, ymax = INT_MIN;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].second < ymin) ymin = points[i].second;
        if (points[i].second > ymax) ymax = points[i].second;
    }

    // Scanline loop
    for (int y = ymin; y <= ymax; y++) {
        vector<int> intersections;

        // Find intersections
        for (int i = 0; i < points.size(); i++) {
            int next = (i + 1) % points.size();
            int y1 = points[i].second, y2 = points[next].second;

            if ((y1 < y && y2 >= y) || (y2 < y && y1 >= y)) {
                int x = points[i].first + (y - y1) * (points[next].first - points[i].first) / (y2 - y1);
                intersections.push_back(x);
            }
        }

        // Sort intersections
        sort(intersections.begin(), intersections.end());

        // Fill the pixels between pairs of x-coordinates in intersections
        for (int i = 0; i < intersections.size(); i += 2) {
            int x1 = intersections[i], x2 = intersections[i + 1];
            for (int x = x1; x <= x2; x++) {
                if (x >= getmaxx()) break;  // Check for x boundary
                putpixel(x, y, GREEN);
            }
        }
    }

    getch();
    closegraph();
}


int main() {
    ScanLineFill s;
    vector<pair<int, int>> points;

    // Add points to create a hexagon
    points.push_back({200, 100});
    points.push_back({300, 150});
    points.push_back({300, 250});
    points.push_back({200, 300});
    points.push_back({100, 250});
    points.push_back({100, 150});

    s.fillPolygon(points);

    return 0;
}

/*Great to hear that it worked! Let me break down the updated `fillPolygon` method to help you understand how it works:

### Steps in the Scan-Line Fill Algorithm:

1. **Draw the Polygon:**
   - We first draw the polygon using the provided points to visualize its shape.

2. **Find ymin and ymax:**
   - We determine the minimum and maximum y-coordinates of the polygon to define the range of scanlines we need to process.

3. **Scanline Loop:**
   - We loop through each scanline (y-coordinate) from ymin to ymax.

4. **Find Intersections:**
   - For each scanline, we find the intersections of the scanline with the edges of the polygon.
   - We iterate through each pair of consecutive points in the polygon and check if the scanline intersects with the edge between them.
   - If an intersection is found, we calculate the x-coordinate of the intersection point using linear interpolation based on the y-coordinate of the scanline and the y-coordinates of the edge endpoints.
   - We store the x-coordinates of the intersections in a vector called `intersections`.

5. **Sort Intersections:**
   - We sort the x-coordinates of the intersections in ascending order to ensure that we process them in the correct sequence for filling.

6. **Fill Pixels:**
   - We fill the pixels between pairs of x-coordinates in the sorted `intersections` vector.
   - For each pair of consecutive x-coordinates, we fill the pixels along the scanline between them to color the interior of the polygon.
   - We also check for the boundary of the screen to ensure that we do not exceed the maximum x-coordinate.

### Key Concepts:

- **Scanline:** A horizontal line that scans across the screen from the minimum to the maximum y-coordinate of the polygon.
  
- **Intersections:** Points where the scanline intersects with the edges of the polygon.

- **Linear Interpolation:** A method to calculate the x-coordinate of an intersection point based on the y-coordinate of the scanline and the y-coordinates of the edge endpoints.

- **Sorting:** Arranging the intersections in ascending order based on their x-coordinates to process them correctly for filling.

I hope this breakdown helps you understand the scan-line fill algorithm and how the updated `fillPolygon` method works to fill the polygon correctly without occupying additional space. If you have any further questions or need additional clarification on any part of the code or algorithm, please feel free to ask!*/