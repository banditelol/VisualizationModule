/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd
** All rights reserved.
** For any questions to The Qt Company, please use contact form at http://qt.io
**
** This file is part of the Qt Data Visualization module.
**
** Licensees holding valid commercial license for Qt may use this file in
** accordance with the Qt License Agreement provided with the Software
** or, alternatively, in accordance with the terms contained in a written
** agreement between you and The Qt Company.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.io
**
****************************************************************************/
/*********************************************************************
 * Author       :   Aditya Rachman Putra
 * Laboratory   :   TA047-Advance Robotics Labratory
 * University   :   ITB
 * Date         :
 * Description  :
 *
 * TODO         :   Set this Dialog as Modalless later in the main prooject
**********************************************************************/
#include "scatterdatamodifier.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtGui/QScreen>
#include <QtGui/QFontDatabase>
#include <QtWidgets/QGroupBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPlainTextEdit>


int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    // Initializing the graph and its container
    Q3DScatter *graph = new Q3DScatter();
    QWidget *container = QWidget::createWindowContainer(graph);
    //! [0]

    QSize screenSize = graph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 2.25, screenSize.height() / 4));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    //! [1]
    QWidget *widget = new QWidget;
    QGroupBox *menuLayout = new QGroupBox;
    QGroupBox *optionLayout = new QGroupBox;
    QVBoxLayout *vLayout = new QVBoxLayout(widget);
    vLayout->addWidget(menuLayout);
    vLayout->addWidget(container, 1);
    vLayout->addWidget(optionLayout);
    //! [1]

    widget->setWindowTitle(QStringLiteral("CRN Dava Visualization"));

    //! [4]
    /*
    QComboBox *themeList = new QComboBox(widget);
    themeList->addItem(QStringLiteral("Qt"));
    themeList->addItem(QStringLiteral("Primary Colors"));
    themeList->addItem(QStringLiteral("Digia"));
    themeList->addItem(QStringLiteral("Stone Moss"));
    themeList->addItem(QStringLiteral("Army Blue"));
    themeList->addItem(QStringLiteral("Retro"));
    themeList->addItem(QStringLiteral("Ebony"));
    themeList->addItem(QStringLiteral("Isabelle"));
    themeList->setCurrentIndex(6);

    QPushButton *labelButton = new QPushButton(widget);
    labelButton->setText(QStringLiteral("Change label style"));
    */
    int logoHeight = 100, logoWidth = 300;
    int buttonSize = 100;
    QGridLayout *gridMenu = new QGridLayout();
    QPushButton *taLogoLabel = new QPushButton();
    QPushButton *configLabel = new QPushButton();
    QPushButton *saveLabel = new QPushButton();
    QPushButton *openLabel = new QPushButton();
    QPushButton *globeLabel = new QPushButton();
    QPixmap taLogoPix("/home/adityarputra/Pictures/placeholder.png");
    QIcon taLogoIcon(taLogoPix);
    QPixmap configPix("/home/adityarputra/Pictures/placeholder.png");
    QIcon configIcon(configPix);
    QPixmap savePix("/home/adityarputra/Pictures/placeholder.png");
    QIcon saveIcon(savePix);
    QPixmap openPix("/home/adityarputra/Pictures/placeholder.png");
    QIcon openIcon(openPix);
    QPixmap globePix("/home/adityarputra/Pictures/placeholder.png");
    QIcon globeIcon(globePix);

    taLogoLabel->setIcon(taLogoIcon);
    taLogoLabel->setMaximumSize(logoWidth,logoHeight);
    //taLogoLabel->setText("TA logo label");
    configLabel->setIcon(configIcon);
    configLabel->setMaximumSize(buttonSize,buttonSize);
    //configLabel->setText("Config Icon");
    saveLabel->setIcon(saveIcon);
    saveLabel->setMaximumSize(buttonSize,buttonSize);
    //saveLabel->setText("Save Icon");
    openLabel->setIcon(openIcon);
    openLabel->setMaximumSize(buttonSize,buttonSize);
    //openLabel->setText("Open Icon");
    globeLabel->setIcon(globeIcon);
    globeLabel->setMaximumSize(buttonSize,buttonSize);
    //globeLabel->setText("Globe Icon");

    gridMenu->addWidget(taLogoLabel,0,0);
    gridMenu->addWidget(configLabel,0,2);
    gridMenu->addWidget(saveLabel,0,3);
    gridMenu->addWidget(openLabel,0,4);
    gridMenu->addWidget(globeLabel,0,5);

    gridMenu->setColumnStretch(0,300);
    gridMenu->setRowMinimumHeight(0,100);
    gridMenu->setColumnStretch(1,100);
    gridMenu->setColumnStretch(2,100);
    gridMenu->setColumnStretch(3,100);
    gridMenu->setColumnStretch(4,100);
    gridMenu->setColumnStretch(5,100);

    menuLayout->setLayout(gridMenu);

    //-----------------------------------//
    QGridLayout *gridOption = new QGridLayout();
    QComboBox *gasTypeCombo = new QComboBox();
    QPushButton *rewindButton = new QPushButton();
    QPushButton *prevButton = new QPushButton();
    QPushButton *startButton = new QPushButton();
    QPushButton *nextButton = new QPushButton();
    QPushButton *forwardButton = new QPushButton();
    QTableWidget *sensorDataTable = new QTableWidget();
    QPlainTextEdit *console = new QPlainTextEdit();

    sensorDataTable->setRowCount(60);
    sensorDataTable->setColumnCount(9);

    QPixmap buttonPix("/home/adityarputra/Pictures/placeholder.png");
    QIcon buttonIcon(buttonPix);

    rewindButton->setIcon(buttonIcon);
    rewindButton->setMaximumWidth(50);
    prevButton->setIcon(buttonIcon);
    prevButton->setMaximumWidth(50);
    startButton->setIcon(buttonIcon);
    startButton->setMaximumWidth(50);
    nextButton->setIcon(buttonIcon);
    nextButton->setMaximumWidth(50);
    forwardButton->setIcon(buttonIcon);
    forwardButton->setMaximumWidth(50);

    gridOption->addWidget(sensorDataTable,0,6,3,1);
    gridOption->addWidget(gasTypeCombo,0,0,1,5);
    gridOption->addWidget(rewindButton,1,0);
    gridOption->addWidget(prevButton,1,1);
    gridOption->addWidget(startButton,1,2);
    gridOption->addWidget(nextButton,1,3);
    gridOption->addWidget(forwardButton,1,4);
    gridOption->addWidget(console,2,0,1,5);
    gridOption->setColumnStretch(0,50);
    gridOption->setColumnStretch(1,50);
    gridOption->setColumnStretch(2,50);
    gridOption->setColumnStretch(3,50);
    gridOption->setColumnStretch(4,50);
    gridOption->setColumnStretch(5,50);
    gridOption->setColumnStretch(6,400);

    optionLayout->setLayout(gridOption);

    //----------------------------------To be deleted---------------------------------
    /*QCheckBox *smoothCheckBox = new QCheckBox(widget);
    smoothCheckBox->setText(QStringLiteral("Smooth dots"));
    smoothCheckBox->setChecked(true);

    QComboBox *itemStyleList = new QComboBox(widget);
    itemStyleList->addItem(QStringLiteral("Sphere"), int(QAbstract3DSeries::MeshSphere));
    itemStyleList->addItem(QStringLiteral("Cube"), int(QAbstract3DSeries::MeshCube));
    itemStyleList->addItem(QStringLiteral("Minimal"), int(QAbstract3DSeries::MeshMinimal));
    itemStyleList->addItem(QStringLiteral("Point"), int(QAbstract3DSeries::MeshPoint));
    itemStyleList->setCurrentIndex(0);

    QPushButton *cameraButton = new QPushButton(widget);
    cameraButton->setText(QStringLiteral("Change camera preset"));

    QPushButton *itemCountButton = new QPushButton(widget);
    itemCountButton->setText(QStringLiteral("Toggle item count"));

    QCheckBox *backgroundCheckBox = new QCheckBox(widget);
    backgroundCheckBox->setText(QStringLiteral("Show background"));
    backgroundCheckBox->setChecked(true);

    QCheckBox *gridCheckBox = new QCheckBox(widget);
    gridCheckBox->setText(QStringLiteral("Show grid"));
    gridCheckBox->setChecked(true);

    QComboBox *shadowQuality = new QComboBox(widget);
    shadowQuality->addItem(QStringLiteral("None"));
    shadowQuality->addItem(QStringLiteral("Low"));
    shadowQuality->addItem(QStringLiteral("Medium"));
    shadowQuality->addItem(QStringLiteral("High"));
    shadowQuality->addItem(QStringLiteral("Low Soft"));
    shadowQuality->addItem(QStringLiteral("Medium Soft"));
    shadowQuality->addItem(QStringLiteral("High Soft"));
    shadowQuality->setCurrentIndex(4);

    QFontComboBox *fontList = new QFontComboBox(widget);
    fontList->setCurrentFont(QFont("Arial"));*/
    //----------------------------------------------------------------

    // Adding widget to respective layout
    /*
    vLayout->addWidget(labelButton, 0, Qt::AlignTop);
    vLayout->addWidget(cameraButton, 0, Qt::AlignTop);
    vLayout->addWidget(itemCountButton, 0, Qt::AlignTop);
    vLayout->addWidget(backgroundCheckBox);
    vLayout->addWidget(gridCheckBox);
    vLayout->addWidget(smoothCheckBox, 0, Qt::AlignTop);
    vLayout->addWidget(new QLabel(QStringLiteral("Change dot style")));
    vLayout->addWidget(itemStyleList);
    vLayout->addWidget(new QLabel(QStringLiteral("Change theme")));
    vLayout->addWidget(themeList);
    vLayout->addWidget(new QLabel(QStringLiteral("Adjust shadow quality")));
    vLayout->addWidget(shadowQuality);
    vLayout->addWidget(new QLabel(QStringLiteral("Change font")));
    vLayout->addWidget(fontList, 1, Qt::AlignTop);
    */
    //! [5]

    //! [2]
    ScatterDataModifier *modifier = new ScatterDataModifier(graph);
    //! [2]

    connect(configLabel,SIGNAL(clicked(bool)),this,
    /*
    QObject::connect(cameraButton, &QPushButton::clicked, modifier,
                     &ScatterDataModifier::changePresetCamera);
    QObject::connect(labelButton, &QPushButton::clicked, modifier,
                     &ScatterDataModifier::changeLabelStyle);
    QObject::connect(itemCountButton, &QPushButton::clicked, modifier,
                     &ScatterDataModifier::toggleItemCount);

    QObject::connect(backgroundCheckBox, &QCheckBox::stateChanged, modifier,
                     &ScatterDataModifier::setBackgroundEnabled);
    QObject::connect(gridCheckBox, &QCheckBox::stateChanged, modifier,
                     &ScatterDataModifier::setGridEnabled);
    QObject::connect(smoothCheckBox, &QCheckBox::stateChanged, modifier,
                     &ScatterDataModifier::setSmoothDots);

    QObject::connect(modifier, &ScatterDataModifier::backgroundEnabledChanged,
                     backgroundCheckBox, &QCheckBox::setChecked);
    QObject::connect(modifier, &ScatterDataModifier::gridEnabledChanged,
                     gridCheckBox, &QCheckBox::setChecked);
    QObject::connect(itemStyleList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeStyle(int)));

    QObject::connect(themeList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeTheme(int)));

    QObject::connect(shadowQuality, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeShadowQuality(int)));

    QObject::connect(modifier, &ScatterDataModifier::shadowQualityChanged, shadowQuality,
                     &QComboBox::setCurrentIndex);
    QObject::connect(graph, &Q3DScatter::shadowQualityChanged, modifier,
                     &ScatterDataModifier::shadowQualityUpdatedByVisual);

    QObject::connect(fontList, &QFontComboBox::currentFontChanged, modifier,
                     &ScatterDataModifier::changeFont);
    QObject::connect(modifier, &ScatterDataModifier::fontChanged, fontList,
                     &QFontComboBox::setCurrentFont);
    */
    //! [6]

    //! [3]
    widget->show();
    return app.exec();
    //! [3]
}
