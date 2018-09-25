#include<stdio.h>
#include<math.h>

#define PI M_PI
#define complexo ponto2d

class ponto2d{
private:
#define ERRO 0.00001

double pol[2],rect[2];

bool atualizado;

void pol(){
pol[0]=sqrt(rect[0]*rect[0]+rect[1]*rect[1]);
pol[1]=atan2(rect[1],rect[0]);
}

void rect(){
rect[0]=pol[0]*cos(pol[1]);
rect[1]=pol[0]*sin(pol[1]);
}

public:
ponto2d operator-();

ponto2d operator+(const ponto2d);
ponto2d operator-(const ponto2d);
ponto2d operator*(const ponto2d);
ponto2d operator/(const ponto2d);

ponto2d operator+(const double);
ponto2d operator-(const double);
ponto2d operator*(const double);
ponto2d operator/(const double);

ponto2d operator=(const ponto2d);
ponto2d operator+=(const ponto2d);
ponto2d operator-=(const ponto2d);
ponto2d operator*=(const ponto2d);
ponto2d operator/=(const ponto2d);

friend inline bool operator==(const ponto2d,const ponto2d);
friend inline bool operator!=(const ponto2d,const ponto2d);

friend ponto2d pow(const ponto2d,const double);
friend ponto2d sqrt(const ponto2d);
friend ponto2d cbrt(const ponto2d);

friend inline double abs(const ponto2d a);

ponto2d() : pol[0](0),pol[1](0),rect[0](0),rect[1](0) {}

void pol(double a,double b){
pol[0]=a;
pol[1]=b;
atualizado=1;
}

void rect(double x,double y){
rect[0]=x;
rect[1]=y;
atualizado=0;
}

void imprimerect(){
if(atualizado) rect();
printf("%lf+%lfi\n",rect[0],rect[1]);
}
void imprimepol(){
if(!atualizado) pol();
printf("%lf /_%lf rad\n",pol[0],pol[1]);
}
};

ponto2d ponto2d::operator-(){
if(!atualizado) pol();
ponto2d aux;
aux.pol[0]=pol[0];
aux.pol[1]=pol[1]+PI;
aux.atualizado=1;
return aux;
}


ponto2d ponto2d::operator+(const ponto2d b){
if(atualizado) rect();
if(b.atualizado) b.rect();
ponto2d aux;
aux.rect[0]=rect[0]+b.rect[0];
aux.rect[1]=rect[1]+b.rect[1];
aux.atualizado=0;
return aux;
}

ponto2d ponto2d::operator-(const ponto2d b){
if(atualizado) rect();
if(b.atualizado) b.rect();
ponto2d aux;
aux.rect[0]=rect[0]-b.rect[0];
aux.rect[1]=rect[1]-b.rect[1];
aux.atualizado=0;
return aux;
}

ponto2d ponto2d::operator*(const ponto2d b){
if(!atualizado) pol();
if(!b.atualizado) b.pol();
ponto2d aux;
aux.pol[0]=pol[0]*b.pol[0];
aux.pol[1]=pol[1]+b.pol[1];
aux.atualizado=1;
return aux;
}

ponto2d ponto2d::operator/(const ponto2d b){
if(!atualizado) pol();
if(!b.atualizado) b.pol();
ponto2d aux;
aux.pol[0]=pol[0]/b.pol[0];
aux.pol[1]=pol[1]-b.pol[1];
aux.atualizado=1;
return aux;
}


ponto2d ponto2d::operator+(const double b){
if(atualizado) rect();
ponto2d aux;
aux.rect[0]=rect[0]+b;
aux.rect[1]=rect[1];
aux.atualizado=0;
return aux;
}

ponto2d ponto2d::operator-(const double b){
if(atualizado) rect();
ponto2d aux;
aux.rect[0]=rect[0]-b;
aux.rect[1]=rect[1];
aux.atualizado=0;
return aux;
}

ponto2d ponto2d::operator*(const double b){
if(!atualizado) pol();
ponto2d aux;
aux.pol[0]=pol[0]*b;
aux.pol[1]=pol[1];
aux.atualizado=1;
return aux;
}

ponto2d ponto2d::operator/(const double b){
if(!atualizado) pol();
ponto2d aux;
aux.pol[0]=pol[0]/b;
aux.pol[1]=pol[1];
aux.atualizado=1;
return aux;
}


ponto2d ponto2d::operator=(const ponto2d b){
atualizado=b.atualizado;

if(atualizado){
pol[0]=b.pol[0];
pol[1]=b.pol[1];
}else{
rect[0]=b.rect[0];
rect[1]=b.rect[1];
}

return *this;
}

ponto2d ponto2d::operator+=(const ponto2d b){
if(atualizado){
atualizado=0;
rect();
}

rect[0]+=b.rect[0];
rect[1]+=b.rect[1];
return *this;
}

ponto2d ponto2d::operator-=(const ponto2d b){
if(atualizado){
atualizado=0;
rect();
}

rect[0]-=b.rect[0];
rect[1]-=b.rect[1];
return *this;
}

ponto2d ponto2d::operator*=(const ponto2d b){
if(!atualizado){
atualizado=1;
pol();
}

pol[0]*=b.pol[0];
pol[1]+=b.pol[1];
return *this;
}

ponto2d ponto2d::operator/=(const ponto2d b){
if(!atualizado){
atualizado=1;
pol();
}

pol[0]/=b.pol[0];
pol[1]-=b.pol[1];
return *this;
}


inline bool operator==(const ponto2d a,const ponto2d b){
if(abs(a.rect[0]-b.rect[0])/a.rect[0]<ERRO && abs(a.rect[1]-b.rect[1])/a.rect[1]<ERRO) return 1;
return 0;
}

inline bool operator!=(const ponto2d a,const ponto2d b){
if(a==b) return 0;
return 1;
}


ponto2d pow(const ponto2d a,const double x){
ponto2d aux;
aux.pol[0]=pow(a.pol[0],x);
aux.pol[1]=x*a.pol[1];
aux.atualizado=1;
return aux;
}

ponto2d sqrt(const ponto2d a){
ponto2d aux;
aux.pol[0]=sqrt(a.pol[0]);
aux.pol[1]=a.pol[1]/2;
aux.atualizado=1;
return aux;
}

ponto2d cbrt(const ponto2d a){
ponto2d aux;
aux.pol[0]=cbrt(a.pol[0]);
aux.pol[1]=a.pol[1]/3;
aux.atualizado=1;
return aux;
}


inline double abs(const ponto2d a){
if(!a.atualizado) a.pol();
return a.pol[0];
}
