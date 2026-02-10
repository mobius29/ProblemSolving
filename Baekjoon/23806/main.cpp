#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> T read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto N = read<int>();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5 * N; j++) { cout << '@'; }
    cout << endl;
  }
  for (int i = 0; i < 3 * N; i++) {
    for (int j = 0; j < 5 * N; j++) {
      if (j < N || j >= 4 * N) cout << '@';
      else cout << ends;
    }
    cout << endl;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5 * N; j++) { cout << '@'; }
    cout << endl;
  }

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}
