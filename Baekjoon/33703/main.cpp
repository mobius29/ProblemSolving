#include <iostream>

#define endl '\n'
using namespace std;

using ll = long long;
template <typename T> T read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const auto N = read<ll>();
  cout << (N * (N + 1) / 2ll) << endl;

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}
