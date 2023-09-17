#include <iostream>
// 구간 합
using namespace std;

int main()
{
    int n, sum = 0;
    string num;
    cin >> n;
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        sum += (num[i] - '0');
    }
    cout << sum << std::endl;
}