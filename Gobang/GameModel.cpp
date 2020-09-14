#include "GameModel.h"

#include <QDebug>

#include <stdio.h>
#include <math.h>
#include <string.h>

CGameModel::CGameModel()
{
    m_pAllRoles = new CGameRole*[GRID_NUM];
    for(int i = 0; i < GRID_NUM; ++i)
    {
        m_pAllRoles[i] = new CGameRole[GRID_NUM];
    }
    Fun_Reset();
}

CGameModel::~CGameModel()
{
    if(nullptr != m_pAllRoles)
    {
        for(int i = 0; i < GRID_NUM; ++i)
        {
            if(nullptr != m_pAllRoles[i])
            {
                delete[] m_pAllRoles[i];
                m_pAllRoles[i] = nullptr;
            }
        }
        delete[] m_pAllRoles;
    }
}

void CGameModel::Fun_Reset()
{
    //复位每个棋盘点的数据
    for(int i = 0; i < GRID_NUM; ++i)
    {
        for(int j = 0; j < GRID_NUM; ++j)
        {
            if(nullptr != m_pAllRoles[i])
            {
                m_pAllRoles[i][j].Fun_Reset();
            }
        }
    }
}

CGameRole* CGameModel::Fun_GetRoll(int iX, int iY)
{
    return &m_pAllRoles[iX][iY];
}

bool CGameModel::Fun_AddPiece(PIECE_COLOR eColor, int iX, int iY)
{
    if(nullptr == m_pAllRoles[iX] || m_pAllRoles[iX][iY].Fun_IsHavePiece())
    {
        return false;
    }

    m_pAllRoles[iX][iY].Fun_SetData(eColor, iX, iY);
    return true;
}
