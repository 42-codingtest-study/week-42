#include <iostream>
using namespace std;

// n  길이를 알 수 있고 로직을 고려 -> O(N) 연산
//  n 만큼 크기의 배열을 만들어 구현 가능
int main()
{
    int n = 0, score = 0;
    int arr[1000];
    float sum = 0, max = 0;

    cin >> n;
    // 점수/Max*10
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    for (int i = 0; i < n; i++)
        sum += arr[i] / max * 100;

    // result += sum * 100 / max;
    cout << sum / n << std::endl;
}