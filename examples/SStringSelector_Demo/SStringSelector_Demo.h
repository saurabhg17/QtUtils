
#ifndef _SSTRINGSELECTOR_DEMO_H_
#define _SSTRINGSELECTOR_DEMO_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include "SStringSelector.h"

class SStringSelector_Demo : public QWidget
{
	Q_OBJECT

public:
	
	SStringSelector_Demo(QWidget* parent=nullptr);
	

private:
	
	QLabel*          mInfoLabel;
	SStringSelector* mStringSelector;
};

#endif // _SSTRINGSELECTOR_DEMO_H_
