#ifndef CASTINGVIEW_H
#define CASTINGVIEW_H

#include <QWidget>

namespace Ui {
class CastingView;
}

class CastingView : public QWidget
{
    Q_OBJECT

public:
    explicit CastingView(QWidget *parent = nullptr);
    ~CastingView();

private:
    Ui::CastingView *ui;
};

#endif // CASTINGVIEW_H
