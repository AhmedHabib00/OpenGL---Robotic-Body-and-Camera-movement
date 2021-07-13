#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14

int moving, startx, starty;
static int upper_body = 0, left_upper_arm = 0, right_upper_arm = 0, left_lower_arm = 0, right_lower_arm = 0, left_thigh = 0, right_thigh = 0, left_leg = 0, right_leg = 0, head = 0, finger_base = 0, bottom_finger_base = 0, finger_up = 0, twist_arm = 0, left_thigh_frba = 0, right_thigh_frba = 0;



GLfloat angle = 0.0;  
GLfloat angle2 = 0.0;  


double eye[] = { 0.0, 0.0, 5.0 };
double center[] = { 0.0, 0.0, 0.0 };
double up[] = { 0.0, 1.0, 0.0 };

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(60.0,1.0,1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)upper_body, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 2.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.9, 0.25, 0.0);
	glRotatef((GLfloat)left_upper_arm, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)twist_arm, 1.0, 0.0, 0.0);
	glTranslatef(0.9, 0.25, 0.0);
	glPushMatrix();
	glScalef(1.5, 0.75, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.62, 0.0, 0.0);
	glRotatef((GLfloat)left_lower_arm, 0.0, 0.0, 1.0);
	glTranslatef(0.62, 0.0, 0.0);
	glPushMatrix();
	glScalef(1.0, 0.75, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.9, 0.25, 0.0);
	glRotatef((GLfloat)right_upper_arm, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)twist_arm, 1.0, 0.0, 0.0);
	glTranslatef(-0.9, 0.25, 0.0);
	glPushMatrix();
	glScalef(1.5, 0.75, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(-0.62, 0.0, 0.0);
	glRotatef((GLfloat)right_lower_arm, 0.0, 0.0, 1.0);
	glTranslatef(-0.62, 0.0, 0.0);
	glPushMatrix();
	glScalef(1.0, 0.75, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.25, -1.0, 0.0);
	glRotatef((GLfloat)left_thigh, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)left_thigh_frba, 1.0, 0.0, 0.0);
	glTranslatef(0.25, -1.0, 0.0);
	glPushMatrix();
	glScalef(0.7, 1.8, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef((GLfloat)left_leg, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glScalef(0.7, 1.2, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glScalef(0.5, 0.2, 1.5);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.25, -1.0, 0.0);
	glRotatef((GLfloat)right_thigh, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)right_thigh_frba, 1.0, 0.0, 0.0);
	glTranslatef(-0.25, -1.0, 0.0);
	glPushMatrix();
	glScalef(0.7, 1.8, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef((GLfloat)right_leg, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glScalef(0.7, 1.2, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glPushMatrix();
	glScalef(0.5, 0.2, 1.5);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, 0.8, 0.0);
	glRotatef((GLfloat)head, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.8, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);
	glutWireSphere(1.5, 10, 10);
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2],center[0], center[1], center[2],up[0], up[1], up[2]);

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void reset()
{
	double e[] = { 0.0, 0.0, 5.0 };
	double c[] = { 0.0, 0.0, 0.0 };
	double u[] = { 0.0, 1.0, 0.0 };
	for (int i = 0; i < 3; i++)
	{
		eye[i] = e[i];
		center[i] = c[i];
		up[i] = u[i];
	}
}



void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta)) * (a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta)) * (a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta)) * (a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta) * p[0];
	temp[1] += cos(theta) * p[1];
	temp[2] += cos(theta) * p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];
}


static void motion(int x, int y)
{
	if (moving) {
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}
}

// MOVE FUNCTIONS 

void moveForward()
{
	double direction[3];
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	float speed = 0.2;
	eye[0] += direction[0] * speed;
	eye[1] += direction[1] * speed;
	eye[2] += direction[2] * speed;

	center[0] += direction[0] * speed;
	center[1] += direction[1] * speed;
	center[2] += direction[2] * speed;
}

void moveBackword()
{
	double direction[3];
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	float speed = -0.2;
	eye[0] += direction[0] * speed;
	eye[1] += direction[1] * speed;
	eye[2] += direction[2] * speed;

	center[0] -= direction[0] * speed;
	center[1] -= direction[1] * speed;
	center[2] -= direction[2] * speed;
}

// END OF MOVE FUNCTIONS


// LOOK FUNCTIONS 

void lookRight()
{
	rotatePoint(up, PI * -8, eye);
}

void lookLeft()
{
	rotatePoint(up, PI * 8, eye);
}
void lookUp()
{
	double horizontal[3];
	double look[] = { center[0] - eye[0], center[1] - eye[1], center[2] - eye[2] };
	crossProduct(up, look, horizontal);
	normalize(horizontal);
	rotatePoint(horizontal, PI * -8, eye);
	rotatePoint(horizontal, PI * -8, up);
}
void lookDown()
{
	double horizontal[3];
	double look[] = { center[0] - eye[0], center[1] - eye[1], center[2] - eye[2] };
	crossProduct(up, look, horizontal);
	normalize(horizontal);
	rotatePoint(horizontal, PI * 8, eye);
	rotatePoint(horizontal, PI * 8, up);
}

// ENF OF LOOK FUNCTIONS
// -----------------------------------------------------------------------------------------------


void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		lookLeft();
		break;
	case GLUT_KEY_RIGHT:
		lookRight();
		break;
	case GLUT_KEY_UP:
		lookUp();
		break;
	case GLUT_KEY_DOWN:
		lookDown();
		break;
	}
	glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		if (right_upper_arm < 80)
		{
			right_upper_arm = (right_upper_arm + 5) % 360;
		}
		glutPostRedisplay();
		break;
	case 'D':
		if (right_upper_arm > -80)
		{
			right_upper_arm = (right_upper_arm - 5) % 360;

		}
		glutPostRedisplay();
		break;


	case 'c':
		if (right_lower_arm < 0)
		{
			right_lower_arm = (right_lower_arm + 5) % 360;

		};
		glutPostRedisplay();
		break;
	case 'C':
		if (right_lower_arm > -80)
		{
			right_lower_arm = (right_lower_arm - 5) % 360;

		};
		glutPostRedisplay();
		break;

	case 'a':
		if (left_upper_arm < 80)
		{
			left_upper_arm = (left_upper_arm + 5) % 360;
		}
		glutPostRedisplay();
		break;
	case 'A':
		if (left_upper_arm > -80)
		{
			left_upper_arm = (left_upper_arm - 5) % 360;

		}
		glutPostRedisplay();
		break;

	case 'z':
		if (left_lower_arm < 80)
		{
			left_lower_arm = (left_lower_arm + 5) % 360;

		};
		glutPostRedisplay();
		break;
	case 'Z':
		if (left_lower_arm > 0)
		{
			left_lower_arm = (left_lower_arm - 5) % 360;

		};
		glutPostRedisplay();
		break;

	case 'r':
		if (right_thigh > -80)
		{
			right_thigh = (right_thigh - 5) % 360;

		}
		glutPostRedisplay();
		break;
	case 'R':

		if (right_thigh <= 80)
		{
			right_thigh = (right_thigh + 5) % 360;
		}
		glutPostRedisplay();
		break;

	case 'q':
		if (left_thigh > -80)
		{
			left_thigh = (left_thigh - 5) % 360;

		}
		glutPostRedisplay();
		break;
	case 'Q':

		if (left_thigh < 80)
		{
			left_thigh = (left_thigh + 5) % 360;
		}
		glutPostRedisplay();
		break;
	case 'g':
		if (twist_arm <= 180)
		{
			twist_arm = (twist_arm + 5) % 360;

		}
		glutPostRedisplay();
		break;
	case 'G':
		if (twist_arm > 0)
		{
			twist_arm = (twist_arm - 5) % 360;

		}
		glutPostRedisplay();
		break;
	case 'o':
		if (left_leg <= 70)
		{
			left_leg = (left_leg + 5) % 360;

		}
		glutPostRedisplay();
		break;
	case 'O':
		if (left_leg > 0)
		{
			left_leg = (left_leg - 5) % 360;

		}
		glutPostRedisplay();
		break;
	case 'f':
		moveForward();
		glutPostRedisplay();
		break;
	case 'b':
		moveBackword();
		glutPostRedisplay();
		break;
	case 's':
		reset();
		glutPostRedisplay();
		break;
	case 'u':
		if (left_thigh_frba > -80) 
		{
			left_thigh_frba = (left_thigh_frba - 5) % 360;
		}
		glutPostRedisplay();
		break;

	case 'U':
		if (left_thigh_frba <= 80)
		{
			left_thigh_frba = (left_thigh_frba + 5) % 360;
		}
		glutPostRedisplay();
		break;
	case 'i':
		if (right_thigh_frba > -80)
		{
			right_thigh_frba = (right_thigh_frba - 5) % 360;

		}
		glutPostRedisplay();
		break;
	case 'I':
		if (right_thigh_frba <= 80)
		{
			right_thigh_frba = (right_thigh_frba + 5) % 360;

		}
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

static void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			moving = 1;
			startx = x;
			starty = y;
		}
		if (state == GLUT_UP) {
			moving = 0;
		}
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}