#include<cmath>
#include<iostream>

#define PI 3.14159265358979323846
#define complexo ponto2d

class ponto2d{
private:
#define ERRO 0.00001

double pol[2],rect[2];

void pol(){
pol[0]=sqrt(rect[0]*rect[0]+rect[1]*rect[1]);
pol[1]=asin(rect[1]/pol[0]);
if(rect[1]<0) pol[1]=PI-pol[1];
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
friend ponto2d operator-(const ponto2d&);

friend ponto2d operator=(ponto2d&,const ponto2d&);
friend ponto2d operator+=(ponto2d&,const ponto2d&);
friend ponto2d operator-=(ponto2d&,const ponto2d&);
friend ponto2d operator*=(ponto2d&,const ponto2d&);
friend ponto2d operator/=(ponto2d&,const ponto2d&);

friend bool operator==(const ponto2d&,const ponto2d&);
friend bool operator!=(const ponto2d&,const ponto2d&);

friend ponto2d pow(const ponto2d&,const double);
friend ponto2d sqrt(const ponto2d&);

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

void imprimerect(){
std::cout<<rect[0]<<"+"<<rect[1]<<"i"<<std::endl;
}

void imprimepol(){
std::cout<<pol[0]<<" /_"<<pol[1]<<" rad"<<std::endl;
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

ponto2d operator-(ponto2d& a){
ponto2d aux;
aux.pol[0]=a.pol[0];
aux.pol[1]=a.pol[1]+PI;
aux.rect();
return aux;
}


ponto2d operator=(ponto2d& a,const ponto2d& b){
a.rect[0]=b.rect[0];
a.rect[1]=b.rect[1];
a.pol[0]=b.pol[0];
a.pol[1]=b.pol[1];
return a;
}

ponto2d operator+=(ponto2d& a,const ponto2d& b){
a.rect[0]+=b.rect[0];
a.rect[1]+=b.rect[1];
a.pol();
return a;
}

ponto2d operator-=(ponto2d& a,const ponto2d& b){
a.rect[0]-=b.rect[0];
a.rect[1]-=b.rect[1];
a.pol();
return a;
}

ponto2d operator*=(ponto2d& a,const ponto2d& b){
a.pol[0]*=b.pol[0];
a.pol[1]+=b.pol[1];
a.rect();
return a;
}

ponto2d operator/=(ponto2d& a,const ponto2d& b){
a.pol[0]/=b.pol[0];
a.pol[1]-=b.pol[1];
a.rect();
return a;
}


bool operator==(const ponto2d& a,const ponto2d& b){
if(abs(a.rect[0]-b.rect[0])/a.rect[0]<ERRO && abs(a.rect[1]-b.rect[1])/a.rect[1]<ERRO) return 1;
return 0;
}

bool operator!=(const ponto2d& a,const ponto2d& b){
if(a==b) return 0;
return 1;
}


ponto2d pow(const ponto2d& a,const double x){
ponto2d aux;
aux.pol[0]=pow(a.pol[0],x);
aux.pol[1]=x*a.pol[1];
aux.rect();
return aux;
}

ponto2d sqrt(const ponto2d& a){
ponto2d aux;
aux.pol[0]=sqrt(a.pol[0]);
aux;pol[1]=a.pol[1]/2;
return aux;
}
