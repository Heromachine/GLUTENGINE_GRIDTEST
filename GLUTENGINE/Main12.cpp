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
//
//#include <FG\glut.h>
//
//#include <assimp\cimport.h>
//#include <assimp\scene.h>
//#include <assimp\postprocess.h>
//
//#include "stb_Image.h"
//#include "cModel.h"
//
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
//GLOABAL VERABLES
//float angle = 0.0f;
//float deltaMove = 0.0f;
//float HorizontalMove = 0.0f;
//float VerticalMove = 0.0f;
//
//float HMove = 0.0f;
//float VMove = 0.0f;
//float rot = 0;
//GameManager GM;
//ObjectLoader Loader;
//
//
////////////////////////////////////////////////
//std::vector < glm::vec3 > vertices;
//std::vector < glm::vec2 > uvs;
//std::vector < glm::vec3 > normals;
//
//
//std::vector < glm::vec3 > vertices1;
//std::vector < glm::vec2 > uvs1;
//std::vector < glm::vec3 > normals1;
//
//
//std::vector < glm::vec3 > vertices2;
//std::vector < glm::vec2 > uvs2;
//std::vector < glm::vec3 > normals2;
//
//Model3D modelA;
//
//Shader Shade;
//Mesh Ship;
//Texture2D Skin;
//Texture2D BackGroundSkin;
//
//Model3D HM3("./res/meshes/HM3.obj");
//
//
//
//Texture2D ShipSkin("./res/textures/HM3_03.bmp");
//Transform Trans;
//Camera camera;
///////////////////////////////////////
//string TITLE;
//
//
//void update();
//void drawMenu();
//void drawOptions();
//void drawGame();
//void drawGameOver();
//void drawInGameMenu();
//void drawHighlight();
//void drawAsteroids(ManagerAsteroid MA);
//void drawMesh();
//void drawShipHealthBar(SpaceShip &Ship);
//void drawAxis();
//void drawAll();
//
//void drawZline();
//void drawYline();
//void drawXline();
//
//void initRendering();
//void renderScene(void);
//void DrawVerticalLine();
//void drawGrid02(Grid &grid);
//void changeSize(int w, int h);
//void DrawRightBVerticleborder();
//void drawGrid(Grid &grid);
//void drawShip(Grid &grid, SpaceShip &Ship);
//void drawShipLite(Texture2D & T2D,  SpaceShip &Ship);
//void drawModel(Texture2D & T2D, Model3D Mod, float scale, SpaceShip &Ship);
//
//
//
///////////////////////////////////////////////////////////////////////
//void drawModelAsteroids(Texture2D & T2D, int i, ManagerAsteroid &MA);
//void drawAsteroid(Texture2D &T2D);
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
//void lightPositional();
//void lightDirectional();
//void LightsAmbient();
//
//void drawShipMenu(Texture2D & T2D);
//void processRot();
//
//
//void drawTexturedPlane(float x, float y, float z, Texture2D & T2D, int texture, float scale,  float w, float h)
//{
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_FRONT);
//	glFrontFace(GL_CW);
//
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	T2D.Bind(texture);
//
//	
//	glColor3f(1, 1, 1);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);    glVertex3f(x, y + h, z);
//	glTexCoord2f(1, 0);    glVertex3f(x + w, y + h, z);
//	glTexCoord2f(1, 1);    glVertex3f(x + w, y, z);
//	glTexCoord2f(0, 1);    glVertex3f(x, y, z);
//	glEnd();
//	
//
//	glDisable(GL_CULL_FACE);
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//}
//
//void DrawMesh(Model3D &mod, Texture2D &skin, int b, float scale, float posX, float posY, float posZ)
//{
//
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CW);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//
//	glTranslatef(posX, posY, posZ);
//	glRotatef(rot, 0.0, 1, 0.0f);
//	glRotatef(rot, 1, 0.0, 0.0f);
//
//	glScalef(scale, scale, scale);
//	glColor3f(1, 1, 1);
//	skin.Bind(b);
//
//	glBegin(GL_TRIANGLES);
//	mod.DrawMesh();
//	glEnd();
//	glPopMatrix();
//
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(500, 50);
//	glutInitWindowSize(WIDTH, HEIGHT);
//	glutCreateWindow("GAME");
//	glewInit();
//	initRendering();
//
//	TEST
//
//	Loader.loadOBJ("./res/meshes/HM3.obj", vertices, uvs, normals);
//	Loader.loadOBJ("./res/meshes/Asteroid001.obj", vertices1, uvs1, normals1);
//	Loader.loadOBJ("./res/meshes/HM3_04.obj", vertices2, uvs2, normals2);
//
//
//	Skin.InitText02("./res/textures/CUBE.png");//0
//	Skin.InitText02("./res/textures/Bay.png");//1
//	Skin.InitText02("./res/textures/Play.png");//2
//	Skin.InitText02("./res/textures/Exit.png");//3
//	Skin.InitText02("./res/textures/SkysharkAqua.png");//4
//	Skin.InitText02("./res/textures/AsteroidText.jpg");//5
//	Skin.InitText02("./res/textures/AUV002.png");//6
//	Skin.InitText02("./res/textures/BG.jpg");//7
//	Skin.InitText02("./res/textures/HM3.png");//8
//
//	modelA.initModel("./res/meshes/HM3.obj");
//
//	 register callbacks
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
//	 enter GLUT event processing cycle
//	glutMainLoop();
//
//	return 1;
//
//}
/////////////////////////////////////////////////////////////FUNCTION DEFINITIONS///////////////////////////////////////////////////////
//void renderScene(void) {
//
//	update();
//
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	LightsAmbient();
//
//	switch (GM.getPage())
//	{
//
//
//	case 0: //MAIN MENU
//	{
//		glViewport(0.0, 0.0, WIDTH, HEIGHT);
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
//
//		
//		lightDirectional();
//		lightPositional();
//		LightsAmbient();
//		drawHighlight();		
//		drawAxis();
//		drawTile(23, 54, -5, 12, 100, 0.0, 1.749, 2);
//		drawTexturedPlane(25, 55, -4, Skin, 4, .5, 50, 9);//SKYSHARK LOGO
//		drawTexturedPlane(0, 0, -6, Skin, 1, .5, 100, 90);
//		
//		drawTexturedPlane
//		(
//			GM.getButtons().at(0).getPosX(),
//			GM.getButtons().at(0).getPosY(),
//			GM.getButtons().at(0).getPosZ(),
//			Skin,
//			2,
//			.5,
//			GM.getButtons().at(0).getWidth()-10,
//			GM.getButtons().at(0).getHeight()
//		);
//		drawTexturedPlane
//		(
//			GM.getButtons().at(2).getPosX(),
//			GM.getButtons().at(2).getPosY(),
//			GM.getButtons().at(2).getPosZ(),
//			Skin,
//			3,
//			.5,
//			GM.getButtons().at(2).getWidth() - 10,
//			GM.getButtons().at(2).getHeight()
//		);
//
//		
//		drawShipMenu(Skin);
//		drawMenu();
//		drawHighlight();
//		DrawMesh(CUBE, Skin, 9, 1, 35, 25, -2);
//		DrawMesh(HM3, Skin, 8, 1, 35, 25, -2 );
//		break;
//	}
//	case 1: //GAME
//	{
//		glViewport(0.0, 0.0, WIDTH, HEIGHT);
//		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//		glLoadIdentity();
//		LightsAmbient();
//		
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
//		glTranslated(-25, -30, -65);
//		lightDirectional();
//		lightPositional();
//		drawAll();
//		drawAxis();
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
//
//void drawMesh(Model3D Mod)
//{
//	float scale = 10.0;
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_FRONT);
//	glFrontFace(GL_CW);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//
//	glTranslatef(55, 20, -2);
//	glRotatef(rot, 0.0, 1, 0.0f);
//	glRotatef(rot, 1, 0.0, 0.0f);
//
//	glScalef(scale, scale, scale);
//	glColor3f(1, 1, 1);
//	Skin001.Bind();
//
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < vertexIndices.size(); i++) {
//
//		glTexCoord2f(uvs[uvIndices[i] - 1].x, uvs[uvIndices[i] - 1].y);
//		glVertex3f(vertices[vertexIndices[i] - 1].x, vertices[vertexIndices[i] - 1].y, vertices[vertexIndices[i] - 1].z);
//		glNormal3f(normals[normalIndices[i] - 1].x, normals[normalIndices[i] - 1].y, normals[normalIndices[i] - 1].z);
//
//	}
//	glEnd();
//	glPopMatrix();
//
//}
//void drawShipMenu(Texture2D & T2D)
//{
//	float scale = 15.0;
//
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//
//
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CW);
//	glEnable(GL_TEXTURE_2D);
//
//	glColor3f(1, 1, 1);
//	glTranslatef(50, 25, 0);
//	glRotatef(rot, 0.0, 1.0, 0.0f);
//	glScalef(scale, scale, scale);
//	T2D.Bind(0);
//	glBegin(GL_TRIANGLES);
//
//
//	for (int i = 0; i < vertices.size(); i++)
//	{
//		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//		glTexCoord2f(uvs[i].x, uvs[i].y);
//		glNormal3f(normals.at(i).x, normals.at(i).y, normals.at(i).z);
//	}
//
//	glEnd();
//	glDisable(GL_CULL_FACE);
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//
//
//}
//void drawShipGame(Texture2D & T2D)
//{
//	float scale = 20.0;
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CW);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	T2D.Bind(0);
//
//
//	glColor3f(1, 1, 1);
//	glTranslatef(50, 25, 0);
//	glRotatef(-25, 0.0, 1.0, 0.0f);
//	glScalef(scale, scale, scale);
//
//	glBegin(GL_TRIANGLES);
//
//
//	for (int i = 0; i < vertices.size(); i++)
//	{
//		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//		glTexCoord2f(uvs[i].x, uvs[i].y);
//		glNormal3f(normals.at(i).x, normals.at(i).y, normals.at(i).z);
//
//
//	}
//
//	glEnd();
//
//	glDisable(GL_CULL_FACE);
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//}
//void drawModel(Texture2D & T2D, Model3D Mod, float scale, SpaceShip &Ship)
//{
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CW);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	T2D.Bind(0);
//
//
//	
//
//
//	glColor3f(0.02, 0.5, 0.27);
//	glTranslatef(Ship.getPosX(), Ship.getPosY(), Ship.getPosZ());
//	glRotatef(rot, 0.0, 1.0, 0.0f);
//	glScalef(scale, scale, scale);
//
//
//
//	//glBindVertexArray(Mod.getVAO());
//	//glDrawElements(GL_TRIANGLES, Mod.getDrawCount(), GL_UNSIGNED_INT, 0);
//	////glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
//	//glBindVertexArray(0);
//
//	glBegin(GL_POLYGON);
//	//cout << "\nMODEL: " << endl;
//	//cout << "VERT SIZE:" << Mod.getModel().positions.size() <<endl ;
//	//cout << "TEXT SIZE:" << Mod.getModel().texCoords.size() << endl;
//	//cout << "NORM SIZE:" << Mod.getModel().normals.size() << endl;
//
//	for (int i = 0; i < Mod.getModel().positions.size(); i++)
//	{
//		
//		glVertex3f(Mod.getModel().positions.at(i).x, Mod.getModel().positions.at(i).y, Mod.getModel().positions.at(i).z);
//		glTexCoord2f(Mod.getModel().texCoords.at(i).x, Mod.getModel().texCoords.at(i).y);
//		//glNormal3f(Mod.getModel().normals.at(i).x, Mod.getModel().normals.at(i).y, Mod.getModel().normals.at(i).z);		
//	}
//
//
//	glEnd();
//
//
//	
//	//aglDisable(GL_CULL_FACE);
//	//glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//}
//void drawShipLite(Texture2D & T2D, SpaceShip &Ship)
//{
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CW);
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	Skin.Bind(0);
//
//	
//	glColor3f(0.02, 0.5, 0.27);
//	glTranslatef(Ship.getPosX(), Ship.getPosY(), Ship.getPosZ());
//	glScalef(.3, .3, .3);
//	glRotatef(90.0, 1.0, 0.0, 0.0f);
//	glRotatef(180.0, 0.0, 1.0, 0.0f);
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < vertices2.size(); i++)
//	{
//
//		glVertex3f(vertices2[i].x, vertices2[i].y, vertices2[i].z);
//		glTexCoord2f(uvs2[i].x, uvs2[i].y);
//		glNormal3f(normals2.at(i).x, normals2.at(i).y, normals2.at(i).z);
//	}
//	glEnd();
//	
//	
//	glDisable(GL_CULL_FACE);
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//}
//
//void drawAsteroid(Texture2D & T2D)
//{
//
//	glPushMatrix();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_FRONT);
//	glFrontFace(GL_CW);
//	
//	glEnable(GL_TEXTURE_2D);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	T2D.Bind(6);
//	glColor3f(1, 1, 1);	
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < vertices1.size(); i++)
//	{
//		glVertex3f(vertices1[i].x, vertices1[i].y, vertices1[i].z);
//		glTexCoord2f(uvs1[i].x, uvs1[i].y);
//		glNormal3f(normals1.at(i).x, normals1.at(i).y, normals1.at(i).z);
//	}
//	glEnd();
//	glDisable(GL_CULL_FACE);
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//}
//void drawModelAsteroids(Texture2D & T2D, int i,  ManagerAsteroid &MA)
//{
//	if (MA.getClusterSize() > 0)
//	{
//
//		for (int i = 0; i < MA.getClusterSize(); i++)
//		{			
//
//			glPushMatrix();
//			glTranslatef(MA.getAsteroidPosX(i), MA.getAsteroidPosY(i), MA.getAsteroidPosZ(i));
//			glScalef(5, 5, 5);
//			glRotatef(rot, 0.0, 1.0, 1.0f);
//			drawAsteroid(T2D);
//			glPopMatrix();
//
//		}
//	}
//
//		
//}
//void processRot()
//{
//	rot += 1;
//
//	if (rot > 360)
//		rot = 0;
//}
//void LightsAmbient()
//{
//	float light = 0.2f;
//	AMBIENT LIGHT
//	GLfloat ambientColor[] = { light, light, light, 1.0f };
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
//}
//void lightDirectional()
//{
//
//	Direction of LIght	
//	GLfloat lightColor[] = { 0.5f, 0.2f, 0.2f, 1.0 };
//	GLfloat lightColor[] = { 3, 3, 3, 1.0 };
//	GLfloat lightPos1[] = { 1.0f, 0.0f, 5.0f, -5.0f };
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
//}
//void lightPositional()
//{
//	POSITIONLIGHT
//	GLfloat diffuse0[] = { 0.5, 0.5, 0.5, 1.0 };
//	GLfloat light0_pos[] = { 4.0, 0.0, 8.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
//	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
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
//		case 27:
//		{
//			GM.Action(4);
//			GM.setPage(4);
//			break;
//		}
//		case 119://w
//		{
//			cout << "w";
//			VerticalMove = (1.3f); break;
//		}
//		case 97://a
//		{
//			cout << "a";
//			HorizontalMove -= 1.3; break;
//		}
//		case 115://s
//		{
//			VerticalMove = (-1.3f); break;
//		}
//		case 100://d
//		{
//			HorizontalMove = (1.3f); break;
//		}
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
//	if (h == 0)
//		h = 1;
//
//	float ratio = WIDTH * 1.0 / HEIGHT;
//
//	// Use the Projection Matrix
//	glMatrixMode(GL_PROJECTION);
//
//	// Reset Matrix
//	glLoadIdentity();
//
//	// Set the viewport to be the entire window
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	// Set the correct perspective.
//	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
//
//	// Get Back to the Modelview
//	glMatrixMode(GL_MODELVIEW);
//
//	glutReshapeWindow(WIDTH, HEIGHT);
//
//}
//void drawAll()
//{
//
//	drawModelAsteroids(Skin, 6, GM.getAsteroidManager());
//	drawTexturedPlane(-5, -10, -1, Skin, 7, 1, 68, 77);
//	drawShipHealthBar(GM.getShip());
//	DrawRightBVerticleborder();
//	DrawVerticalLine();
//	drawAllBullets(GM.getShip());
//	drawAsteroids(GM.getAsteroidManager());
//	drawModel(Skin, modelA, 1, GM.getShip());
//	drawShipLite(Skin, GM.getShip());
//	drawAxis();
//
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
//		x = 0;
//		y += gapB;
//		for (int c = 0; c < grid.getCol(); c++)
//		{
//			/*if ((c * r) % 2 == 0)
//			{
//			red = 0.0f;
//			}*/
//			drawTile(x, y, z, w, h, red, green, blue);
//			x += gapR;
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
//
//
//void drawTile(float x, float y, float z, float h, float w, float r, float g, float b)
//
//{
//	glPushMatrix();
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
//void drawAllBullets(SpaceShip &ship)
//{
//	if (ship.getClip().size() > 0)
//	{
//
//		for (int i = 0; i < ship.getClip().size(); i++)
//		{
//			
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
//
//
//
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
//void drawShipHealthBar(SpaceShip &Ship)
//{
//
//	drawTile
//	(
//		Ship.getHitSum() + 40,
//		60,
//		0,
//		3,
//		Ship.getHealth(),
//		1.0f, 0.2, 0.2
//	);
//
//	drawTile
//	(
//		40,
//		60,
//		0,
//		3,
//		20,
//		0.50f, 0.42, 0.12
//	);
//
//}
//void drawShip(Grid &grid, SpaceShip &Ship)
//{
//	if (Ship.isActive())
//		drawTile
//		(
//			Ship.getPosX(),
//			Ship.getPosY(),
//			Ship.getPosZ(),
//			grid.getTileH(),
//			grid.getTileW(),
//			1.0f, 0.1, 1.0
//		);
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
//		processRot();
//		break;
//	case PAGE_GAME_RENDER:
//	{
//		processRot();
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
//void draw2DRect(float x, float y, float z, float w, float h, float r, float g, float b)
//{
//	glPushMatrix();
//	glLoadIdentity();
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
//void initRendering()
//{
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glEnable(GL_NORMALIZE);
//	glShadeModel(GL_SMOOTH);
//
//}
//
//void drawOptions();
//void drawGame();
//void drawGameOver();
//void drawInGameMenu();