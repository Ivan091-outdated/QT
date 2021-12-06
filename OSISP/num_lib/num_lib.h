#ifndef NUM_LIB_H
#define NUM_LIB_H

#include "num_lib_global.h"

#include <QString>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QTextEdit>

QString numToString(quint64 num, int base);

QPushButton* createDeleteButton(QWidget* parent = nullptr);

QSpinBox* createSpinBox(int initValue, QWidget* parent = nullptr);

QWidget* createParentWidget(QWidget* parent = nullptr);

QTextEdit* createTextArea(QWidget* parent = nullptr);

QFont createFont();

#endif // NUM_LIB_H
