#include "card.h"
#include "gameboard.h"

#include <QFont>
#include <QPainter>
#include <QMessageBox>

Card::Card(char c, int width, int height)
    : m_letter(c)
    , m_width(width)
    , m_height(height)
    , m_isFace(false)
{
    m_back = paint('?', QColor(0x00, 0xce, 0x9f), QColor(Qt::white), m_width, m_height);
    m_face = paint(m_letter, QColor(Qt::white), QColor(Qt::black), m_width, m_height);
    this->setPixmap(m_back);
}

void Card::showFace()
{
    this->setPixmap(m_face);
    m_isFace = true;
}

void Card::showBack()
{
    this->setPixmap(m_back);
    m_isFace = false;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    GameBoard *board = static_cast<GameBoard*>(scene());

    if (!board->canClick()) {
        return;
    }

    if (!m_isFace) {
        if (!board->cardShown()) {
            showFace();
            board->setCardShown(this);
        } else {
            showFace();
            board->setCanClick(false);
            QTimer::singleShot(1500, [this, board] {

                if (m_letter == board->cardShown()->m_letter) {
                    board->removeItem(board->cardShown());
                    board->removeItem(this);

                    delete board->cardShown();
                    delete this;

                    if (board->items().count() == 0) {
                        QMessageBox::information(nullptr, "Grat!", "Nyertéééél!");
                    }
                } else {
                    this->showBack();
                    board->cardShown()->showBack();
                }

                board->setCardShown(nullptr);
                board->setCanClick(true);
            });
        }
    }
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
