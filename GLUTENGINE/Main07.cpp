//#include "cGameManager.h"
//#include "cGrid.h";
//#include "cMesh.h"
//#include "cShader.h"
//#include "cTexture.h"
//#include "SpaceShip.h"
//#include "cVaccum.h"
//#include "cDFSMissile.h"
//#include "AStarMissile.h"
//#include "cBullet.h"
//#include "BASICSHADER.h"
//#include "cManagerAsteroid.h"
//#include"cObjectLoader.h"
//#include <FG\glut.h>
//#include <assimp\cimport.h>
//#include <assimp\scene.h>
//#include <assimp\postprocess.h>
//
//using namespace std;
//
//int WIDTH = 1280;
//int HEIGHT = 768;
//enum Pages
//{
//	PAGE_MAIN_MENU,
//	PAGE_GAME_RENDER,
//	PAGE_OPTION_MENU,
//	PAGE_LOAD_MENU,
//	PAGE_INGAME_MENU,
//	PAGE_GAME_OVER
//};
//
//int page = PAGE_MAIN_MENU;
//
////GLOABAL VERABLES
//float angle = 0.0f;
//float deltaMove = 0.0f;
//float HorizontalMove = 0.0f;
//float VerticalMove = 0.0f;
//
//float HMove = 0.0f;
//float VMove = 0.0f;
//
//GameManager GM;
////Grid grid("Grid2.txt", 2, 1);
////SpaceShip Ship(grid, 4);
////ManagerAsteroid MA(grid);
//const aiScene *model = aiImportFile("./res/meshes/SpaceShip.obj", aiProcessPreset_TargetRealtime_Fast);
//
//string TITLE;
//
//std::vector < glm::vec3 > vertices;
//std::vector < glm::vec2 > uvs;
//std::vector < glm::vec3 > normals;
//
//void drawShip02(Grid &grid, SpaceShip &Ship);
//void update();
//void drawMenu();
//void drawOptions();
//void drawGame();
//void drawGameOver();
//void drawInGameMenu();
//void drawHighlight();
//void drawAsteroids(ManagerAsteroid MA);
//void drawShipHealthBar(SpaceShip &Ship);
//void drawAxis();
//void drawAll();
//
//void drawZline();
//void drawYline();
//void drawXline();
//
//void renderScene(void);
//void DrawVerticalLine();
//void drawGrid02(Grid &grid);
//void changeSize(int w, int h);
//void DrawRightBVerticleborder();
//void drawGrid(Grid &grid);
//void drawShip(Grid &grid, SpaceShip &Ship);
//
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
//int main(int argc, char **argv)
//{
//
//	ObjectLoader Loader;
//	Loader.loadOBJ("./res/meshes/HM3.obj", vertices, uvs, normals);
//	//cout <<"# MODELS:" <<model->mNumMeshes << endl; 
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(500, 10);
//	glutInitWindowSize(WIDTH, HEIGHT);
//	glutCreateWindow("GAME");
//	glewInit();
//
//	//BasicShader BS("1");
//	//Ship.InitDraw();
//	// register callbacks
//	glutDisplayFunc(renderScene);
//	glutReshapeFunc(changeSize);
//	glutIdleFunc(renderScene);
//	glutMouseFunc(mouseButton);
//	glutIgnoreKeyRepeat(1);
//
//	glutSpecialFunc(pressKey);
//	glutSpecialUpFunc(releaseKey);
//
//	glutKeyboardFunc(processNormalKeys);
//	glutKeyboardUpFunc(keyboardKeyUp);
//	// enter GLUT event processing cycle
//	glutMainLoop();
//
//	return 1;
//
//}
///////////////////////////////////////////////////////////////FUNCTION DEFINITIONS///////////////////////////////////////////////////////
//void renderScene(void) {
//
//	update();
//	// Clear Color and Depth Buffers	
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
//
//	switch (GM.getPage())
//	{
//
//
//	case 0:
//	{
//		glViewport(0.0, 0.0, WIDTH, HEIGHT);
//		glClearColor(0.2f, 1.0f, 1.0f, 1.0f);
//		glLoadIdentity();
//		gluLookAt(
//			0.0f, //Shake and zoom out 0.0f
//			0.0, //Nods downs and zooms out0.0f,
//			30.0f, //Zoom
//			0, // SHake Head
//			0, //Nod 
//			0, //NOTHING 0.0f,
//			0,// LEAN HEAD
//			1.0f, // 1.0f  DONT KNOW
//			0.0);
//
//		glTranslated(-50, -30, -50);
//		drawHighlight();
//		drawMenu();
//		drawAxis();
//
//		break;
//	}
//	case 1:
//	{
//		glViewport(0.0, 0.0, WIDTH, HEIGHT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glLoadIdentity();
//		gluLookAt(
//			0.0f, //Shake and zoom out 0.0f
//			0.0, //Nods downs and zooms out0.0f,
//			50.0f, //Zoom
//			0, // SHake Head
//			0, //Nod 
//			0, //NOTHING 0.0f,
//			0,// LEAN HEAD
//			1.0f, // 1.0f  DONT KNOW
//			0.0);
//
//
//		glTranslated(-30, -25, -50);
//		drawAll();
//		break;
//	}
//	case 4:
//	{
//		glViewport(0.0, 0.0, WIDTH, HEIGHT);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glLoadIdentity();
//		gluLookAt(
//			0.0f, //Shake and zoom out 0.0f
//			0.0, //Nods downs and zooms out0.0f,
//			30.0f, //Zoom
//			0, // SHake Head
//			0, //Nod 
//			0, //NOTHING 0.0f,
//			0,// LEAN HEAD
//			1.0f, // 1.0f  DONT KNOW
//			0.0);
//		glTranslated(-50, -30, -50);
//		drawHighlight();
//		drawMenu();
//		drawAxis();
//		break;
//	}
//
//	}
//
//	glutSwapBuffers();
//}
//void processNormalKeys(unsigned char key, int xx, int yy)
//{
//	switch (GM.getPage())
//	{
//	case PAGE_MAIN_MENU:
//	{
//		switch (key)
//		{
//		case 27:
//		{
//			exit(0);
//			break;
//		}
//		case 32: // SPACEBAR
//		{
//			GM.Action(GM.getButtons().at(GM.getCurrentButton()).getAction());
//			GM.setPage(GM.getButtons().at(GM.getCurrentButton()).getAction());
//			break;
//
//		}
//		case 119://w
//		{
//			GM.HighlightUp(GM.getButtons());
//
//			break;
//		}
//		case 115://s
//		{
//			GM.HighlightDown(GM.getButtons());
//			break;
//		}
//
//		}
//		break;
//	}
//	case PAGE_GAME_RENDER:
//	{
//		switch (key)
//		{
//			case 27:
//			{
//				GM.Action(4);
//				GM.setPage(4);
//				break;
//			}
//			case 119://w
//			{
//				cout << "w";
//				VerticalMove = (1.3f); break;
//			}
//			case 97://a
//			{
//				cout << "a";
//				HorizontalMove -= 1.3; break;
//			}
//			case 115://s
//			{
//				VerticalMove = (-1.3f); break;
//			}
//			case 100://d
//			{
//				HorizontalMove = (1.3f); break;
//			}			
//		}
//		break;
//	}
//	case PAGE_INGAME_MENU:
//	{
//		switch (key)
//		{
//		case 32: // SPACEBAR
//		{
//			GM.setPage(GM.getButtons().at(GM.getCurrentButton()).getAction());
//			GM.setPage(GM.getButtons().at(GM.getCurrentButton()).getAction());
//			break;
//		}
//		case 119://w
//		{
//			GM.HighlightUp(GM.getButtons());
//			break;
//		}
//
//		case 115://s
//		{
//			GM.HighlightDown(GM.getButtons());
//			break;
//		}
//
//		}
//		break;
//
//	}
//	case PAGE_OPTION_MENU:
//		break;
//	case PAGE_GAME_OVER:
//		break;
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
//
//
//	switch (key) {
//	case GLUT_KEY_LEFT:
//	case GLUT_KEY_RIGHT:HMove = 0;
//		cout << "\nX:" << GM.getShip().getPosX() << endl; ; break;
//
//
//
//	case GLUT_KEY_UP:
//	case GLUT_KEY_DOWN: VMove = 0;
//		cout << "\nY:" << GM.getShip().getPosY() << endl; ; break;
//	}
//}
//void keyboardKeyUp(unsigned char key, int x, int y)
//{
//	switch (GM.getPage())
//	{
//	case PAGE_INGAME_MENU:
//		break;
//	case PAGE_OPTION_MENU:
//		break;
//	case PAGE_GAME_OVER:
//		break;
//	case PAGE_MAIN_MENU:
//		break;
//	case PAGE_GAME_RENDER:
//		switch (key)
//		{
//		case 119://w
//		case 115:VerticalMove = 0;  break;//s
//
//		case 97://a
//		case 100:HorizontalMove = 0; break;//d
//		}
//		break;
//	}
//}
//void changeSize(int w, int h) {
//
//	//if (h == 0)
//	//	h = 1;
//
//	float ratio = WIDTH * 1.0 / HEIGHT;
//
//	//// Use the Projection Matrix
//	glMatrixMode(GL_PROJECTION);
//
//	//// Reset Matrix
//	glLoadIdentity();
//
//	//// Set the viewport to be the entire window
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	//// Set the correct perspective.
//	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
//
//	//// Get Back to the Modelview
//	glMatrixMode(GL_MODELVIEW);
//
//	glutReshapeWindow(WIDTH, HEIGHT);
//
//}
//
//void drawAll()
//{
//
//	//drawGrid02(GM.getGrid());
//	//drawShip(GM.getGrid(), GM.getShip());
//	drawZline();
//	drawYline();
//	drawXline();
//	DrawRightBVerticleborder();
//	DrawVerticalLine();
//	drawAllBullets(GM.getShip());
//	drawAsteroids(GM.getAsteroidManager());
//	drawShipHealthBar(GM.getShip());
//	drawShip02(GM.getGrid(), GM.getShip());
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
//	if (ship.getClip().size() > 0)
//	{
//
//		for (int i = 0; i < ship.getClip().size(); i++)
//		{
//			drawBullet
//			(
//				ship.getClip().at(i).getPosX(),
//				ship.getClip().at(i).getPosY(),
//				ship.getClip().at(i).getPosZ(),
//				1
//			);
//		}
//	}
//}
//void drawAsteroids(ManagerAsteroid MA)
//{
//
//	if (MA.getClusterSize() > 0)
//		for (int i = 0; i < MA.getClusterSize(); i++)
//		{
//			drawBullet
//			(
//				MA.getAsteroidPosX(i),
//				MA.getAsteroidPosY(i),
//				MA.getAsteroidPosZ(i),
//				2
//			);
//		}
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
//
//void drawShipHealthBar(SpaceShip &Ship)
//{
//	
//	drawTile
//	(
//		Ship.getHitSum()+ 40,
//		60,
//		0,
//		3,
//		Ship.getHealth(),
//		1.0f, 0.2, 0.2
//	);
//
//}
//void drawShip(Grid &grid, SpaceShip &Ship)
//{
//	if (Ship.isActive())
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
//void update()
//{
//
//	switch (GM.getPage())
//	{
//	case PAGE_INGAME_MENU:
//		break;
//	case PAGE_OPTION_MENU:
//		break;
//	case PAGE_GAME_OVER:
//		break;
//	case PAGE_MAIN_MENU:
//		break;
//	case PAGE_GAME_RENDER:
//	{
//		if (VerticalMove)
//		{
//			GM.getShip().moveShipVertical(VerticalMove);
//
//		}
//		else
//			if (HorizontalMove)
//			{
//				GM.getShip().moveShipHorizontal(HorizontalMove);
//
//			}
//
//		if (VMove)
//		{
//			HMove--;
//
//		}
//		if (HMove)
//		{
//			HMove++;
//
//		}
//		GM.Update();
//
//		break;
//	}
//	}
//
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
//			GM.getShip().addBullet();
//		}
//		break;
//	}
//
//};
//
//void draw2DRect(float x, float y, float z, float w, float h, float r, float g, float b)
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
//
//}
//
//void drawAxis()
//{
//	drawZline();
//	drawYline();
//	drawXline();
//
//}
//void drawHighlight()
//{
//
//	draw2DRect
//	(
//		GM.getButtonHL().getPosX(),
//		GM.getButtonHL().getPosY(),
//		GM.getButtonHL().getPosZ(),
//
//		GM.getButtonHL().getWidth(),
//		GM.getButtonHL().getHeight(),
//
//		GM.getButtonHL().getCr(),
//		GM.getButtonHL().getCg(),
//		GM.getButtonHL().getCb()
//	);
//
//}
//void drawMenu()
//{
//	for (int i = 0; i < GM.getButtons().size(); i++)
//	{
//		draw2DRect
//		(
//			GM.getButtons().at(i).getPosX(),
//			GM.getButtons().at(i).getPosY(),
//			GM.getButtons().at(i).getPosZ(),
//
//			GM.getButtons().at(i).getWidth(),
//			GM.getButtons().at(i).getHeight(),
//
//			GM.getButtons().at(i).getCr(),
//			GM.getButtons().at(i).getCg(),
//			GM.getButtons().at(i).getCb()
//		);
//	}
//}
//void drawOptions();
//void drawGame();
//void drawGameOver();
//void drawInGameMenu();
//
//void drawShip02(Grid &grid, SpaceShip &Ship)
//{
//	
//	glPushMatrix();
//	glColor3f(0.02, 0.5, 0.27);
//	glTranslatef(Ship.getPosX(), Ship.getPosY(), Ship.getPosZ());
//	glRotatef(90.0, 1.0, 0.0, 0.0f);
//	glRotatef(180.0, 0.0, 1.0, 0.0f);
//	glBegin(GL_TRIANGLES);		
//	for (int i = 0; i < vertices.size(); i++)
//		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//	glEnd();
//	
//
//
//	glPopMatrix();
//
//}