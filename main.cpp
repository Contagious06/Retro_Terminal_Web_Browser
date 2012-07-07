#include <iostream>
#include "TerminalBrowser.h"
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>

//./RetroTerminalWebBrowser http://google.com 800 640 10 10

int main(int argc, char **argv)
{
    std::string URL("http://google.com");

    int panelW = 400;
    int panelH = 320;

    int consoleW = 400;
    int consoleH = 320;


    if(argc == 6)
    {
        std::stringstream ss;

        for(int i = 1; i < 6; i++)
        {
            std::cout << argv[i] << std::endl;
            ss << argv[i] << " ";
        }

        ss >> URL >> panelW >> panelH >> consoleW >> consoleH;
    }


    //std::cout << argc << " " << URL << " " << panelW << " " << panelH << " " << consoleW << " " << consoleH << std::endl;

    TerminalBrowser *tb = new TerminalBrowser(panelW, panelH, consoleW, consoleH);
    tb->LoadURL(URL);

    //tb->Update();

    //sleep(4); //Hopefully it's finished loading the webpage by then..

    while(true)
    {
        tb->Update();
        if(tb->IsDirty())
        {
            system("clear");
            tb->Render();
        }
        //std::cout << "HI!\n" << std::endl;
    }


    return 0;
}
