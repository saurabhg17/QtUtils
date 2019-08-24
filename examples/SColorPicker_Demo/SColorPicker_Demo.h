
#ifndef _SCOLORPICKER_DEMO_H_
#define _SCOLORPICKER_DEMO_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include "SColorPicker.h"

class SColorPicker_Demo : public QWidget
{
	Q_OBJECT

public:
	
	SColorPicker_Demo(QWidget* parent = nullptr);
	

public slots:
	
	void colorPicked(const QColor& color);

	
private:
	
	QLabel*       mColorLabel;
	SColorPicker* mColorPicker;
	QLabel*       mSelectedColor;
};

#endif // _SCOLORPICKER_DEMO_H_
