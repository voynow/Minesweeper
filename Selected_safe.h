#ifndef PS_JV_GRAPHICS_FINAL_SELECTED_SAFE_H
#define PS_JV_GRAPHICS_FINAL_SELECTED_SAFE_H

#include "Tile.h"

class Safe_Space : public Tile {
public:
    Safe_Space() {
        adj_bombs = 0;
        int temp = column;
        if (row % 2 == 0) {
            ++temp;
        }
        if (temp % 2 == 1) {
            original_fill = {colors[LIGHT_BROWN].r, colors[LIGHT_BROWN].g,colors[LIGHT_BROWN].b};
            current_fill = {colors[LIGHT_BROWN].r, colors[LIGHT_BROWN].g,colors[LIGHT_BROWN].b};

        } else {
            original_fill = {colors[DARK_BROWN].r, colors[DARK_BROWN].g,colors[DARK_BROWN].b};
            current_fill = {colors[DARK_BROWN].r, colors[DARK_BROWN].g,colors[DARK_BROWN].b};
        }
    }

    void draw() const override {
        glColor3f(current_fill.r, current_fill.g, current_fill.b);
        glBegin(GL_QUADS);
        glVertex2i(x1, y1);
        glVertex2i(x2, y1);
        glVertex2i(x2, y2);
        glVertex2i(x1, y2);
        glEnd();

        if (adj_bombs != 0) {
            if (adj_bombs == 1) {
                glColor3f(colors[ONE].r, colors[ONE].g, colors[ONE].b);
            } else if (adj_bombs == 2) {
                glColor3f(colors[TWO].r, colors[TWO].g, colors[TWO].b);
            } else if (adj_bombs == 3) {
                glColor3f(colors[THREE].r, colors[THREE].g, colors[THREE].b);
            } else if (adj_bombs == 4) {
                glColor3f(colors[FOUR].r, colors[FOUR].g, colors[FOUR].b);
            } else if (adj_bombs == 5) {
                glColor3f(colors[FIVE].r, colors[FIVE].g, colors[FIVE].b);
            } else if (adj_bombs == 6) {
                glColor3f(colors[SIX].r, colors[SIX].g, colors[SIX].b);
            } else if (adj_bombs == 7) {
                glColor3f(colors[SEVEN].r, colors[SEVEN].g, colors[SEVEN].b);
            } else if (adj_bombs == 8) {
                glColor3f(colors[EIGHT].r, colors[EIGHT].g, colors[EIGHT].b);
            }
            unsigned char filler[] = "8";
            glRasterPos2i(x1 + (0.5 * (x2 - x1)) - (0.5 * glutBitmapLength(GLUT_BITMAP_HELVETICA_18, filler)),
                          y1 + (0.5 * (y2 - y1)) + (0.75 * glutBitmapLength(GLUT_BITMAP_HELVETICA_18, filler)));
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, reinterpret_cast<int>('0' + adj_bombs));
            glEnd();
        }
    }

};

#endif //PS_JV_GRAPHICS_FINAL_SELECTED_SAFE_H