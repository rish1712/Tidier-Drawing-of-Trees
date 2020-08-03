#include "tree.h"
#include "primitive.h"
#include <GL/GL.h>
#include <vector>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

void init() {
    /*!glClear function sets the bitplane area of the window to GL_COLOR_BUFFER_BIT
    and GL_DEPTH_BUFFER_BIT
    */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*!glutInitDisplayMode sets the display mode as GLUT_SINGLE orGLUT_RGB
	*/
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/*! glutInitWindowsPosition requests future windows to open at a given position which is given as its arguments
	*/
	glutInitWindowPosition(0, 0);
	/*!glutInitWindowSize sets the windows size according to the arguments given
	*/
	glutInitWindowSize(750, 750);
    /*! glutCreateWindow gives the title to the window which is given as string as arguments
    */
	glutCreateWindow("Tidier Drawing of tree");
	/*!glClearColor gives the background color of the window
	*/
	glClearColor(1.0, 1.0, 0.0, 1);
	/*! glColor3f is used to give color to the points
	*/
	glColor3f(1.0, 1.0, 1.0);
	/*! gluOrtho2D can be used to set the clipping area of 2D orthographic view.
	*/
	gluOrtho2D(0, 1366,0, 768);

}
tree *t;
void drawTree()
{
    /*! Calling the tidier function to make tree according to the tidier algorithm
    */
	t->Tidier();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	/*! calling the init function which contains the specifications of the backside window
	*/
	init();
	int answer, n, type,flag=0;
	vector <int> vec(10000000);
start:
    flag=0;
    /*! the system(cls) clears the screen
    */
	system("cls");
	cout <<"Which type of tree you want to make " << endl;
	cout <<" Type 1 for a BST " << endl;
	cout <<" Type 2 for making a random tree " << endl;
	cout <<" Type 3 for making a balanced tree" << endl;
	cin >> answer;
	/*! if the selection is not equal to 1 or 2 or 3 then again go back to start
	*/
	if(answer!=1&&answer!=2&&answer!=3)
       {
        cout<<"please enter a valid selection";
        flag=1;
        goto start;
       }
    cout<< endl;
    if(flag==0)
        cout << "Please enter number of vertices in your tree ";
    /*! Taking the number of vertices in my tree
    */
    cin >> n;
	if (answer == 1)
	{
		cout << "Enter the values which you want for a BST in a vector";
		cout<<endl;
		/*!Taking the values in the vector with
		*/
		for (int i = 0; i < n; ++i)
            cin >> vec[i];
         /*! calling the constructor of tree class with arguments as the adress of the vector  and the no of vertices
        */
		t = new tree(vec, n);
	}
	else if (answer == 2)
    {   /*! calling the constructor of tree class with arguments as number of vertices and the boolean value tells
        whether the tree has to be balanced or random
        */
        t = new tree(n, false);
    }

	else if (answer == 3)
    {
        /*! calling the constructor of tree class with arguments as number of vertices and the boolean value tells
        whether the tree has to be balanced or random
        */
        t = new tree(n, true);
    }
    /*!Calling the inbuilt "glutDisplayFunc" function for drawing tree
    */
    glutDisplayFunc(drawTree);
    /*!glutMainLoop() is a function that loops within itself, processing events and triggering your callback functions when necessary
    */
    glutMainLoop();
	return 0;
}

