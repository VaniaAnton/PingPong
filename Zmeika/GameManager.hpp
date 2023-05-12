
#ifndef GameManager_hpp
#define GameManager_hpp
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <cstdlib>
#include "Ball.hpp"
#include "PlayerControl.hpp"



class GameManager{
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    //bool quit;
    Ball *ball;
    PlayerControl * player1;
    PlayerControl *player2;
    
    public:
    bool quit;
    GameManager(int w, int h){
        srand(time_t(NULL));
        quit = false;
        score1=score2=0;
        width = w; height = h;
        ball = new Ball(w/2, h/2);
        player1 = new PlayerControl(1, h/2-3);
        player2 = new PlayerControl(w-2, h/2-3);
    }
    ~GameManager()
    {
        delete ball;
        delete player1;
        delete player2;
    }
    void scoreUp(PlayerControl* player){
        if(player==player1){
            score1++;
        }
        else if(player ==player2){
            score2++;
        }
        ball->reset();
        player1->reset();
        player2->reset();
    }
    void Draw()
    {
        system("cls");
        for(int i=0; i<width+2; i++){
            cout<<"#";
            
        }
        //cout<<endl;
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++)
            {
                int ballx =ball->getX();
                int bally = ball->getY();
                int player1x = player1->getX();
                int player2x = player2->getX();
                int player1y = player1->getY();
                int player2y = player2->getY();
                
                if(j==0){
                    cout<<"#";
                }
                if(ballx ==j && bally==i){
                    cout<<"o";//ball
                }
                else if(player1x ==j && player1y ==i){
                    cout<<"|";//player1
                }
                else if(player2x ==j && player2y ==i){
                    cout<<"|";//player2
                }
                else if(player1x ==j && player1y+1 ==i){
                    cout<<"|";//player1
                }
                else if(player1x ==j && player1y+2 ==i){
                    cout<<"|";//player1
                }
                else if(player1x ==j && player1y+3==i){
                    cout<<"|";//player1
                }
                else if(player2x ==j && player2y+1 ==i){
                    cout<<"|";//player2
                }
                else if(player2x ==j && player2y+2 ==i){
                    cout<<"|";//player2
                }
                else if(player2x ==j && player2y+3 ==i){
                    cout<<"|";//player2
                }
                else{
                    cout<<" ";
                }
                
                if(j==width-1){
                    cout<<"#";
                }
            }
            cout<<endl;
        }
        for (int i=0; i< width+2; i++){
            cout<<"#";
        }
        cout<<endl;
        cout<<"Score1 :"<<score1<<endl;
        cout<<"Score2 :"<<score2<<endl;
        
    }
    void Input(){
        ball->move();

//        int ballx =ball->getX();
//        int bally = ball->getY();
//        int player1x = player1->getX();
        //int player2x = player2->getX();
            int player1y = player1->getY();
        int player2y = player2->getY();

//        int player2x = player2->getX
        if(quit==false){
            char current = getchar();
            if(current == 'w'){
                if(player1y>0){
                    player1->moveUp();
                    Draw();
                }
            }
            if(current == 'o'){
                if(player2y>0){
                    player2->moveUp();
                }
            }
            if(current == 's'){
                if(player1y+4<height){
                    player1->moveDown();
                }
            }
            if(current == 'l'){
                if(player2y+4<height){
                    player2->moveDown();
                }
            }
            if(ball->getDirection() ==STOP){
                ball->randomDirection();
            }
            if(current == 'q' || current =='Q'){
                quit =true;
            }

        }
        
    }



    void logic(){
        
        int ballx =ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();
        
        //left paddle
        for(int i=0; i<4; i++){
            if(ballx == player1x+1)
                if(bally==player1y+i)
                    ball->changeDirection((eDirection)((rand()%3)+4));
        }
        //right paddlen
        for(int i=0; i<4; i++){
            if(ballx == player2x-1)
                if(bally==player2y+i)
                    ball->changeDirection((eDirection)((rand()%3)+1));
        }
        //buttom wall
        if(bally == height -1){
            ball->changeDirection(ball->getDirection()== DOWNRIGHT ? UPRIGHT:UPLEFT);
        }
        //top wall
        if(bally == 0){
            ball->changeDirection(ball->getDirection()== UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        }
        //right wall
        if(ballx ==width -1)
            scoreUp(player1);
        //left wall
        if(ballx ==0)
            scoreUp(player2);
    }
    void Run()
    {
        while(quit==false){
            Draw();
            Input();
            logic();
        }
    }
    
};

#endif /* GameManager_hpp */
