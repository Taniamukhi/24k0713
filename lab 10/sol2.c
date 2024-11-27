#include <stdio.h>
#include <stdio.h>
#include <math.h>
struct Point
{
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
int isPointInRectangle(struct Point p, struct Point bottomLeft, struct Point topRight) {
    return (p.x >= bottomLeft.x && p.x <= topRight.x &&
            p.y >= bottomLeft.y && p.y <= topRight.y);
}
int main()
 {
    struct Point p1, p2, bottomLeft, topRight;
    printf("Enter coordinates of the first point (x y): ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Enter coordinates of the second point (x y): ");
    scanf("%f %f", &p2.x, &p2.y);
    float distance = calculateDistance(p1, p2);
    printf("Distance between the points: %.2f\n", distance);
    printf("Enter bottom-left corner of the rectangle (x y): ");
    scanf("%f %f", &bottomLeft.x, &bottomLeft.y);
    printf("Enter top-right corner of the rectangle (x y): ");
    scanf("%f %f", &topRight.x, &topRight.y);
    if (isPointInRectangle(p1, bottomLeft, topRight))
	 {
        printf("Point (%.2f, %.2f) is inside the rectangle.\n", p1.x, p1.y);
    }
	 else
	  {
        printf("Point (%.2f, %.2f) is outside the rectangle.\n", p1.x, p1.y);
    }
    if (isPointInRectangle(p2, bottomLeft, topRight))
	{
        printf("Point (%.2f, %.2f) is inside the rectangle.\n", p2.x, p2.y);
    } 
	else
	 {
        printf("Point (%.2f, %.2f) is outside the rectangle.\n", p2.x, p2.y);
    }
    return 0;
}
