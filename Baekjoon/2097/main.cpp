#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

int solve(const int N) {
  int a = 2, b = 2;
  while (a * b < N) {
    if (a == b) a += 1;
    else b += 1;
  }

  return (a + b - 2) * 2;
  ;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N = read<int>();
  cout << solve(N) << endl;

  return 0;
}
