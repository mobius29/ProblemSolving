#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

using ll = long long;

constexpr int MOD = 1e9 + 7;

template <typename T> T read();
ll pow(const ll &a, const ll &b);

int solve(const array<ll, 4> &inputs) {
  auto [n, m, r, k] = inputs;

  if (m <= r) return 0;

  // (r + 1)^n - 2 * r^n + (r - 1)^n
  ll a = pow(r + 1, n), b = 2 * pow(r, n) % MOD, c = pow(r - 1, n);
  ll cnt = (((a - b + MOD) % MOD) + c) % MOD;
  return (m - r) * cnt % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto T = read<int>();
  while (T--) {
    array<ll, 4> inputs;
    for (auto &el : inputs) el = read<ll>();
    cout << solve(inputs) << endl;
  }

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

ll pow(const ll &a, const ll &b) {
  if (b == 0) return 1;

  ll m = pow(a, b / 2) % MOD;
  ll rest = b % 2 == 1 ? a : 1;
  return ((m * m) % MOD) * rest % MOD;
}
