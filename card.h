#ifndef CARD_H
#define CARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QColor>
#include <QTimer>

class Card : public QGraphicsPixmapItem
{
private:
    char m_letter;
    int m_width;
    int m_height;
    bool m_isFace;
    QPixmap m_face;
    QPixmap m_back;

public:
    Card(char c, int width, int height);
    QPixmap paint(char c, QColor bg, QColor fg, int width, int height);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void showFace();
    void showBack();
};

#endif // CARD_H
