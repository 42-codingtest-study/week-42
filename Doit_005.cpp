// 1초
#include <iostream>
#include <cstring>
int main()
{
    int n, m;
    int arr[1000001];
    int devideCount[1001]; // 누적합
    long ans = 0;

    scanf("%d %d", &n, &m);
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] = (arr[i - 1] + arr[i]) % m;
        if (arr[i] == 0)
            ans++;
        // 나머지가 같은 인덱스 카운트
        devideCount[arr[i]]++;
    }
    // printf("%ld\n", ans);
    // 조합 게산
    for (int i = 0; i < m; i++)
    {
        // printf("devide count : %d\n", devideCount[i]);
        ans += (long)devideCount[i] * (devideCount[i] - 1) / 2;
        // printf("ans : %ld\n ", ans);
    }
    // printf("%ld\n", ans + devideCount[1]);
    printf("%ld\n", ans);
}
