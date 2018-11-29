#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_2()));
       timer->start(1000);


}





void MainWindow::on_pushButton_clicked()
{
    QString spin_1=ui->doubleSpinBox->text();
    QString spin_2=ui->doubleSpinBox_2->text();
    QString spin_3=ui->doubleSpinBox_3->text();
    QString spin_4=ui->doubleSpinBox_4->text();
    QString spin_5=ui->doubleSpinBox_5->text();
    
    double spin_1f=ui->doubleSpinBox->value();
    double spin_2f=ui->doubleSpinBox_2->value();
    double spin_3f=ui->doubleSpinBox_3->value();
    double spin_4f=ui->doubleSpinBox_4->value();
    double spin_5f=ui->doubleSpinBox_5->value();

    Velocity_initial=spin_1f;
    mass=spin_2f;
    cd_din=spin_3f;
    diameter=spin_4f;
    angle_rad=spin_5f;

    
}


double MainWindow::ser_k()
{
    double a=get_cd_din();
    double b=get_diameter();
    double Area,radius;
        radius=b/2;
        Area=4*PI*radius*radius; // Area de la esfera es igual a: 4*PI*radio al cuadrado

        k=0.5*rho*a*Area;
        return k;
}

void MainWindow::mover()
{


}




double MainWindow::set_Xpos(double a)
{
    double v,w,x,y,z;
    double b;
    z=a;
    v=ser_k();
    w=get_mass();
    x=get_velocity_initial();
    y=get_angle_rad();
    b=((-1)*(v/w));
   Xpos=(w/v)*(x)*(cos(y))*((1-(exp(b*z)))); // Fórmula para hallar la posición en x con resistencia en el aire

    return Xpos;

}

double MainWindow::set_Ypos(double a)
{
    double v,w,x,y,z;
    double b;
    z=a;
    v=ser_k();
    w=get_mass();
    x=get_velocity_initial();
    y=get_angle_rad();
    double c;
    b=((-1)*(v/w));
    c=(w/v);
    Ypos=(c)*(x*(sin(y))+(c*g))*(1-(exp(b*z)))-(c*g*z);//Fórmula para hallar posición en Y con resistencia en el aire

    return Ypos;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

scene= new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
QBrush greenBrush(Qt::green);
QPen blackpen(Qt::black);
blackpen.setWidth(6);
ellipse=scene->addEllipse(0, 0,15, 15, blackpen, greenBrush);

double PX=0.0,PY=0.0;
for(int i=0; i<100;i++){
        double t=0.0;
           for (int i=0;i<700;i++){
     PX= set_Xpos(t);
     PY= set_Ypos(t);
          if (PY<0.0 && t>0.0)// if para que los valores de posición de Y no sean inferiores al piso(cuando Y<0)
              break;
          else
              ui->lcdNumber->display(PX);
              ui->lcdNumber_2->display(PY);
              scene= new QGraphicsScene(this);
                  ui->graphicsView->setScene(scene);
                   ellipse=scene->addEllipse(PX, PY,15, 15, blackpen, greenBrush);
          t=t+0.1;  }
               }}

