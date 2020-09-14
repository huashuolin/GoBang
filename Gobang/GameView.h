/**************************************************************************
*   Copyright       huashuolin001
*   FileName:       GameView.h
*   Description:    棋盘视图
*   Author:         huashuolin001
*   Date:           23/05/2019
*   Modification History:
*    <version>       <time>          <author>        <desc>
*       1.0        23/05/2019     huashuolin001       创建
**************************************************************************/

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "GameModel.h"
#include "GameController.h"

#include <QFrame>
#include <QtGui>

class CGameView : public QFrame
{
    Q_OBJECT

public:
    CGameView(QWidget *parent);
    virtual ~CGameView();

public slots:
    /**@fn         Slot_SelectPiece
    *  @brief      槽函数：选择棋子颜色
    *  @para       PIECE_COLOR eColor    棋子颜色，COLOR_WHITE为白棋，COLOR_BLACK为黑棋
    *  @return     void
    */
    void Slot_SelectPiece(PIECE_COLOR eColor);

    /**@fn         Slot_ReStartGame
    *  @brief      槽函数：重新开始游戏
    *  @return     void
    */
    void Slot_ReStartGame();


private:
    virtual void paintEvent ( QPaintEvent * event );
    virtual void resizeEvent ( QResizeEvent * event );
    virtual void mouseReleaseEvent ( QMouseEvent * event );


private:
    /**@fn         ResetGame
    *  @brief      重置游戏
    *  @return     void
    */
    void ResetGame();

    /**@fn         CaculateCellSize
    *  @brief      计算每个单元格大小（当窗口改变大小时，重新计算每个单元格大小）
    *  @return     void
    */
    void CaculateCellSize();

    /**@fn         GetPostion
    *  @brief      从鼠标位置换算出单元格坐标
    *  @para       QPoint pt    鼠标坐标
    *  @para       [OUT]int& iX    在棋盘的横向坐标
    *  @para       [OUT]int& iX    在棋盘的横向坐标
    *  @return     bool    true代表成功获取单元格坐标，false代表获取失败
    */
    bool GetPostion(QPoint pt, int& iX, int& iY);


    QRect m_cells[GRID_NUM][GRID_NUM] ; // GRID_NUMxGRID_NUM方格,每个单元的具体位置
    CGameModel m_GameModel; //所有的游戏数据
    CGameController m_gameController;// 游戏控制器（包含游戏规则）
    PIECE_COLOR m_eColor; //当前下棋的棋子颜色

signals:
    /**@fn         Signal_PiecePlay
    *  @brief      信号：下棋
    *  @para       PIECE_COLOR eColor    棋子颜色，COLOR_WHITE为白棋，COLOR_BLACK为黑棋
    *  @return     bool    true代表成功获取单元格坐标，false代表获取失败
    */
    void Signal_PiecePlay(PIECE_COLOR eColor);
};

#endif // GAMEVIEW_H
