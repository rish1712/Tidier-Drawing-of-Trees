#include "primitive.h"
#include <math.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include<stdlib.h>
/*! This function draws a pixel using OpenGL
    The return type id void
*/
void drawPixel(GLint x, GLint y)
{
	/*! glColor3f is used to give color to the points
	*/
	glColor3f(1.0, 0.0, 0.0);
	/*! glPointSize sets the size of the points according to the given argument
	*/
	glPointSize(1.5);
	/*! glBegin refers todelimit the vertices of a primitive or a group of like primitives.
	*/
	glBegin(GL_POINTS);
	glVertex2i(x, 480 - y);
	glEnd();
}
/*! This function draws the line according to the Bresenham Algorithm under the case when the slope of the line is less than 1
    The return type of this function is void
    the function has the arguments as the initial X,Y coordinates and final X,y coordinates of the line
 */
void drawLine1(int x1, int y1, int x2, int y2)
{
	int k = y2 > y1 ? 1 : -1;
	int dx = x2 - x1;
	int dy = abs(y2 - y1);
	int d = 2 * dy - dx;
	int incrE = 2 * dy;
	int incrNE = 2 * (dy - dx);
	int x = x1;
	int y = y1;
	drawPixel(x, y);
	while (x < x2)
	{
		if (d <= 0)
			d += incrE;
		else
		{
			d += incrNE;
			y += k;
		}
		x += 1;
		drawPixel(x, y);
	}
}
/*!This function draws the line according to the Bresenham Algorithm under the case when the slope of the line is more than 1 or equal to 1
    The return type of this function is void
    The function has the arguments as the initial X,Y coordinates and final X,y coordinates of the line
*/
void drawLine2(int x1, int y1, int x2, int y2)
{
	int k = x2 > x1 ? 1 : -1;
	int dx = abs(x2 - x1);
	int dy = y2 - y1;
	int d = 2 * dx - dy;
	int incrE = 2 * dx;
	int incrNE = 2 * (dx - dy);
	int x = x1;
	int y = y1;
	drawPixel(x, y);
	while (y < y2)
	{
		if (d <= 0)
			d += incrE;
		else
		{
			d += incrNE;
			x += k;
		}
		y += 1;
		drawPixel(x, y);
	}
}
/*! Bresenham Algorithm for drawing line
    The return type of this function is void
    this function takes arguments as initial X,Y coordinates,final X,Y coordinates of the line and compares them according to different cases and calls
    drawLine1 or drawLine2 according to various cases
 */
void line(int x1, int y1, int x2, int y2)
{
	if ((x2 >= x1) && (y2 >= y1))
	{
		if (x2 - x1 > y2 - y1)
			drawLine1(x1, y1, x2, y2);
		else
			drawLine2(x1, y1, x2, y2);
	}
	else if ((x2 >= x1) && (y2 < y1))
	{
		if (x2 - x1 > y1 - y2)
			drawLine1(x1, y1, x2, y2);
		else
			drawLine2(x2, y2, x1, y1);
	}
	else
		line(x2, y2, x1, y1);
}
/*! This function sets up the initial, final coordinates of the line and calls the function which makes the line
This function return type is void
the arguments of this function are the inital X and Y coordinates and final X and Y coordinates of the line
*/
void primitives::drawLine(int sx1, int sy1, int sx2, int sy2)
{
	x1 = sx1;
	x2 = sx2;
	y1 = sy1;
	y2 = sy2;
	cx = 0;
	cy = 0;
	radius = 0;
	line(x1, y1,x2,y2);
	glFlush();
}
/*! this function plotCircle draws the circle symmetrically with respect to the 8 symmetric lines of circle
    This function return type is void
    The argument of this function are any coordinates on circle and the X,Y coordinates of the circle
*/
void plotCircle(int x, int y, int cx, int cy)
{
	drawPixel(cx + x, cy + y);
	drawPixel(cx - x, cy + y);
	drawPixel(cx + x, cy - y);
	drawPixel(cx - x, cy - y);
	drawPixel(cx + y, cy + x);
	drawPixel(cx - y, cy + x);
	drawPixel(cx + y, cy - x);
	drawPixel(cx - y, cy - x);
}
/*!This function draws the circle with the given arguments as X coordinate of the circle center,Y coordinate of the center of the circle
   and the radius of the circle
   This function return type id void
*/
void primitives::drawCircle(int pcx, int pcy, int pradius )
{
    x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
    int x = 0;
	int y = pradius;
	int d = 1 - pradius;
	int deltaE = 3;
	int deltaSE = -2 * pradius + 5;
	plotCircle(x, y, pcx, pcy);
	while (y > x)
	{
		if (d < 0)
		{
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		else
		{
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			--y;
		}
		++x;
		plotCircle(x, y, pcx, pcy);
	}
	glFlush();
}

