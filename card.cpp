#include "card.h"

#include <QFont>
#include <QPainter>

Card::Card(char c, int width, int height)
    : m_letter(c)
    , m_width(width)
    , m_height(height)
{
    QPixmap p = paint(m_letter, QColor(Qt::white), QColor(Qt::black), m_width, m_height);
    this->setPixmap(p);
}

QPixmap Card::paint(char c, QColor bg, QColor fg, int width, int height)
{
    QFont font;
    font.setPixelSize(height - 15);
    QPixmap pix(width, height);
    pix.fill(Qt::transparent);
    QPainter painter;
    painter.begin(&pix);
    painter.setFont(font);
    painter.setPen(bg);
    painter.setBrush(bg);
    painter.drawRoundedRect(0, 0, width, height, 10, 10, Qt::RelativeSize);
    painter.setPen(fg);
    painter.drawText(0, 0, width, height, Qt::AlignCenter, QString(c));
    painter.end();
    return pix;
}
