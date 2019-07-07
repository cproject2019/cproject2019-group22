#pragma once
#include "Qtmainwindow.h"
#include <QtWidgets/QApplication>
#include<string.h>
#include "Windows.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Qtmainwindow w;

	w.show();





	return a.exec();
}
