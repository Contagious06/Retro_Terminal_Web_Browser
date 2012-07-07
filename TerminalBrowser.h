
#ifndef TERMINALBROWSER_H
#define TERMINALBROWSER_H

#include <iostream>
#include "AwesomiumPanel.h"
#include "Misc.h"

class TerminalBrowser
{
    public:
    TerminalBrowser(int windowWith, int windowHeight, int terminalWidth, int terminalHeight)
    {
        m_terminalWidth = terminalWidth;
        m_terminalHeight = terminalHeight;


        m_panel = new AwesomiumPanel(windowWith, windowHeight);
        isDirty = true;

        m_pageX = 0;
        m_pageY = 0;
    }

    ~TerminalBrowser()
    {
        delete m_panel;
    }

    void LoadURL(const std::string &URL)
    {
        m_panel->LoadURL(URL);
    }

    bool IsDirty() //if the page needs to be rendered again..
    {
        return m_panel->IsDirty() || isDirty;
    }

    void Update()
    {
        m_panel->Update();
    }

    void Render()
    {
        isDirty = false;
        int panelWidth = m_panel->GetWidth();
        //int panelHeight = m_panel->GetHeight();

        const unsigned char *buff = m_panel->GetBuffer();

        if(buff == NULL) { return; }

        //int offset = 0;
        for(int y = 0; y < m_terminalHeight; y++)
        {
            for(int x = 0; x < m_terminalWidth; x++)
            {
                int i = (y * m_terminalWidth + x + m_pageX + y * (panelWidth - m_terminalWidth)) * 4; // TOTO: take into account pageY, can only scroll from left to right
                gotoXY(x*2, y);
                int c = 32 + (buff[i] + buff[i+1] + buff[i+2]) / (float)(255*3) * 10;
                std::cout << "\033[" <<  c << ";30m";
                std::cout << "  ";
                std::cout << "\033[0m";
            }
        }
    }


    void SetPageX(int x)
    {
        if(x != m_pageX) isDirty = true;

        m_pageX = x;
    }

    void SetPageY(int y)
    {
        if(y != m_pageY) isDirty = true;
        m_pageY = y;
    }

    int GetPageX()
    {
        return m_pageX;
    }

    int GetPageY()
    {
        return m_pageY;
    }

    private:
    int m_terminalWidth; //Width & Height of the rendering window in the terminal
    int m_terminalHeight;

    int m_pageX; //The location of the window on the webpage
    int m_pageY;

    bool isDirty;

    AwesomiumPanel *m_panel;
};




#endif
