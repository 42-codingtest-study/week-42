// #include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int arr[1025][1025];
int sum[1025][1025];

int main()
{
  //시간 1초에 배열 크기가 1024x1024 니까 O(N) 으로..
  //자료구조는 그냥 배열로
  
  scanf("%d %d", &n, &m);
  sum[1][0] = 0;
  sum[0][0] = 0;
  sum[0][1] = 0;
  for (int i = 1; i <=n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &arr[i][j]);
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]; 
    }  //2차원 구간합 구해놓기
  }
  
  int x1,y1,x2,y2;
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%d\n",sum[x2][y2]- sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
  } //2차원 구간합 구하기
  return 0;
}