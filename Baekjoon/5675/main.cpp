#include <iostream>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

int m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> m) {
    cout << (m % 6 == 0 ? 'Y' : 'N') << endl;
  }

  return 0;
}
