
#include <QtWidgets/QColorDialog>
#include <QtWidgets/QStyleOption>
#include <QtGui/QPainter>
#include "SColorPicker.h"

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
SColorPicker::SColorPicker(QWidget* parent) : QWidget(parent)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setFixedSize(16, 16);
	setWindowTitle("Choose a color");
	mColor = QColor::fromRgbF(1, 1, 1);
	_setBackColor();
}
SColorPicker::SColorPicker(const QColor& color, const QString& title, QWidget *parent) : QWidget(parent)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setFixedSize(16, 16);
	setWindowTitle(title);
	mColor = color;
	_setBackColor();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SColorPicker::pickColor()
{
	QColor _color = QColorDialog::getColor(mColor, dynamic_cast<QWidget*>(parent()), windowTitle());
	if(_color.isValid())
	{
		mColor = _color;
		_setBackColor();
		colorPicked(mColor);
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SColorPicker::mouseReleaseEvent(QMouseEvent*)
{
	pickColor();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
// Paint event is required for applying style sheets in a widget sub-classed from QWidget.
void SColorPicker::paintEvent(QPaintEvent*)
{
	QStyleOption _option;
	_option.initFrom(this);

	QPainter _painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &_option, &_painter, this);
};
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SColorPicker::_setBackColor()
{
	// Using stylesheet instead of QPalette according to the Qt documentation:
	// "However, this wasn't guaranteed to work for all styles, because style authors 
	// are restricted by the different platforms' guidelines and (on Windows and macOS) 
	// by the native theme engine."
	// https://doc.qt.io/qt-5.12/stylesheet.html.
	
	QString _color = mColor.name(QColor::HexRgb);
	QString _styleSheet = QString("background-color: %1;").arg(_color);
	QWidget::setStyleSheet(_styleSheet);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
