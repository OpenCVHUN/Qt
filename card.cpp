#include "card.h"

#include <QFont>
#include <QPainter>

Card::Card(char c)
    : m_letter(c)
{
    QPixmap p = paint(m_letter, QColor(Qt::white), QColor(Qt::black), 80, 150);
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
