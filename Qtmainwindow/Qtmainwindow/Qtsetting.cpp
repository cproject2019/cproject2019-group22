#include "Qtsetting.h"
#include<QtMultimedia/qmediaplayer.h>
#include<QUrl>


Qtsetting::Qtsetting(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	music = new QButtonGroup(this);
	music->addButton(ui.music1, 0);
	music->addButton(ui.music2, 1);
	music->addButton(ui.music3, 2);
	ui.music1->setChecked(true);
	
	difficulty = new QButtonGroup(this);
	difficulty->addButton(ui.dsimple, 0);
	difficulty->addButton(ui.dmid, 1);
	difficulty->addButton(ui.ddifficult, 2);
	ui.dsimple->setChecked(true);

	control1 = new QButtonGroup(this);
	control1->addButton(ui.mouse, 0);
	control1->addButton(ui.key, 1);
	ui.mouse->setChecked(true);


	sound = new QButtonGroup(this);
	sound->addButton(ui.soundon, 0);
	sound->addButton(ui.soundoff, 1);
	ui.soundon->setChecked(true);




	connect(ui.back1, SIGNAL(clicked()), this, SLOT(slotback1()));
	connect(sound, SIGNAL(clicked()), this, SLOT(slotsound()));
	
	connect(control1, SIGNAL(clicked()), this, SLOT(slotcontrol1()));
	
	connect(music, SIGNAL(clicked()), this, SLOT(slotmusic()));
	
	connect(difficulty, SIGNAL(clicked()), this, SLOT(slotdifficulty()));
	
	connect(ui.soundbs, SIGNAL(QSlider::valueChanged(int)), this, SLOT(slotmusic(int)));
}


void Qtsetting::slotback1()
{

	this->hide();

}
int Qtsetting::slotsound()
{
	return  sound->checkedId();
}

int Qtsetting::slotmusic()
{  
	return music->checkedId();
	
	
}
void Qtsetting::soundbs(int value)
{
	int pos = ui.soundbs->value();
	QMediaPlayer *player = new QMediaPlayer();
	int a = Qtsetting::slotmusic();
	switch (a)
	{

	case 0:

		player = new QMediaPlayer;
		connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
		player->setMedia(QUrl::fromLocalFile("F:\\C PROJECT\\background1.mp3"));
		player->setVolume(pos);
		player->play();
		break;

	case 1:
		player = new QMediaPlayer;
		connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
		player->setMedia(QUrl::fromLocalFile("F:\\C PROJECT\\background2.mp3"));
		player->setVolume(pos);
		player->play();

		break;
	case 2:
		player = new QMediaPlayer;
		connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
		player->setMedia(QUrl::fromLocalFile("F:\\C PROJECT\\background3.mp3"));
		player->setVolume(pos);
		player->play();
		break;

	}
	

}


 int Qtsetting::slotdifficulty()
{
	return difficulty->checkedId();
}


 

void Qtsetting::slotcontrol1()
{
	
}





Qtsetting::~Qtsetting()
{
	
}
