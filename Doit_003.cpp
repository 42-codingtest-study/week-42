// s[i] = s[i-1] + a[i]
//  어떻게  O(N) 의 시간초과 문제를 O(1)로 해결하는지
// 구간 합

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // 시간 초과 나서 추가함

    int n, m;
    int sumArr[100001];

    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        // cin >> sum;
        scanf("%d", &sum);
        sumArr[i] = sumArr[i - 1] + sum;
    }
    for (int i = 0; i < m; i++)
    {
        // cin >> start >> end;
        int start, end;
        scanf("%d %d", &start, &end);
        // cout << sumArr[end] - sumArr[start - 1] << endl;
        printf("%d\n", sumArr[end] - sumArr[start - 1]);
    }
}