#include <stdio.h>
int main()
{
   int n, m, i, j, k;
printf("Enter the number of processes :");
scanf("%d",&n);
printf("Enter the number of resources :");
scanf("%d",&m);
    int alloc[n][m];
  int max[n][m];
 
    int avail[m];
    
 for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
  printf("Enter the allocation matrix P%d :",i);
scanf("%d",&alloc[i][j]);
}
} 
 for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
  printf("Enter the max matrix P%d :",i);
scanf("%d",&max[i][j]);
}
} 
printf("Enter the available resources : ");
for(int k=0;k<m;k++)
{
scanf("%d",&avail[k]);
}
 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
     
      if(flag==1)
    {
      printf("Following is system is safe and the SAFE Sequence is :\n");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }
     
 
    return (0);
 
    // This code is contributed by Deep Baldha (CandyZack)
}
