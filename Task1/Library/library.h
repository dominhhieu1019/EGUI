#ifndef LIBRARY_H
#define LIBRARY_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QIODevice>

#include "addeditwindow.h"


namespace Ui {
class Library;
}
class AddEditWindow;
class QTableWidgetItem;
//class QModelIndex;

class Library : public QWidget
{
    Q_OBJECT

public:
    explicit Library(QWidget *parent = nullptr);
    ~Library();
    //void setSourceModel(QAbstractItemModel *model);

private slots:
    void on_filterButton_clicked();

    void on_clearButton_clicked();

    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_bookTable_itemDoubleClicked(QTableWidgetItem *item);

    void on_deleteButton_clicked();

private:
    Ui::Library *ui;
    AddEditWindow *addEditDialog;
    QStringList *book;                  //save chosen book data or new book
    QStringList yearList = {""};               //list year of year combobox
    const int AUTHOR_COL = 0;
    const int TITLE_COL = 1;
    const int YEAR_COL = 2;

    void readInputFile();
    void filter();
    int resetFilter();
    void clear();
    void addBook();
    void editBook();
    bool checkBookExist(QStringList *book);
    void editRow(int row);              //edit book at 'row'
    void deleteBook();
    void writeOutputFile();
    void updateYearBox();                    //add year items to yearComboBox

};

#endif // LIBRARY_H
