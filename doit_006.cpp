#include <iostream>

using namespace std;

int main()
{
  // n 이 10000000 이고, 모든 경우의 수를 다 계산하면 시간초과남.
  // O(N) 으로 문제 풀기
  // 크기가 정해져있으니 그냥 배열로 품.
  int n;
  long long cnt = 1;
  int start = 1; // 투포인터 같은 지점에서 시작
  int end = 1;

  cin >> n;

  int value = 1;

  while (start != n) // 종료조건 -> end가 끝가지 다다르면? start 도 상관 없음.
  {
    if (value < n)
    {
      end++;
      value += end;
    }
    else if (value > n)
    {
      value -= start;
      start++;
    }
    else if (value == n)
    {
      end++;
      value += end;
      cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}