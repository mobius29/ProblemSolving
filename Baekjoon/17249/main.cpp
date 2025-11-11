#include <iostream>
#include <string>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

string str;
int l, r;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> str;

  bool isLeft = true;
  for (auto c : str) {
    if (c == '@') {
      if (isLeft)
        l++;
      else
        r++;
    }

    if (c == '(') {
      isLeft = false;
    }
  }

  cout << l << ends << r << endl;

  return 0;
}
