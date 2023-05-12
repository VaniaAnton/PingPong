
#ifndef PlayerControl_hpp
#define PlayerControl_hpp
#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;
class PlayerControl{
private:
    int x,y;
    int originalX, originalY;
public:
    PlayerControl(){
        x=y=0;
    }
    PlayerControl(int posX, int posY) : PlayerControl(){
        originalX = posX; originalY = posY;
        x= posX; y = posY;
        
    }
    inline void reset(){ x= originalX; y =originalY;}
    inline int getX(){ return x;}
    inline int getY() {return y;}
    inline void moveUp(){ y--; }
    inline void moveDown(){ y++;}
    friend ostream & operator<<(ostream & os, PlayerControl c){
        os<<" Control  ["<<c.x<<","<<c.y<<"]" ;
        return os;
    }
};
#endif /* PlayerControl_hpp */
