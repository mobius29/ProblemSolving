#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;

template <typename T> T read();
template <typename T> Vec<T> read(int size);
template <typename T> Vec<Vec<T>> read(const int row_size, const int col_size);

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr array<pii, 4> DELTA = { { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } } };

struct Node {
  int x, y, cnt;
  Node(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {
  }
};

int solve(Vec<Vec<int>> &v, const int &N, const int &M, const int &K) {
  queue<Node> q;
  Vec<Vec<bool>> visited(N, Vec<bool>(M, false));

  queue<pii> mannequins;
  Vec<Vec<int>> dist(N, Vec<int>(M, INF));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (v[i][j] == 3) {
        mannequins.emplace(i, j);
        dist[i][j] = 0;
      } else if (v[i][j] == 4) {
        q.emplace(i, j, 0);
        visited[i][j] = true;
      }
    }
  }

  auto is_in = [N, M](int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; };

  while (!mannequins.empty()) {
    auto [x, y] = mannequins.front();
    mannequins.pop();

    for (const auto &[dx, dy] : DELTA) {
      int nx = x + dx, ny = y + dy;
      if (is_in(nx, ny) && dist[nx][ny] == INF) {
        dist[nx][ny] = dist[x][y] + 1;
        if (dist[nx][ny] < K) mannequins.emplace(nx, ny);
      }
    }
  }

  while (!q.empty()) {
    auto [x, y, cnt] = q.front();
    q.pop();

    if (v[x][y] == 2) return cnt;

    for (const auto &[dx, dy] : DELTA) {
      int nx = x + dx, ny = y + dy;
      if (is_in(nx, ny) && !visited[nx][ny]) {
        visited[nx][ny] = true;
        if (v[nx][ny] == 1 || dist[nx][ny] <= K) continue;

        q.emplace(nx, ny, cnt + 1);
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto N = read<int>(), M = read<int>(), K = read<int>();
  auto v = read<int>(N, M);

  cout << solve(v, N, M, K) << endl;

  return 0;
}

// --------------------------- Helper Functions ---------------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

template <typename T> Vec<T> read(int size) {
  Vec<T> v(size);
  for (T &el : v) el = read<T>();
  return v;
}

template <typename T> Vec<Vec<T>> read(const int row_size, const int col_size) {
  Vec<Vec<T>> v(row_size, Vec<T>(col_size));
  for (Vec<T> &row : v) { row = read<T>(col_size); }
  return v;
}
