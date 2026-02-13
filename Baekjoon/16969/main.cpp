#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

using ll = long long;

template <typename T> T read();
constexpr ll MOD = 1e9 + 9;

ll solve(const string &str) {
  ll ret = 1;

  char last = 0;
  for (auto &c : str) {
    if (c == 'c') ret *= (c == last ? 25LL : 26LL);
    else ret *= (c == last ? 9LL : 10LL);
    ret %= MOD;

    last = c;
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const auto str = read<string>();
  cout << solve(str) << endl;

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}
