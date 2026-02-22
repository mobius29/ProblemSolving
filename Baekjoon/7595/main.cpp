#include <iostream>

#define endl '\n'
using namespace std;

template <typename T> T read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    auto N = read<int>();
    if (N == 0) break;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= i; j++) { cout << '*'; }
      cout << endl;
    }
  }

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
