#include<stdio.h>
#include<math.h>
#define EPSILON 0.0005


int main()
{

  // Input Matrix
  int n;
   printf("Enter no. of variables : ");
   scanf("%d",&n);
  float a[n][n+1];
  printf("Enter elements in augmented matrix : ");
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }


  // Checking Convergence
  float s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==j)
            s1+=fabs(a[i][j]);
        else
            s2+=fabs(a[i][j]);
      }
    }
    if(s1<s2)
    {
      printf("Gauss Seidel Method does not converges");
      exit(0);
    }
    printf("Gauss Seidel Method converges");




    //Finding variables
    float x[50][n];
    for(int i=0;i<n;i++)
        x[0][i]=0;

    int k=1;
    int flag=1;
    do{
        for(int i=0;i<n;i++)
        {
          x[k][i] = a[i][n];

          for(int j=0;j<i;j++)
            x[k][i] -= (a[i][j]*x[k][j]);

          for(int j=i+1;j<n;j++)
            x[k][i] -= (a[i][j]*x[k-1][j]);

          x[k][i] /= a[i][i];
        }

        for(int l=0;l<n;l++)
        {
          if(fabs(x[k-1][l]-x[k][l])<EPSILON)
          {
            flag=0;
            break;
          }
        }
      k++;
    }while(flag);

    k--;
    printf("\n\nSolution :\n");
    for(int i=0;i<n;i++)
        printf("x%d : %f\n",i+1,x[k][i]);

  return 0;
}

/*
Input1
10 1 1 12
2 10 1 13
2 2 10 14
*/

/*
Input2
10 -2 -1 -1 3
-2 10 -1 -1 15
-1 -1 10 -2 27
-1 -1 -2 10 -9
*/

/*
Input3
1 1 -1 -2
2 -1 1 5
-1 2 2 1
*/
