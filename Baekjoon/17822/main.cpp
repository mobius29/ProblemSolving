#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

Vec<pii> get_remove_positions(Vec2<int> &disks, const int N, const int M) {
  Vec<pii> remove_positions;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      auto cur = disks[i][j];
      if (cur == 0) continue;

      bool flag = false;
      auto next_j = (j + 1) % M;
      if (cur == disks[i][next_j]) {
        remove_positions.push_back({ i, j });
        remove_positions.push_back({ i, next_j });
        flag = true;
      }

      if (i < N - 1 && cur == disks[i + 1][j]) {
        if (!flag) remove_positions.push_back({ i, j });
        remove_positions.push_back({ i + 1, j });
      }
    }
  }

  return remove_positions;
}

void solve(Vec2<int> &disks, const int N, const int M, const int x, const int k) {
  Vec<pii> remove_positions = get_remove_positions(disks, N, M);

  if (!remove_positions.empty()) {
    for (const auto &[i, j] : remove_positions) { disks[i][j] = 0; }
    return;
  }

  int sum = 0, count = 0;
  for (const auto &disk : disks) {
    for (const auto &el : disk) {
      if (el == 0) continue;
      sum += el, count++;
    }
  }

  for (auto &disk : disks) {
    for (auto &el : disk) {
      if (el == 0) continue;

      if (el * count > sum) el -= 1;
      else if (el * count < sum) el += 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, T;
  cin >> N >> M >> T;

  Vec2<int> disks(N, Vec<int>(M));
  for (auto &disk : disks)
    for (auto &el : disk) cin >> el;

  while (T--) {
    int x, d, k;
    cin >> x >> d >> k;

    int shift = d == 0 ? M - k : k;
    for (int i = x - 1; i < N; i += x) {
      auto &disk = disks[i];
      rotate(disk.begin(), disk.begin() + shift, disk.end());
    }

    solve(disks, N, M, x, k);
  }

  int result = 0;
  for (const auto &disk : disks)
    for (const auto &el : disk) result += el;
  cout << result << endl;

  return 0;
}
