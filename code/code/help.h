#ifndef HELP_H
#define HELP_H
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include<QDialog>
#include<QMovie>
#include<QScopedPointer>

class Help : public QDialog
{
    Q_OBJECT
public:
    Help(QWidget *parent);
    ~Help(){}
private:
    QPushButton *moveBut,*defBut,*cBut,*xBut,*xlongBut,*aBut,*backBut;
    QLabel *gifLab;
    QMovie *gifMov;
    //QScopedPointer<QMovie> *gifMov;
    
public slots:
    void slo_moveGif();
    void slo_defGif();
    void slo_cGif();
    void slo_xGif();
    void slo_xlongGif();
    void slo_aGif();
    void slo_back();
    
};

#endif // HELP_H





















