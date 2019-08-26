
#include "SStringSelector_Demo.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
SStringSelector_Demo::SStringSelector_Demo(QWidget* parent)
	: QWidget(parent)
{
	setFixedSize(300, 150);
	setWindowTitle("SStringSelector Demo");
	
	mInfoLabel      = new QLabel("Select a string:");
	mStringSelector = new SStringSelector();
	
	QVBoxLayout* _vLayout = new QVBoxLayout();
	_vLayout->addWidget(mInfoLabel);
	_vLayout->addWidget(mStringSelector);
	_vLayout->addStretch();
	_vLayout->setSpacing(20);
	_vLayout->setContentsMargins(20, 20, 20, 20);
	this->setLayout(_vLayout);

	QStringList _colors = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Brown", "Magenta",
		"Tan", "Cyan", "Olive", "Maroon", "Navy", "Aquamarine", "Turquoise", "Silver", "Lime",
		"Teal", "Indigo", "Violet", "Pink", "Black", "White", "Gray"};
	mStringSelector->setStrings(_colors);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
