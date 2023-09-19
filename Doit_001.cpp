#include <iostream>

using namespace std;
// n  길이를 알 수 있고 로직을 고려 -> O(N) 연산
//  n 만큼 크기의 배열을 만들어 구현 가능
int main()
{
    int n, sum = 0;
    string num;
    cin >> n; // 숫자의 개수 N
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        sum += (num[i] - '0');
    }
    cout << sum << std::endl;
}