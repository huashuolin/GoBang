#include "GameController.h"


CGameController::CGameController()
{

}

CGameController::~CGameController()
{

}

bool CGameController::Fun_IsWin(PIECE_COLOR eColor, int iX, int iY, const CGameRole** pAllRoles)
{
    if(nullptr == pAllRoles)
    {
        return false;
    }

    //判断左上—右下方向（以刚落下的棋子为中心，加上前后各4颗）是否有连续5个同样的棋子
    {
        int iContinueCount = 0; //和刚落下棋子颜色相同的连续的棋子个数
        int iMovePosX = iX - 4;
        int iMovePosY = iY - 4;
        for(; iMovePosX <= iX + 4 && iMovePosY <= iY + 4; iMovePosX++, iMovePosY++)
        {
            if(iMovePosX >= 0 && iMovePosY >= 0 && iMovePosX < GRID_NUM && iMovePosY < GRID_NUM && nullptr != pAllRoles[iMovePosX] && true == pAllRoles[iMovePosX][iMovePosY].Fun_IsHavePiece() && pAllRoles[iMovePosX][iMovePosY].Fun_GetPieceColor() == eColor)
            {
                iContinueCount++;
            }
            else
            {
                iContinueCount = 0;
            }
            if(5 == iContinueCount)
            {
                return true;
            }
        }
    }

    //判断左-右方向（以刚落下的棋子为中心，加上前后各4颗）是否有连续5个同样的棋子
    {
        int iContinueCount = 0;
        int iMovePosX = iX - 4;
        int iMovePosY = iY;
        for(; iMovePosX <= iX + 4 ; iMovePosX++)
        {
            if(iMovePosX >= 0 && iMovePosY >= 0 && iMovePosX < GRID_NUM && iMovePosY < GRID_NUM && nullptr != pAllRoles[iMovePosX] && true == pAllRoles[iMovePosX][iMovePosY].Fun_IsHavePiece() && pAllRoles[iMovePosX][iMovePosY].Fun_GetPieceColor() == eColor)
            {
                iContinueCount++;
            }
            else
            {
                iContinueCount = 0;
            }
            if(5 == iContinueCount)
            {
                return true;
            }
        }
    }

    //判断左下-右上方向（以刚落下的棋子为中心，加上前后各4颗）是否有连续5个同样的棋子
    {
        int iContinueCount = 0;
        int iMovePosX = iX - 4;
        int iMovePosY = iY + 4;
        for(; iMovePosX <= iX + 4 && iMovePosY >= iY - 4 ; iMovePosX++, iMovePosY--)
        {
            if(iMovePosX >= 0 && iMovePosY >= 0 && iMovePosX < GRID_NUM && iMovePosY < GRID_NUM && nullptr != pAllRoles[iMovePosX] && true == pAllRoles[iMovePosX][iMovePosY].Fun_IsHavePiece() && pAllRoles[iMovePosX][iMovePosY].Fun_GetPieceColor() == eColor)
            {
                iContinueCount++;
            }
            else
            {
                iContinueCount = 0;
            }
            if(5 == iContinueCount)
            {
                return true;
            }
        }
    }

    //判断上-下方向（以刚落下的棋子为中心，加上前后各4颗）是否有连续5个同样的棋子
    {
        int iContinueCount = 0;
        int iMovePosX = iX;
        int iMovePosY = iY -4 ;
        for(; iMovePosY <= iY + 4 ; iMovePosY++)
        {
            if(iMovePosX >= 0 && iMovePosY >= 0 && iMovePosX < GRID_NUM && iMovePosY < GRID_NUM && nullptr != pAllRoles[iMovePosX] && true == pAllRoles[iMovePosX][iMovePosY].Fun_IsHavePiece() && pAllRoles[iMovePosX][iMovePosY].Fun_GetPieceColor() == eColor)
            {
                iContinueCount++;
            }
            else
            {
                iContinueCount = 0;
            }
            if(5 == iContinueCount)
            {
                return true;
            }
        }
    }
    return false;
}
