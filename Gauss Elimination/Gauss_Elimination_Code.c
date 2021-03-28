#include<stdio.h>
#include<math.h>

int main()
{
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

  for(int j=0;j<n;j++)
  {
    for(int i=0;i<n;i++)
    {
      if(i>j)
      {
        float sub = a[i][j]/a[j][j];
        for(int k=0;k<n+1;k++)
            a[i][k] -= (sub*a[j][k]);
      }
    }
  }

  float res[n];

  res[n-1] = a[n-1][n]/a[n-1][n-1];
  for(int i=n-2;i>=0;i--)
  {
    float temp=0;

    for(int j=i+1;j<n+1;j++)
        temp += (a[i][j]*res[j]);

    res[i] = (a[i][n]-temp)/a[i][i];
  }

  printf("\nThe solution is: \n");
  for(int i=0; i<n; i++)
     printf("x%d = %.1f\n",i+1,res[i]);

return 0;
}
