#include"../headers/conv2D.h"

using namespace std;

void test_0(double *xv,double *yv,int n,string file)
{
  fstream F;
  double pi=4.0*atan(1.0);
  double rmin,rmax,r,tht,thtinc;
  int i;

  rmin=0.5;
  rmax=1.0;
  thtinc=pi/n;

  F.open(file.c_str(),ios::out);
  for(i=0;i<=n;i++)
    {
      r=rmax;
      tht=0.5*pi+i*thtinc;
      xv[i]=r*cos(tht);
      yv[i]=r*sin(tht);
      F<<xv[i]<<" "<<yv[i]<<endl;
    }
  for(i=n+1;i<2*n+2;i++)
    {
      r=rmin;
      tht=1.5*pi-(i-n-1)*thtinc;
      xv[i]=r*cos(tht);
      yv[i]=r*sin(tht);
      F<<xv[i]<<" "<<yv[i]<<endl;
    }
  F<<xv[0]<<" "<<yv[0]<<endl;
  F.close();
}

int main(int argc,char *argv[])
{
  srand(time(NULL));
  int n=10,i;
  if(argc>1)
    n=atoi(argv[1]);
  double *x,*y;
  x=new double [2*n+2];
  y=new double [2*n+2];
  test_0(x,y,n,"datap");

  conv2D bord(2*n+2,x,y);

  fstream F;
  F.open("pnts",ios::out);
  double xp,yp;
  for(i=0;i<10000;i++)
    {
      xp=-1+2.0*rand()/(RAND_MAX+1.0);
      yp=-1+2.0*rand()/(RAND_MAX+1.0);
      if(!bord.contains(xp,yp))
	F<<xp<<" "<<yp<<"\n";
    }
  F.close();

  bord.printZones();

  return(0);
}
