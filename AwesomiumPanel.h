#ifndef AWESOMIUMPANEL_H
#define AWESOMIUMPANEL_H

#include <iostream>
#include <string>
#include <Awesomium/WebCore.h>

/**
 * \class	AwesomiumPanel
 *
 * \brief	Just a simple/quick wrapper class for awesomium - more can be added later i.e. keyboard/mouse input etc
 *
 * \author	Matthew Vlietstra
 * \date	07/07/2012
 */
class AwesomiumPanel
{
    public:
    AwesomiumPanel(int width, int height);

    ~AwesomiumPanel();

    void LoadURL(const std::string &url);

    void Update();

    bool IsDirty();

    const unsigned char *GetBuffer();

    int GetWidth();

    int GetHeight();

    void Resize(int width, int height);

    private:
    Awesomium::WebCore *m_webCore;
    Awesomium::WebView *m_webView;

    int m_width;
    int m_height;
};


#endif
