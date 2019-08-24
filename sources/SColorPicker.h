
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
