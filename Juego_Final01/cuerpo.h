#ifndef CUERPO_H
#define CUERPO_H


class cuerpo
{
public:
    cuerpo();
    void set_valores(float x, float y, float a, float n);//indica los valores de el objeto
    void par();//actualiza la posicion de el objeto,moviendolo en x e y
    float get_px();
    float get_py();
    float get_h();
    float get_w();
    float GetVx();
    float GetVy();
    float GetRad();
    void CalcularPosicion();//calcula donde esta uvicado el personaje en el juego
    void posicionporro();
    void set_px(float x);
    void set_py(float y);
    void SetVx(float vx_);
    void SetVy(float vy_);
    void SetRad(float r);
    void Setmasa(float m);
private:
    float px;//posicion en x
    float py;//posicion en y
    float h=40;//altura
    float w=40;//ancho
    float dt=0.1;//constante
    float vx,vy,rad,V,ax=0,ay=0,A,K,cd=0.01,p=1.225,masa=100,u;
    int angulom=0;//es el angulo de el movimiento circular de el porro lanzado por el de artes
    int circun=20;//radio de la circunferencia
};

#endif // CUERPO_H
