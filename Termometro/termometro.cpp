#include "termometro.h"
#include "ui_termometro.h"
#include<QDebug>

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);

        connect(ui->dialCent, SIGNAL(valueChanged(int)),
                this, SLOT(cent2Fahr(int)));
        connect(ui->dialFahr, SIGNAL(valueChanged(int)),
                this, SLOT(fahr2Cent(int)));
        connect(ui->dialCent, SIGNAL(valueChanged(int)),
                this, SLOT(cent2Kelv(int)));
       /*connect(ui->dialKelv, SIGNAL(valueChanged(int)),
                this, SLOT(kelv2Cent(int)));*/
        connect(ui->dialFahr, SIGNAL(valueChanged(int)),
                this, SLOT(fahr2Kelv(int)));
        /*connect(ui->dialKelv, SIGNAL(valueChanged(int)),
               this, SLOT(kelv2Fahr(int)));*/





        connect(ui->dialCent, SIGNAL(sliderPressed()),
                this, SLOT(dialPresionado()));
        connect(ui->dialFahr, SIGNAL(sliderPressed()),
                this, SLOT(dialPresionado()));
        connect(ui->dialCent, SIGNAL(sliderPressed()),
                this, SLOT(dialPresionado()));
        connect(ui->dialKelv, SIGNAL(sliderPressed()),
                this, SLOT(dialPresionado()));
        connect(ui->dialFahr, SIGNAL(sliderPressed()),
                this, SLOT(dialPresionado()));
        connect(ui->dialKelv, SIGNAL(sliderPressed()),
                this, SLOT(dialPresionado()));



        connect(ui->dialCent, SIGNAL(sliderReleased()),
                this, SLOT(dialRelajado()));
        connect(ui->dialFahr, SIGNAL(sliderReleased()),
                this, SLOT(dialRelajado()));   
        connect(ui->dialCent, SIGNAL(sliderReleased()),
                this, SLOT(dialRelajado()));
        connect(ui->dialKelv, SIGNAL(sliderReleased()),
                this, SLOT(dialRelajado()));
        connect(ui->dialFahr, SIGNAL(sliderReleased()),
                this, SLOT(dialRelajado()));
        connect(ui->dialKelv, SIGNAL(sliderReleased()),
                this, SLOT(dialRelajado()));



        ui->dialFahr->setValue(32);
        ui->dialKelv->setValue(273);


}

Termometro::~Termometro()
{
    delete ui;
}

float Termometro::cent2Fahr(int valor)
{
    if (ui->dialCent->hasFocus()){
            float f = valor * 9/5 + 32;
            ui->dialFahr->setValue(f);
            return f;
        }
    return 0;
}

float Termometro::fahr2Cent(int valor)
{
    if(ui->dialFahr->hasFocus()){
           float c = (valor - 32) * 5/9;
           ui->dialCent->setValue(c);
           return c;
       }
    return 0;
}

float Termometro::cent2Kelv(int valor)
{
    if (ui->dialCent->hasFocus()){
            float k = valor + 273;
            ui->dialKelv->setValue(k);
            return k;
        }
    return 0;
}

/*float Termometro::kelv2Cent(int valor)
{
    if (ui->dialKelv->hasFocus()){
            float c = (valor - 273);
            ui->dialKelv->setValue(c);
            return c;
        }
    return 0;
}*/
float Termometro::fahr2Kelv(int valor)
{
    if (ui->dialFahr->hasFocus()){
            float k = (valor - 32)*5/9+273;
            ui->dialKelv->setValue(k);
            return k;
        }
    return 0;
}

/*float Termometro::kelv2Fahr(int k)
{
    if (ui->dialKelv->hasFocus()){
            float f = (k - 273)*9/5+32;
            ui->dialKelv->setValue(f);
            return f;
        }
    return 0;
}*/

void Termometro::dialPresionado()
{
    // if (ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::ClosedHandCursor);
    // }else{
        ui->dialFahr->setCursor(Qt::ClosedHandCursor);
    // }
        ui->dialCent->setCursor(Qt::ClosedHandCursor);
        ui->dialKelv->setCursor(Qt::ClosedHandCursor);
        ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        ui->dialKelv->setCursor(Qt::ClosedHandCursor);

       /* ui->dialKelv->setCursor(Qt::ClosedHandCursor);
        ui->dialCent->setCursor(Qt::ClosedHandCursor);
        ui->dialKelv->setCursor(Qt::ClosedHandCursor);
        ui->dialFahr->setCursor(Qt::ClosedHandCursor);*/


}
void Termometro::dialRelajado()
{
     //if (ui->dialCent->hasFocus()){
            ui->dialCent->setCursor(Qt::ArrowCursor);
  //   }else{
            ui->dialFahr->setCursor(Qt::ArrowCursor);
  //   }
            ui->dialCent->setCursor(Qt::ArrowCursor);
            ui->dialKelv->setCursor(Qt::ArrowCursor);
            ui->dialFahr->setCursor(Qt::ArrowCursor);
            ui->dialKelv->setCursor(Qt::ArrowCursor);

            /*ui->dialKelv->setCursor(Qt::ArrowCursor);
            ui->dialCent->setCursor(Qt::ArrowCursor);
            ui->dialKelv->setCursor(Qt::ArrowCursor);
            ui->dialFahr->setCursor(Qt::ArrowCursor);*/



}


