#include"../headers/conv2D.h"

using namespace std;

int main()
{
  int n=25,i;
  double *x,*y;
  x=new double [n];
  y=new double [n];

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

  bord.printZones("zones");

  return(0);
}
