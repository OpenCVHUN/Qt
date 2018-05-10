#include "gameboard.h"
#include "card.h"

#include <vector>
#include <QTime>

GameBoard::GameBoard()
    : m_rows(2)
    , m_columns(8)
{
    qsrand(static_cast<quint32>(QTime::currentTime().msec()));

    int cards = m_rows * m_columns;
    std::vector<char> letters;
    char first = 'A';
    char last = 'A' + static_cast<char>(cards) - 1;

    for (int i = 0; i < cards; i++) {
        char l = first + (qrand() % (last - first));
        letters.push_back(l);
    }

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_columns; j++) {
            char c = letters[0];
            letters.erase(letters.begin());
            Card *card = new Card(c);
            card->setPos(QPointF(80 * j, 150 * i));
            this->addItem(card);
        }
    }
}

void GameBoard::startGame()
{

}

void GameBoard::endGame()
{

}
