#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

template <typename T> using Vec = vector<T>;

constexpr int INF = 0x3f3f3f3f;

constexpr array<int, 4> dx = { { -1, 0, 1, 0 } };
constexpr array<int, 4> dy = { { 0, -1, 0, 1 } };

struct Layer {
  array<array<short, 5>, 5> board;

  friend istream &operator>>(istream &is, Layer &p) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) { is >> p.board[i][j]; }
    }
    return is;
  }

  bool operator<(const Layer &other) const {
    return board < other.board;
  }

  void rotate() {
    array<array<short, 5>, 5> new_board;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) new_board[j][4 - i] = board[i][j];
    }
    board = new_board;
  }
};

int solve(Vec<Layer> &layers) {
  int result = INF;

  auto _bfs = [&](const array<int, 5> &ord) -> int {
    queue<pair<tuple<int, int, int>, int>> q;
    q.push({ { 0, 0, 0 }, 0 });

    bool is_visited[5][5][5] = {};
    is_visited[0][0][0] = true;

    static auto _is_in = [](const int &x, const int &y) { return 0 <= x && x < 5 && 0 <= y && y < 5; };

    while (!q.empty()) {
      auto [loc, cnt] = q.front();
      q.pop();

      if (loc == tuple{ 4, 4, 4 }) return cnt;

      auto [z, x, y] = loc;

      for (int i = -1; i <= 1; i += 2) {
        auto nz = z + i;
        if (0 <= nz && nz < 5 && !is_visited[nz][x][y] && layers[ord[nz]].board[x][y]) {
          q.push({ { nz, x, y }, cnt + 1 });
          is_visited[nz][x][y] = true;
        }
      }

      for (int i = 0; i < 4; i++) {
        auto [nx, ny] = array{ x + dx[i], y + dy[i] };
        if (!_is_in(nx, ny) || is_visited[z][nx][ny]) continue;
        is_visited[z][nx][ny] = true;

        if (layers[ord[z]].board[nx][ny] == 1) q.push({ { z, nx, ny }, cnt + 1 });
      }
    }

    return INF;
  };

  auto _dfs = [&](auto &&self, int cur) -> void {
    if (result == 12) return;

    if (cur == 5) {
      array<int, 5> order = { 0, 1, 2, 3, 4 };
      do {
        auto start = order[0], end = order[4];
        if (layers[start].board[0][0] && layers[end].board[4][4] == 1) { result = min(result, _bfs(order)); }
      } while (next_permutation(all(order)));

      return;
    }

    for (int i = 0; i < 4; i++) {
      self(self, cur + 1);
      layers[cur].rotate();
    }
  };

  _dfs(_dfs, 0);

  return result == INF ? -1 : result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Vec<Layer> layers(5);
  for (auto &layer : layers) cin >> layer;

  cout << solve(layers) << endl;

  return 0;
}
