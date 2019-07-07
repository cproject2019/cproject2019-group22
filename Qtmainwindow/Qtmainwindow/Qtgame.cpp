#include "Qtgame.h"

Qtgame::Qtgame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.back2, SIGNAL(clicked()), this, SLOT(slotback2()));
}

void Qtgame::slotback2()
{
	emit sendsignal();
	this->hide();

}
Qtgame::~Qtgame()
{
}
