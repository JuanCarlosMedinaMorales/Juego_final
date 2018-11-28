#include "cuerpograf.h"
#include <cuerpo.h>

grafica::grafica(QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/Images/caminar1.png"));

    car=new Cuerpo;

}

void grafica::mov()
{
   // int contador=0;
    if (contador==0 && cont<4)
    {
        setPixmap(QPixmap(":/Images/caminar1.png"));
        contador=1;
        flag=0;
    }
    else if (contador==1&& cont >4)
    {
        setPixmap(QPixmap(":/Images/caminar2.png"));
        flag=2;
        contador=2;
    }
    else if (contador==2&& cont >8)
    {
        setPixmap(QPixmap(":/Images/caminar3.png"));
        flag=1;
        contador=3;
    }
    else if (contador==3&& cont >12)
    {
        setPixmap(QPixmap(":/Images/caminar4.png"));
        flag=1;
        contador=4;
    }
    else if (contador==4&& cont >16)
    {
        setPixmap(QPixmap(":/Images/caminar5.png"));
        flag=1;
        contador=5;
    }
    else if (contador==5&& cont >20)
    {
        setPixmap(QPixmap(":/Images/caminar6.png"));
        flag=1;
        contador=0;
    }

    if (cont==24)cont=0;

    cont++;

}
void grafica::pelea()
{
        if (contador2==0 && cont<4)
        {
            setPixmap(QPixmap(":/Images/pegar1.png"));
            contador2=1;
            flag=0;
        }
        else if (contador2==1&& cont >4)
        {
            setPixmap(QPixmap(":/Images/pegar3.png"));
            flag=2;
            contador2=2;
        }
        else if (contador2==2&& cont >8)
        {
            setPixmap(QPixmap(":/Images/pegar4.png"));
            flag=1;
            contador2=3;
        }
        else if (contador2==3&& cont >12)
        {
            setPixmap(QPixmap(":/Images/pegar5.png"));
            flag=1;
            contador2=4;
        }
        else if (contador2==4&& cont >16)
        {
            setPixmap(QPixmap(":/Images/pegar6.png"));
            flag=1;
            contador2=0;
        }
        if (cont==20)cont=0;

        cont++;



}

void grafica::salto(int vec)
{
    if(vec==1){
        if (contador2==0 && cont<4)
        {
            setPixmap(QPixmap(":/Images/saltar1.png"));
            contador2=1;
            flag=0;
        }
        else if (contador2==1&& cont >4)
        {
            setPixmap(QPixmap(":/Images/saltar2.png"));
            flag=2;
            contador2=2;
        }
        else if (contador2==2&& cont >8)
        {
            setPixmap(QPixmap(":/Images/saltar3.png"));
            flag=1;
            contador2=3;
        }
        else if (contador2==3&& cont >12)
        {
            setPixmap(QPixmap(":/Images/saltar4.png"));
            flag=1;
            contador2=4;
        }
        else if (contador2==4&& cont >16)
        {
            setPixmap(QPixmap(":/Images/saltar5.png"));
            flag=1;
            contador2=5;
        }
    }
    else if(vec==2){
        if (contador2==5 && cont<4)
        {
            setPixmap(QPixmap(":/Images/saltar6.png"));
            contador2=1;
            flag=0;
        }
        else if (contador2==1&& cont >4)
        {
            setPixmap(QPixmap(":/Images/saltar6.png"));
            flag=2;
            contador2=2;
        }
        else if (contador2==2&& cont >8)
        {
            setPixmap(QPixmap(":/Images/saltar6.png"));
            flag=1;
            contador2=3;
        }
        else if (contador2==3&& cont >12)
        {
            setPixmap(QPixmap(":/Images/saltar7.png"));
            flag=1;
            contador2=4;
        }
        else if (contador2==4&& cont >16)
        {
            setPixmap(QPixmap(":/Images/saltar8.png"));
            flag=1;
            contador2=0;
        }
    }

    if (cont==20)cont=0;

    cont++;

}




Cuerpo* grafica::get_carro(){
    return car;
}


void grafica::posicion(float v_lim){
    car->CalcularPosicion();
    setPos(car->get_px(),(v_lim-car->get_py()-((car->get_h())*escala)));
}
void grafica::par(float v_lim){

    setPos(car->get_px(),(v_lim-car->get_py()-((car->get_h())*escala)));
    car->par();

}



grafica::~grafica(){
    delete car;
}
float grafica::get_escala(){
    return escala;
}

float grafica::get_contador()
{
    return contador;
}
