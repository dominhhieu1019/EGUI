#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Library)
{
    ui->setupUi(this);
    ui->bookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->yearComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);
    readInputFile();
    this->book = new QStringList;
    addEditDialog = new AddEditWindow;
}

Library::~Library()
{
    writeOutputFile();
    delete book;
    delete addEditDialog;
    delete ui;
}

void Library::readInputFile()
{
    QFile file("book_data.txt");
    QString data;
    QStringList rowOfData;
    QStringList rowData;
    int colNum = 3;                                     // number of columns

    data.clear();
    rowOfData.clear();
    rowData.clear();


    if (file.open(QFile::ReadOnly | QIODevice::Text))
    {
        data = file.readAll();
        rowOfData = data.split("\n");
        ui->bookTable->setRowCount(rowOfData.size()-1);
        ui->bookTable->setColumnCount(colNum);
        file.close();
    }

    for (int row = 0; row < rowOfData.size(); row++)
    {
        rowData = rowOfData.at(row).split("$");
        for (int col = 0; col < rowData.size(); col++)
        {
            QTableWidgetItem* tableItem = new QTableWidgetItem(rowData.at(col));
            ui->bookTable->setItem(row, col, tableItem);
            if(col == colNum - 1)
                yearList.push_back(rowData.at(col));
        }
    }
    updateYearBox();

    /*QFile file("book.txt");
    QStringList bookInfo;
    const int columnNumber = 3;
    int row = 0;                            //row number

    if (file.open(QIODevice::ReadOnly))
    {
        QTableWidgetItem* tableItem = new QTableWidgetItem("bookInfo.at(x)");
        //tableItem->setText("bookInfo.at(x)");
        ui->bookTable->setItem(1, 2, tableItem);
        ui->bookTable->setColumnCount(columnNumber);
        while(!file.atEnd())
        {
            QString line = file.readLine(); //read each line of the input file
            bookInfo = line.split("#");
            ui->bookTable->insertRow(row);
            for(int x = 0; x < columnNumber; x++)
            {
                QTableWidgetItem* tableItem = new QTableWidgetItem(bookInfo.at(x));
                ui->bookTable->setItem(row, x, tableItem);
            }
            row++;
        }
    }
    file.close();
    */
}

void Library::on_filterButton_clicked()
{
    filter();
}

void Library::on_clearButton_clicked()
{
    clear();
}

void Library::on_addButton_clicked()
{
    addBook();
}

void Library::on_editButton_clicked()
{
    editBook();
}

void Library::on_bookTable_itemDoubleClicked(QTableWidgetItem *item)
{
    editBook();
}


void Library::on_deleteButton_clicked()
{
    deleteBook();
}

void Library::filter()
{
    QString titleSearch = ui->titleLineEdit->text();
    QString authorSearch = ui->authorLineEdit->text();
    QString yearSearch = ui->yearComboBox->currentText();

    int rowNum = resetFilter();
    for (int row = 0; row < rowNum; row++)
    {
        if (!(ui->bookTable->item(row, AUTHOR_COL)->text().contains(authorSearch))
              || !(ui->bookTable->item(row, TITLE_COL)->text().contains(titleSearch))
                || (ui->bookTable->item(row, YEAR_COL)->text() != yearSearch && !yearSearch.isEmpty()))
            ui->bookTable->setRowHidden(row, true);
    }
}

int Library::resetFilter()
{
    int rowNum = ui->bookTable->rowCount();
    for (int row = 0; row < rowNum; row++)
        ui->bookTable->setRowHidden(row, false);

    return rowNum;
}

void Library::clear()
{
    resetFilter();
    foreach(QLineEdit *text, findChildren<QLineEdit*>())        //clear all QLineEdit
        text->clear();
}

void Library::addBook()
{
    book->clear();
    addEditDialog->showAddWindow(book);
    addEditDialog->exec();

    if (!book->isEmpty())
    {
        if (!checkBookExist(book))
        {
            int row = ui->bookTable->rowCount();
            ui->bookTable->insertRow(row);
            editRow(row);

            //update yearComboBox
            yearList.push_back(book->at(YEAR_COL));
            updateYearBox();

            QMessageBox::information(this, tr("Add Successful"),
                                     tr("Book has been added to library data."));
        }
        else
            QMessageBox::critical(this, tr("Add Unsuccessful"),
                                     tr("Book is already in the library data."));
    }
}

void Library::editBook()
{
    if (!ui->bookTable->currentItem())
    {
        QMessageBox::information(this, tr("Select book"),
                                 tr("Select book to edit."));
        return;
    }

    book->clear();
    int row = ui->bookTable->currentRow();
    book->push_back(ui->bookTable->item(row, AUTHOR_COL)->text());
    book->push_back(ui->bookTable->item(row, TITLE_COL)->text());
    book->push_back(ui->bookTable->item(row, YEAR_COL)->text());
    const QString oldYear = book->at(YEAR_COL);
    addEditDialog->showEditWindow(book);
    addEditDialog->exec();

    if (!book->isEmpty())
    {
        if (!checkBookExist(book))
        {
            editRow(row);
            if ((ui->bookTable->findItems(oldYear, Qt::MatchExactly)).isEmpty())
                yearList.removeAll(oldYear);

            //update yearComboBox
            yearList.push_back(book->at(YEAR_COL));
            updateYearBox();

            QMessageBox::information(this, tr("Edit Successful"),
                                     tr("Book has been edited successfully."));
        }
        else
            QMessageBox::critical(this, tr("Edit Unsuccessful"),
                                     tr("EDIT UNSUCCESSFUL"));
    }
}

bool Library::checkBookExist(QStringList *newBook)
{
    QList<QTableWidgetItem *> items = ui->bookTable->findItems(newBook->at(TITLE_COL), Qt::MatchExactly);
    for (int i = 0; i < items.count(); i++)
    {
        int rowItem = ui->bookTable->row(items.at(i));
        if (ui->bookTable->item(rowItem, AUTHOR_COL)->text() == newBook->at(AUTHOR_COL)       //check if same book
                 && ui->bookTable->item(rowItem, YEAR_COL)->text() == newBook->at(YEAR_COL))
        {
            return true;
        }
    }
    return false;
}

void Library::editRow(int row)
{
    for (int i = 0; i < 3; i++)
    {
        QTableWidgetItem* tableItem = new QTableWidgetItem(book->at(i));
        ui->bookTable->setItem(row, i, tableItem);
    }
    //preserve filter
    if (!(book->at(AUTHOR_COL).contains(ui->authorLineEdit->text()))
          || !(book->at(TITLE_COL).contains(ui->titleLineEdit->text()))
            || (book->at(YEAR_COL) != ui->yearComboBox->currentText()
                && !ui->yearComboBox->currentText().isEmpty()))
        ui->bookTable->setRowHidden(row, true);
}

void Library::deleteBook()
{
    QModelIndexList rowSelected = ui->bookTable->selectionModel()->selectedRows();
    if (rowSelected.isEmpty())
    {
        QMessageBox::information(this, tr("Select book"),
                                 tr("Select book to delete."));
        return;
    }

    int button = QMessageBox::question(this, tr("Confirm Delete"),
                                       tr("Are you sure you want to delete selected book?"),
                                       QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::Yes)
    {
        QStringList oldYear;
        oldYear.clear();

        for (int i = 0; i < rowSelected.count(); i++)
        {
            oldYear.push_back(ui->bookTable->item(rowSelected.at(i).row(), YEAR_COL)->text());
            ui->bookTable->removeRow(rowSelected.at(i).row());
        }

        for (auto i : oldYear)
        {
            if ((ui->bookTable->findItems(i, Qt::MatchExactly)).isEmpty())
                yearList.removeAll(i);
        }
        updateYearBox();
    }
}

void Library::writeOutputFile()
{
    QFile file("book_data.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        return;

    QTextStream out(&file);
    int colNum = ui->bookTable->columnCount();
    for(int row = 0; row < ui->bookTable->rowCount(); row++)
        for(int col = 0; col < colNum; col++)
        {
            if(col == colNum - 1)
                out << ui->bookTable->item(row, col)->text() << endl;
            else
                out << ui->bookTable->item(row, col)->text() << "$";
        }
    file.close();
}

void Library::updateYearBox()
{
    yearList.sort();
    yearList.removeDuplicates();
    const QString oldYearComboBox = ui->yearComboBox->currentText();
    ui->yearComboBox->clear();
    ui->yearComboBox->addItems(yearList);
    if (yearList.contains(oldYearComboBox))
        ui->yearComboBox->setCurrentText(oldYearComboBox);
}

