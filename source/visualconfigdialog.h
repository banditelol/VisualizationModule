#ifndef VISUALCONFIGDIALOG_H
#define VISUALCONFIGDIALOG_H

#include <QDialog>
#include <QtWidgets>
QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
class QRadioButton;
class QCheckBox;
class QFont;
class QFrame;
class QComboBox;
QT_END_NAMESPACE

class VisualConfigDialog : public QDialog
{
    Q_OBJECT
public:
    VisualConfigDialog();

    bool overwrite = 1;
    char scenario_type = 0; // 0 = spiral, 1 = zigzag
    double home_lat, home_long, home_alt, height;
    double way_lat, way_long, way_alt;

    double spiral_theta, spiral_radius, spiral_cirnum;
    int spiral_iteration;
    double zig_width, zig_height, zig_sqrnum;

    QString name;
    QString filename;
    QString dirpath;

private slots:
    void browse();
    void assignParameter();

private:

    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();
    QPushButton *createButton(const QString &text, const char *member);
    QComboBox *createComboBox(const QString &text = QString());
    enum { NumGridRows = 3, NumButtons = 4 };

    QPushButton *browseButton;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QLabel *labels[2*NumGridRows+4];
    QLabel *wpNumLabel, *latLabel, *lonLabel, *altLabel, *typeLabel, *heightLabel;
    QLabel *directoryLabel, *missionNameLabel, *helpLabel, *helpTitleLabel;
    QLineEdit *lineEdits[2*NumGridRows], *lineHeight;
    QLineEdit *wpNumLine, *latLine, *lonLine, *altLine, *missionNameLine;
    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;
    QRadioButton *typeSpiralRadio, *typeSquareRadio;
    QComboBox *directoryComboBox;
    QAction *exitAction;
    QCheckBox *overCheck;

};

#endif // VISUALCONFIGDIALOG_H
