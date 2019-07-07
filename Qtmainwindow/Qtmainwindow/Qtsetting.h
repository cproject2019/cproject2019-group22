#pragma once

#include <QWidget>
#include "ui_Qtsetting.h"
#include <QButtonGroup>
#include <QDebug>

class Qtsetting : public QWidget
{
	Q_OBJECT

public:
	Qtsetting(QWidget *parent = Q_NULLPTR);
	~Qtsetting();
	private slots:
	void slotback1();
	
	void soundbs(int);
	void slotcontrol1();

	int slotmusic();

	int slotdifficulty();
	int slotsound();
private:
	QButtonGroup *music;

		QButtonGroup *difficulty;
		QButtonGroup *control1;
		QButtonGroup *sound;


private:
	Ui::Qtsetting ui;
};

