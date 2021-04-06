#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include "myobjects.h"
#define FPS 50

void display();
void reshape(int w, int h);

float roadXMin = -30;
float carXMin = -40;
float housesX = 0;
float all_houses_min_y = 4;
float mountain_start_x=-30;
float black_houses_start = 40;
float front_house_x = 30;

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}

float treesDown = -30;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawDay(); // blue sky an
    many_clouds();
    mountain(mountain_start_x, 4);// mountain

    // random black houses;
    many_black_houses(black_houses_start); // black houses
    home(roadXMin + 80, 12.5);
    home(roadXMin + 100, 12.5);
    green_field(roadXMin, all_houses_min_y); // green field at beginning of animation
    random_houses(); // block houses



    // trees on upper side of road
    many_cut_trees(roadXMin + 60, all_houses_min_y, 10);
    many_trees(roadXMin, all_houses_min_y, 5);

    drawRoad(roadXMin); // road
    drawCar(carXMin,3);
    person();
    move_person();


    // trees on lower side of road
    many_cut_trees(treesDown + 80, all_houses_min_y-3.5, 4);
    many_trees(treesDown + 1, all_houses_min_y-3.5, 7);



    roadXMin-=0.1;
    treesDown -= 0.125;
    front_house_x -= 0.1;
    mountain_start_x -= 0.015;
    black_houses_start -= 0.03;
    carXMin += 0.03;

    glutSwapBuffers();
}

void timer(int x)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer, 0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(750,550);
    glutInitWindowPosition(200,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT WINDOW TITLE");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}


void reshape(int w, int h)
{
    // view port
    glViewport(0,0,w,h );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-30,0,0,40);

}


