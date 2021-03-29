#include<stdio.h>
#include<math.h>

int main()
{
  int n;
  printf("Enter no. of variables : ");
  scanf("%d",&n);


  float a[n][n+1];
  printf("Enter elements in augmented matrix : ");
  for(int i=0;i<n;i++){
    for(int j=0;j<n+1;j++)
      scanf("%f",&a[i][j]);
  }



  for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
      if(i>j){
        float sub = a[i][j]/a[j][j];
        for(int k=0;k<n+1;k++)
            a[i][k] -= (sub*a[j][k]);
       }
     }
   }


  for(int j=n-1;j>=0;j--){
    for(int i=n-1;i>=0;i--){
      if(i<j){
        float sub = a[i][j]/a[j][j];
        for(int k=0;k<n+1;k++)
            a[i][k] -= (sub*a[j][k]);
       }
     }
   }


  printf("\nThe solution is: \n");
  for(int i=0; i<n; i++)
     printf("x%d = %.1f\n",i+1,a[i][n]/a[i][i]);

return 0;
}
