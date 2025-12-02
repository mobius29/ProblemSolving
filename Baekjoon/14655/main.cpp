#include <iostream>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

int N, coin;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  int max = 0;
  for (int i = 0; i < N; ++i) {
    cin >> coin;
    max += coin > 0 ? coin : -coin;
  }

  for (int i = 0; i < N; ++i)
    cin >> coin;

  cout << 2 * max << endl;

  return 0;
}
