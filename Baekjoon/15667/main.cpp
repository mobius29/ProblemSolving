#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto N = read<int>();
  for (int i = 1;; i++) {
    if (i * i + i + 1 == N) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
