/**************************************************************************
*   Copyright       huashuolin001
*   FileName:       GameRole.h
*   Description:    游戏棋盘每个点（可下棋子位置）的数据
*   Author:         huashuolin001
*   Date:           23/05/2019
*   Modification History:
*    <version>       <time>          <author>        <desc>
*       1.0        23/05/2019     huashuolin001       创建
**************************************************************************/

#ifndef GAMEROLE_H
#define GAMEROLE_H

#include "CommonDefine.h"
#include <QPixmap>

/* 角色定义 */

class CGameRole
{
public:
    CGameRole()
    {
    }

    virtual ~CGameRole()
    {

    }

    /**@fn         Fun_SetData
    *  @brief      设置棋盘每个节点位置的数据
    *  @para       PIECE_COLOR eColor    棋子颜色，COLOR_WHITE为白棋，COLOR_BLACK为黑棋
    *  @para       int iX   //在棋盘的横向坐标
    *  @para       int iX   //在棋盘的横向坐标
    *  @return     void
    */
    void Fun_SetData(PIECE_COLOR eColor, int iX, int iY)
    {
        m_bHavePiece = true;
        m_eColor = eColor;
        m_iX = iX;
        m_iY = iY;
        if(COLOR_WHITE == eColor)
        {
            m_icon.load(":/Resources/white.png");
        }
        else if(COLOR_BLACK == eColor)
        {
            m_icon.load(":/Resources/black.png");
        }
    }

    void Fun_Reset()
    {
        m_bHavePiece = false;
    }

    QPixmap Fun_GetIcon()
    {
        return m_icon;
    }

    bool Fun_IsHavePiece() const
    {
        return m_bHavePiece;
    }

    int Fun_GetXPos()
    {
        return m_iX;
    }

    int Fun_GetYPos()
    {
        return m_iY;
    }

    PIECE_COLOR Fun_GetPieceColor() const
    {
        return m_eColor;
    }

private:
    bool m_bHavePiece;// 此处是否有棋子，true为有棋子，false为无棋子
    PIECE_COLOR m_eColor; //COLOR_WHITE为白棋，COLOR_BLACK为黑棋
    int m_iX; //在棋盘的横向坐标
    int m_iY; //在棋盘的纵向坐标
    QPixmap m_icon; // 相应的图标显示
};




#endif

