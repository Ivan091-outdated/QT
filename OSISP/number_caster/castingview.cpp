#include "castingview.h"
#include "ui_castingview.h"

CastingView::CastingView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CastingView)
{
    ui->setupUi(this);
}

CastingView::~CastingView()
{
    delete ui;
}
