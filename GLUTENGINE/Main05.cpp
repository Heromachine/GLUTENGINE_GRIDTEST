//#include "cGrid.h";
//#include "cMesh.h"
//#include "SpaceShip.h"
//#include "cVaccum.h"
//#include "cDFSMissile.h"
//#include "AStarMissile.h"
//#include "cBullet.h"
//#include <FG\glut.h>
//
//
////GLOABAL VERABLES
//float angle = 0.0f;
//float deltaMove = 0.0f;
//float HorizontalMove = 0.0f;
//float VerticalMove = 0.0f;
//
//
//float HMove = 0.0f;
//float VMove = 0.0f;
////(int gridsize, int tilesize, int gapsize)
////Grid grid(10, 2, 0);
//
//Grid grid("Grid2.txt", 2, 1);
//SpaceShip Ship(grid, 4);
//vector <Bullet> clip;
//
//string TITLE;
//
////Vaccum Vac(grid2, 03, false);
////DFSMissile missile(grid, 35, 399);
////AStartMissile missile(grid, 20, 399);
////DFSMissile missile(grid, 0, 289);
//
//void drawAll();
//void drawGrid(Grid &grid);
//void drawShip(Grid &grid, SpaceShip &Ship);
//void drawZline();
//void drawYline();
//void drawXline();
//
//void drawGrid02(Grid &grid);
//void renderScene(void);
//void DrawVerticalLine();
//void changeSize(int w, int h);
//void DrawRightBVerticleborder();
//
////void drawMesh(Mesh &m);
//void pressKey(int key, int xx, int yy);
//void releaseKey(int key, int x, int y);
//void drawAllBullets(SpaceShip &Ship);
//void keyboardKeyUp(unsigned char key, int x, int y);
//
//void drawBullet(float x, float y, float z, float size);
//void processNormalKeys(unsigned char key, int xx, int yy);
//void drawTile(float x, float y, float z, float h, float w, float r, float g, float b);
//void mouseButton(int btn, int state, int x, int y);
//
//
////void addBullet(vector<Bullet> clip, SpaceShip Ship)
////{
////	cout << "\nCLIP SIZE:" << clip.size() << endl;
////	Bullet B;
////	B.setPosX(Ship.getPosX());
////	B.setPosY(Ship.getPosY());
////	B.setPosZ(Ship.getPosZ());
////	clip.push_back(B);
////}
////
////
////void projectBullets(vector<Bullet> clip, float bulletSpeed)
////{
////	if (clip.size() > 0)
////	for (int i = 0; i < clip.size(); i++)
////	{
////		float newpos = clip.at(i).getPosX() + bulletSpeed;
////		clip.at(i).setPosX(newpos);
////	}
////
////}
//
//int main(int argc, char **argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(1200, 100);
//	glutInitWindowSize(500, 500);
//
//
//	int x = 0;
//	int s = 0;
//	int e = 0;
//
//
//
//	cout << "SELECT: DFS[1]  or A*Search[2]\n \tENTER:";
//	cin >> x;
//
//	cout << "\n\tENTER START 1 - 399: ";
//	cin >> s;
//	cout << "\n\tENTER END 1 - 399: ";
//	cin >> e;
//
//
//
//	switch (x)
//	{
//
//	case 1:
//	{
//		DFSMissile missile(grid, s, e);
//		glutCreateWindow("DFS");
//
//		// register callbacks
//		glutDisplayFunc(renderScene);
//		glutReshapeFunc(changeSize);
//		glutIdleFunc(renderScene);
//		glutMouseFunc(mouseButton);
//		glutIgnoreKeyRepeat(1);
//
//		glutSpecialFunc(pressKey);
//		glutSpecialUpFunc(releaseKey);
//
//		glutKeyboardFunc(processNormalKeys);
//		glutKeyboardUpFunc(keyboardKeyUp);
//		// enter GLUT event processing cycle
//		glutMainLoop();
//
//		return 1;
//		break;
//	}
//	case 2:
//	{
//		AStartMissile missile(grid, s, e);
//		glutCreateWindow("A*");
//
//		// register callbacks
//		glutDisplayFunc(renderScene);
//		glutReshapeFunc(changeSize);
//		glutIdleFunc(renderScene);
//		//glutMouseFunc(mouseButton);
//		glutIgnoreKeyRepeat(1);
//
//		glutSpecialFunc(pressKey);
//		glutSpecialUpFunc(releaseKey);
//
//		glutKeyboardFunc(processNormalKeys);
//		glutKeyboardUpFunc(keyboardKeyUp);
//		// enter GLUT event processing cycle
//		glutMainLoop();
//
//		return 1;
//		break;
//	}
//	default:
//		cout << "BAD INPUT";
//
//		break;
//	}
//
//
//
//
//
//
//
//}
///////////////////////////////////////////////////////////////FUNCTION DEFINITIONS///////////////////////////////////////////////////////
//void processNormalKeys(unsigned char key, int xx, int yy)
//{
//	switch (key)
//	{
//	case 27:
//	{
//		exit(0);
//		break;
//	}
//	case 119://w
//	{
//		cout << "w";
//		VerticalMove = (0.05f); break;
//	}
//	case 97://a
//	{
//		cout << "a";
//		HorizontalMove -= 0.05; break;
//	}
//	case 115://s
//	{
//		VerticalMove = (-0.05f); break;
//	}
//	case 100://d
//	{
//		HorizontalMove = (0.05f); break;
//	}
//	}
//}
//void pressKey(int key, int xx, int yy) {
//
//	switch (key) {
//	case GLUT_KEY_LEFT: HMove = (-0.05f); break;
//	case GLUT_KEY_RIGHT: HMove = (0.05f);  break;
//	case GLUT_KEY_UP: VMove = (0.05f); break;
//	case GLUT_KEY_DOWN: VMove = (-0.05f); break;
//	}
//}
//void releaseKey(int key, int x, int y) {
//
//	switch (key) {
//	case GLUT_KEY_LEFT:
//	case GLUT_KEY_RIGHT:HMove = 0;
//		cout << "\nX:" << Ship.getPosX() << endl; ; break;
//
//
//
//	case GLUT_KEY_UP:
//	case GLUT_KEY_DOWN: VMove = 0;
//		cout << "\nY:" << Ship.getPosY() << endl; ; break;
//	}
//}
//void keyboardKeyUp(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 119://w
//	case 115:VerticalMove = 0;  break;//s
//
//	case 97://a
//	case 100:HorizontalMove = 0; break;//d
//	}
//}
//void changeSize(int w, int h) {
//
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
//void renderScene(void) {
//
//	if (VerticalMove)
//	{
//		Ship.moveShipVertical(VerticalMove);
//
//	}
//	if (HorizontalMove)
//	{
//		Ship.moveShipHorizontal(HorizontalMove);
//
//	}
//
//	if (VMove)
//	{
//		HMove--;
//
//	}
//	if (HMove)
//	{
//		HMove++;
//
//	}
//
//	Ship.projectBullets();
//
//	// Clear Color and Depth Buffers
//	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	// Reset transformations
//	glLoadIdentity();
//	// Set the camera
//	gluLookAt(
//		0.0f, //Shake and zoom out 0.0f
//		0.0, //Nods downs and zooms out0.0f,
//		50.0f, //Zoom
//		0, // SHake Head
//		0, //Nod 
//		0, //NOTHING 0.0f,
//		0,// LEAN HEAD
//		1.0f, // 1.0f  DONT KNOW
//		0.0);
//
//	//glRotatef(angle, angle, angle, 0.0f);
//	glTranslated(-30, -25, -50);
//	drawAll();
//
//
//	angle += 0.5;
//	glutSwapBuffers();
//}
//
//void drawAll()
//{
//	drawGrid02(grid);
//	drawShip(grid, Ship);
//	drawZline();
//	drawYline();
//	drawXline();
//	DrawRightBVerticleborder();
//	DrawVerticalLine();
//	drawAllBullets(Ship);
//}
//void drawGrid(Grid &grid)
//{
//	int startTile = 0;
//
//	float x = grid.getTilePosX(startTile);
//	float y = grid.getTilePosY(startTile);
//	float z = 0.0f;
//	float w = grid.getTileWidth(startTile);
//	float h = grid.getTileHeight(startTile);
//	//grid.setTileGap(1.90);
//
//	float gapR = grid.getTileGap();
//	float gapB = grid.getTileGap();
//
//	float red = 1.0;
//	float green = 1.0;
//	float blue = 1.0;
//
//	for (int r = 0; r < grid.getRow(); r++)
//	{
//		//x = 0;
//		//y += gapB;
//		for (int c = 0; c < grid.getCol(); c++)
//		{
//			/*if ((c * r) % 2 == 0)
//			{
//			red = 0.0f;
//			}*/
//			drawTile(x, y, z, w, h, red, green, blue);
//			//x += gapR;
//		}
//	}
//}
//void drawGrid02(Grid &grid)
//{
//	for (int i = 0; i < (grid.getRow() * grid.getCol()); i++)
//	{
//		int red = 0, green = 0, blue = 0;
//		char val = grid.getTileValue(i);
//		switch (val)
//		{
//		case 'x'://UNOWN
//		{
//			red = 1.0f;
//			green = 1.0f;
//			blue = 1.0f;
//			break;
//		}
//		case '|': //OBSTICLE
//		{
//			red = 0.0f;
//			green = 0.0f;
//			blue = 0.0f;
//			break;
//		}
//		case 'o'://SEEN
//		{
//			red = 1.0f;
//			green = 1.0f;
//			blue = 0.0f;
//			break;
//		}
//		case '-'://visited
//		{
//			red = 0.0f;
//			green = 1.0f;
//			blue = 1.0f;
//			break;
//		}
//		case '#': //GOAL
//		{
//			red = 1.0f;
//			green = 0.0f;
//			blue = 0.0f;
//
//			break;
//		}
//		case '~'://START
//		{
//			red = 0.0f;
//			green = 1.0f;
//			blue = 0.0f;
//			break;
//		}
//
//
//		}
//		drawTile
//		(
//			grid.getTilePosX(i),
//			grid.getTilePosY(i),
//			0.0f,
//			grid.getTileW(),
//			grid.getTileH(),
//			red, green, blue
//		);
//	}
//}
//void drawTile(float x, float y, float z, float h, float w, float r, float g, float b)
//
//{
//	glPushMatrix();
//	//glLoadIdentity();
//	glBegin(GL_POLYGON);
//	glColor3f(r, g, b);
//
//	glVertex3f(x, y, z);
//	glVertex3f(x + w, y, z);
//	glVertex3f(x + w, y + h, z);
//	glVertex3f(x, y + h, z);
//	glEnd();
//	glPopMatrix();
//}
//
//void drawAllBullets(SpaceShip &ship)
//{
//	if (ship.getClipSize() > 0)
//	for (int i = 0; i < ship.getClipSize(); i++)
//	{
//		cout << "BULLET DRAWN";
//		drawBullet
//		(
//			ship.getBulletPosX(i),
//			ship.getBulletPosY(i),
//			ship.getBulletPosZ(i),
//			1
//		);
//	}
//}
//void drawBullet(float x, float y, float z, float size)
//{
//	drawTile
//	(
//		x,
//		y,
//		z,
//		size,
//		size,
//		1.0f, 0.0, 0.0
//	);
//}
//void drawShip(Grid &grid, SpaceShip &Ship)
//{
//	drawTile
//	(
//		Ship.getPosX(),
//		Ship.getPosY(),
//		Ship.getPosZ(),
//		grid.getTileH(),
//		grid.getTileW(),
//		1.0f, 0.1, 1.0
//	);
//
//}
//void drawZline()
//{
//	glPushMatrix();
//	glBegin(GL_LINES);
//	glColor3f(0, 1, 0);//green
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 10);
//	glEnd();
//	glPopMatrix();
//}
//void drawXline()
//{
//	glPushMatrix();
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0);//red
//	glVertex3f(0, 0, 0);
//	glVertex3f(10, 0, 0);
//	glEnd();
//	glPopMatrix();
//}
//void drawYline()
//{
//	glPushMatrix();
//	glBegin(GL_LINES);
//	glColor3f(0, 0, 1);//blue
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 10, 0);
//	glEnd();
//	glPopMatrix();
//}
//void DrawRightBVerticleborder()
//{
//	glPushMatrix();
//	glBegin(GL_LINES);
//	glColor3f(1, 1, 1);//blue
//	glVertex3f(2, 0, 0);
//	glVertex3f(2, 1.5, 0);
//	glEnd();
//	glPopMatrix();
//
//}
//void DrawVerticalLine()
//{
//	glPushMatrix();
//	glBegin(GL_LINES);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 0, 0);
//	glVertex3f(1, 1.5, 0);
//	glEnd();
//	glPopMatrix();
//
//}
//void mouseButton(int btn, int state, int x, int y) {
//	
//	switch (btn) 
//	{
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN) 
//		{
//			Ship.addBullet();
//		}
//		break;
//	}
//
//};