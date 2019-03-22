#ifndef ADDEDITWINDOW_H
#define ADDEDITWINDOW_H

#include <QWidget>
#include <QMap>
#include <QDate>
#include <QDialog>
#include <QMessageBox>
#include <QRegExpValidator>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class AddEditWindow : public QDialog
{
     Q_OBJECT

public:
    AddEditWindow(QDialog *parent = nullptr);
    void showAddWindow(QStringList *newBook);
    void showEditWindow(QStringList *newBook);
private slots:
    void addBook();
    void cancel();

protected:
    QPushButton *addButton;
    QPushButton *cancelButton;
    QLineEdit *authorLine;
    QLineEdit *titleLine;
    QLineEdit *yearLine;

    QStringList *newBook;
};

#endif // ADDEDITWINDOW_H
