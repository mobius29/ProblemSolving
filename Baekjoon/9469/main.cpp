#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

double solve(const array<double, 4> &input) {
  auto [d, a, b, f] = input;
  return d * f / (a + b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int P;
  cin >> P;

  while (P--) {
    int n;
    cin >> n;

    array<double, 4> input;
    for (double &el : input) cin >> el;

    cout << n << ends << solve(input) << endl;
  }

  return 0;
}
