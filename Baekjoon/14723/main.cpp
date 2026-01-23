#include <iostream>

#define ends " "
#define endl "\n"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int a = 1, b = 1;
  int x = 1;
  for (int i = 1; i < N; i++) {
    if (a == 1) {
      a = ++x;
      b = 1;
    } else {
      a--, b++;
    }
  }

  cout << a << ends << b << endl;

  return 0;
}
