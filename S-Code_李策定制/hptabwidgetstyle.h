#ifndef HPTABWIDGETSTYLE_H
#define HPTABWIDGETSTYLE_H


#include  <QProxyStyle>
#include  <QStyleOption>

#include  <QPainter>
#include  <QTabBar>
#include  <QScrollBar>
#include  <QDebug>

class HpTabWidgetStyle : public QProxyStyle
{
public:
    HpTabWidgetStyle();

    QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    int m_width;
    int m_height;
};

#endif // HPTABWIDGETSTYLE_H
