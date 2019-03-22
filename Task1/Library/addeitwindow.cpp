#include <QtWidgets>
#include "addeditwindow.h"

AddEditWindow::AddEditWindow(QDialog *parent)
    : QDialog (parent)
{
    setModal(true);
    this-> newBook = new QStringList;
//  window declaration
    QLabel *authorLabel = new QLabel(tr("Author:"));
    authorLine = new QLineEdit;

    QLabel *titleLabel = new QLabel(tr("Title:"));
    titleLine = new QLineEdit;

    QLabel *yearLabel = new QLabel(tr("Year:"));
    yearLine = new QLineEdit;
    QRegExp rx("[0-9]\\d{0,3}");
    yearLine->setValidator(new QRegExpValidator(rx, this));

    addButton = new QPushButton(tr("&Add"));
    addButton->show();

    cancelButton = new QPushButton(tr("&Cancel"));
    cancelButton->show();

//  connecting signals and slots
    connect(addButton, SIGNAL(clicked()), this, SLOT(addBook()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

//  setting layout
    const QSize BUTTON_SIZE = QSize(80, 25);
    addButton->setFixedSize(BUTTON_SIZE);
    cancelButton->setFixedSize(BUTTON_SIZE);

    QGridLayout *lineEdit = new QGridLayout;
    lineEdit->addWidget(authorLabel, 0, 0);
    lineEdit->addWidget(authorLine, 0, 1);
    lineEdit->addWidget(titleLabel, 1, 0);
    lineEdit->addWidget(titleLine, 1, 1);
    lineEdit->addWidget(yearLabel, 2, 0);
    lineEdit->addWidget(yearLine, 2, 1);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(lineEdit, Qt::AlignTop);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    setMinimumSize(400, 250);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowFlags(Qt::Tool);
}

void AddEditWindow::showAddWindow(QStringList *newBook)
{
    authorLine->clear();
    titleLine->clear();
    yearLine->clear();

    addButton->setText(tr("&Add"));
    setWindowTitle(tr("Add Book"));

    this->newBook = newBook;

    show();
}

void AddEditWindow::showEditWindow(QStringList *newBook)
{
    authorLine->setText(newBook->at(0));
    titleLine->setText(newBook->at(1));
    yearLine->setText(newBook->at(2));

    addButton->setText(tr("&Save"));
    setWindowTitle(tr("Edit Book"));

    this->newBook = newBook;

    show();
}

void AddEditWindow::addBook()
{
    QString author, title, year;

    author.clear();
    title.clear();
    year.clear();
    author = authorLine->text();
    title = titleLine->text();
    year = yearLine->text();

    if (author.isEmpty() || title.isEmpty() || year.isEmpty() || (year.toInt() > QDate::currentDate().year()))
    {
        QMessageBox::information(this, tr("Invalid information"),
                              tr("Please enter valid author, title and year."));
        return;
    }

    newBook->clear();
    newBook->push_back(author);
    newBook->push_back(title);
    newBook->push_back(year);
    close();
}

void AddEditWindow::cancel()
{
    newBook->clear();
    close();
}

