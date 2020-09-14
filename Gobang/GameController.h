/**************************************************************************
*   Copyright       huashuolin001
*   FileName:       GameController.h
*   Description:    游戏规则
*   Author:         huashuolin001
*   Date:           23/05/2019
*   Modification History:
*    <version>       <time>          <author>        <desc>
*       1.0        23/05/2019     huashuolin001       创建
**************************************************************************/

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "CommonDefine.h"
#include "GameRole.h"


class CGameController
{
public:
    CGameController();

    virtual ~CGameController();

    /**@fn         Fun_IsWin
    *  @brief      判断是否获胜
    *  @para       PIECE_COLOR eColor    棋子颜色，COLOR_WHITE为白棋，COLOR_BLACK为黑棋
    *  @para       int iX    在棋盘的横向坐标
    *  @para       int iX    在棋盘的横向坐标
    *  @return     bool    是否获胜，true代表获胜，false相反
    */
    bool Fun_IsWin(PIECE_COLOR eColor, int iX, int iY, const CGameRole** pAllRoles);
};

#endif // GAMECONTROLLER_H
