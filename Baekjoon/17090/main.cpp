#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

template <typename T> T read();
template <typename T> Vec<T> read(int size);
template <typename T> Vec<Vec<T>> read(int r_size, int c_size);

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

constexpr array<int, 4> dx = { { -1, 0, 1, 0 } };
constexpr array<int, 4> dy = { { 0, -1, 0, 1 } };

int N, M;
Vec2<char> maze;

bool dfs(int r, int c, Vec2<bool> &can_escape, Vec2<bool> &visited) {
  static auto is_in = [](int r, int c) { return 0 <= r && r < N && 0 <= c && c < M; };
  static auto move = [](int r, int c, char l) {
    if (l == 'U') r = r - 1;
    if (l == 'R') c = c + 1;
    if (l == 'D') r = r + 1;
    if (l == 'L') c = c - 1;

    return make_pair(r, c);
  };

  auto [nr, nc] = move(r, c, maze[r][c]);
  if (!is_in(nr, nc)) { return can_escape[r][c] = true; }

  if (visited[nr][nc]) { return can_escape[r][c] = can_escape[nr][nc]; }
  visited[nr][nc] = true;

  return can_escape[r][c] = dfs(nr, nc, can_escape, visited);
}

int solve() {
  int cnt = 0;

  Vec2<bool> can_escape(N, Vec<bool>(M, false));
  Vec2<bool> visited(N, Vec<bool>(M, false));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j]) {
        visited[i][j] = true;
        dfs(i, j, can_escape, visited);
      };
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // cout << can_escape[i][j] << ends;
      if (can_escape[i][j]) cnt++;
    }
    // cout << endl;
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  N = read<int>(), M = read<int>(); // 3 <= N, M <= 500
  maze = read<char>(N, M);          // 1 of U, R, D, L

  cout << solve() << endl;

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

template <typename T> Vec<T> read(int size) {
  Vec<T> v(size);
  for (auto &el : v) el = read<T>();
  return v;
}

template <typename T> Vec<Vec<T>> read(int r_size, int c_size) {
  Vec<Vec<T>> v(r_size, Vec<T>(c_size));
  for (auto &r : v) r = read<T>(c_size);
  return v;
}
