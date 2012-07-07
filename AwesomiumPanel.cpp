
#include "AwesomiumPanel.h"
#include <Awesomium/WebCore.h>

AwesomiumPanel::AwesomiumPanel(int width, int height)

{
    m_width = width;
    m_height = height;

    //m_webCore = Awesomium::WebCore::GetPointer(); //Get the webcore singleton
    m_webCore = new Awesomium::WebCore();
    m_webView = m_webCore->createWebView(m_width, m_height);
}

AwesomiumPanel::~AwesomiumPanel()
{
    m_webView->destroy();
    delete m_webCore;
}

void AwesomiumPanel::LoadURL(const std::string &url)
{
    m_webView->loadURL(url.c_str());
}

void AwesomiumPanel::Update()
{
    m_webCore->update();
}

bool AwesomiumPanel::IsDirty()
{
    return m_webView->isDirty();
}

const unsigned char *AwesomiumPanel::GetBuffer()
{
    const Awesomium::RenderBuffer *rBuffer = m_webView->render();
    return rBuffer->buffer;
}

int AwesomiumPanel::GetWidth()
{
    return m_width;
}

int AwesomiumPanel::GetHeight()
{
    return m_height;
}

void AwesomiumPanel::Resize(int width, int height)
{
    m_width = width;
    m_height = height;

    m_webView->resize(m_width, m_height);
}
