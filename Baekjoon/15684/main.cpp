#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

using ll = long long;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

int N, M, H;
Vec2<bool> ladder;

// O(N * H)
bool simulate() {
  auto _simulate = [&](const int start) {
    int end = start;
    for (int h = 1; h <= H; h++) {
      if (end < N && ladder[h][end]) end += 1;
      else if (end > 1 && ladder[h][end - 1]) end -= 1;
    }

    return start == end;
  };

  for (int start = 1; start <= N; start++) {
    if (!_simulate(start)) return false;
  }

  return true;
}

bool is_placable(const int h, const int n) {
  if (ladder[h][n]) return false;
  if (n > 1 && ladder[h][n - 1]) return false;
  if (n < N - 1 && ladder[h][n + 1]) return false;

  return true;
}

bool dfs(int cur_count, int cur_idx, const int target_count) {
  if (cur_count == target_count) { return simulate(); }

  for (int i = cur_idx; i <= H * (N - 1); i++) {
    int h = (i - 1) / (N - 1) + 1;
    int n = (i - 1) % (N - 1) + 1;

    if (!is_placable(h, n)) { continue; }

    ladder[h][n] = true;
    if (dfs(cur_count + 1, i + 1, target_count)) return true;
    ladder[h][n] = false;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> H;
  ladder.assign(H + 1, Vec<bool>(N, false));

  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    ladder[a][b] = true;
  }

  for (int target_count = 0; target_count <= 3; target_count++) {
    if (dfs(0, 1, target_count)) {
      cout << target_count << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
