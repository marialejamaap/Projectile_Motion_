#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <windows.h>
#include <time.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <stdlib.h>
#include <ctime>
#include <QString>
#include <QSpinBox>

#define ALTO 1000
#define ANCHO 500
#define DT 20

double const PI=3.1416;
double const rho=1.6;
double const g=9.8;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    Ui::MainWindow *particula;
    QGraphicsScene *scene=nullptr;
      QGraphicsEllipseItem *ellipse=nullptr;
      QGraphicsRectItem *rectangle=nullptr;
      QTimer *timer;
    double Velocity_initial;
    double mass;
    double cd_din;
    double diameter;
    double angle_rad;
    double Xpos;
    double Ypos;
    double k;
    double vx;
    double vy;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double get_velocity_initial(){return Velocity_initial;}
    double get_mass(){return mass;}
    double get_cd_din(){return cd_din;}
    double get_diameter(){return diameter;}
    double get_angle_rad(){return angle_rad;}
    double set_Xpos(double a);
     double set_Ypos(double a);
     double ser_k();
     void mover();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
