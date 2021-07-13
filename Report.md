Name: Ahmed Mohamed Yehia Habib
Code: 1170323

The most challenging part was the coordination in the rotation and the rotation in the y axis for the thighs. 
""" 
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

"""

The other challenge was to set a limit for the movement of the legs, arms and lower arms to be realistic as for humans as it was very challenging to coordinate the rotation for 
each to be the exact as humans so i assumed and there's of course some percentage of error for the estimated limits for the motion

"""
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
"""

I had some help from Mahmoud Fawzi regarding the limits and some help from Omar Abo El fadl regarding the y-axis rotation