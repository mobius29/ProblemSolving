#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> T read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    auto N = read<int>();
    if (N == 0) break;

    auto last = -1;
    for (int i = 0; i < N; i++) {
      auto a = read<int>();
      if (last == a) continue;

      cout << a << ends;
      last = a;
    }

    cout << '$' << endl;
  }

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}
