#include <iostream>
#include <string>

#define ends ' '
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  cout << (a.length() >= b.length() ? "go" : "no") << endl;

  return 0;
}
