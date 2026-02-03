#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> using Vec = vector<T>;

int solve(const int N) {
  Vec<int> fibo(46, 0);
  fibo[1] = 1;

  for (int i = 2; i <= N; i++) { fibo[i] = fibo[i - 1] + fibo[i - 2]; }

  return fibo[N];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  cout << solve(N) << endl;

  return 0;
}
