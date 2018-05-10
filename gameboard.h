#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>

class GameBoard : public QGraphicsScene
{
private:
    int m_rows;
    int m_columns;

public:
    GameBoard();
    void startGame();
    void endGame();
};

#endif // GAMEBOARD_H
