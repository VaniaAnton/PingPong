

#ifndef Ball_hpp
#define Ball_hpp
#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;
enum eDirection{STOP = 0, LEFT =1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT =5, DOWNRIGHT =6};

class Ball{
private:
    int x, y;
    int originalX, originalY;
    eDirection direction;
public:
    Ball(int posX, int posY){
        originalX = posX;
        originalY = posY;
        x = posX; y =posY;
        direction = STOP;
    }
    void reset(){
        x = originalX; y = originalY;
        direction = STOP;
    }
    void changeDirection(eDirection d){
        direction = d;
    }
    void randomDirection(){
        direction = (eDirection)(( rand() % 6 ) + 1);
    }
    inline int getX(){return x;}
    inline int getY(){return y;}
    inline eDirection getDirection(){return direction;}
    
    void move(){
        switch (direction) {
            case STOP:
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UPLEFT:
                x--; y--;
                break;
            case DOWNLEFT:
                x--; y++;
                break;
            case UPRIGHT:
                x++; y--;
                break;
            case DOWNRIGHT:
                x++; y++;
                break;
            default:
                break;
        }
    }
    friend ostream & operator<<(ostream & os, Ball c){
        os<<" Ball ["<<c.x<<","<<c.y<<"]["<<c.direction<<"]";
        return os;
    }
};
#endif /* Ball_hpp */
