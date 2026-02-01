#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

int solve(const int A, const int B) {
  if (B % A != 0) return 0;

  int y = B / A, cnt = 0;
  for (int i = 1; i * i <= y; i++) {
    if (y % i == 0) {
      cnt++;
      if (i * i < y) cnt++;
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B;
  cin >> A >> B;
  cout << solve(A, B) << endl;

  return 0;
}
