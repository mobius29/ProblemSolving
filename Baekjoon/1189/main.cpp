#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

template <typename T> T read();
template <typename T> Vec<T> read(int size);
template <typename T> Vec<Vec<T>> read(int r_size, int c_size);

constexpr array<int, 4> dx = { { -1, 0, 1, 0 } };
constexpr array<int, 4> dy = { { 0, -1, 0, 1 } };

int solve(const int R, const int C, const int K, const Vec2<char> board) {
  Vec2<bool> visited(R, Vec<bool>(C, false));

  auto is_in = [R, C](int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; };
  auto dfs = [&](auto &&self, int x, int y, int cnt) {
    if (cnt > K) { return 0; }
    if (cnt == K && x == 0 && y == C - 1) { return 1; }

    int ret = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!is_in(nx, ny) || board[nx][ny] == 'T' || visited[nx][ny]) continue;

      visited[nx][ny] = true;
      ret += self(self, nx, ny, cnt + 1);
      visited[nx][ny] = false;
    }

    return ret;
  };

  visited[R - 1][0] = true;
  return dfs(dfs, R - 1, 0, 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const auto R = read<int>(), C = read<int>(), K = read<int>();
  const auto board = read<char>(R, C);

  cout << solve(R, C, K, board) << endl;

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
