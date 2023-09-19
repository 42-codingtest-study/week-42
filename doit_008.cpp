#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

//입력이 2000개, 2000x2000 개 투포인터 사용하장
// 배열  사용
// 가능 반례 : 좋은수가 없을경우

int n;
long long arr[2002];
long long sum[2002];
set<int> numbers;
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lld", &arr[i]);
  sort(arr, arr+n); //투포인터 사용을 위한 정렬

  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    int target = arr[i];

    int pointer1 = 0;
    int pointer2 = n-1; //투포인터
    
    while(pointer1 < pointer2)
    {
      if (pointer1 != i && pointer2 != i) // i 번째 수는 제외한다.
      {
        if (arr[pointer1] + arr[pointer2] == target)
        {
          numbers.insert(i);
          pointer1++;
        }
        if (arr[pointer1] + arr[pointer2] < target )
          pointer1++;
        if (arr[pointer1] + arr[pointer2] > target )
          pointer2--;
      }
      if (pointer1 == i)
        pointer1++;
      else if (pointer2 == i)
        pointer2--;
    }
  }
  printf("%d\n", (int)numbers.size());
  return 0;
}