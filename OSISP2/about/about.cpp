#include "about.h"

void about()
{
    QMessageBox about;
    about.setWindowTitle("О программе");
    about.setText("Автор: Cиняк Д.А ПО-4/n"
                  "Игра заграждения. Правила игры: игрок закрашивает 2 рядом стоящие области, затем бот делает свой ход."
                  "Игра закончится, когда у одного из игроков не останется ходов."

                  );
    about.exec();
}
