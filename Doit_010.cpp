#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
typedef pair<int, int> node;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l;
    deque<node> arr;

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int now;
        cin >> now;
        // 현재 수보다 큰 값 제거
        while (arr.size() && arr.back().first > now)
            arr.pop_back();

        arr.push_back(node(now, i));
        // 범위 벗어난 값 제거ㅌ
        if (arr.front().second <= i - l)
            arr.pop_front();
        cout << arr.front().first << " ";
    }
}