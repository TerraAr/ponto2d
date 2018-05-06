#include<cmath>

#define PI 3.14159265358979323846

class ponto2d{
private:
double pol[2],rect[2];

void pol(){
pol[0]=sqrt(rect[0]*rect[0]+rect[1]*rect[1]);
pol[1]=atan(rect[1]/rect[0]);
}

void rect(){
rect[0]=pol[0]*cos(pol[1]);
rect[1]=pol[0]*sin(pol[1]);
}

public:
friend ponto2d operator+(const ponto2d&,const ponto2d&);
friend ponto2d operator-(const ponto2d&,const ponto2d&);
friend ponto2d operator*(const ponto2d&,const ponto2d&);
friend ponto2d operator/(const ponto2d&,const ponto2d&);

ponto2d(){
pol[0]=0;
pol[1]=0;
rect[0]=0;
rect[1]=0;
}

void pol(double a,double b){
pol[0]=a;
pol[1]=b;
rect();
}

void rect(double x,double y){
rect[0]=x;
rect[1]=y;
pol();
}
};

ponto2d operator+(const ponto2d& a,const ponto2d& b){
ponto2d aux;
aux.rect[0]=a.rect[0]+b.rect[0];
aux.rect[1]=a.rect[1]+b.rect[1];
aux.pol();
return aux;
}

ponto2d operator-(const ponto2d& a,const ponto2d& b){
ponto2d aux;
aux.rect[0]=a.rect[0]-b.rect[0];
aux.rect[1]=a.rect[1]-b.rect[1];
aux.pol();
return aux;
}

ponto2d operator*(const ponto2d& a,const ponto2d& b){
ponto2d aux;
aux.pol[0]=a.pol[0]*b.pol[0];
aux.pol[1]=a.pol[1]+b.pol[1];
aux.rect();
return aux;
}

ponto2d operator/(const ponto2d& a,const ponto2d& b){
ponto2d aux;
aux.pol[0]=a.pol[0]/b.pol[0];
aux.pol[1]=a.pol[1]-b.pol[1];
aux.rect();
return aux;
}