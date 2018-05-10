#ifndef CARD_H
#define CARD_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QColor>

class Card : public QGraphicsPixmapItem
{
private:
    char m_letter;

public:
    Card(char c);
    QPixmap paint(char c, QColor bg, QColor fg, int width, int height);
};

#endif // CARD_H
