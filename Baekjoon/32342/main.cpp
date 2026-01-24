#include <iostream>
#include <string>

#define ends " "
#define endl "\n"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;
  cin >> Q;

  const string WOW = "WOW";

  while (Q--) {
    string str;
    cin >> str;

    size_t len = str.length();
    if (len < 3) {
      cout << 0 << endl;
      continue;
    }

    int cnt = 0;
    for (int i = 0; i < len - 2; i++) {
      bool flag = true;
      for (int j = 0; j < 3; j++) {
        if (WOW[j] != str[i + j]) flag = false;
      }

      if (flag) cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}
