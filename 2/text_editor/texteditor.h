#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>

class TextEditor : QWidget
{
public:
    TextEditor();

protected:
    void closeEvent(QCloseEvent *e);
};

#endif // TEXTEDITOR_H
