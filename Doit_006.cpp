#include <iostream>

using namespace std;
// O(N)
int main()
{
    int n;
    int sum = 1, res = 1;
    int start = 1, end = 1; // 같은 곳에서 시작해서 최대 갯수 찾기

    scanf("%d", &n);

    while (start != n)
    {
        if (sum < n)
        {
            end++;
            sum += end;
        }
        else if (sum > n)
        {
            sum -= start;
            start++;
        }
        else
        {
            end++;
            sum += end;
            res++;
        }
    }

    printf("%d\n", res);
}
