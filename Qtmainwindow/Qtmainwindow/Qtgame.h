#pragma once

#include <QWidget>
#include "ui_Qtgame.h"

class Qtgame : public QWidget
{
	Q_OBJECT

public:
	Qtgame(QWidget *parent = Q_NULLPTR);
	~Qtgame();
	private slots:
	void slotback2();
signals:
	void sendsignal();
private:
	Ui::Qtgame ui;
};
