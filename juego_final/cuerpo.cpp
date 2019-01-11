#include "cuerpo.h"
#include <math.h>

Cuerpo::Cuerpo()
{
    px=0;
    py=0;
    h=0;
    w=0;
    vx=0;
    vy=1;
    float K=p*cd;
}
void Cuerpo::set_valores(float x, float y, float a, float n)
{
  px=x;
  py=y;
  h=a;
  w=n;
}
float Cuerpo::get_px()
{
  return px;
}
float Cuerpo::get_py()
{
  return py;
}
float Cuerpo::get_h()
{
  return h;
}
float Cuerpo::get_w()
{
    return w;
}

float Cuerpo::GetVx()
{
    return vx;
}

float Cuerpo::GetVy()
{
    return vy;
}

void Cuerpo::CalcularPosicion()
{
    angulom=atan2(vy,vx);
//    V=sqrt((vx*vx)+(vy*vy));
//    ax+= (-((K*(V*V)*(rad*rad))/masa))*cos(angulom); // calcula la aceleracion en x
//    ay+=(-((K*(V*V)*(rad*rad))/masa))*sin(angulom)-10; //calcula la aceleracion en y
//    vx+=ax*0.02;
//    u=vx;
//    vy+=ay*0.02;
    px+=vx*0.02+((ax*(0.02*0.02))/2);
    py+=vy*0.02+((ay*(0.02*0.02))/2);


    if(py>-200){
        vy-=50;
        ax=0;
        ay=1;
    }
    else{
        vy=0;
        vx=0;
        ax=0;
        ay=1;
    }

//    px+=vx*cos(angulom)*0.2;
//    py+=vy*0.02+((ay*(0.02*0.02))/2);

    if (px>=950){
        px=950;


    }
    if(px<=0){
        px=0;
    }
    if (py<=-200){
        py=-200;
        //vy*=-1;
    }

}

void Cuerpo::posicionporro()
{
    if(py<300){
        px-=vx;
    }
    else{
        px+=vx;
    }

    circun=(px-500)*(px-500);
    circun=40000-circun;
    circun=sqrt(circun);
    circun+=300;
    py=circun;


//    if(py>=500){
//        py=500;
//        vy=vy*-1;
//    }
//    if(px>=900){
//        px=700;
//        vx=vx*-1;
//    }
//    if(px<=200){
//        px=300;
//        vx=vx*-1;
//    }
//    if(py<=0){
//        py=0;
//        vy=vy*-1;
//    }

}
void Cuerpo::set_px(float x)
{
  px=x;
}
void Cuerpo::set_py(float y)
{
    py=y;
}

void Cuerpo::SetVx(float vx_)
{
    vx=vx_;
}

void Cuerpo::SetVy(float vy_)
{
    vy=vy_;
}
void Cuerpo::par()
{

        px=px+dt;
        py=py+dt-0.2;

}
