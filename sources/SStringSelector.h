
#ifndef _SStringSelector_H_
#define _SStringSelector_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDialog>

// The SStringSelector class is a widget which allows a user to select a single string 
// from a list of predefined strings.
// 
// SStringSelector widget has two sections: display and selection.
// Display  section is the default view and shows the currently selected item and a browse button.
// When a user click browser button, selection section is presented to the user. It consists of a 
// dialog, containing a list of all string to select from and a line edit to filter string.
class SStringSelector : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString filterPlaceholderText READ filterPlaceholderText WRITE setFilterPlaceholderText DESIGNABLE true)
	Q_PROPERTY(QString selectionDialogTitle  READ selectionDialogTitle  WRITE setSelectionDialogTitle  DESIGNABLE true)
	

public:
	
	SStringSelector(QWidget* parent=nullptr);
	SStringSelector(const QStringList& strings, QWidget* parent = nullptr);
	~SStringSelector();
	
	// Set and get the list of string to choose from.
	void setStrings(const QStringList& strings);
	inline const QStringList& strings() const { return mStrings; }

	// Get and set the currently selected string.
	QString selectedString() const;
	int     selectedStringPos() const;
	void    setSelectedString(const QString& string);
	
	inline void    setFilterPlaceholderText(const QString& x)       {mFilterPlaceholderText = x;}
	inline void    setSelectionDialogTitle(const QString& x)        {mSelectionDialogTitle  = x;}
	inline QString filterPlaceholderText()                    const {return mFilterPlaceholderText;}
	inline QString selectionDialogTitle()                     const {return mSelectionDialogTitle;}


public slots:
	
	void showStringSelectionDialog();
	void searchForString(const QString& string);
	void stringItemDoubleClicked(QListWidgetItem* item);
	

signals:
		
	void stringSelected(const QString& string);
	

private:
	
	void _createDisplayWidget();
	void _createSelectionDialog();
	void _addStringsToListWidget();
	

private:
	
	// Display view widgets.
	QLineEdit*   mDisplayLineEdit;
	QPushButton* mDisplayBrowseButton;

	// Selection view widgets.
	QDialog*     mSelectionDialog;
	QPushButton* mSelectionDialogOkButton;
	QPushButton* mSelectionDialogCancelButton;
	QLineEdit*   mSelectionSearchBox;
	QListWidget* mSelectionListWidget;
	QString      mFilterPlaceholderText;
	QString      mSelectionDialogTitle;
	
	// List of string to select from.
	QStringList      mStrings;
	QListWidgetItem* mCurrentSelection;
};

#endif // _SStringSelector_H_
