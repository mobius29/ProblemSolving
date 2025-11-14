#include <iostream>
#include <vector>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

vi v(11, 0);
int N, answer;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 2; i <= N; i++) {
    int m = i / 2;
    if (i % 2 == 0) {
      v[i] = m * m + 2 * v[m];
    } else {
      v[i] = m * (m + 1) + v[m] + v[m + 1];
    }
  }

  cout << v[N] << endl;

  return 0;
}
