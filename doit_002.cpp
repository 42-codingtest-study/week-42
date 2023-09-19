#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
  //시간복잡도 2초 2억,  N 1000 이하니까 O(N)
  // 자료구조는 그냥 배열 사용
  int n,m;
  float arr[1002];

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%f", &arr[i]); 
  m = *max_element(arr, arr+n);  
  
  float sum = 0;
  for (int i = 0; i < n; i++)
    sum += float(arr[i]/m*100);

  return 0;
//반례 떠올려야함
}