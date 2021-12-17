#include "helper.h"


void exit_game()
{
    QMessageBox pmbx;
    pmbx.setWindowTitle("Подтверждение выхода.");
    pmbx.setText("Вы действительно хотите выйти?");
    pmbx.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int n = pmbx.exec();
    if (n == QMessageBox::Yes)
    {
      exit(0);
    }
}

void new_game()
{
    QMessageBox msg;
    msg.setText("Новая игра");
    msg.exec();
}
