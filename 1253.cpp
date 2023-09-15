#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0)
#define ll long long

// 좋다
int main()
{
    fast;
    int N, _answer = 0;
    ll tmp, A[2001];
    memset(A, 0, sizeof(A));
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    if (N == 1)
    {
        cout << 0;
        return 0;
    }
    sort(A, A + N);
    for (int i = 0; i < N; i++)
    {
        int _start = 0 == i ? 1 : 0, _end = N - 1 == i ? N - 2 : N - 1;
        while (_start < _end)
        {
            if (A[_start] + A[_end] >= A[i])
            {
                if (A[_start] + A[_end] == A[i])
                {
                    if (_start == i)
                        _start++;
                    else if (_end == i)
                        _end--;
                    else
                    {
                        _answer++;
                        break;
                    }
                }
                else
                    _end--;
            }
            else
                _start++;
        }
    }
    cout << _answer;
}
