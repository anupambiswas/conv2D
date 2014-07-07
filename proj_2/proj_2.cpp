#include"../headers/conv2D.h"

using namespace std;

void test_0(double *xv,double *yv,int n,string file)
{
  fstream F;
  double pi=4.0*atan(1.0);
  double rmin,rmax,r,tht,rdif;
  rmin=0.5;
  rmax=1.0;
  rdif=rmax-rmin;
  F.open(file.c_str(),ios::out);
  for(int i=0;i<n;i++)
    {
      r=rmin+rdif*rand()/(RAND_MAX+1.0);
      tht=(2*pi/n)*i;
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
  int n=100,i;
  if(argc>1)
    n=atoi(argv[1]);
  double *x,*y;
  x=new double [n];
  y=new double [n];
  test_0(x,y,n,"datap");

  fstream G("ds",ios::in);
  for(i=0;i<n;i++)
    {
      G>>x[i]>>y[i];
    }
  G.close();

  conv2D bord(n,x,y);
  fstream F;
  F.open("pnts",ios::out);
  double xp,yp;
  for(i=0;i<1000;i++)
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
