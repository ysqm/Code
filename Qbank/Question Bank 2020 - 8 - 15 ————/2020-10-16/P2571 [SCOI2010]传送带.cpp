# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <iostream>
# define LL long long
# define eps 1e-7

double distance(const double x,const double y,const double ax,const double ay){return sqrt((ax-x)*(ax-x)+(ay-y)*(ay-y));}
double P,Q,R,Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;

double Calc(const double sx,const double sy)
{
    double lx = Cx,ly = Cy,rx = Dx,ry = Dy,lans,rans;
    double lmidx,lmidy,rmidx,rmidy;
    while(fabs(rx-lx) > eps || fabs(ry-ly) > eps)
    {
        lmidx = lx + (rx-lx)/3;lmidy = ly + (ry-ly)/3;
        rmidx = rx - (rx-lx)/3;rmidy = ry - (ry-ly)/3;
        lans = distance(lmidx,lmidy,Dx,Dy)/Q + distance(sx,sy,lmidx,lmidy)/R;
        rans = distance(rmidx,rmidy,Dx,Dy)/Q + distance(sx,sy,rmidx,rmidy)/R;
        if(lans > rans) {lx = lmidx;ly = lmidy;}
        else {rx = rmidx;ry = rmidy;}
    }
    return lans;
}

int main()
{
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&Ax,&Ay,&Bx,&By,&Cx,&Cy,&Dx,&Dy,&P,&Q,&R);
    
    double lx = Ax,ly = Ay,rx = Bx,ry = By,lans,rans,ans = 1e9;
    double lmidx,lmidy,rmidx,rmidy;
    do
    {
        lmidx = lx + (rx-lx)/3;lmidy = ly + (ry-ly)/3;
        rmidx = rx - (rx-lx)/3;rmidy = ry - (ry-ly)/3;
        lans = distance(lmidx,lmidy,Ax,Ay)/P + Calc(lmidx,lmidy);
        rans = distance(rmidx,rmidy,Ax,Ay)/P + Calc(rmidx,rmidy);
        if(lans > rans) {lx = lmidx;ly = lmidy;}
        else {rx = rmidx;ry = rmidy;}
    }while(fabs(rx-lx) > eps || fabs(ry-ly) > eps);
    printf("%.2lf",lans);
    return 0;
}
