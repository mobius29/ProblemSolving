#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

int solve(const int N) {
  int ret = 0;

  for (int i = 1, diff = 0; diff < N; diff += i++) {
    if ((N - diff) % i == 0) ret++;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  cout << solve(N) << endl;

  return 0;
}
