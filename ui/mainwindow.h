#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Board.hpp"

#include <QMainWindow>
#include <QTimer>
#include <QWheelEvent>
#include "./BoardGraphicsScene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_step_clicked();
    void on_action_open_triggered();
    void on_button_play_clicked();
    void on_radio_button_draw_icon_toggled(bool checked);
    void on_slider_speed_valueChanged(int value);

    void step_board();

private:
    Ui::MainWindow *ui;
    BoardGraphicsScene *scene;
    QTimer *timer_simulation_delay;

    void load_board(std::string fname);
    int get_timer_delay() const;
};

#endif // MAINWINDOW_H