#pragma once

#include <QtWidgets/QWidget>
#include "ui_XVideoUI.h"

class XVideoUI : public QWidget
{
	Q_OBJECT

public:
	XVideoUI(QWidget *parent = Q_NULLPTR);
	void timerEvent(QTimerEvent *e);//定时刷新进度条

public slots:
	void Open();

private:
	Ui::XVideoUIClass ui;
};
