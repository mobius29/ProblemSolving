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

ll N, S, L;
Vec<ll> dists;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S >> L;
  S -= 1;

  dists.assign(N - 1, 0);
  for (int i = 0; i < N - 1; ++i) { cin >> dists[i]; }

  Vec<ll> prefix_sum(N, 0);
  prefix_sum[S] = 0;
  for (int i = S - 1; i >= 0; --i) { prefix_sum[i] = prefix_sum[i + 1] + dists[i]; }
  for (int i = S + 1; i < N; ++i) { prefix_sum[i] = prefix_sum[i - 1] + dists[i - 1]; }

  int answer = 1;

  for (int i = 0; i <= S; ++i) {
    for (int j = N - 1; j >= S; --j) {
      ll left = prefix_sum[i] * 2 + prefix_sum[j];
      ll right = prefix_sum[i] + prefix_sum[j] * 2;

      if (left <= L || right <= L) {
        answer = max(answer, j - i + 1);
        break;
      }
    }
  }

  cout << answer << endl;

  return 0;
}
