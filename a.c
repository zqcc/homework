#include<stdio.h>
#include<stdlib.h>
#define DEBUG
int main (){
  int i,j;
  int n=0,m=0;
  scanf("%d%d\n", &n, &m);
  int **map;
  int s[2],e[2];
  map = (int **)malloc(n*sizeof(int*));
  for (i=0; i<m; i++){
    map[i] = (int *)malloc(m*sizeof(int));
  }
  for (i=0; i<n; i++){
    for (j=0 ; j<m; j++){
      if((map[i][j] = (int)getchar())=='S'){
        s[0]=i;
        s[1]=j;
      }else if(map[i][j]=='E'){
        e[0]=i;
        e[1]=j;
      }
    }
    getchar();
  }

#ifdef DEBUG
  printf("***---DEBUG---***\n");
  printf("%d %d\n",n ,m);
  for (i=0; i<n; i++){
    for (j=0; j<m; j++){
      printf("%c",map[i][j]);
    }
    printf("\n");
  }
#endif

  for (i=0; i<m; i++){
    free(map[i]);
  }
  free(map);
  return 0;
}
