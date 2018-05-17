//#include <iostream>
//#include <stdlib.h>
//#include <math.h>
//#include <fstream>
//#include <string>
//#include <vector>
//
//#include <FG\glut.h>
//#include <FG\freeglut.h>
//
//#include "cCircle.h"
//#include "cRectangle.h"
//#include "cTriangle.h"
//
//
////#include "cGlutDisplay.h"
//using namespace std;
//// angle of rotation for the camera direction
//float angle = 0.0f;
//
//// actual vector representing the camera's direction
//float lx = 0.0f, lz = -1.0f;
//
//// XZ position of the camera
////float x = 0.0f, z = 0.0f;
//
////mouse location; 
//float mx;
//float my;
//// the key states. These variables will be zero
////when no key is being presses
//float deltaAngle = 0.0f;
//float deltaMove = 0;
//int xOrigin = -1;
//
//// Constant definitions for Menus
//#define RED 1
//#define GREEN 2
//#define BLUE 3
//#define ORANGE 4
//
//#define TRIANGLE 1
//#define RECTANGLE 2
//#define CIRCLE 3
//#define SQUARE 4
//
//#define FILL 1
//#define LINE 2
//
//#define SHRINK 1
//#define NORMAL 2
//
//#define LOAD 1
//#define SAVE 2
//#define CLEAR 3
//#define MOVE 4
//
//#define PI 3.1415926535897932384626433832795
//
////Radius
//static float radius = 0.2f;
//
//// Pop up menu identifiers
//int fillMenu, shrinkMenu, mainMenu, colorMenu, shapeMenu, saveShapes, loadShapes;
//
//// Shape color
//float red = 0.0f, blue = 0.0f, green = 0.0f;
//
//float scale = 1.0f;
////
//// menu status
//int menuFlag = 0;
//
////VP MOUSE COORDINATES
//float ox = 0;
//float oy = 0;
//
//float axisX = 0;
//float axisY = 0;
//float currentx = 0;
//float currenty = 0;
//float x = 0.0f, z = 0.0f;
//
//
//vector <cShape> myShapes;
////vector <cRectangle> myRec;
////vector <cCircle> myCir;
//
//int WIDTH = 1000, HEIGHT = 1000;
//
//
//bool movingShape = false; 
//int shapeindex = 0;
//
//void changeSize(int w, int h) {
//
//	// Prevent a divide by zero, when window is too short
//	// (you cant make a window of zero width).
//	if (h == 0)
//		h = 1;
//
//	float ratio = w * 1.0 / h;
//
//	// Use the Projection Matrix
//	glMatrixMode(GL_PROJECTION);
//
//	// Reset Matrix
//	glLoadIdentity();
//
//	// Set the viewport to be the entire window
//	glViewport(0, 0, w, h);
//
//	// Set the correct perspective.
//	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
//
//	// Get Back to the Modelview
//	glMatrixMode(GL_MODELVIEW);
//}
//
//
//
//void drawAxis02()
//{
//	glPushMatrix();
//	glLoadIdentity();
//	glBegin(GL_LINES);
//	glColor3f(1.0f, 0.0f, 1.0f);
//	glVertex2f(-1.0f, axisY);
//	glVertex2f(1.0f, axisY);
//	glEnd();
//	glPopMatrix();
//
//	glPushMatrix();
//	glLoadIdentity();
//	glBegin(GL_LINES);
//	glVertex2f(axisX, 1.0f);
//	glVertex2f(axisX, -1.0f);
//	glEnd();
//	glPopMatrix();
//}
//void drawAxis()
//{
//	glPushMatrix();
//	glLoadIdentity();
//	glBegin(GL_LINES);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glVertex2f(-1.0f, oy);
//	glVertex2f(1.0f, oy);
//	glEnd();
//	glPopMatrix();
//
//	glPushMatrix();
//	glLoadIdentity();
//	glBegin(GL_LINES);
//	glVertex2f(ox, 1.0f);
//	glVertex2f(ox, -1.0f);
//	glEnd();
//	glPopMatrix();
//}
//
//
//int verifySelectedShape()
//{
//	if (system("CLS")) system("clear");
//
//	float DISTANCE1 = 0;
//	float DISTANCE2 = 0;
//
//	float best;
//	int closestShape = 0;
//
//	for (int i = 0; i < myShapes.size(); i++)
//	{
//		
//		//DISTANCE BETWEEN MOUSE POSITION AND CLOSEST SHAPE POSITION  
//		DISTANCE1 = sqrt
//		(
//			pow((myShapes[closestShape].getPx() - currentx), 2) 
//			+
//			pow((myShapes[closestShape].getPy() - currenty), 2) 
//		);
//
//		DISTANCE2 = sqrt(
//		pow((myShapes[i].getPx() - myShapes[i].getPy()), 2) +
//		pow((currentx - currenty), 2));
//
//		cout << "\n==================================================================================\nDISTANCES: \n";
//		cout << "CLOSEST SHAPE: \n" << myShapes[closestShape].getName() << "[" << closestShape << "] [" << DISTANCE1 << "]\n";
//
//		cout << "CURRENT SHAPE: \n" << myShapes[i].getName() << "[" << i << "] [" << DISTANCE2 << "]\n";
//		cout << "\n===================================================================================\n";
//		
//		
//		
//		if (DISTANCE1 > DISTANCE2)
//		{
//			closestShape = i;
//			best = DISTANCE2;
//		}
//		else
//		{
//			best = DISTANCE1;
//		}
//
//	}
//	cout << "CLOSEST SHAPE: \n" << myShapes[closestShape].getName() << "[" <<closestShape << "] ["<< best <<"]\n";
//
//
//	return closestShape;
//}
//
//
//void drawTriangle3D()
//{
//	glPushMatrix();
//	glLoadIdentity();
//	glBegin(GL_TRIANGLES);
//	glVertex3f(-2.0f, -2.0f, 0.0f);
//	glVertex3f(2.0f, 0.0f, 0.0);
//	glVertex3f(0.0f, 2.0f, 0.0);
//	glEnd();
//	glPopMatrix();
//}
//void drawTriangle2D(float tx, float ty, float tr, float tg, float tb)
//{
//	glPushMatrix();
//	glLoadIdentity();
//	glBegin(GL_TRIANGLES);
//	glColor3f(tr, tg, tb);
//	glVertex2f(tx, (ty + 0.2f));
//	glVertex2f((tx - 0.15f), (ty - 0.15f));
//	glVertex2f((tx + 0.15f), (ty - 0.15f));
//	glEnd();
//	glPopMatrix();
//}
//void drawRectangle2D(float tx, float ty, float tr, float tg, float tb)
//{
//	glPushMatrix();
//	glLoadIdentity();
//
//	glBegin(GL_POLYGON);
//	glColor3f(tr, tg, tb);
//	glVertex2f((tx - 0.2f), (ty + 0.2f));
//	glVertex2f((tx - 0.2f), (ty - 0.2f));
//	glVertex2f((tx + 0.2f), (ty - 0.2f));
//	glVertex2f((tx + 0.2f), (ty + 0.2f));
//	
//	
//	
//	glEnd();
//	glPopMatrix();
//}
//void drawCircle2D(float tx, float ty, float tr, float tg, float tb)
//{
//	glPushMatrix();
//	glLoadIdentity();
//	glBegin(GL_POLYGON);
//	glColor3f(tr, tg, tb);
//	for (float i = 0; i < 2 * PI; i += PI / 30)
//		glVertex3f(cos(i) * radius + tx, sin(i) * radius + ty, 0.0);
//	glEnd();
//
//	glPopMatrix();
//
//
//
//}
//
//void DrawAllShapes()
//{
//	drawAxis();
//	
//	for (int i = 0; i < myShapes.size(); i++)
//	{
//		if (myShapes[i].getName() == "Triangle")
//		drawTriangle2D
//		(
//			myShapes[i].getPx(),
//			myShapes[i].getPy(),
//			myShapes[i].getCr(),
//			myShapes[i].getCg(),
//			myShapes[i].getCb()
//		);
//		else if (myShapes[i].getName() == "Circle")
//			drawCircle2D
//			(
//				myShapes[i].getPx(),
//				myShapes[i].getPy(),
//				myShapes[i].getCr(),
//				myShapes[i].getCg(),
//				myShapes[i].getCb()
//			);
//		else if (myShapes[i].getName() == "Rectangle")
//			drawRectangle2D
//			(
//				myShapes[i].getPx(),
//				myShapes[i].getPy(),
//				myShapes[i].getCr(),
//				myShapes[i].getCg(),
//				myShapes[i].getCb()
//			);
//
//	}
//
//}
//void computePos(float deltaMove) {
//
//	x += deltaMove * lx * 0.1f;
//	z += deltaMove * lz * 0.1f;
//
//}
//void renderScene(void) {
//
//	if (deltaMove)
//		computePos(deltaMove);
//
//
//	// Clear Color and Depth Buffers
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	// Reset transformations
//	glLoadIdentity();
//
//	// Reset transformations
//	glLoadIdentity();
//	// Set the camera
//	gluLookAt(0.0f, 0.0f, 10.0f,
//		0.0f, 0.0f, 0.0f,
//		0.0f, 1.0f, 0.0f);
//
//	glRotatef(angle, 0.0f, 1.0f, 0.0f);
//	drawTriangle3D();
//	//DrawAllShapes();
//	angle += 0.1f;
//	glutSwapBuffers();
//}
//void processNormalKeys(unsigned char key, int xx, int yy) {
//
//	glutSetMenu(mainMenu);
//
//	if (key == 27)
//	{
//		glutDestroyMenu(mainMenu);
//		glutDestroyMenu(fillMenu);
//		glutDestroyMenu(colorMenu);
//		glutDestroyMenu(shrinkMenu);
//		exit(0);
//	}
//}
//void pressKey(int key, int xx, int yy) {
//
//	switch (key) {
//	case GLUT_KEY_UP: deltaMove = 0.5f; break;
//	case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
//	}
//}
//void releaseKey(int key, int x, int y) {
//
//	switch (key) {
//	case GLUT_KEY_UP:
//	case GLUT_KEY_DOWN: deltaMove = 0; break;
//	}
//}
//bool isInsideShape()
//{
//	bool inside = false;
//
//	if (myShapes[shapeindex].getName() == "Rectangle")
//	{
//		float DISTANCE1 = sqrt
//		(
//			pow((myShapes[shapeindex].getPx() - currentx), 2)
//			+
//			pow((myShapes[shapeindex].getPy() - currenty), 2)
//		);
//
//		if (DISTANCE1 > radius)
//		{
//			inside = true;
//		}
//
//	}
//	else
//
//		if (myShapes[shapeindex].getName() == "Circle")
//		{
//			float DISTANCE1 = sqrt
//			(
//				pow((myShapes[shapeindex].getPx() - currentx), 2)
//				+
//				pow((myShapes[shapeindex].getPy() - currenty), 2)
//			);
//
//			if (!DISTANCE1 > radius)
//				inside = true;
//
//		}
//	return inside;
//}
//void mouseButton(int btn, int state, int x, int y) {
//	
//	 mx = x;
//	 my = y;
//	ox = (mx / (WIDTH / 2) - 1.0);
//	oy = -(my / (HEIGHT / 2) - 1.0);
//
//
//
//
//	switch (btn) {
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN) {
//			currentx = ox;
//			currenty = oy;
//			//printf(" y = %f\n", currentx);
//			//printf(" x = y%f\n", currenty);
//			//cout << "\nSHAPE SIZE: " << myShapes.size() << endl;
//			if (myShapes.size() > 1 && !movingShape)
//				shapeindex = verifySelectedShape();
//
//			if (movingShape)
//			{
//				//if (isInsideShape())
//				//{
//				//	myShapes[shapeindex].setPosx(ox);
//				//	myShapes[shapeindex].setPosy(oy);
//				//	
//				//}
//
//				myShapes[shapeindex].setPosx(ox);
//				myShapes[shapeindex].setPosy(oy);
//				movingShape = false;
//			}
//
//		}
//		break;
//	}
//
//};
//
//void currentCursorLocation(int x, int y)
//{
//	axisX =  (x / (WIDTH / 2) - 1.0);
//	axisY = -(y / (HEIGHT / 2) - 1.0);
//}
//void LoadShape(const string& fileName)
//{
//	cout << "LOADING...";
//	ifstream file;
//	file.open((fileName).c_str());
//
//	string line;
//
//	if (file.is_open())
//	{
//		//cout << "\n\nFILE " << fileName << " is open" << endl;
//
//		while (file.good())
//		{
//			getline(file, line);
//
//			int linesize = line.size();
//			if (line == "Shape:")
//			{
//				getline(file, line);
//				int shapeType;
//				string shape = line;
//				if (shape == "Triangle")
//					shapeType = 1;
//				else if (shape == "Rectangle")
//					shapeType = 2;
//				else if (shape == "Circle")
//					shapeType = 3;
//				else
//					break;
//
//				getline(file, line);
//				float x = stof(line);
//				getline(file, line);
//				float y = stof(line);
//				getline(file, line);
//				float r = stof(line);
//				getline(file, line);
//				float g = stof(line);
//				getline(file, line);
//				float b = stof(line);
//
//
//				switch (shapeType)
//				{
//				case 1:
//				{
//					cout << "LOADING: " << shape << endl;
//					cTriangle cT = cTriangle(shape, x, y, r, g, b);
//					myShapes.push_back(cT);
//					break;
//				}
//				case 2:
//				{
//					cout << "LOADING: " << shape << endl;
//					cRectangle cR = cRectangle(shape, x, y, r, g, b);
//					myShapes.push_back(cR);
//					break;
//				}
//				case 3:
//				{
//					cout << "LOADING: " << shape << endl;
//					cCircle cC = cCircle(shape, x, y, r, g, b);
//					myShapes.push_back(cC);
//					break;
//				}
//				}
//			}
//		}
//	}
//	else
//	{
//		cerr << "UNABLE OPEN FILE" << fileName << endl;
//	}
//
//}
//void SaveShape(const string& fileName)
//{
//	if (remove("Text.txt") != 0)
//		perror("Error deleting file");
//	else
//		puts("File successfully deleted");
//
//	ofstream outfile("Text.txt");
//
//	ofstream file;
//	file.open((fileName).c_str());
//
//	string line;
//
//	if (file.is_open())
//	{
//
//		for (int i = 0; i < myShapes.size(); i++)
//		{
//			file << "\nShape:" << endl;
//			file << myShapes[i].getName() << endl;
//			file << myShapes[i].getPx() << endl;
//			file << myShapes[i].getPy() << endl;
//			file << myShapes[i].getCr() << endl;
//			file << myShapes[i].getCg() << endl;
//			file << myShapes[i].getCb() << endl;
//
//		}
//
//	}
//
//
//}
//void processMenuStatus(int status, int x, int y) {
//
//	if (status == GLUT_MENU_IN_USE)
//		menuFlag = 1;
//	else
//		menuFlag = 0;
//}
//void processMainMenu(int option) {
//
//	switch (option)
//	{
//		case CLEAR:
//		{
//			myShapes.clear();
//			break;
//		}
//		case LOAD:
//		{
//			myShapes.clear();
//			LoadShape("Text.txt");
//			break;
//		}
//		case SAVE:
//		{
//			SaveShape("Text.txt");
//			break;
//		}
//
//		case MOVE:
//		{
//			movingShape = true;
//			break;
//		}
//	}
//
//}
//
//void processCreateShape(int option)
//{
//
//	switch (option)
//	{
//	case TRIANGLE:
//	{
//
//		cTriangle cT = cTriangle("Triangle", currentx, currenty, red, green, blue);
//
//		myShapes.push_back(cT);
//		break;
//	}
//
//	case RECTANGLE:
//	{
//		cRectangle cR = cRectangle("Rectangle", currentx, currenty, red, green, blue);
//		myShapes.push_back(cR);
//		break;
//	}
//
//	case CIRCLE:
//	{
//		cCircle cC = cCircle("Circle", currentx, currenty, red, green, blue);
//		myShapes.push_back(cC);
//		break;
//	}
//
//	case SQUARE:
//	{
//		cTriangle cS = cTriangle("Square", currentx, currenty, red, green, blue);
//		myShapes.push_back(cS);
//		break;
//	}
//
//
//	}
//}
//void processShrinkMenu(int option) {
//
//	switch (option) {
//
//	case SHRINK: scale = 0.5f; break;
//	case NORMAL: scale = 1.0f; break;
//	}
//}
//void processColorMenu(int option) {
//
//	switch (option) {
//	case RED:
//		red = 1.0f;
//		green = 0.0f;
//		blue = 0.0f;
//		break;
//	case GREEN:
//		red = 0.0f;
//		green = 1.0f;
//		blue = 0.0f;
//		break;
//	case BLUE:
//		red = 0.0f;
//		green = 0.0f;
//		blue = 1.0f;
//		break;
//	case ORANGE:
//		red = 1.0f;
//		green = 0.5f;
//		blue = 0.0f;
//		break;
//	}
//
//}
//void createPopupMenus() {
//
//
//
//	shrinkMenu = glutCreateMenu(processShrinkMenu);
//
//	glutAddMenuEntry("Shrink", SHRINK);
//	glutAddMenuEntry("NORMAL", NORMAL);
//
//
//	shapeMenu = glutCreateMenu(processCreateShape);
//	glutAddMenuEntry("TRIANGLE", TRIANGLE);
//	glutAddMenuEntry("RECTANGLE", RECTANGLE);
//	glutAddMenuEntry("CIRCLE", CIRCLE);
//	glutAddMenuEntry("SQUARE", SQUARE);
//
//
//	colorMenu = glutCreateMenu(processColorMenu);
//	glutAddMenuEntry(" Red    ", RED);
//	glutAddMenuEntry(" Green  ", GREEN);
//	glutAddMenuEntry(" Blue   ", BLUE);
//	glutAddMenuEntry(" Orange ", ORANGE);
//
//
//
//
//	mainMenu = glutCreateMenu(processMainMenu);
//	glutAddSubMenu("Color ", colorMenu);
//	glutAddSubMenu("Shape ", shapeMenu);
//	glutAddMenuEntry("Save  ", SAVE);
//	glutAddMenuEntry("Clear ", CLEAR);
//	glutAddMenuEntry("Load  ", LOAD);
//	glutAddMenuEntry("Move ", MOVE);
//
//
//
//
//	// attach the menu to the right button
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	// this will allow us to know if the menu is active
//	glutMenuStatusFunc(processMenuStatus);
//
//}
//void Update(int option)
//{
//
//	//axisX = (mx / (WIDTH / 2) - 1.0);
//	//axisY = -(my / (HEIGHT / 2) - 1.0);
//	drawAxis02();
//	glutPostRedisplay();
//	glutTimerFunc(100, Update, 0);
//
//}
//
//
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(320, 320);
//	glutCreateWindow("DRAW SHAPES");
//
//	glutDisplayFunc(renderScene);
//	glutReshapeFunc(changeSize);
//	glutIdleFunc(renderScene);
//
//	glutIgnoreKeyRepeat(1);
//	glutKeyboardFunc(processNormalKeys);
//	glutSpecialFunc(pressKey);
//	glutSpecialUpFunc(releaseKey);
//
//	// here are the two new functions
//	glutMouseFunc(mouseButton);
//	//glutPassiveMotionFunc(currentCursorLocation);
//
//	// OpenGL init
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//
//	//glutTimerFunc(1, Update, 0);
//	// init Menus
//	//createPopupMenus();
//
//	// enter GLUT event processing cycle
//	glutMainLoop();
//	return 1;
//
//}