#include <iostream>
#include <algorithm>
using namespace std;

// n 이 15000개고, 그 중 두개를 모두 골라 m과 비교하면 시간초과는 안날거같긴 함.
// 225000000
//  배열 사용.
int main()
{
  int n, m;
  int arr[15000];

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // 양 끝에서 좁혀오는 투포인터 사용을 위해 정렬
  sort(arr, arr + n);

  int start = 0;
  int end = n - 1;
  int cnt = 0; // 최대 가능 갯수가 15000x15000 보다 작기 때문에 그냥 int

  // 투포인터 진행
  while (start != end)
  {
    if (arr[start] + arr[end] < m)
    {
      start++;
    }
    else if (arr[start] + arr[end] == m)
    {
      cnt++;
      end--;
    }
    else if (arr[start] + arr[end] > m)
    {
      end--;
    }
  }
  cout << cnt << "\n";

  return 0;
}