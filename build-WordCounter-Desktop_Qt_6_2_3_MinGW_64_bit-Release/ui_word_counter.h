/********************************************************************************
** Form generated from reading UI file 'word_counter.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORD_COUNTER_H
#define UI_WORD_COUNTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordCounter
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *window_layout;
    QHBoxLayout *topAreaLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_path_file;
    QHBoxLayout *path_file_Layout;
    QLineEdit *lineEdit_path_file;
    QPushButton *browse_file_button;
    QVBoxLayout *submitLayout;
    QSpacerItem *verticalSpacer_submit;
    QPushButton *path_submit_button;
    QTextEdit *file_outputArea;
    QHBoxLayout *bottomAreaLayout;
    QTableWidget *file_stats_table;
    QVBoxLayout *other_output_Layout;
    QCheckBox *original_folder_checkBox;
    QHBoxLayout *getGraph_button_Layout;
    QSpacerItem *horizontalSpacer_graph_l;
    QPushButton *getGraph_button;
    QSpacerItem *horizontalSpacer_graph_r;

    void setupUi(QMainWindow *WordCounter)
    {
        if (WordCounter->objectName().isEmpty())
            WordCounter->setObjectName(QString::fromUtf8("WordCounter"));
        WordCounter->setWindowModality(Qt::NonModal);
        WordCounter->setEnabled(true);
        WordCounter->resize(633, 533);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WordCounter->sizePolicy().hasHeightForWidth());
        WordCounter->setSizePolicy(sizePolicy);
        WordCounter->setMinimumSize(QSize(633, 533));
        WordCounter->setSizeIncrement(QSize(0, 0));
        WordCounter->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(WordCounter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setSizeIncrement(QSize(0, 0));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        window_layout = new QVBoxLayout();
        window_layout->setObjectName(QString::fromUtf8("window_layout"));
        window_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        topAreaLayout = new QHBoxLayout();
        topAreaLayout->setObjectName(QString::fromUtf8("topAreaLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_path_file = new QLabel(centralwidget);
        label_path_file->setObjectName(QString::fromUtf8("label_path_file"));
        QFont font;
        font.setPointSize(11);
        label_path_file->setFont(font);

        verticalLayout->addWidget(label_path_file);

        path_file_Layout = new QHBoxLayout();
        path_file_Layout->setObjectName(QString::fromUtf8("path_file_Layout"));
        lineEdit_path_file = new QLineEdit(centralwidget);
        lineEdit_path_file->setObjectName(QString::fromUtf8("lineEdit_path_file"));
        QFont font1;
        font1.setItalic(true);
        lineEdit_path_file->setFont(font1);
        lineEdit_path_file->setAutoFillBackground(false);
        lineEdit_path_file->setInputMethodHints(Qt::ImhNone);
        lineEdit_path_file->setDragEnabled(false);
        lineEdit_path_file->setClearButtonEnabled(true);

        path_file_Layout->addWidget(lineEdit_path_file);

        browse_file_button = new QPushButton(centralwidget);
        browse_file_button->setObjectName(QString::fromUtf8("browse_file_button"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        browse_file_button->setFont(font2);

        path_file_Layout->addWidget(browse_file_button);


        verticalLayout->addLayout(path_file_Layout);


        topAreaLayout->addLayout(verticalLayout);

        submitLayout = new QVBoxLayout();
        submitLayout->setObjectName(QString::fromUtf8("submitLayout"));
        verticalSpacer_submit = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Maximum);

        submitLayout->addItem(verticalSpacer_submit);

        path_submit_button = new QPushButton(centralwidget);
        path_submit_button->setObjectName(QString::fromUtf8("path_submit_button"));
        path_submit_button->setFont(font2);

        submitLayout->addWidget(path_submit_button);


        topAreaLayout->addLayout(submitLayout);


        window_layout->addLayout(topAreaLayout);

        file_outputArea = new QTextEdit(centralwidget);
        file_outputArea->setObjectName(QString::fromUtf8("file_outputArea"));
        QFont font3;
        font3.setPointSize(11);
        font3.setItalic(false);
        file_outputArea->setFont(font3);
        file_outputArea->setReadOnly(true);

        window_layout->addWidget(file_outputArea);

        bottomAreaLayout = new QHBoxLayout();
        bottomAreaLayout->setObjectName(QString::fromUtf8("bottomAreaLayout"));
        file_stats_table = new QTableWidget(centralwidget);
        if (file_stats_table->columnCount() < 1)
            file_stats_table->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        file_stats_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (file_stats_table->rowCount() < 5)
            file_stats_table->setRowCount(5);
        QFont font4;
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font4);
        file_stats_table->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        file_stats_table->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        file_stats_table->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        file_stats_table->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        file_stats_table->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        file_stats_table->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        file_stats_table->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        file_stats_table->setItem(2, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        file_stats_table->setItem(3, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        file_stats_table->setItem(4, 0, __qtablewidgetitem10);
        file_stats_table->setObjectName(QString::fromUtf8("file_stats_table"));
        file_stats_table->setEnabled(true);
        file_stats_table->setFont(font4);
        file_stats_table->setFocusPolicy(Qt::StrongFocus);
        file_stats_table->setLineWidth(1);
        file_stats_table->setAutoScroll(true);
        file_stats_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        file_stats_table->setTabKeyNavigation(false);
        file_stats_table->setProperty("showDropIndicator", QVariant(false));
        file_stats_table->setDragDropOverwriteMode(false);
        file_stats_table->setSelectionMode(QAbstractItemView::NoSelection);
        file_stats_table->setSelectionBehavior(QAbstractItemView::SelectItems);
        file_stats_table->setTextElideMode(Qt::ElideNone);
        file_stats_table->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        file_stats_table->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        file_stats_table->setShowGrid(false);
        file_stats_table->setGridStyle(Qt::SolidLine);
        file_stats_table->setWordWrap(true);
        file_stats_table->setCornerButtonEnabled(true);
        file_stats_table->setRowCount(5);
        file_stats_table->setColumnCount(1);
        file_stats_table->horizontalHeader()->setVisible(false);
        file_stats_table->horizontalHeader()->setDefaultSectionSize(100);
        file_stats_table->horizontalHeader()->setHighlightSections(false);
        file_stats_table->horizontalHeader()->setStretchLastSection(false);
        file_stats_table->verticalHeader()->setVisible(true);
        file_stats_table->verticalHeader()->setCascadingSectionResizes(false);
        file_stats_table->verticalHeader()->setMinimumSectionSize(26);
        file_stats_table->verticalHeader()->setDefaultSectionSize(26);
        file_stats_table->verticalHeader()->setHighlightSections(false);
        file_stats_table->verticalHeader()->setStretchLastSection(false);

        bottomAreaLayout->addWidget(file_stats_table);

        other_output_Layout = new QVBoxLayout();
        other_output_Layout->setObjectName(QString::fromUtf8("other_output_Layout"));
        original_folder_checkBox = new QCheckBox(centralwidget);
        original_folder_checkBox->setObjectName(QString::fromUtf8("original_folder_checkBox"));
        QFont font5;
        font5.setBold(true);
        original_folder_checkBox->setFont(font5);

        other_output_Layout->addWidget(original_folder_checkBox);

        getGraph_button_Layout = new QHBoxLayout();
        getGraph_button_Layout->setObjectName(QString::fromUtf8("getGraph_button_Layout"));
        horizontalSpacer_graph_l = new QSpacerItem(35, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        getGraph_button_Layout->addItem(horizontalSpacer_graph_l);

        getGraph_button = new QPushButton(centralwidget);
        getGraph_button->setObjectName(QString::fromUtf8("getGraph_button"));
        getGraph_button->setFont(font5);

        getGraph_button_Layout->addWidget(getGraph_button);

        horizontalSpacer_graph_r = new QSpacerItem(35, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        getGraph_button_Layout->addItem(horizontalSpacer_graph_r);


        other_output_Layout->addLayout(getGraph_button_Layout);


        bottomAreaLayout->addLayout(other_output_Layout);

        bottomAreaLayout->setStretch(0, 20);

        window_layout->addLayout(bottomAreaLayout);

        window_layout->setStretch(0, 2);
        window_layout->setStretch(1, 20);
        window_layout->setStretch(2, 9);

        verticalLayout_2->addLayout(window_layout);

        WordCounter->setCentralWidget(centralwidget);

        retranslateUi(WordCounter);

        QMetaObject::connectSlotsByName(WordCounter);
    } // setupUi

    void retranslateUi(QMainWindow *WordCounter)
    {
        WordCounter->setWindowTitle(QCoreApplication::translate("WordCounter", "Contatore file di testo", nullptr));
        label_path_file->setText(QCoreApplication::translate("WordCounter", "Inserisci il percorso del file:", nullptr));
        lineEdit_path_file->setText(QString());
        lineEdit_path_file->setPlaceholderText(QCoreApplication::translate("WordCounter", ".../Documenti/Il_lupo_e_il_cane.txt", nullptr));
        browse_file_button->setText(QCoreApplication::translate("WordCounter", "...", nullptr));
        path_submit_button->setText(QCoreApplication::translate("WordCounter", "invia", nullptr));
        file_outputArea->setHtml(QCoreApplication::translate("WordCounter", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial';\"><br /></p></body></html>", nullptr));
        file_outputArea->setPlaceholderText(QCoreApplication::translate("WordCounter", "Il testo verr\303\240 visualizzato qui...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = file_stats_table->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WordCounter", "numero caratteri (incl spazi):", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = file_stats_table->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WordCounter", "numero caratteri (escl spazi):", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = file_stats_table->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WordCounter", "numero parole:", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = file_stats_table->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WordCounter", "numero frasi:", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = file_stats_table->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WordCounter", "numero paragrafi:", nullptr));

        const bool __sortingEnabled = file_stats_table->isSortingEnabled();
        file_stats_table->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = file_stats_table->item(0, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WordCounter", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = file_stats_table->item(1, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WordCounter", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = file_stats_table->item(2, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WordCounter", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = file_stats_table->item(3, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WordCounter", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = file_stats_table->item(4, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WordCounter", "0", nullptr));
        file_stats_table->setSortingEnabled(__sortingEnabled);

        original_folder_checkBox->setText(QCoreApplication::translate("WordCounter", "Salvare nel folder originale", nullptr));
        getGraph_button->setText(QCoreApplication::translate("WordCounter", "mostra grafico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WordCounter: public Ui_WordCounter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORD_COUNTER_H
