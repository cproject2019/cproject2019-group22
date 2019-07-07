#include "Qtmainwindow.h"

Qtmainwindow::Qtmainwindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.setting, SIGNAL(clicked()), this, SLOT(slotset()));
	connect(ui.pm, SIGNAL(clicked()), this, SLOT(slotpm()));
	connect(ui.p2p, SIGNAL(clicked()), this, SLOT(slotp2p()));
	connect(ui.leave, SIGNAL(clicked()), this, SLOT(slotleave()));
}
 void Qtmainwindow::slotset()
 {
	 this->hide();
	 setting = new Qtsetting;//指针实例化
	 connect(setting, SIGNAL(sendsignal()), this, SLOT(reshow()));
	 setting->show();
 }
 void Qtmainwindow::slotpm()
 {
	 this->hide();
	 game = new Qtgame;//指针实例化
	 connect(game, SIGNAL(sendsignal()), this, SLOT(reshow()));
	 game->show();
 }
 void Qtmainwindow::slotp2p()
 {
	 this->hide();
	 game = new Qtgame;//指针实例化
	 connect(game, SIGNAL(sendsignal()), this, SLOT(reshow()));
	 game->show();
 }
 void Qtmainwindow::slotleave()
 {
	this-> close();
 }