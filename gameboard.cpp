#include "gameboard.h"
#include "card.h"

#include <vector>
#include <QTime>
#include <QGraphicsDropShadowEffect>

GameBoard::GameBoard()
    : m_rows(2)
    , m_columns(8)
    , m_cardShown(nullptr)
    , m_canClick(true)
{
    this->startGame();
}

Card *GameBoard::cardShown() const
{
    return m_cardShown;
}

void GameBoard::setCardShown(Card *c)
{
    m_cardShown = c;
}

bool GameBoard::canClick() const
{
    return m_canClick;
}

void GameBoard::setCanClick(bool c)
{
    m_canClick = c;
}

void GameBoard::startGame()
{
    int oldCount = this->items().count();
    for (int i = 0; i < oldCount; i++) {
        auto item = this->items().at(0);
        delete item;
    }

    this->setCanClick(true);
    this->setCardShown(nullptr);

    qsrand(static_cast<quint32>(QTime::currentTime().msec()));

    // Kártyák száma: sorok x oszlopok száma
    int cards = m_rows * m_columns;

    // Gondoskodunk róla, hogy páros számú kártya legyen
    if ((cards % 2) != 0) {
        cards -= 1;
    }

    // Gondolkodtató feladat: "jó"-e ez így? Mi történik, ha cards túl nagy szám?

    std::vector<char> letters;

    // A-tól kezdve mindegyik betűből kettőt elhelyezünk a listában
    for (char i = 'A'; i < ('A' + cards / 2); i++) {
        // Mindegyikből kettő kell, hogy legyen majd párja
        letters.push_back(i);
        letters.push_back(i);
    }

    int cardWidth = 100;
    int cardHeight = 170;
    int margin = 10;

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_columns; j++) {
            // Ennyi betűnk van összesen
            int count = static_cast<int>(letters.size());
            // Választunk egyet véletlenszerűen
            int index = qrand() % count;

            // Megkeressük a vektorban az oda mutató iterátort
            auto it = letters.begin() + index;
            // Ez a betű van benne
            char c = *it;
            // Töröljük a vektorból
            letters.erase(it);

            Card *card = new Card(c, cardWidth, cardHeight);
            card->setPos(QPointF((cardWidth + margin) * j, (cardHeight + margin) * i));

            QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
            effect->setColor(QColor(0, 0, 0, 200));
            effect->setOffset(0);
            effect->setBlurRadius(12);
            card->setGraphicsEffect(effect);

            this->addItem(card);
        }
    }
}

void GameBoard::endGame()
{
    this->setCanClick(false);

    int oldCount = this->items().count();
    for (int i = 0; i < oldCount; i++) {
        auto *c = static_cast<Card*>(this->items().at(i));
        c->showFace();
    }
}
