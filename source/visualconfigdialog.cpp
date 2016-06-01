#include <QWidget>
#include "visualconfigdialog.h"

VisualConfigDialog::VisualConfigDialog()
{
    //createMenu();
    createHorizontalGroupBox();
    createGridGroupBox();
    createFormGroupBox();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(assignParameter()));
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Scenario Dialog"));
}

void VisualConfigDialog::browse()
{
    QString directory = QFileDialog::getExistingDirectory(this,
                               tr("Find Files"), QDir::homePath());

    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
    }
}

//! [7]
void VisualConfigDialog::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}
//! [7]

//! [8]
void VisualConfigDialog::createGridGroupBox()
{
    const char* labelSpiralParam[NumGridRows]= {"N :","R (in meter):","S :"};
    const char* labelSquareParam[NumGridRows]= {"N :","W (in meter):","L (in meter):"};
    gridGroupBox = new QGroupBox(tr("Scenario Specific Options"));
//! [8]
    QGridLayout *layout = new QGridLayout;

//! [9]
    labels[2*NumGridRows] = new QLabel();
    labels[2*NumGridRows+1] = new QLabel();
    labels[2*NumGridRows+2] = new QLabel(tr("Spiral Scanning"));
    labels[2*NumGridRows+3] = new QLabel(tr("Zig-Zag Scanning"));
    helpLabel = new QLabel(tr("N is the number of waypoint generated for spiral scenario\n and number of square generated for zig-zag scenario\nR is the radius of outmost circle in spiral scenario\nS is number of circle in spiral scenario\nW is the width of zigzag scanning area\nL is the length of zigzag scanning area\nHeight is relative to home altitude"));
    heightLabel = new QLabel(tr("Height (in meter):"));
    lineHeight = new QLineEdit;

    QPixmap spiralPix("/home/adityarputra/projects/qgroundcontrol/resources/spiral.png");
    QPixmap squarePix("/home/adityarputra/projects/qgroundcontrol/resources/square.png");

    labels[2*NumGridRows]->setPixmap(spiralPix);
    labels[2*NumGridRows]->setMaximumSize(100,100);
    labels[2*NumGridRows+1]->setPixmap(squarePix);
    labels[2*NumGridRows+1]->setMaximumSize(100,100);
    layout->addWidget(labels[2*NumGridRows],0,0,1,2,Qt::AlignCenter);
    layout->addWidget(labels[2*NumGridRows+1],0,4,1,2,Qt::AlignCenter);
    layout->addWidget(labels[2*NumGridRows+2],1,0,1,2,Qt::AlignCenter);
    layout->addWidget(labels[2*NumGridRows+3],1,4,1,2,Qt::AlignCenter);
    layout->addWidget(helpLabel,0,2,3,2,Qt::AlignCenter);
    layout->addWidget(heightLabel,4,2);
    layout->addWidget(lineHeight,4,3);


    for (int i = 0; i < NumGridRows; ++i) {
        labels[i] = new QLabel(tr(labelSpiralParam[i]));
        lineEdits[i] = new QLineEdit;
        layout->addWidget(labels[i], i + 2, 0);
        layout->addWidget(lineEdits[i], i + 2, 1);
    }

    for (int i = 0; i < NumGridRows; ++i) {
        labels[i+NumGridRows] = new QLabel(tr(labelSquareParam[i]));
        lineEdits[i+NumGridRows] = new QLineEdit;
        layout->addWidget(labels[i+NumGridRows], i + 2, 4);
        layout->addWidget(lineEdits[i +NumGridRows], i + 2, 5);
    }

    lineEdits[0]->setPlaceholderText("4");
    lineEdits[1]->setPlaceholderText("100");
    lineEdits[2]->setPlaceholderText("1");
    lineEdits[3]->setPlaceholderText("2");
    lineEdits[4]->setPlaceholderText("100");
    lineEdits[5]->setPlaceholderText("100");
    lineEdits[0]->setPlaceholderText("4");
    lineHeight->setPlaceholderText("25");

    lineEdits[0]->setText("4");
    lineEdits[1]->setText("100");
    lineEdits[2]->setText("1");
    lineEdits[3]->setText("2");
    lineEdits[4]->setText("100");
    lineEdits[5]->setText("100");
    lineHeight->setText("25");
//! [10]

//! [11]
    layout->setColumnStretch(0, 10);
    layout->setColumnStretch(1, 20);
    layout->setColumnStretch(2, 10);
    layout->setColumnStretch(3, 20);
    layout->setColumnStretch(4, 10);
    layout->setColumnStretch(5, 20);

    gridGroupBox->setLayout(layout);
}
//! [11]

//! [12]
void VisualConfigDialog::createFormGroupBox()
{
    browseButton = createButton(tr("&Browse..."), SLOT(browse()));
    directoryComboBox = createComboBox(QDir::homePath());
    directoryLabel = new QLabel(tr("In directory:"));

    formGroupBox = new QGroupBox(tr("Common Settings :"));
    QGridLayout *layout = new QGridLayout;
    wpNumLabel = new QLabel(tr("Number of Waypoints:"));
    latLabel = new QLabel(tr("Home Latitude :"));
    lonLabel = new QLabel(tr("Home Longitude :"));
    altLabel = new QLabel(tr("Home Altitude :"));
    missionNameLabel = new QLabel(tr("Mission Name : "));
    wpNumLine = new QLineEdit;
    wpNumLine->setPlaceholderText("6");
    wpNumLine->setText("6");
    latLine = new QLineEdit;
    latLine->setPlaceholderText("-6.9180522");
    latLine->setText("-6.9180522");
    lonLine = new QLineEdit;
    lonLine->setPlaceholderText("107.6167910");
    lonLine->setText("107.6167910");
    altLine = new QLineEdit;
    altLine->setPlaceholderText("768");
    altLine->setText("768");
    missionNameLine = new QLineEdit;
    missionNameLine->setPlaceholderText("default");
    missionNameLine->setText("default");

    typeLabel = new QLabel(tr("choose the type of scenario"));
    typeSpiralRadio = new QRadioButton(tr("spiral"));
    typeSpiralRadio->setChecked(true);
    typeSquareRadio = new QRadioButton(tr("square"));

    overCheck = new QCheckBox(tr("Overwrite mission ?"));

    layout->addWidget(directoryLabel,0,0);
    layout->addWidget(directoryComboBox,0,1,1,4);
    layout->addWidget(browseButton,0,5);
    layout->addWidget(missionNameLabel,1,0);
    layout->addWidget(missionNameLine,1,1);
    layout->addWidget(overCheck,1,2,1,2);
    layout->addWidget(typeSpiralRadio,1,4);
    layout->addWidget(typeSquareRadio,1,5);
    layout->addWidget(latLabel,2,0);
    layout->addWidget(latLine,2,1);
    layout->addWidget(lonLabel,2,2);
    layout->addWidget(lonLine,2,3);
    layout->addWidget(altLabel,2,4);
    layout->addWidget(altLine,2,5);

    formGroupBox->setLayout(layout);
}
//! [12]

QPushButton *VisualConfigDialog::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}
//! [9]

//! [10]
QComboBox *VisualConfigDialog::createComboBox(const QString &text)
{
    QComboBox *comboBox = new QComboBox;
    comboBox->setEditable(true);
    comboBox->addItem(text);
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    return comboBox;
}

void VisualConfigDialog::assignParameter()
{
    qDebug()<<"parameter assigned!!";
    home_alt = (altLine->text()).toDouble();
    home_long = (lonLine->text()).toDouble();
    home_lat = (latLine->text()).toDouble();
    height = lineHeight->text().toDouble();

    spiral_cirnum = (lineEdits[2]->text()).toDouble();
    spiral_iteration = (lineEdits[0]->text()).toDouble();
    spiral_radius = (lineEdits[1]->text()).toDouble();

    zig_height = (lineEdits[5]->text()).toDouble();
    zig_width = (lineEdits[4]->text()).toDouble();
    zig_sqrnum = (lineEdits[3]->text()).toDouble();

    name = missionNameLine->text();
    dirpath = directoryComboBox->currentText();
    scenario_type = typeSquareRadio->isChecked();
    overwrite = overCheck->isChecked();

    qDebug() << "home pos :" << altLine->text() << " " <<lonLine->text() << " " <<latLine->text();
    qDebug() << "spiral param :" << lineEdits[2]->text()<< " " << lineEdits[0]->text()<< " " << lineEdits[1]->text();
    qDebug() << "square param :" << lineEdits[5]->text() << " " << lineEdits[4]->text()<< " " << lineEdits[3]->text();
}
