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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  array<int, 3> coins = { 0, 0, 0 };
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;

    int rest = 1000 - a % 1000;
    for (int i = 0; i < 3; ++i) {
      coins[i] += (rest % 10);
      rest /= 10;
    }
  }

  for (const auto &c : coins) { cout << c << ends; }

  return 0;
}
