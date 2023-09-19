// s[i] = s[i-1] + a[i]
//  어떻게  O(N) 의 시간초과 문제를 O(1)로 해결하는지
// 구간 합

#include <iostream>
// memset
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    int arr[1025][1025];

    int x1, x2, y1, y2;
    memset(arr, 0, sizeof(arr));

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]);
    }
}