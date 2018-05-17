#ifndef CGLUTDISPLAY_H
#define CGLUTDISPLAY_H
#include <vector>
#include "cCircle.h"
#include "cRectangle.h"
#include "cTriangle.h"
float angle = 0.0f;

// actual vector representing the camera's direction
//float lx = 0.0f, lz = -1.0f;

// XZ position of the camera
//float x = 0.0f, z = 0.0f;

//mouse location; 
float mx;
float my;
// the key states. These variables will be zero
//when no key is being presses
//float deltaAngle = 0.0f;
//float deltaMove = 0;
int xOrigin = -1;

// Constant definitions for Menus
#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

#define TRIANGLE 1
#define RECTANGLE 2
#define CIRCLE 3
#define SQUARE 4

#define FILL 1
#define LINE 2

#define SHRINK 1
#define NORMAL 2

#define LOAD 1
#define SAVE 2
#define CLEAR 3

#define PI 3.1415926535897932384626433832795

//Radius
static float radius = 0.2f;

// Pop up menu identifiers
int fillMenu, shrinkMenu, mainMenu, colorMenu, shapeMenu, saveShapes, loadShapes;

// Shape color
float red = 0.0f, blue = 0.0f, green = 0.0f;

float scale = 1.0f;

// menu status
int menuFlag = 0;


//VP MOUSE COORDINATES
float ox = 0;
float oy = 0;

float currentx = 0;
float currenty = 0;

float deltaMove = 0;
float x = 0.0f, z = 0.0f;
float lx = 0.0f, lz = -1.0f;

vector <cShape> myTri;
vector <cRectangle> myRec;
vector <cCircle> myCir;



class cGlutDisplay
{
private: 
	int WIDTH = 1000, HEIGHT = 1000;
	int sceneNum = 0;
	float deltaAngle = 0.0f;
	
	static void drawTriangle2D(float tx, float ty, float tr, float tg, float tb)
	{
		glPushMatrix();
		glLoadIdentity();
		glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
		glColor3f(tr, tg, tb); // Red
		glVertex2f(tx, ty);    // x, y
		glVertex2f((tx - 0.5f), (ty - 0.5f));
		glVertex2f((tx + 0.5f), (ty - 0.5f));
		glEnd();
		glPopMatrix();
	}
	static void drawRectangle2D(float tx, float ty, float tr, float tg, float tb)
	{
		glPushMatrix();
		glLoadIdentity();

		glBegin(GL_POLYGON);
		glColor3f(tr, tg, tb); // Red

		glVertex2f(tx, (ty - 0.5f));
		glVertex2f((tx + 0.5f), (ty - 0.5f));
		glVertex2f((tx + 0.5f), ty);
		glVertex2f(tx, ty);
		glEnd();
		glPopMatrix();
	}
	static void drawCircle2D(float tx, float ty, float tr, float tg, float tb)
	{
		glPushMatrix();
		glLoadIdentity();
		glBegin(GL_POLYGON);
		glColor3f(tr, tg, tb);
		for (float i = 0; i < 2 * PI; i += PI / 30) //<-- Change this Value
			glVertex3f(cos(i) * radius + tx, sin(i) * radius + ty, 0.0);
		glEnd();
		//Draw Circle
		glPopMatrix();



	}

	static void RegisterCallbacks()
	{
		glutDisplayFunc(renderScene);
		glutReshapeFunc(changeSize);
		glutIdleFunc(renderScene);

	}



	static void changeSize(int w, int h) {

		// Prevent a divide by zero, when window is too short
		// (you cant make a window of zero width).
		if (h == 0)
			h = 1;

		float ratio = w * 1.0 / h;

		// Use the Projection Matrix
		glMatrixMode(GL_PROJECTION);

		// Reset Matrix
		glLoadIdentity();

		// Set the viewport to be the entire window
		glViewport(0, 0, w, h);

		// Set the correct perspective.
		//gluPerspective(45.0f, ratio, 0.1f, 100.0f);

		// Get Back to the Modelview
		glMatrixMode(GL_MODELVIEW);
	}

	static void renderScene(void) {

		if (deltaMove)
			computePos(deltaMove);

		// Clear Color and Depth Buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Reset transformations
		glLoadIdentity();

		DrawAllShapes();

		glutSwapBuffers();
	}
	static void computePos(float deltaMove) {

		camx += deltaMove * lx * 0.1f;
		camz += deltaMove * lz * 0.1f;
	}



	static void DrawAllShapes()
	{
		for (int i = 0; i < myTri.size(); i++)
		{
			drawTriangle2D
			(
				myTri[i].getPx(),
				myTri[i].getPy(),
				myTri[i].getCr(),
				myTri[i].getCg(),
				myTri[i].getCb()
			);
		}

		for (int i = 0; i < myRec.size(); i++)
		{
			drawRectangle2D
			(
				myRec[i].getPx(),
				myRec[i].getPy(),
				myRec[i].getCr(),
				myRec[i].getCg(),
				myRec[i].getCb()
			);
		}

		for (int i = 0; i < myCir.size(); i++)
		{
			drawCircle2D
			(
				myCir[i].getPx(),
				myCir[i].getPy(),
				myCir[i].getCr(),
				myCir[i].getCg(),
				myCir[i].getCb()
			);
		}

	}
	static void processNormalKeys(unsigned char key, int xx, int yy) {

		glutSetMenu(mainMenu);

		if (key == 27)
		{
			glutDestroyMenu(mainMenu);
			glutDestroyMenu(fillMenu);
			glutDestroyMenu(colorMenu);
			glutDestroyMenu(shrinkMenu);
			exit(0);
		}
	}
	static void pressKey(int key, int xx, int yy) {

		switch (key) {
		case GLUT_KEY_UP: deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
		}
	}
	static void releaseKey(int key, int x, int y) {

		switch (key) {
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN: deltaMove = 0; break;
		}
	}
	static void mouseButton(int btn, int state, int x, int y) {
		float mx = x;
		float my = y;
		ox = (mx / (500 / 2) - 1.0);
		oy = -(my / (500 / 2) - 1.0);
		switch (btn) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) {
				currentx = ox;
				currenty = oy;
				printf("%f\n", currentx);
				printf("%f\n", currenty);
			}
			break;
		}

	};
	static void LoadShape(const string& fileName)
	{
		cout << "LOADING...";
		ifstream file;
		file.open((fileName).c_str());

		string line;

		if (file.is_open())
		{
			//cout << "\n\nFILE " << fileName << " is open" << endl;

			while (file.good())
			{
				getline(file, line);

				int linesize = line.size();
				if (line == "Shape:")
				{
					getline(file, line);
					int shapeType;
					string shape = line;
					if (shape == "Triangle")
						shapeType = 1;
					else if (shape == "Rectangle")
						shapeType = 2;
					else if (shape == "Circle")
						shapeType = 3;
					else
						break;

					getline(file, line);
					float x = stof(line);
					getline(file, line);
					float y = stof(line);
					getline(file, line);
					float r = stof(line);
					getline(file, line);
					float g = stof(line);
					getline(file, line);
					float b = stof(line);


					switch (shapeType)
					{
					case 1:
					{
						cout << "LOADING: " << shape << endl;
						cTriangle cT = cTriangle(shape, x, y, r, g, b);
						myTri.push_back(cT);
						break;
					}
					case 2:
					{
						cout << "LOADING: " << shape << endl;
						cRectangle cR = cRectangle(shape, x, y, r, g, b);
						myRec.push_back(cR);
						break;
					}
					case 3:
					{
						cout << "LOADING: " << shape << endl;
						cCircle cC = cCircle(shape, x, y, r, g, b);
						myCir.push_back(cC);
						break;
					}
					}
				}
			}
		}
		else
		{
			cerr << "UNABLE OPEN FILE" << fileName << endl;
		}

	}
	static void SaveShape(const string& fileName)
	{
		if (remove("Text.txt") != 0)
			perror("Error deleting file");
		else
			puts("File successfully deleted");

		ofstream outfile("Text.txt");

		ofstream file;
		file.open((fileName).c_str());

		string line;

		if (file.is_open())
		{

			for (int i = 0; i < myTri.size(); i++)
			{
				file << "\nShape:" << endl;
				file << myTri[i].getName() << endl;
				file << myTri[i].getPx() << endl;
				file << myTri[i].getPy() << endl;
				file << myTri[i].getCr() << endl;
				file << myTri[i].getCg() << endl;
				file << myTri[i].getCb() << endl;

			}

			for (int i = 0; i < myRec.size(); i++)
			{
				file << "\nShape:" << endl;
				file << myRec[i].getName() << endl;
				file << myRec[i].getPx() << endl;
				file << myRec[i].getPy() << endl;
				file << myRec[i].getCr() << endl;
				file << myRec[i].getCg() << endl;
				file << myRec[i].getCb() << endl;

			}

			for (int i = 0; i < myCir.size(); i++)
			{
				file << "\nShape:" << endl;
				file << myCir[i].getName() << endl;
				file << myCir[i].getPx() << endl;
				file << myCir[i].getPy() << endl;
				file << myCir[i].getCr() << endl;
				file << myCir[i].getCg() << endl;
				file << myCir[i].getCb() << endl;

			}

		}


	}
	static void processMenuStatus(int status, int x, int y) {

		if (status == GLUT_MENU_IN_USE)
			menuFlag = 1;
		else
			menuFlag = 0;
	}
	static void processMainMenu(int option) {

		switch (option)
		{
		case CLEAR:
		{
			myTri.clear();
			myCir.clear();
			myRec.clear();
			break;
		}
		case LOAD:
		{
			myTri.clear();
			myCir.clear();
			myRec.clear();
			LoadShape("Text.txt");
			break;
		}
		case SAVE:
		{
			SaveShape("Text.txt");
			break;
		}
		}

	}
	static void processCreateShape(int option)
	{

		switch (option)
		{
		case TRIANGLE:
		{

			cTriangle cT = cTriangle("Triangle", currentx, currenty, red, green, blue);
			myTri.push_back(cT);
			break;
		}

		case RECTANGLE:
		{
			cRectangle cR = cRectangle("Rectangle", currentx, currenty, red, green, blue);
			myRec.push_back(cR);
			break;
		}

		case CIRCLE:
		{
			cCircle cC = cCircle("Circle", currentx, currenty, red, green, blue);
			myCir.push_back(cC);
			break;
		}

		case SQUARE:
		{
			cTriangle cS = cTriangle("Square", currentx, currenty, red, green, blue);
			myTri.push_back(cS);
			break;
		}


		}
	}
	static void processShrinkMenu(int option) {

		switch (option) {

		case SHRINK: scale = 0.5f; break;
		case NORMAL: scale = 1.0f; break;
		}
	}
	static void processColorMenu(int option) {

		switch (option) {
		case RED:
			red = 1.0f;
			green = 0.0f;
			blue = 0.0f;
			break;
		case GREEN:
			red = 0.0f;
			green = 1.0f;
			blue = 0.0f;
			break;
		case BLUE:
			red = 0.0f;
			green = 0.0f;
			blue = 1.0f;
			break;
		case ORANGE:
			red = 1.0f;
			green = 0.5f;
			blue = 0.5f;
			break;
		}

	}
	static void createPopupMenus() {



		shrinkMenu = glutCreateMenu(processShrinkMenu);

		glutAddMenuEntry("Shrink", SHRINK);
		glutAddMenuEntry("NORMAL", NORMAL);


		shapeMenu = glutCreateMenu(processCreateShape);
		glutAddMenuEntry("TRIANGLE", TRIANGLE);
		glutAddMenuEntry("RECTANGLE", RECTANGLE);
		glutAddMenuEntry("CIRCLE", CIRCLE);
		glutAddMenuEntry("SQUARE", SQUARE);


		colorMenu = glutCreateMenu(processColorMenu);
		glutAddMenuEntry(" Red    ", RED);
		glutAddMenuEntry(" Green  ", GREEN);
		glutAddMenuEntry(" Blue   ", BLUE);
		glutAddMenuEntry(" Orange ", ORANGE);




		mainMenu = glutCreateMenu(processMainMenu);
		glutAddSubMenu("Color ", colorMenu);
		glutAddSubMenu("Shape ", shapeMenu);
		glutAddMenuEntry("Save  ", SAVE);
		glutAddMenuEntry("Clear ", CLEAR);
		glutAddMenuEntry("Load  ", LOAD);




		// attach the menu to the right button
		glutAttachMenu(GLUT_RIGHT_BUTTON);

		// this will allow us to know if the menu is active
		glutMenuStatusFunc(processMenuStatus);

	}


	public:
		cGlutDisplay(string name, int winHeight, int winWidth)
		{

			
			glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
			glutInitWindowPosition(500, 200);
			glutInitWindowSize(WIDTH, HEIGHT);
			glutCreateWindow("DRAW SHAPES");

			RegisterCallbacks();

			glutIgnoreKeyRepeat(1);
			glutKeyboardFunc(processNormalKeys);
			glutSpecialFunc(pressKey);
			glutSpecialUpFunc(releaseKey);

			// here are the two new functions
			glutMouseFunc(mouseButton);

			// OpenGL init
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);

			// init Menus
			createPopupMenus();

			// enter GLUT event processing cycle
			glutMainLoop();



		}

};


#endif // !CGLUTDISPLAY_H


