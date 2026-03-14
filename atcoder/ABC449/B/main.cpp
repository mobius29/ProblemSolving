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

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

constexpr array<int, 4> dx = { { -1, 0, 1, 0 } };
constexpr array<int, 4> dy = { { 0, -1, 0, 1 } };

Vec<int> solve(int H, int W, const Vec<pii> &queries) {
  Vec<int> result;
  result.reserve(queries.size());

  for (const auto &[type, lines] : queries) {
    if (type == 1) {
      result.push_back(W * lines);
      H -= lines;
    } else {
      result.push_back(H * lines);
      W -= lines;
    }
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W, Q;
  cin >> H >> W >> Q;

  Vec<pii> queries(Q);
  for (auto &[fs, se] : queries) cin >> fs >> se;

  auto output = solve(H, W, queries);
  for (const auto &el : output) cout << el << endl;

  return 0;
}
