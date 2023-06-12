# include <stdio.h>
# include <math.h>

// creating the struct line
struct line{
	struct point{
		float x;
		float y;
	}point1, point2;
	float slope;
	float distance;
};

// used to solve the slope between the two points
float solveSlope(struct line line1) {
	line1.slope = (line1.point2.y - line1.point1.y)/(line1.point2.x - line1.point1.x);
	return line1.slope;
}

// used to get the midpoint between the two points
void getMidpoint(struct line line1) {
	float x, y;
	x = (line1.point1.x + line1.point2.x)/2;
	y = (line1.point1.y + line1.point2.y)/2;

	printf("\nMidpoint: %.6f %.6f", x, y);
}

// used to solve the distance between the two points
float solveDistance(struct line line1) {
	float xDistance = (line1.point1.x - line1.point2.x)*(line1.point1.x - line1.point2.x);
	float yDistance = (line1.point1.y - line1.point2.y)*(line1.point1.y - line1.point2.y);

	line1.distance = sqrt(xDistance + yDistance);
	return line1.distance;
}

// used to get the slope-intercept form between the two points
void getSlopeInterceptForm(struct line line1) {
	float b;
	// finding b in y=mx + b
	b = line1.point1.y - (line1.slope*line1.point1.x);
	printf("\ny = %.6fx + (%.6f)", line1.slope, b);
}

int main() {
	// creating struct line called line1
	struct line line1;

	// getting x and y values of point1
	printf("Enter x and y for point1: ");
	scanf("%f %f", &line1.point1.x, &line1.point1.y);

	//getting x and y values of point2
	printf("Enter x and y for point2: ");
	scanf("%f %f", &line1.point2.x, &line1.point2.y);

	line1.slope = solveSlope(line1);
	printf("\nSlope: %.6f", line1.slope);

	getMidpoint(line1);

	line1.distance = solveDistance(line1);
	printf("\nDistance between 2 points: %.6f", line1.distance);
	getSlopeInterceptForm(line1);

	return 0;
}