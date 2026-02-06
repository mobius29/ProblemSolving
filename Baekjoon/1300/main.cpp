#include <algorithm>
#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

using ll = long long;

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

int solve(const ll N, const ll k) {
  int ret = 0;

  ll low = 1, high = N * N;
  while (low <= high) {
    ll m = (low + high) / 2;

    ll cnt = 0;
    for (ll i = 1; i <= N; i++) { cnt += min(N, m / i); }

    if (cnt < k) low = m + 1;
    else { high = m - 1, ret = m; }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const auto N = read<ll>(), k = read<ll>();
  cout << solve(N, k) << endl;

  return 0;
}
