#include "cuerpo.h"
#include "math.h"

cuerpo::cuerpo()
{
    px=0;
    py=0;
    h=0;
    w=0;
    vx=0;
    vy=1;
}

void cuerpo::set_valores(float x, float y, float a, float n)
{
    px=x;
    py=y;
    h=a;
    w=n;
}

void cuerpo::par()
{
    px=px+dt;
    py=py+dt-0.2;

}

float cuerpo::get_px()
{
    return px;
}

float cuerpo::get_py()
{
    return py;
}

float cuerpo::get_h()
{
    return h;
}

float cuerpo::get_w()
{
    return w;
}

float cuerpo::GetVx()
{
    return vx;
}

float cuerpo::GetVy()
{
    return  vy;
}

float cuerpo::GetRad()
{
    return  rad;
}

void cuerpo::CalcularPosicion()//con esta ecuacion se aplica el movimiento parabolico al lanzar el proyectil
{
    angulom=atan2(vy,vx);
    px+=vx*dt+((ax*(dt*dt))/2);//0.02es delta dt
     py+=vy*dt+((ay*(dt*dt))/2);
//    px+=vx*0.02+((ax*0.02)/2);//calcula la posicion en x segun la velocidad y aceleracion de el objeto
//     py+=vy*0.02+((ay*(0.02))/2);//clcula la posicionen y segun la velocidad y la aeleracion
     if(py>-200){//si la altura exede el limite la velocidad dismnuye
         vy-=50;
         ax=0;
         ay=1;
     }
     else if(py<-200){
         py=-200;
     }
     else{
         vy=0;
         vx=0;
         ax=0;
         ay=0;
     }
}

void cuerpo::posicionporro()//con esta ecuacion se genera el movimiento circular
{
    rad=angulom*3.14/180;//se obtiene el radio de el movimiento circular de el porro
    px=px+circun*cos(rad);//se calcula la posicion de el porro en tiempo
    py=py+circun*sin(rad);
    angulom+=5;//se sunma 5 a los gradospara que se pueda dar una vulta de 360 grados
    if(angulom>=360){//cuando da lavuelta completa se regresa el contador de grados a cero
        angulom=0;
    }
}

void cuerpo::set_px(float x)
{
    px=x;
}

void cuerpo::set_py(float y)
{
    py=y;
}

void cuerpo::SetVx(float vx_)
{
    vx=vx_;
}

void cuerpo::SetVy(float vy_)
{
    vy=vy_;
}

void cuerpo::SetRad(float r)
{
    rad=r;
}

void cuerpo::Setmasa(float m)
{
    masa=m;
}

void cuerpo::setax(float Ax)
{
    ax=Ax;
}

void cuerpo::setay(float Ay)
{
    ay=Ay;
}
