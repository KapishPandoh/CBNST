#include<stdio.h>
#include<math.h>
#define EPSILON 0.0005

float function(float x)
{
  //return x*x-13;
  return 3*x-cos(x)-1;
}

float diffr(float x)
{
  //return 2*x;
  return 3+sin(x);
}

int main()
{
  float x1,x2,x0,x,xn;
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


  x0 = (x1+x2)/2;
  x = 0;
  i=1;

  do
  {
     xn=x0;
     x = x0 - (function(x0)/diffr(x0));
     x0 = x;

    printf("x%d : %.3f\n",i,x);
    i++;

  }while(abs(xn-x)>EPSILON);

  printf("\nRoot of give equation : %.3f\n\n",x);
return 0;
}
