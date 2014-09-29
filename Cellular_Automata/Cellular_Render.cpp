#ifndef Cellular_Render.h
#define Cellular_Render.h

#include "Cellular_Render.h"

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