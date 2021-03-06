#include "cuerpograf.h"
#include <cuerpo.h>

grafica::grafica(QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(c));
    cap.append(":/CCD1.png");
    cap.append(":/CCD2.png");
    cap.append(":/CCD3.png");
    cap.append(":/CCD4.png");
    cap.append(":/CCD1.png");
    cap.append(":/CCD2.png");
    cap.append(":/CCV1.png");
    cap.append(":/CCV2.png");
    cap.append(":/CCV3.png");
    cap.append(":/CCV4.png");
    cap.append(":/CCV5.png");
    cap.append(":/CCV6.png");

    f.append(cap);
    n.append(":/caminar1.png");
    n.append(":/caminar2.png");
    n.append(":/caminar3.png");
    n.append(":/caminar4.png");
    n.append(":/caminar5.png");
    n.append(":/caminar6.png");
    n.append(":/caminar1V.png");
    n.append(":/caminar2V.png");
    n.append(":/caminar3v.png");
    n.append(":/caminar4v.png");

    f.append(n);

    esmad.append(":/smadC1.png");
    esmad.append(":/esmadC2.png");
    esmad.append(":/esmadC3.png");
    esmad.append(":/esmadC4.png");
    esmad.append(":/esmadC5.png");
    esmad.append(":/esmadC6.png");
    esmad.append(":/esmadC1V.png");
    esmad.append(":/esmadC2V.png");
    esmad.append(":/esmadC3V.png");
    esmad.append(":/esmadC4V.png");

    f.append(esmad);
    car=new Cuerpo;

}

void grafica::mov(int seleccion,char direccion)
{
    if (contador==0 && cont<2)
    {
        if(direccion=='A'||direccion=='4'){
            setPixmap(QPixmap(f.at(seleccion).at(6)));
            contador=1;

        }
        else{
            setPixmap(QPixmap(f.at(seleccion).at(0)));
            contador=1;
        }


        flag=0;
    }
    else if (contador==1&& cont >2)
    {
        if(direccion=='A'||direccion=='4'){
            setPixmap(QPixmap(f.at(seleccion).at(7)));
            contador=2;

        }
        else {
            setPixmap(QPixmap(f.at(seleccion).at(1)));
            flag=2;
            contador=2;
        }

    }
    else if (contador==2&& cont >4)
    {
        if(direccion=='A'||direccion=='4'){
            setPixmap(QPixmap(f.at(seleccion).at(8)));
            contador=3;

        }
        else{
            setPixmap(QPixmap(f.at(seleccion).at(2)));
            flag=1;
            contador=3;

        }
            }
    else if (contador==3&& cont >6)
    {
        if(direccion=='A'||direccion=='4'){
            setPixmap(QPixmap(f.at(seleccion).at(9)));
            contador=1;
            cont=0;

        }
        else{
            setPixmap(QPixmap(f.at(seleccion).at(3)));
            flag=1;
            contador=4;
        }

    }
    else if (contador==4&& cont >8)
    {
        setPixmap(QPixmap(f.at(seleccion).at(4)));
        flag=1;
        contador=5;
    }
    else if (contador==5&& cont >10)
    {
        setPixmap(QPixmap(f.at(seleccion).at(5)));
        flag=1;
        contador=0;
    }

    if (cont==12)cont=0;

    cont++;


}
void grafica::pelea()
{
        if (contador2==0 && cont<4)
        {
            setPixmap(QPixmap(":/pegar1.png"));
            contador2=1;
            flag=0;
        }
        else if (contador2==1&& cont >4)
        {
            setPixmap(QPixmap(":/pegar3.png"));
            flag=2;
            contador2=2;
        }
        else if (contador2==2&& cont >8)
        {
            setPixmap(QPixmap(":/pegar4.png"));
            flag=1;
            contador2=3;
        }
        else if (contador2==3&& cont >12)
        {
            setPixmap(QPixmap(":/pegar5.png"));
            flag=1;
            contador2=4;
        }
        else if (contador2==4&& cont >16)
        {
            setPixmap(QPixmap(":/pegar6.png"));
            flag=1;
            contador2=5;
        }
        else if (contador2==5&& cont >20)
        {
            setPixmap(QPixmap(":/pegar7.png"));
            flag=1;
            contador2=3;
        }
        if (cont==24)cont=0;
        cont++;




}

void grafica::salto(int vec,char direccion,int seleccion,int P)
{
    if(vec==1&&P==1){
        if (direccion=='D')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/saltar2.png"));
                flag=1;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltando2.png"));
                flag=1;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS1.png"));
                flag=1;
            }
        }
        if (direccion=='A')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/arsaltV.png"));
                flag=1;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltandoV1.png"));
                flag=1;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS1V.png"));
                flag=1;
            }
        }

        get_carro()->CalcularPosicion();
    }
    else if(vec==1&&P==2){
        if (direccion=='6')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/saltar2.png"));
                flag=1;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltando2.png"));
                flag=1;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS1.png"));
                flag=1;
            }
        }
        if (direccion=='4')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/arsaltV.png"));
                flag=1;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltandoV1.png"));
                flag=1;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS1V.png"));
                flag=1;
            }
        }

        get_carro()->CalcularPosicion();
    }
    else if(vec==2&&P==1){
        if (direccion=='D')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/saltar6.png"));
                flag=0;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltando2.png"));
                flag=0;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS2.png"));
                flag=0;
            }
        }
        if (direccion=='A')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/arsaltV.png"));
                flag=0;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltandoV2.png"));
                flag=0;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS2V.png"));
                flag=0;
            }
        }

        get_carro()->CalcularPosicion();
    }
    else if(vec==2&&P==2){
        if (direccion=='6')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/saltar6.png"));
                flag=0;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltando2.png"));
                flag=0;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS2.png"));
                flag=0;
            }
        }
        if (direccion=='4')
        {
            if(seleccion==1){
                setPixmap(QPixmap(":/arsaltV.png"));
                flag=0;
            }
            if(seleccion==0){
                setPixmap(QPixmap(":/capu_saltandoV2.png"));
                flag=0;
            }
            if(seleccion==2){
                setPixmap(QPixmap(":/esmadS2V.png"));
                flag=0;
            }
        }

        get_carro()->CalcularPosicion();
    }
    get_carro()->CalcularPosicion();

}




Cuerpo* grafica::get_carro(){
    return car;
}


void grafica::posicion(float v_lim){
    car->CalcularPosicion();
    setPos(car->get_px(),(v_lim-car->get_py()-((car->get_h())*escala)));

}

void grafica::porro(float v_lim)
{
 car->posicionporro();
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

//void grafica::set_c(QString co)
//{
//    c=co;
//}

