
#include "SStringSelector.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHeaderView>

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
SStringSelector::SStringSelector(QWidget* parent) : QWidget(parent)
{
	mCurrentSelection      = nullptr;
	mFilterPlaceholderText = "Filter items";
	mSelectionDialogTitle  = "Select an item";
	_createDisplayWidget();
	_createSelectionDialog();
}
SStringSelector::SStringSelector(const QStringList& strings, QWidget* parent) : QWidget(parent)
{
	mCurrentSelection = nullptr;
	mFilterPlaceholderText = "Filter items";
	mSelectionDialogTitle = "Select an item";
	_createDisplayWidget();
	_createSelectionDialog();
	setStrings(strings);
}
SStringSelector::~SStringSelector()
{
	delete mSelectionDialog;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SStringSelector::setStrings(const QStringList& strings)
{
	mStrings          = strings;
	mCurrentSelection = nullptr;
	_addStringsToListWidget();
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
QString SStringSelector::selectedString() const
{
	return (mCurrentSelection != nullptr) ? mCurrentSelection->text() : QString();
}
int SStringSelector::selectedStringPos() const
{
	return (mCurrentSelection != nullptr) ? mCurrentSelection->data(Qt::UserRole).toInt() : -1;
}
void SStringSelector::setSelectedString(const QString& string)
{
	for(int i=0 ; i<mStrings.count() ; ++i)
	{
		if(string.compare(mStrings[i], Qt::CaseSensitive) == 0)
		{
			mCurrentSelection = mSelectionListWidget->item(i);
			mDisplayLineEdit->setText(selectedString());
			break;
		}
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SStringSelector::showStringSelectionDialog()
{
	mSelectionListWidget->setCurrentItem(mCurrentSelection);
	if(mSelectionDialog->exec() == QDialog::Accepted)
	{
		if(mSelectionListWidget->selectedItems().count() > 0)
		{
			mCurrentSelection = mSelectionListWidget->selectedItems()[0];
		}
		else
		{
			mCurrentSelection = nullptr;
		}
		
		emit stringSelected(selectedString());
		mDisplayLineEdit->setText(selectedString());
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SStringSelector::searchForString(const QString& string)
{
	if(string.isEmpty())
	{
		for(int i=0 ; i<mStrings.count() ; ++i)
		{
			mSelectionListWidget->item(i)->setHidden(false);
		}
	}
	else
	{
		for(int i=0 ; i<mStrings.count() ; ++i)
		{
			if(mStrings[i].contains(string, Qt::CaseInsensitive))
			{
				mSelectionListWidget->item(i)->setHidden(false);
			}
			else
			{
				mSelectionListWidget->item(i)->setHidden(true);
			}
		}
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SStringSelector::stringItemDoubleClicked(QListWidgetItem*)
{
	mSelectionDialog->accept();
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SStringSelector::_createDisplayWidget()
{
	mDisplayLineEdit = new QLineEdit();
	mDisplayLineEdit->setReadOnly(true);

	mDisplayBrowseButton = new QPushButton("...");
	mDisplayBrowseButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	mDisplayBrowseButton->setMaximumWidth(20);
	connect(mDisplayBrowseButton, &QPushButton::clicked, this, &SStringSelector::showStringSelectionDialog);
	
	QHBoxLayout* _layout = new QHBoxLayout();
	_layout->addWidget(mDisplayLineEdit);
	_layout->addWidget(mDisplayBrowseButton);
	_layout->setContentsMargins(0, 0, 0, 0);
	_layout->setSpacing(10);
	setLayout(_layout);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SStringSelector::_createSelectionDialog()
{
	mSelectionDialog = new QDialog();
	mSelectionDialog->setSizeGripEnabled(true);
	mSelectionDialog->setWindowTitle(mSelectionDialogTitle);

	mSelectionSearchBox = new QLineEdit();
	mSelectionSearchBox->addAction(QIcon(":/Nakul_Widgets/Search.ico"), QLineEdit::LeadingPosition);
	mSelectionSearchBox->setClearButtonEnabled(true);
	mSelectionSearchBox->setPlaceholderText(mFilterPlaceholderText);
	mSelectionSearchBox->setToolTip(mFilterPlaceholderText);
	connect(mSelectionSearchBox, &QLineEdit::textChanged, this, &SStringSelector::searchForString);
	
	mSelectionListWidget = new QListWidget();
	mSelectionListWidget->setSelectionMode(QListWidget::SingleSelection);
	_addStringsToListWidget();
	connect(mSelectionListWidget, &QListWidget::itemDoubleClicked, this, &SStringSelector::stringItemDoubleClicked);
	
	mSelectionDialogOkButton = new QPushButton("OK");
	mSelectionDialogOkButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	mSelectionDialogOkButton->setDefault(true);
	connect(mSelectionDialogOkButton, &QPushButton::clicked, mSelectionDialog, &QDialog::accept);
	
	mSelectionDialogCancelButton = new QPushButton("Cancel");
	mSelectionDialogCancelButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	connect(mSelectionDialogCancelButton, &QPushButton::clicked, mSelectionDialog, &QDialog::reject);
	
	QHBoxLayout* _layout = new QHBoxLayout();
	_layout->addStretch();
	_layout->addWidget(mSelectionDialogOkButton);
	_layout->addWidget(mSelectionDialogCancelButton);
	_layout->addStretch();
	
	QVBoxLayout* _mainLayout = new QVBoxLayout();
	_mainLayout->addWidget(mSelectionSearchBox);
	_mainLayout->addWidget(mSelectionListWidget);
	_mainLayout->addLayout(_layout);
	_mainLayout->setContentsMargins(10, 10, 10, 10);
	_mainLayout->setSpacing(10);
	mSelectionDialog->setLayout(_mainLayout);
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void SStringSelector::_addStringsToListWidget()
{
	mSelectionListWidget->clear();
	for(int i=0 ; i<mStrings.count() ; ++i)
	{
		QListWidgetItem* _item = new QListWidgetItem(mStrings[i]);
		_item->setData(Qt::UserRole, i);
		mSelectionListWidget->addItem(_item);
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
