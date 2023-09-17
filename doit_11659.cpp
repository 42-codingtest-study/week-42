#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  // 입력 10만 -> O(n^2), O(nlogn) 다 안됨. 무조건 O(n)
  // 갯수 정해져있으니 그냥 배열로
  // 반례 생각하기 -> 수가 long long 으로 넘어갈 확률은? -> 1000이 10만개 100000,000 -> 안넘긴 할듯
  int n, m;
  int arr[100002];
  int sum[100002];

  scanf("%d %d", &n, &m);  
  // cin>>n>>m;
  sum[0]  = 0;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &arr[i]);
    // cin>>arr[i];
    if (i == 1)
      sum[i] = arr[i];
    else
      sum[i] = sum[i-1] + arr[i];
  }
  
  for (int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    // cin>>from >> to;
    printf("%d\n", sum[to] - sum[from-1]);
    // cout<<sum[to] - sum[from-1] << "\n";
  }
  return 0;
}