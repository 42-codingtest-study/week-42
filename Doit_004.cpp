#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

// 구간 합 구하기 5
int main() {
  fast;
  int N, M, x1, x2, y1, y2;
  int graph[1025][1025];
  memset(graph, 0, sizeof(graph));
  cin >> N >> M;
  // 2차원 구간 합 구하기 (인덱스 0은 계산하기 쉽게 놔둠)
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> graph[i][j];
      graph[i][j] += graph[i][j - 1] + graph[i - 1][j] - graph[i - 1][j - 1];
    }
  }
  while (M--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << graph[x2][y2] - graph[x1 - 1][y2] - graph[x2][y1 - 1] +
                graph[x1 - 1][y1 - 1]
         << "\n";
  }
}
