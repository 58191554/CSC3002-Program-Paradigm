/*
 * File: HFractal.cpp
 * ------------------
 * This program draws an H-fractal on the graphics window.int main() {
 */

#include "HFractal.h"
#include <iostream>
using namespace std;


void drawHFractal(GWindow & gw, double x, double y, double size, int order){
    gw.setColor("black");
    if (order == 0){
        cout << "draw" << endl;
        gw.drawLine(x-size/2, y, x+size/2 , y);
        gw.drawLine(x-size/2, y-size/2, x-size/2, y+size/2);
        gw.drawLine(x+size/2, y-size/2, x+size/2, y+size/2);
    }

    else{
        drawHFractal(gw, x+size/2, y+size/2, size/2, order-1);
        drawHFractal(gw, x+size/2, y-size/2, size/2, order-1);
        drawHFractal(gw, x-size/2, y+size/2, size/2, order-1);
        drawHFractal(gw, x-size/2, y-size/2, size/2, order-1);
        gw.drawLine(x-size/2, y, x+size/2 , y);
        gw.drawLine(x-size/2, y-size/2, x-size/2, y+size/2);
        gw.drawLine(x+size/2, y-size/2, x+size/2, y+size/2);
    }
}
