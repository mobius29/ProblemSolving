#include <algorithm>
#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  Vec<pii> v;
  for (int i = 1; i <= M; i++) {
    int h1, h2;
    cin >> h1 >> h2;
    v.emplace_back(h1, i);
    v.emplace_back(h2, i);
  }

  sort(all(v));

  int idx = (N - 1) % (2 * M);
  cout << v[idx].second << endl;

  return 0;
}
