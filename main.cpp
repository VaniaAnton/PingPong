#include <iostream>
#include "Ball.hpp"
#include "PlayerControl.hpp"
#include "GameManager.hpp"
#include <cstdlib>

int main()
{
    std::system("export TERM=xterm");
    GameManager obj(40,20);
    while (obj.quit == false) {
        obj.Run();
        cout<<"hereeee"<<endl;
        cout<<flush;
        //system("clear");
    }
    
}
