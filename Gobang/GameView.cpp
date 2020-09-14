#include "GameView.h"

#include <QApplication>
#include <QMessageBox>
//#pragma execution_character_set(“utf-8”)

CGameView::CGameView(QWidget *parent)
    : QFrame(parent)
    , m_eColor(COLOR_WHITE)
{
    ResetGame();
}

CGameView::~CGameView()
{

}

// 重置游戏
void CGameView::ResetGame()
{
    m_GameModel.Fun_Reset();
    update();
}

// 当窗口改变大小时，重新计算单元格大小
void CGameView::CaculateCellSize()
{
    int iWidth = this->width();
    int iHeight = this->height();

    // 计算GRID_NUM个方格的位置
    for(int i = 0; i < GRID_NUM; i++)
    {
        int top = i * iHeight / GRID_NUM;
        for(int j = 0; j < GRID_NUM; j++)
        {
            int left = j * iWidth / GRID_NUM;
            m_cells[i][j] = QRect(left, top, iWidth / GRID_NUM, iHeight / GRID_NUM);
        }
    }
}

// 从鼠标位置换算出单元格坐标
bool CGameView::GetPostion(QPoint pt, int& iX, int& iY)
{
    for(int i = 0; i < GRID_NUM; i++)
    {
        for(int j = 0; j < GRID_NUM; j++)
        {
            QRect rect = m_cells[i][j];
            //r.adjust(2,2,-2,-2);

            if(rect.contains(pt))
            {
                iX = i;
                iY = j;
                return true;
            }
        }
    }
    return false;
}

void CGameView::resizeEvent ( QResizeEvent * event )
{
    //当窗口改变大小时，重新计算每个单元格大小
    CaculateCellSize();
}

void CGameView::paintEvent ( QPaintEvent * event )
{
    int iWidth = this->width();
    int iHeight = this->height();
    QRect rect(0,0, iWidth, iHeight);

    // 背景
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(0xFF, 0xFF, 0xFF)));
    painter.drawRect(rect);


    //GRID_NUMxGRID_NUM方格
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(0x33, 0x33, 0x33));
    painter.setPen(pen);
    for(int i = 0; i <= GRID_NUM; i++)
    {
        int iXPos = (i + 0.5) * iWidth / GRID_NUM;
        int iXStart = 0.5 * iWidth / GRID_NUM;
        int iXEnd = iWidth - iXStart;
        int iYPos = (i+0.5) * iHeight / GRID_NUM;
        int iYStart = 0.5 * iHeight / GRID_NUM;
        int iYEnd = iHeight - iYStart;
        painter.drawLine(iXPos, iYStart, iXPos, iYEnd - 1);
        painter.drawLine(iXStart, iYPos, iXEnd - 1, iYPos);
    }

    // 棋子：如果该单元格里有棋子，则画出该棋子
    for(int i = 0; i < GRID_NUM; i++)
    {
        for(int j=0; j<GRID_NUM; j++)
        {
            CGameRole* pRole = m_GameModel.Fun_GetRoll(i, j);
            if(pRole != NULL && pRole->Fun_IsHavePiece())
            {
                QRect rect = m_cells[pRole->Fun_GetXPos()][pRole->Fun_GetYPos()];
                painter.drawPixmap(rect, pRole->Fun_GetIcon());
            }
        }
    }
}

// 鼠标松开
void CGameView::mouseReleaseEvent ( QMouseEvent * event )
{
    int iX = 0;
    int iY = 0;
    if(false == GetPostion(event->pos(), iX, iY))
    {
        return;
    }
    bool bAddRst = m_GameModel.Fun_AddPiece(m_eColor, iX, iY);
    if(false == bAddRst)
    {
        return;
    }

    update();

    bool bRst = m_gameController.Fun_IsWin(m_eColor, iX, iY, (const CGameRole**)m_GameModel.Fun_GetAllRoles());
    if(true == bRst)
    {
        if(COLOR_BLACK == m_eColor)
        {
            QMessageBox* pTipWnd = new QMessageBox(this);
            pTipWnd->setText(STRING_BLACK_PIECE_WIN);
            pTipWnd->exec();
        }
        else
        {
            QMessageBox* pTipWnd = new QMessageBox(this);
            pTipWnd->setText(STRING_WHITE_PIECE_WIN);
            pTipWnd->exec();
        }
        ResetGame();
    }
    else
    {
        emit Signal_PiecePlay(m_eColor);
    }

}

void CGameView::Slot_SelectPiece(PIECE_COLOR eColor)
{
    m_eColor = eColor;
}

void CGameView::Slot_ReStartGame()
{
    ResetGame();
}




