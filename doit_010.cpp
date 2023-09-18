#include <iostream>
#include <deque>
#include <vector>
#include <utility>

using namespace std;

// 5000000개 입력에 대한 크기 D부분문자열 찾고, 그 중 최솟값 찾기
// n x nlogn(정렬)  시간초과 난당
// 슬라이딩 윈도우 사용
int n, l;
deque<pair<int, int>> dq;
vector<pair<int, int>> node;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tmp;
  cin >> n >> l;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    node.push_back(make_pair(i, tmp)); // 노드들을 만든다.
  }
  for (int i = 0; i < n; i++)
  {
    while (!dq.empty() && dq.back().second > node[i].second) // 디큐 젤 뒤에 수를 현재 입력값과 비교해 더 값이 크면 팝해버린다.
      dq.pop_back();
    dq.push_back(node[i]); // 디큐 뒤에 새 노드를 넣는다.

    if (!dq.empty() && (i - dq.front().first) >= l) // 디큐가 안비어있고, 지금 디큐에 현재 가장 작은 값이 슬라이딩윈도우 범위를 벗어났으면 팝
      dq.pop_front();
    cout << dq.front().second << " ";
  }
}