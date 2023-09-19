#include <iostream>

using namespace std;

int main()
{
  // 1. N 값이 주어지고 바뀌는 일 없으니 그냥 배열 사용
  // 2. 1초 제한 시간. 수의 범위가 1 ~ 100 이므로 O(N) 복잡도로 그냥 다 더한다.
  int n;
  int sum = 0;
  string input;
  cin>>n;
  cin>>input;
  for (int i = 0; i <n; i++)
    sum += (input[i] - '0');
  cout<<sum<<"\n";

}