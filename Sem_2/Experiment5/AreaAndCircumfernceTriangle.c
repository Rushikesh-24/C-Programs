// Point A: (2, 5)
// Point B: (-3, 8)
// Point C: (6, -2)
// a-b = 5.83
// c-a =8.06
// c-b = 13.45
#include <stdio.h>
#include <math.h>
float distance(int, int, int, int, int, int);
float Area(float,float,float);
int main()
{
    int x1, x2, x3, y1, y2, y3;
    float Area;
    printf("Enter the coordinates of the point of triangle\n");
    printf("Point A:");
    scanf("%d%d", &x1,&y1);
    printf("Point B:");
    scanf("%d%d", &x2,&y2);
    printf("Point C:");
    scanf("%d%d", &x3,&y3);
    Area = distance(x1, x2, x3, y1, y2, y3);
    printf("\n%f",Area);
    return 0;
}
float distance(int x1, int x2, int x3, int y1, int y2, int y3)
{
    float d1, d2, d3;
    d1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    d2 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    d3 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    printf("Distance between point A and B is %f\nDistance between point A and C is %f\nDistance between point C and B is %f\n", d1, d2, d3);
    return Area(d1, d2, d3);
}
float Area(float d1, float d2, float d3)
{
    float Area = 0, semiPerimeter = 0;
    semiPerimeter = (d1 + d2 + d3)/2;
    Area = sqrt(semiPerimeter*(semiPerimeter - d1)*(semiPerimeter-d2)*(semiPerimeter-d3));
    printf("Perimeter = %f",semiPerimeter*2);
    return Area;
}