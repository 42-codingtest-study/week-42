#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int arr[2001];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // 정렬
    sort(arr, arr + n);

    int res = 0;

    if (n == 1)
    {
        printf("0");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int start = 0;
        int end = n - 1;
        long number = arr[i];

        while (start < end)
        {
            if (arr[start] + arr[end] == number)
            {
                if (start != i && end != i)
                {
                    res++;
                    break;
                }
                else if (start == i)
                    start++;
                else if (end == i)
                    end--;
            }
            else if (arr[start] + arr[end] < number)
                start++;
            else if (arr[start] + arr[end] > number)
                end--;
        }
    }
    printf("%d\n", res);
}