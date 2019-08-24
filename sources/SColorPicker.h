
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

#ifndef _SCOLORPICKER_H_
#define _SCOLORPICKER_H_

#include <QtGui/QColor>
#include <QtGui/QMouseEvent>
#include <QtWidgets/QWidget>

// The SColorPicker class provides a widget for picking colors using system color dialog.
class SColorPicker : public QWidget
{
	Q_OBJECT
	
public:
	
	SColorPicker(QWidget *parent = nullptr);
	SColorPicker(const QColor& color, const QString& title, QWidget *parent = Q_NULLPTR);
	
	inline QColor  color() const {return mColor;}
	inline QString title() const {return windowTitle();}
	
	inline void setColor(const QColor& color)  {mColor = color;}
	inline void setTitle(const QString& title) {setWindowTitle(title);}
	

public slots:
	
	void pickColor();
	

signals:
	
	void colorPicked(const QColor& color);
	

protected:
	
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	virtual void paintEvent(QPaintEvent*) override;


private:
	
	void _setBackColor();
	
private:
	
	QColor mColor;
};

#endif // _BEMSOLVER_QCOLORPICKER_H_
