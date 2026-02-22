#include <iostream>

#define endl '\n'
using namespace std;

using ll = long long;

template <typename T> T read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto N = read<ll>();

  ll answer = 0;
  while (N) {
    answer = answer * 2 + N % 2;
    N /= 2;
  }
  cout << answer << endl;

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T _read_primitive() {
  T ret;
  cin >> ret;
  return ret;
}

template <typename T> T read() {
  return _read_primitive<T>();
}
