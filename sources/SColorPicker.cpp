
// This file is part of SLogLib; you can redistribute it and/or
// modify it under the terms of the MIT License.
// 
// Copyright (c) 2019 Saurabh Garg
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 
// Authors: Saurabh Garg (saurabhgarg@mysoc.net)

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
