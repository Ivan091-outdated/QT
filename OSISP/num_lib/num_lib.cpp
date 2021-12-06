#include "num_lib.h"




QString numToString(quint64 num, int base)
{
    return QString::number(num, base).toUpper();
}

QPushButton* createDeleteButton(QWidget* parent)
{
    return new QPushButton(parent);
}

QSpinBox* createSpinBox(int initValue, QWidget *parent)
{
    auto spinbox = new QSpinBox(parent);
    spinbox->setValue(initValue);
    spinbox->setMinimum(2);
    spinbox->setMaximum(16);
    spinbox->setMinimumSize(100, 100);
    return spinbox;
}

QWidget* createParentWidget(QWidget *parent)
{
    auto wid = new QWidget(parent);
    wid->setLayout(new QHBoxLayout);
    return wid;
}

QTextEdit* createTextArea(QWidget *parent)
{
    return new QTextEdit(parent);
}

QFont createFont()
{
    QFont font;
    font.setPointSize(30);
    font.setFamily("Consolas");
    return font;
}
