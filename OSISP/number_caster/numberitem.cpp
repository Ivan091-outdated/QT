#include "numberitem.h"

#include <QSlider>
#include <QTextEdit>
#include <QVBoxLayout>

NumberItem::NumberItem(QWidget *parent) : QWidget(parent)
{
    setLayout(new QHBoxLayout);
    auto slider = new QSlider(Qt::Orientation::Horizontal);
    auto textEditor = new QTextEdit();
    layout()->addWidget(slider);
    layout()->addWidget(new QTextEdit);

    connect(textEditor, &QTextEdit)
}
