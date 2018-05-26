// Problem1.cpp
// ENSC482 - Homework 1
// Created by Klein Gomes on 2018-05-20.
// Copyright © 2018 Klein Gomes. All rights reserved.
//
// Problem 1(20)  
// Using the framework of the C++/OpenGL source codes and the supplied tutorial, draw your own three sample of graphical visulization models.

#include "stdafx.h"
#include <GL/glew.h>
#include <gl/freeglut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


void init(void) 
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void drawTriangle() 
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(5, 100);
	glVertex2i(5, 15);
	glVertex2i(60, 100);
	glEnd();
}

void drawSquare() 
{
	glColor3f(1.0, 0.0, 0.0);
	// Vertical Lines
	glBegin(GL_LINES);
	glVertex2i(80, 55);
	glVertex2i(80, 15);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(120, 55);
	glVertex2i(120, 15);
	glEnd();
	// Horizontal Lines
	glBegin(GL_LINES);
	glVertex2i(80, 55);
	glVertex2i(120, 55);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(80, 15);
	glVertex2i(120, 15);
	glEnd();
}

void drawCircle() 
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	float x1 = 90;
	float x2 = 90;
	glVertex2f(x1, x2);
	for (int i = 0; i < 360; i++)
	{
		glVertex2f(x1 + sin(i) * 20, x2 + cos(i) * 20);
	}
	glEnd();
}

void drawThreeShapes(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawTriangle();
	drawSquare();
	drawCircle();
	glFlush();
}


int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Homework 1 - Problem 1: Klein Gomes");
	
	init();
	glutDisplayFunc(drawThreeShapes);
	glutMainLoop();
	std::cin.get();
	return 0;
}