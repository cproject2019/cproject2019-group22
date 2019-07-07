#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qtmainwindow.h"
#include "Qtgame.h"
#include "Qtsetting.h"

class Qtmainwindow : public QMainWindow
{
	Q_OBJECT

public:
	Qtmainwindow(QWidget *parent = Q_NULLPTR);

	private slots:
	void slotset();
	void slotpm();
	void slotp2p();
	void slotleave();


private:
	Ui::QtmainwindowClass ui;
	
	Qtgame *game;
private:
	Qtsetting *setting;
};
