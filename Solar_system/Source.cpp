
//#include "Testing_freeGLUT.h"
#include <glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "imageloader.h"
#include <Windows.h>


using namespace std;


class Planet {
public:
	float radius, distance, orbit, orbitSpeed, axisTilt, axisAni;
	Planet(float radius, float distance, float orbit, float orbitSpeed, float axisTilt, float axisAni) {
		this->radius = radius;
		this->distance = distance;
		this->orbit = orbit;
		this->orbitSpeed = orbitSpeed;
		this->axisTilt = axisTilt;
		this->axisAni = axisAni;
	}

};


unsigned int loadTexture(Image* image) {
	unsigned int textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}


/*Sun and planets declaration*/
Planet sun(5.0, 0, 0, 0, 0, 0);
unsigned int sunTexture;
Planet earth(2.0, 16, 0, 2.98, 23.44, 0); //3
unsigned int earthTexture;
Planet moon(0.40, 3, 0, 5.40, 0, 0);
unsigned int moonTexture;
Planet mercury(1.0, 7, 0, 4.74, 02.11, 0); //1
unsigned int mercuryTexture;
Planet venus(1.5, 11, 0, 3.50, 177.0, 0); //2
unsigned int venusTexture;
Planet mars(1.2, 21, 0, 2.41, 25.00, 0); //4
unsigned int marsTexture;
Planet jupiter(3.5, 28, 0, 1.31, 03.13, 0); //5
unsigned int jupiterTexture;
Planet saturn(3.0, 37, 0, 0.97, 26.70, 0); //6
unsigned int saturnTexture;
Planet uranus(2.5, 45.5, 0, 0.68, 97.77, 0); //7
unsigned int uranusTexture;
Planet neptune(2.3, 53.6, 0, 0.54, 28.32, 0); //8
unsigned int neptureTexture;
//background
unsigned int bgTexture;


void loading_textures(){
	cout << "loading textures ..." << endl;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	//background
	//bgTexture = loadTexture(loadBMP("textures/stars-bg.bmp"));


	//planets
	sunTexture = loadTexture(loadBMP("textures/2k-sun.bmp"));
	mercuryTexture = loadTexture(loadBMP("textures/2k-mercury.bmp"));
	venusTexture = loadTexture(loadBMP("textures/2k-venus-atmosphere.bmp"));
	earthTexture = loadTexture(loadBMP("textures/peter2k.bmp"));
	marsTexture = loadTexture(loadBMP("textures/2k-mars.bmp"));
	jupiterTexture = loadTexture(loadBMP("textures/2k-jupiter.bmp"));
	saturnTexture = loadTexture(loadBMP("textures/2k-saturn.bmp"));
	uranusTexture = loadTexture(loadBMP("textures/2k-uranus.bmp"));
	neptureTexture = loadTexture(loadBMP("textures/2k-neptune.bmp"));

	//moon
	moonTexture = loadTexture(loadBMP("textures/2k-moon.bmp"));


	cout << "textures loaded" << endl;
}


void graphicScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(GLdouble eyeX,GLdouble eyeY,GLdouble eyeZ,GLdouble centerX,GLdouble centerY,GLdouble centerZ,GLdouble upX,GLdouble upY,GLdouble upZ);
	gluLookAt(0.0, 10.0, 80.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//viewport
	//gluLookAt(0.0, 50.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	GLUquadric *quadric;
	quadric = gluNewQuadric();

	//cout << sun.radius << endl;

	//Sun
	//cout << "loading sun" << endl;
	glPushMatrix();
	//glRotatef(sun.orbit, 0.0, 1.0, 0.0);
	glTranslatef(sun.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(sun.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(sun.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90+180.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, sunTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//minifiying texture quality
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, sun.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	sun.axisAni += 1;


	//Mercury
	//cout << "loading mercury" << endl;
	glPushMatrix();
	glRotatef(mercury.orbit, 0.0, 1.0, 0.0);
	glTranslatef(mercury.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(mercury.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(mercury.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mercuryTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, mercury.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	mercury.orbit += mercury.orbitSpeed;
	mercury.axisAni += 10;

	//Venus
	//cout << "loading venus" << endl;
	glPushMatrix();
	glRotatef(venus.orbit, 0.0, 1.0, 0.0);
	glTranslatef(venus.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(venus.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(venus.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0+180, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, venusTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //used for low quality ones
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, venus.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	venus.orbit += venus.orbitSpeed;
	venus.axisAni += 10;

	//Earth
	//cout << "loading earth" << endl;
	glPushMatrix();
	glRotatef(earth.orbit, 0.0, 1.0, 0.0);
	glTranslatef(earth.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(earth.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(earth.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0+180, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, earthTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, earth.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	


	glPushMatrix();
	//glColor3ub(255, 255, 255);
	glRotatef(moon.orbit, 0.0, 1.0, 0.0);
	glTranslatef(moon.distance, 0.0, 0.0);
	
	//glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, moonTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, moon.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPopMatrix();//earth pop matrix
	earth.orbit += earth.orbitSpeed;
	earth.axisAni += 10;


	//Mars
	//cout << "loading mars" << endl;
	glPushMatrix();
	glRotatef(mars.orbit, 0.0, 1.0, 0.0);
	glTranslatef(mars.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(mars.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(mars.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, marsTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, mars.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	mars.orbit += mars.orbitSpeed;
	mars.axisAni += 10;


	//Jupiter
	//cout << "loading jupiter" << endl;
	glPushMatrix();
	glRotatef(jupiter.orbit, 0.0, 1.0, 0.0);
	glTranslatef(jupiter.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(jupiter.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(jupiter.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, jupiterTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, jupiter.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	jupiter.orbit += jupiter.orbitSpeed;
	jupiter.axisAni += 10;


	//Saturn
	//cout << "loading saturn" << endl;
	glPushMatrix();
	glRotatef(saturn.orbit, 0.0, 1.0, 0.0);
	glTranslatef(saturn.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(saturn.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(saturn.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, saturnTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, saturn.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	saturn.orbit += saturn.orbitSpeed;
	saturn.axisAni += 10;


	//Uranus
	//cout << "loading uranus" << endl;
	glPushMatrix();
	glRotatef(uranus.orbit, 0.0, 1.0, 0.0);
	glTranslatef(uranus.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(uranus.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(uranus.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, uranusTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, uranus.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	uranus.orbit += uranus.orbitSpeed;
	uranus.axisAni += 10;


	//Neptune
	//cout << "loading neptune" << endl;
	glPushMatrix();
	glRotatef(neptune.orbit, 0.0, 1.0, 0.0);
	glTranslatef(neptune.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(neptune.axisTilt, 1.0, 0.0, 0.0); //Planet default tilt
	glRotatef(neptune.axisAni, 0.0, 1.0, 0.0); //Animation on its vertical axis rotation
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, neptureTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, neptune.radius, 20.0, 20.0);//sphere
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	neptune.orbit += neptune.orbitSpeed;
	neptune.axisAni += 10;


	glutSwapBuffers();

	glutPostRedisplay();
	Sleep(30);
	
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{
	int size = 600;

	std::cout << "PGRa_final-project..." << std::endl;
	// test(argc, argv);
	glutInit(&argc, argv);

	glutInitWindowSize(size, size);
	glutInitWindowPosition(600, 0);
	glutCreateWindow("PGRa_final-project");
	glutDisplayFunc(graphicScene);
	glutReshapeFunc(resize);
	glewInit();


	loading_textures();
	glutMainLoop();
}
