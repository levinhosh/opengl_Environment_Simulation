#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>

#include "myobjects.h"

#define pi 3.142857

// VARIABLES

float _min_y = 4;
float sun_x = -2.5;
float sun_y = 35;
float cloud1_x = -20;
float cloud1_y = 20;
float cloud2_x = -5;
float cloud2_y = 15;
float cloud3_x = -35;
float cloud3_y = 12;
float black_houses_speed = 0.07;

// END VARIABLES

void rectangle(float x, float y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x+2, y);
        glVertex2f(x+2, y+1);
        glVertex2f(x, y+1);
    glEnd();
}


void drawHouses(float x, float y)
{
    glColor3f(0.5, 0.3, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(x, y-4+4);
    glVertex2i(x,y-4+10);
    glVertex2i(x+2, y-4+10);
    glVertex2i(x+2, y-4+8);
    glVertex2i(x+8, y-4+8);
    glVertex2i(x+8, y-4+9);
    glVertex2i(x+13, y-4+9);
    glVertex2i(x+13, y-4+11);
    glVertex2i(x+18, y-4+11);
    glVertex2i(x+18, y-4+6);
    glVertex2i(x+21, y-4+6);
    glVertex2i(x+21, y-4+9);
    glVertex2i(x+28, y-4+9);
    glVertex2i(x+28, y-4+15);
    glVertex2i(x+32, y-4+15);
    glVertex2i(x+32, y-4+11);
    glVertex2i(x+40, y-4+11);
    glVertex2i(x+40, y-4+8);
    glVertex2i(x+52, y-4+8);
    glVertex2i(x+52,y-4+4);

    glVertex2i(x+58, y-4+8);
    glVertex2i(x+58, y-4+9);
    glVertex2i(x+69, y-4+9);
    glVertex2i(x+69, y-4+11);
    glVertex2i(x+75, y-4+11);
    glVertex2i(x+75, y-4+6);
    glVertex2i(x+81, y-4+6);
    glVertex2i(x+81, y-4+9);
    glVertex2i(x+98, y-4+9);
    glVertex2i(x+98, y-4+15);
    glVertex2i(x+102, y-4+15);
    glVertex2i(x+102, y-4+11);
    glVertex2i(x+120, y-4+11);
    glVertex2i(x+120, y-4+8);
    glVertex2i(x+132, y-4+8);
    glVertex2i(x+132,y-4+4);


    glEnd();

}


void drawDay()
{


    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-30,4);
        glVertex2f(1000, 4);
        glColor3f(0.0,0.9,1.0);
        glVertex2f(1000,50);
        glVertex2f(-30,50);
    glEnd();

    drawCircle(sun_x,sun_y,2,1.0,0.7,0.3,0.7);
    drawCircle(sun_x,sun_y,1.8,1.0,0.9,1.0,0.0);

    sun_x -= 0.01;

}


void drawCar(float x, int y)
{
glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+10,y);
    glVertex2f(x+10,y+2);
    glVertex2f(x+8,y+2);
    glVertex2f(x+7,y+4);
    glVertex2f(x+3,y+4);
    glVertex2f(x+1,y+2);
    glVertex2f(x,y+2);
    glEnd();

    // windows
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x+3,y+2);
    glVertex2f(x+4,y+2);
    glVertex2f(x+4,y+3);
    glVertex2f(x+3,y+3);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x+6,y+2);
    glVertex2f(x+7,y+2);
    glVertex2f(x+7,y+3);
    glVertex2f(x+6,y+3);
    glEnd();

    drawCircle(x+1.0, 3.0, 0.5, 0.6, 0.6, 0.6, 1.0);
    drawCircle(x+8.0, 3.0, 0.5, 0.6, 0.6, 0.6, 1.0);

}


float theta;
void drawCircle(float originX, float originY, float radius, float red, float green, float blue, float alpha)
{
    glColor4f(red, green, blue, alpha);
    glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            theta = i*3.1415/180;
            glVertex2f(radius*cos(theta)+originX, radius*sin(theta)+originY);
        }
    glEnd();
}


void drawRoad(float xMin)
{

    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xMin,1);
    glVertex2f(xMin+1000,1);
    glEnd();


    float x = xMin;

    while(x<30){
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, 2.5);
        glVertex2f(x+0.5, 2.5);
        glEnd();

        x+=5;
    }

    glBegin(GL_LINE_LOOP);
    glVertex2f(xMin,4);
    glVertex2f(xMin+1000,4);
    glEnd();
}


void draw_buildings(float x, float y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x-1.5+1.5, y-4+4.0);
        glVertex2f(x-1.5+2.0, y-4+18.0);
        glVertex2f(x-1.5+2.3, y-4+18.0);
        glVertex2f(x-1.5+2.8, y-4+19.0);
        glVertex2f(x-1.5+3.0, y-4+19.0);
        glVertex2f(x-1.5+3.2, y-4+21.0);
        glVertex2f(x-1.5+3.5, y-4+21.0);
        glVertex2f(x-1.5+4.0, y-4+26.0);
        glVertex2f(x-1.5+4.5, y-4+21.0);
        glVertex2f(x-1.5+4.8, y-4+21.0);
        glVertex2f(x-1.5+5.0, y-4+19.0);
        glVertex2f(x-1.5+5.2, y-4+19.0);
        glVertex2f(x-1.5+5.7, y-4+18.0);
        glVertex2f(x-1.5+6.0, y-4+18.0);
        glVertex2f(x-1.5+6.5, y-4+4.0);
    glEnd();
}


void draw_house2(float x, float y)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x-12+12, y-4+4);
        glVertex2f(x-12+12, y-4+12);
        glVertex2f(x-12+13, y-4+16);
        glVertex2f(x-12+14, y-4+12);
        glVertex2f(x-12+14, y-4+4);

    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(x-12+11.8, y-4+12.0);
        glVertex2f(x-12+11.8, y-4+12.2);
        glVertex2f(x-12+14.2, y-4+12.2);
        glVertex2f(x-12+14.2, y-4+12.0);
    glEnd();
}


void draw_house3(float x, float y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x-17+17.0, y-4+4.0);
        glVertex2f(x-17+17.0, y-4+13.0);
        glVertex2f(x-17+19.0, y-4+13.0);
        glVertex2f(x-17+19.0, y-4+4.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(x-17+16.8, y-4+13.0);
        glVertex2f(x-17+16.8, y-4+13.2);
        glVertex2f(x-17+19.2, y-4+13.2);
        glVertex2f(x-17+19.2, y-4+13.0);
    glEnd();

}


void draw_house4(float x, float y)
{
    glBegin(GL_POLYGON);
        glVertex2f(x-23+23, y-4+4);
        glVertex2f(x-23+23.4, y-4+14);
        glVertex2f(x-23+23.6,y-4+14);
        glVertex2f(x-23+24, y-4+18);
        glVertex2f(x-23+24.4, y-4+14);
        glVertex2f(x-23+24.6, y-4+14);
        glVertex2f(x-23+25, y-4+4);
    glEnd();
}


void draw_house5(float x, float y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x-8+8, y-4+4);
        glVertex2f(x-8+8, y-4+12);
        glVertex2f(x-8+8.2, y-4+12);
        glVertex2f(x-8+8.5, y-4+18);
        glVertex2f(x-8+8.8, y-4+12);
        glVertex2f(x-8+9, y-4+12);
        glVertex2f(x-8+9, y-4+4);
    glEnd();
}


void draw_house_block(float x, float y)
{
    glColor3f(0.7, 0.4, 0.5);
    glBegin(GL_POLYGON);
        glVertex2f(x-1+1, y-4+4);
        glVertex2f(x-1+11, y-4+4);
        glVertex2f(x-1+11, y-4+11);
        glVertex2f(x-1+1, y-4+11);
    glEnd();

    rectangle(x-1+2, y-4+9);
    rectangle(x-1+5, y-4+9);
    rectangle(x-1+8, y-4+9);
    rectangle(x-1+2, y-4+7);
    rectangle(x-1+5, y-4+7);
    rectangle(x-1+8, y-4+7);
    rectangle(x-1+2, y-4+5);
    rectangle(x-1+5, y-4+5);
    rectangle(x-1+8, y-4+5);

}


float generate_random(int range)
{
    srand(time(NULL));
    float x = rand() % 5;
    return x;
}


float random_x = generate_random(5) + 10;
void random_houses()
{
    float start_y = 4;

    int num_houses = 70;
    while (num_houses < 1000){
        srand(time(NULL));
        draw_house_block(random_x + num_houses, start_y);
        num_houses += 15;
    }
    random_x -= 0.1;
}


void random_black_houses(float building_start_x)
{
        draw_buildings(building_start_x, _min_y);
        draw_house2(building_start_x+12, _min_y);
        draw_house5(building_start_x + 5, _min_y);
        draw_house4(building_start_x + 7, _min_y);
        draw_house3(building_start_x + 9, _min_y);
        draw_house3(building_start_x + 17, _min_y);
        draw_house5(building_start_x + 20, _min_y);
        draw_house4(building_start_x + 23,_min_y);
        draw_house5(building_start_x + 20.5, _min_y);

}


void many_black_houses(float x)
{
        float hx = 0;
        while(hx<180){
            random_black_houses(hx + x);
            hx += 24;
        }
}

void clouds(float x, float y)
{
    circle(y, y, 1.0);
    circle(x+1.1, y, 1.0);
    circle(x+2.5, y, 1.0);
    circle(x+1.7, y+1, 1.0);
    circle(x+0.7, y+0.9, 1.0);

}

void mountain(float x, float y)
{
    glColor3f(0.25, 0.25, 0.25);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x+2, y+4);
        glVertex2f(x+7, y+6);
        glVertex2f(x+9, y+7.5);
        glVertex2f(x+11, y+8);
        glVertex2f(x+13, y+8.4);
        glVertex2f(x+15, y+6);
        glVertex2f(x+16.7, y+5.2);
        glVertex2f(x+18.5, y+6);
        glVertex2f(x+20.3, y+7);
        glVertex2f(x+30, y+9.2);
        glVertex2f(x+37, y+10);
        glVertex2f(x+41, y+8.7);
        glVertex2f(x+44.5, y+6);
        glVertex2f(x+47, y+4);
        glVertex2f(x+51, y+2);
        glVertex2f(x+53, y+1.2);
        glVertex2f(x+57, y);
    glEnd();
}

void green_field(float x, float y)
{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x, y+2);
        glVertex2f(x+2, y+2.8);
        glVertex2f(x+4, y+2.5);
        glVertex2f(x+5.5, y-4+6);
        glVertex2f(x+8, y-4+5.2);
        glVertex2f(x+10, y-4+6);
        glVertex2f(x+12, y-4+6.3);
        glVertex2f(x+14, y-4+6.2);
        glVertex2f(x+16, y-4+5.4);
        glVertex2f(x+18, y-4+5);
        glVertex2f(x+20, y-4+4.8);
        glVertex2f(x+22, y-4+5.8);
        glVertex2f(x+23.5, y-4+7);
        glVertex2f(x+25, y-4+7.4);
        glVertex2f(x+26, y-4+7.2);
        glVertex2f(x+31, y-4+8);
        glVertex2f(x+81, y-4+4);
    glEnd();
}

void drawBushes(float x, float y, float scale)
{
     glColor3f(0.5, 0.6, 0.1);
    glBegin(GL_POLYGON);

    glVertex2f(x*scale, y*scale);
    glVertex2f((x-0.1)*scale, (y+0.15)*scale);
    glVertex2f((x)*scale, (y+0.1)*scale);
    glVertex2f((x-0.05)*scale, (y+0.25)*scale);
    glVertex2f((x+0.05)*scale, (y+0.15)*scale);
    glVertex2f((x+0.07)*scale, (y+0.35)*scale);
    glVertex2f((x+0.1)*scale, (y+0.15)*scale);
    glVertex2f((x+0.2)*scale, (y+0.25)*scale);
    glVertex2f((x+0.15)*scale, (y+0.10)*scale);
    glVertex2f((x+0.25)*scale, (y+0.15)*scale);
    glVertex2f((x+0.15)*scale, y*scale);
    glEnd();


}

void circle(float originX, float originY, float radius)
{
    glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            theta = i*3.1415/180;
            glVertex2f(radius*cos(theta)+originX, radius*sin(theta)+originY);
        }
    glEnd();
}


void draw_tree(float x, float y)
{
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x+0.5, y);
        glVertex2f(x+0.5, y+3.5);
        glVertex2f(x, y+3.5);
    glEnd();

    glColor3f(0.4,0.8,0.4);
    circle(x-0.5, y+4, 1);
    circle(x+1, y+4, 1);
    circle(x+0.25, y+5, 1);

}


void home(float x, float y){
    //ROOF
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3,0.5,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+7, y);
    glVertex2f(x+10, y-10+7);
    glVertex2f(x+2, y-10+7);
    glEnd();
    //TOP OF FRONT WALL
    glColor3f(0.7,0.2,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y-10+10);
    glVertex2f(x-2, y-10+7);
    glVertex2f(x+2, y-10+7);
    glEnd();
    //FRONT WALL

    glColor3f(0.7,0.2,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x-2, y-10+7);
    glVertex2f(x+2, y-10+7);
    glVertex2f(x+2, y-10+2);
    glVertex2f(x-2, y-10+2);
    glEnd();
    //FRONT DOOR

    glColor3f(0.7,0.2,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x-1, y-10+5);
    glVertex2f(x+1, y-10+5);
    glVertex2f(x+1, y-10+2);
    glVertex2f(x-1, y-10+2);
    glEnd();

    //FRONT DOOR LOC
    glColor3f(0.3,0.7,0.9);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2f(x+13, y-10+17);
    glEnd();
    //side wall
    glColor3f(0.1, 0.2,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x+2, y-10+7);
    glVertex2f(x+10, y-10+7);
    glVertex2f(x+10, y-10+2);
    glVertex2f(x+2, y-10+2);
    glEnd();
    //window 1
    glColor3f(0.2, 0.4,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x+2.6, y-10+6.4);
    glVertex2f(x+5, y-10+6.4);
    glVertex2f(x+5, y-10+4.6);
    glVertex2f(x+2.6, y-10+4.6);
    glEnd();
    //line of window 1

    glColor3f(0.1,0.7,0.5);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(x+3.8, y-10+6.4);
    glVertex2f(x+3.8, y-10+4.6);
    glVertex2f(x+2.6, y-10+5.46);
    glVertex2f(x+5, y-10+5.46);
    glEnd();
    //window 2

    glColor3f(0.2,0.4,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x+6.6, y-10+6.4);
    glVertex2f(x+9, y-10+6.4);
    glVertex2f(x+9, y-10+4.6);
    glVertex2f(x+6.6, y-10+4.6);
    glEnd();
    //lines of window 2
    glColor3f(0.1,0.7,0.5);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(x+7.8, y-10+6.4);
    glVertex2f(x+7.8, y-10+4.6);
    glVertex2f(x+6.6, y-10+5.46);
    glVertex2f(x+9, y-10+5.46);
    glEnd();


}


void many_trees(float x, float y, float spacing)
{

    int i = 0;
    while (i<80){
        draw_tree(x + i, y);
        i += spacing;
    }
}


void cut_trees(float x, float y)
{
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x+0.5, y);
        glVertex2f(x+0.5, y+1.5);
        glVertex2f(x, y+1.5);
    glEnd();
}


void many_cut_trees(float x, float y, float spacing)
{
    int i = 0;
    while (i<80){
        cut_trees(x + i, y);
        i += spacing;
    }
}


void many_clouds()
{
    glColor3f(1,1,1);
    clouds(cloud1_x, cloud1_y);
    clouds(cloud2_x, cloud2_y);
    clouds(cloud3_x, cloud3_y);
    clouds(cloud1_x+4, cloud3_y+25);

    cloud1_x+= 0.05;
    cloud2_x -= 0.07;
    cloud3_x += 0.035;

    if (cloud1_x > 0){cloud1_x = -45;}
    if (cloud2_x < -40){cloud2_x = 0;}
    if (cloud3_x > 0){cloud3_x=-40;}
}





float backleg = 8.7;
float frontleg = 11.5;
void person()
{
    glColor3f(0.8,0.8,1);
    // HEAD
    circle(-10, 10, 1);

    // NECK
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2f(-10, 9);
        glVertex2f(-10, 8);
    glEnd();

    // BODY
    glBegin(GL_TRIANGLES);
        glVertex2f(-9.4, 8);
        glVertex2f(-10.6, 8);
        glVertex2f(-10, 5);
    glEnd();

    // HANDS
    //left
    glBegin(GL_LINE_LOOP);
        glVertex2f(-9.4, 8);
        glVertex2f(-8.7, 6);
    glEnd();
    //right
    glBegin(GL_LINE_LOOP);
        glVertex2f(-10.6, 8);
        glVertex2f(-11.5, 6);
    glEnd();

    // LEGS
    // left
    glBegin(GL_LINE_LOOP);
        glVertex2f(-10, 5);
        glVertex2f(-backleg, 2.4);
    glEnd();
    // right
    glBegin(GL_LINE_LOOP);
        glVertex2f(-10, 5);
        glVertex2f(-frontleg, 2.4);
    glEnd();

}

int direction = 0;
void move_person()
{

    if(direction == 0){
        frontleg -= 0.05;
        backleg += 0.05;
    }
    else{
        frontleg += 0.05;
        backleg -= 0.05;
    }

    if(frontleg < 8.5){
        direction = 1;
    }
    if(frontleg > 11.5){
        direction = 0;
    }
}

