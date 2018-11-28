#ifndef CUERPO_H
#define CUERPO_H




class Cuerpo
{
private:
    float px;
    float py;
    float h=40;
    float w=40;
    float dt=0.1;
    float vx,vy,rad,angulom,V,ax=0,ay=0,A,K,cd=0.01,p=1.225,masa=100,u;

public:
    Cuerpo();

    void set_valores(float x, float y, float a, float n);

    void par();
    float get_px();

    float get_py();

    float get_h();

    float get_w();
    float GetVx();
    float GetVy();
    float GetRad();
    void CalcularPosicion();


    void set_px(float x);

    void set_py(float y);
    void SetVx(float vx_);
    void SetVy(float vy_);
    void SetRad(float r);
    void Setmasa(float m);
};

#endif // CUERPO_H
