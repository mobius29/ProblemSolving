#include <iostream>

#define ends " "
#define endl "\n"
using namespace std;

int T, n, a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;
  while (T--) {
    cin >> n;

    b = 0;
    for (int i = 0; i < n; i++) {
      b += 1;

      cin >> a;
      if (a == b)
        b += 1;
    }

    cout << b << endl;
  }

  return 0;
}
