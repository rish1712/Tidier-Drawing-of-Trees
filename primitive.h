class primitives
{
	/*!X coordinate of first point of the line
	*/
    int x1;
	/*! Y coordinate of first point of the line
	*/
	int y1;
	/*! X coordinate of second point of the line
	*/
	int x2;
	/*! Y coordinate of second point of the line
	*/
	int y2;
	/*! X coordinate of center of circle
	*/
	int cx;
	/*! Y coordinate of center of circle
	*/
	int cy;
	/*! Radius of circle
	*/
	int radius;
public:
	/*!This function draws the line using Bresenham's Line Algorithm
	*/
	void drawLine(int,int,int,int);
	/*!This function draws the circle using Bresenham's circle Algorithm
	*/
	void drawCircle(int,int,int);
};
