/********************************************************************************
** Form generated from reading UI file 'library.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARY_H
#define UI_LIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Library
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLineEdit *authorLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *titleLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QComboBox *yearComboBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *filterButton;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *bookTable;
    QHBoxLayout *Add_edit;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *editButton;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer_17;

    void setupUi(QWidget *Library)
    {
        if (Library->objectName().isEmpty())
            Library->setObjectName(QString::fromUtf8("Library"));
        Library->resize(1036, 654);
        verticalLayout = new QVBoxLayout(Library);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 10, -1, 10);
        groupBox = new QGroupBox(Library);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(900, 60));
        horizontalLayoutWidget_4 = new QWidget(groupBox);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 10, 881, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_4 = new QLabel(horizontalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        authorLineEdit = new QLineEdit(horizontalLayoutWidget_4);
        authorLineEdit->setObjectName(QString::fromUtf8("authorLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(authorLineEdit->sizePolicy().hasHeightForWidth());
        authorLineEdit->setSizePolicy(sizePolicy1);
        authorLineEdit->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(authorLineEdit);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_6 = new QLabel(horizontalLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        titleLineEdit = new QLineEdit(horizontalLayoutWidget_4);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));
        sizePolicy1.setHeightForWidth(titleLineEdit->sizePolicy().hasHeightForWidth());
        titleLineEdit->setSizePolicy(sizePolicy1);
        titleLineEdit->setMinimumSize(QSize(200, 0));

        horizontalLayout_4->addWidget(titleLineEdit);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_5 = new QLabel(horizontalLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        yearComboBox = new QComboBox(horizontalLayoutWidget_4);
        yearComboBox->setObjectName(QString::fromUtf8("yearComboBox"));
        yearComboBox->setMinimumSize(QSize(70, 0));

        horizontalLayout_4->addWidget(yearComboBox);

        horizontalSpacer_5 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        filterButton = new QPushButton(horizontalLayoutWidget_4);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        horizontalLayout_4->addWidget(filterButton);

        clearButton = new QPushButton(horizontalLayoutWidget_4);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_4->addWidget(clearButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 10, -1, 10);
        bookTable = new QTableWidget(Library);
        if (bookTable->columnCount() < 3)
            bookTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        bookTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        bookTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        bookTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (bookTable->rowCount() < 5)
            bookTable->setRowCount(5);
        bookTable->setObjectName(QString::fromUtf8("bookTable"));
        bookTable->setFrameShape(QFrame::StyledPanel);
        bookTable->setFrameShadow(QFrame::Sunken);
        bookTable->setLineWidth(1);
        bookTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        bookTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        bookTable->setSortingEnabled(true);
        bookTable->setRowCount(5);
        bookTable->setColumnCount(3);
        bookTable->horizontalHeader()->setCascadingSectionResizes(true);
        bookTable->horizontalHeader()->setDefaultSectionSize(290);
        bookTable->horizontalHeader()->setMinimumSectionSize(50);
        bookTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        bookTable->horizontalHeader()->setStretchLastSection(true);
        bookTable->verticalHeader()->setVisible(false);
        bookTable->verticalHeader()->setHighlightSections(false);

        horizontalLayout_2->addWidget(bookTable);


        verticalLayout->addLayout(horizontalLayout_2);

        Add_edit = new QHBoxLayout();
        Add_edit->setSpacing(6);
        Add_edit->setObjectName(QString::fromUtf8("Add_edit"));
        Add_edit->setContentsMargins(-1, 10, -1, 10);
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Add_edit->addItem(horizontalSpacer_14);

        addButton = new QPushButton(Library);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy2);
        addButton->setMinimumSize(QSize(200, 0));

        Add_edit->addWidget(addButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Add_edit->addItem(horizontalSpacer_15);

        editButton = new QPushButton(Library);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy2.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy2);
        editButton->setMinimumSize(QSize(200, 0));

        Add_edit->addWidget(editButton);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        Add_edit->addItem(horizontalSpacer_16);

        deleteButton = new QPushButton(Library);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy2.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy2);
        deleteButton->setMinimumSize(QSize(200, 0));

        Add_edit->addWidget(deleteButton);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Add_edit->addItem(horizontalSpacer_17);


        verticalLayout->addLayout(Add_edit);


        retranslateUi(Library);

        QMetaObject::connectSlotsByName(Library);
    } // setupUi

    void retranslateUi(QWidget *Library)
    {
        Library->setWindowTitle(QApplication::translate("Library", "Library", nullptr));
        groupBox->setTitle(QApplication::translate("Library", "Filter", nullptr));
        label_4->setText(QApplication::translate("Library", "Author", nullptr));
        label_6->setText(QApplication::translate("Library", "Title", nullptr));
        label_5->setText(QApplication::translate("Library", "Year", nullptr));
        filterButton->setText(QApplication::translate("Library", "Filter", nullptr));
        clearButton->setText(QApplication::translate("Library", "Clear", nullptr));
        QTableWidgetItem *___qtablewidgetitem = bookTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Library", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = bookTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Library", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = bookTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Library", "Year", nullptr));
        addButton->setText(QApplication::translate("Library", "Add new book", nullptr));
        editButton->setText(QApplication::translate("Library", "Edit book", nullptr));
        deleteButton->setText(QApplication::translate("Library", "Delete book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Library: public Ui_Library {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARY_H
