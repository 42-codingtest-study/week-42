#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int arr[1000002];
int sum[1000002];
long long cnt;

void getCombination(int arr[]) // 조합으로 나머지가 같았던 수 중 개수가 1보다 큰 애들 조합한다.
{
  for (int i = 0; i < m; i++)
  {
    long long num = (long long)arr[i];
    if (num > 1)
    {
      long long C = num * (num - 1) / 2; // nC2 계산식
      cnt += C;
    }
  }
}

int main()
{
  cnt = 0;

  cin >> n >> m;

  sum[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    sum[i] = (sum[i - 1] + (arr[i])) % m; // 합을 나눗셈 한 걸로 저장한다.
    if (sum[i] == 0)                      // 이미 나머지가 0 인 경우 원소 1개 짜리 개수 센다.
      cnt++;
  }

  int sameNumbers[1002];
  memset(sameNumbers, 0, 1002 * sizeof(int));
  for (int i = 1; i <= n; i++)
    sameNumbers[sum[i]]++;
  // sameNumbers 는 각각 나머지가 0,1,2... m-1 인 부분합의 개수를 저장한다.

  getCombination(sameNumbers);

  cout << cnt << "\n";
  return 0;
}