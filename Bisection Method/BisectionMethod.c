#include<stdio.h>
#include<math.h>
#define EPSILON 0.0005

float function(float x)
{
   //return ( (x*x*x) + (4*x*x) - 10 ) ;
   return x-cos(x);
}


int main()
{
  float x1,x2,xn,x=0.0;
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

  printf("a = %.f \nb = %.f\n\n",x1,x2);
  i=1;
  do
  {
     xn = x;
     x = (x1+x2)/2;

     if(function(x)<0)
        x1=x;

     else if(function(x)>0)
        x2=x;


   printf("x%d : %.3f\n",i,x);
   i++;
  }while(fabs(xn-x)>EPSILON);

  printf("\nRoot of give equation : %.3f\n\n",x);
return 0;
}
