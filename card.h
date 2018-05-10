#ifndef CARD_H
#define CARD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QColor>

class Card : public QGraphicsPixmapItem
{
private:
    char m_letter;
    int m_width;
    int m_height;

public:
    Card(char c, int width, int height);
    QPixmap paint(char c, QColor bg, QColor fg, int width, int height);
};

#endif // CARD_H
