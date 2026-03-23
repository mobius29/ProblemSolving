#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

using ll = long long;
template <typename T> using Vec = vector<T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  Vec<ll> A(N);
  for (auto &a : A) cin >> a;

  ll B, C;
  cin >> B >> C;

  ll result = 0;
  for (auto a : A) {
    a -= B, result += 1;
    if (a > 0) { result += a % C == 0 ? a / C : a / C + 1; }
  }

  cout << result << endl;

  return 0;
}
