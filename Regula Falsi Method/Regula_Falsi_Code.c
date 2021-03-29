#include<stdio.h>
#include<math.h>
#define EPSILON 0.0005

double function(double x)
{
  //return x-exp(-x);
  return x*log10(x)-1.2;
}


int main()
{
  double x1,x2,xn,x=0.0,res;
  int i=0;

  do
  {
     if(function(i)<0)
        x1=i;

     else if(function(i)>0)
     {
        x2=i;
        break;
     }
    i++;
  }while(1);

  printf("a = %.lf \nb = %.lf\n\n",x1,x2);
  i=1;
  do
  {
     xn  = x;
     res = ((x2-x1)/(function(x2)-function(x1)))*function(x1);
     x   = x1-res;
     
     if(function(x)<0)
        x1=x;

     else if(function(x)>0)
        x2=x;
    
   printf("x%d : %.3lf\n",i,x);
   i++;
  }while(fabs(xn-x)>EPSILON);

  printf("\nRoot of give equation : %.3lf\n\n",x);
return 0;
}
