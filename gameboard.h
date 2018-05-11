#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>

#include "card.h"

class GameBoard : public QGraphicsScene
{
private:
    int m_rows;
    int m_columns;
    Card *m_cardShown;
    bool m_canClick;

public:
    GameBoard();
    void startGame();
    void endGame();

    Card *cardShown() const;
    void setCardShown(Card *c);
    bool canClick() const;
    void setCanClick(bool c);
};

#endif // GAMEBOARD_H
