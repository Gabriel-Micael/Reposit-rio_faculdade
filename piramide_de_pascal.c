#include <stdio.h>

int main(void) {
  int mat[100][100],n;
  scanf("%d",&n);
  for(int i =0 ; i < n;i++){
    mat[i][i]=1;
    mat[i][0]=1;
    for(int j = 1;j<i;j++){
      mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
    }
  }
  for(int i = 0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%4d ",mat[i][j]);
    }
    printf("\n");
  }
}
