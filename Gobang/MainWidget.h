#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "ui_MainWidget.h"

//测试
class CMainWidget : public QWidget
{
    Q_OBJECT

public:
    CMainWidget(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~CMainWidget();

private:
    Ui::CMainWidgetClass ui;

signals:
    void Signal_PieceClick(PIECE_COLOR eColor);

public slots:
    void Slot_BlackPieceClick();
    void Slot_WhitePieceClick();
    void Slot_PiecePlay(PIECE_COLOR eColor);

};

#endif // MAINWIDGET_H
