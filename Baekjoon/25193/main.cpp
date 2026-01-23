#include <iostream>
#include <string>

#define endl "\n"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  string S;
  cin >> S;

  int C = 0;
  for (auto c : S) {
    if (c == 'C') C++;
  }

  int area = N - C + 1;
  cout << (C % area == 0 ? C / area : C / area + 1) << endl;

  return 0;
}
