#include "MainWidget.h"

CMainWidget::CMainWidget(QWidget *parent,  Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    ui.setupUi(this);

    connect(ui.pushButton_blackPiece, SIGNAL(clicked()), this, SLOT(Slot_BlackPieceClick()));
    connect(ui.pushButton_whitePiece, SIGNAL(clicked()), this, SLOT(Slot_WhitePieceClick()));
    connect(this, SIGNAL(Signal_PieceClick(PIECE_COLOR)), ui.widget_chessboard, SLOT(Slot_SelectPiece(PIECE_COLOR)));
    connect(ui.widget_chessboard, SIGNAL(Signal_PiecePlay(PIECE_COLOR)), this, SLOT(Slot_PiecePlay(PIECE_COLOR)));
    connect(ui.pushButton_restart, SIGNAL(clicked()), ui.widget_chessboard, SLOT(Slot_ReStartGame()));
}

CMainWidget::~CMainWidget()
{

}

void CMainWidget::Slot_BlackPieceClick()
{
    ui.pushButton_blackPiece->setChecked(true);
    ui.pushButton_whitePiece->setChecked(false);
    emit Signal_PieceClick(COLOR_BLACK);
}

void CMainWidget::Slot_WhitePieceClick()
{
    ui.pushButton_blackPiece->setChecked(false);
    ui.pushButton_whitePiece->setChecked(true);
    emit Signal_PieceClick(COLOR_WHITE);
}

void CMainWidget::Slot_PiecePlay(PIECE_COLOR eColor)
{
    if(COLOR_BLACK == eColor)
    {
        ui.pushButton_blackPiece->setChecked(false);
        ui.pushButton_whitePiece->setChecked(true);
        emit Signal_PieceClick(COLOR_WHITE);
    }
    else
    {
        ui.pushButton_blackPiece->setChecked(true);
        ui.pushButton_whitePiece->setChecked(false);
        emit Signal_PieceClick(COLOR_BLACK);
    }
}
