#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

constexpr array<pii, 8> adjacent = {
  pii{ -1, -1 }, pii{ -1, 0 }, pii{ -1, 1 }, pii{ 0, -1 }, pii{ 0, 1 }, pii{ 1, -1 }, pii{ 1, 0 }, pii{ 1, 1 },
};

int N, M, K;
Vec2<int> ground, A;
Vec<Vec2<int>> trees;

Vec2<int> spring() {
  Vec2<int> gradients(N, Vec<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      auto &tree = trees[i][j];
      for (int k = tree.size() - 1; k >= 0; k--) {
        if (ground[i][j] < tree[k]) {
          gradients[i][j] += tree[k] / 2;
          tree[k] = 0;
        } else {
          ground[i][j] -= tree[k];
          tree[k] += 1;
        }
      }

      sort(all(tree), [](auto &a, auto &b) { return a > b; });

      while (!tree.empty() && tree.back() == 0) {
        if (tree.back() == 0) tree.pop_back();
      }
    }
  }

  return gradients;
}

void summer(Vec2<int> &gradients) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) { ground[i][j] += gradients[i][j]; }
}

void autumn() {
  static auto is_in = [](int r, int c) { return 0 <= r && r < N && 0 <= c && c < N; };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (const auto &age : trees[i][j]) {
        if (age % 5 != 0) continue;

        for (const auto &d : adjacent) {
          int nx = i + d.first, ny = j + d.second;
          if (!is_in(nx, ny)) continue;

          trees[nx][ny].push_back(1);
        }
      }
    }
  }
}

void winter() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) ground[i][j] += A[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;
  ground.assign(N, Vec<int>(N, 5));

  A.reserve(N);
  for (int i = 0; i < N; i++) {
    Vec<int> row(N);
    for (auto &el : row) cin >> el;

    A.push_back(row);
  }

  trees.assign(N, Vec2<int>(N, Vec<int>()));
  for (int i = 0; i < M; i++) {
    int x, y, age;
    cin >> x >> y >> age;

    trees[x - 1][y - 1].push_back(age);
  }

  for (int i = 0; i < K; i++) {
    auto gradients = spring();
    summer(gradients);
    autumn();
    winter();
  }

  ll answer = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) answer += trees[i][j].size();
  }
  cout << answer << endl;

  return 0;
}
