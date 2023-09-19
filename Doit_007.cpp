#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    int arr[15001];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // 정렬
    sort(arr, arr + n);

    int start = 0;
    int end = n - 1;
    int cnt = 0;

    while (start != end) // 종료 조건
    {
        if (arr[start] + arr[end] < m)
        {
            start++;
        }
        else if (arr[start] + arr[end] > m)
        {
            end--;
        }
        else if (arr[start] + arr[end] == m)
        {
            cnt++;
            end--;
        }
    }
    printf("%d\n", cnt);
}