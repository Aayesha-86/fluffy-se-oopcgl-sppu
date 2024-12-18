#include<iostream>
#include<graphics.h>
#include<conio.h> // For getch()
using namespace std;

// Base class for Ball control
class Ball {
protected:
    int x, y, radius, color;
public:
    Ball(int x, int y, int radius, int color) : x(x), y(y), radius(radius), color(color) {}

    virtual void draw() {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse(x, y, radius, radius);
    }

    virtual void move(char direction) {
        clear();
        switch (direction) {
        case 'w': // Up
            y -= 10;
            break;
        case 's': // Down
            y += 10;
            break;
        case 'a': // Left
            x -= 10;
            break;
        case 'd': // Right
            x += 10;
            break;
        }
        draw();
    }

    void clear() {
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(x, y, radius, radius);
    }

    virtual ~Ball() {}
};

// Derived class for Fancy Ball
class FancyBall : public Ball {
public:
    FancyBall(int x, int y, int radius, int color) : Ball(x, y, radius, color) {}

    void draw() override {
        setcolor(color);
        setfillstyle(HATCH_FILL, color);
        fillellipse(x, y, radius, radius);
    }

    void move(char direction) override {
        Ball::move(direction);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Ball* ball = new FancyBall(300, 300, 20, RED);
    ball->draw();

    char ch;
    cout << "Use WASD keys to move the ball. Press 'q' to quit.\n";
    while (true) {
        if (kbhit()) {
            ch = getch();
            if (ch == 'q') {
                break;
            }
            ball->move(ch);
        }
    }

    delete ball;
    closegraph();
    return 0;
}

