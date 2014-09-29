#ifndef CELLULAR_RENDER_H
#define CELLULAR_RENDER_H

#include <Windows.h>
#include <GL/glut.h>

#include "Automaton.h"

class cellular_render{

public:
	cellular_render(automaton *user_automaton);
	void display(automaton *user_automaton);
};
cellular_render::cellular_render(automaton *user_automaton){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Cellular Automata");
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the infinitely event-processing loop

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
}

void cellular_render::display(automaton *user_automaton) {
	float offsetx = 1 / width;
	float offsety = 1 / height;


	//Loop through each value in matrix
	for (int y = 1; y < height - 1; y++){
		for (int x = 1; x < width - 1; x++){
			if (user_automaton.compose(x, y)){

				GLfloat coord_x = (x / width) * 2 - 1;
				GLfloat coord_x_offset = (y / height + offsety) * 2 - 1;
				GLfloat coord_y = (y / height) * 2 - 1;
				GLfloat coord_y_offset = (y / height) * 2 - 1;

				glBegin(GL_QUADS);
				glColor3f(1.0f, 1.0f, 1.0f);
				glVertex2f(coord_x, coord_y);
				glVertex2f(coord_x_offset, coord_y);
				glVertex2f(coord_x_offset, coord_y_offset);
				glVertex2f(coord_x, coord_y_offset);
				glEnd();

			}
		}
	}



	glFlush();  // Render now
}
#endif