/**************************************************************************
*   Copyright       huashuolin001
*   FileName:       GameModel.h
*   Description:    记录游戏棋盘所有点（可下棋子位置）的数据
*   Author:         huashuolin001
*   Date:           23/05/2019
*   Modification History:
*    <version>       <time>          <author>        <desc>
*       1.0        23/05/2019     huashuolin001       创建
**************************************************************************/

#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "GameRole.h"
#include "GamePosition.h"
#include "CommonDefine.h"

/* 棋盘数据 */
class CGameModel
{
public:
    CGameModel();
     virtual ~CGameModel();

    /**@fn         Fun_Reset
    *  @brief      重置游戏数据
    *  @return     void
    */
    void Fun_Reset();

    /**@fn         Fun_GetRoll
    *  @brief      根据棋盘位置获取棋盘点数据
    *  @para       int iX    在棋盘的横向坐标
    *  @para       int iX    在棋盘的横向坐标
    *  @return     CGameRole*    棋盘点数据
    */
    CGameRole* Fun_GetRoll(int iX, int iY);

    /**@fn         Fun_AddPiece
    *  @brief      添加棋子数据
    *  @para       PIECE_COLOR eColor    棋子颜色，COLOR_WHITE为白棋，COLOR_BLACK为黑棋
    *  @para       int iX    在棋盘的横向坐标
    *  @para       int iX    在棋盘的横向坐标
    *  @return     bool    返回true代表添加成功，返回false代表添加失败或者该位置已经有棋子
    */
    bool Fun_AddPiece(PIECE_COLOR eColor, int iX, int iY);

    /**@fn         Fun_GetAllRoles
    *  @brief      获取所有棋盘点数据
    *  @return     CGameRole**    所有棋盘点数据
    */
    CGameRole** Fun_GetAllRoles()
    {
        return m_pAllRoles;
    }

private:
    CGameRole** m_pAllRoles; //所有棋盘点数据，用二重指针维护一个二维数组的数据（即棋盘格的数据，GRID_NUM*GRID_NUM的大小）
};

#endif //GAMEMODEL_H


