#include <algorithm>
#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Vec<int> v(3);
  for (auto &a : v) a = read<int>();

  if (v[0] == v[1] && v[1] == v[2]) {
    cout << (10000 + 1000 * v[1]) << endl;
  } else if (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]) {
    int m = max({ v[0], v[1], v[2] });
    cout << (100 * m) << endl;
  } else {
    int m = v[0] == v[1] || v[1] == v[2] ? v[1] : v[0];
    cout << (1000 + 100 * m) << endl;
  }

  return 0;
}
