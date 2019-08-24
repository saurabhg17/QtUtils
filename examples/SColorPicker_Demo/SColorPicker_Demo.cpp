
#include "SColorPicker_Demo.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
SColorPicker_Demo::SColorPicker_Demo(QWidget* parent)
	: QWidget(parent)
{
	setFixedSize(512, 512);
	
	mColorLabel    = new QLabel("Pick a color");
	mColorPicker   = new SColorPicker();
	mSelectedColor = new QLabel("");

	QHBoxLayout* _hLayout = new QHBoxLayout();
	_hLayout->addStretch();
	_hLayout->addWidget(mColorLabel);
	_hLayout->addWidget(mColorPicker);
	_hLayout->addStretch();
	
	QVBoxLayout* _vLayout = new QVBoxLayout();
	_vLayout->addLayout(_hLayout);
	_vLayout->addWidget(mSelectedColor);
	_vLayout->setSpacing(20);
	_vLayout->setContentsMargins(20, 20, 20, 20);

	this->setLayout(_vLayout);
	colorPicked(mColorPicker->color());
	connect(mColorPicker, &SColorPicker::colorPicked, this, &SColorPicker_Demo::colorPicked);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SColorPicker_Demo::colorPicked(const QColor& color)
{
	QString _color      = color.name(QColor::HexRgb);
	QString _styleSheet = QString("border: 1px solid black; background-color: %1;").arg(_color);
	mSelectedColor->setStyleSheet(_styleSheet);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
