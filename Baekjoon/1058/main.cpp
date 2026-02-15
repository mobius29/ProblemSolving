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
template <typename T> using Vec2 = Vec<Vec<T>>;

template <typename T> T read();
template <typename T> Vec<T> read(int size);
template <typename T> Vec<Vec<T>> read(int r_size, int c_size);

const int INF = 0x3f3f3f3f;

int solve(const int N, const Vec2<char> &friends) {
  Vec2<int> dist(N, Vec<int>(N, INF));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (friends[i][j] == 'Y') dist[i][j] = 1;
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int ret = 0;
  for (const auto &row : dist) {
    int cnt = 0;
    for (const auto &cell : row) cnt += (cell <= 2);
    ret = max(ret, cnt);
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const auto N = read<int>();            // 1 <= N <= 50
  const auto friends = read<char>(N, N); // Y / N

  cout << solve(N, friends) << endl;

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

template <typename T> Vec<T> read(int size) {
  Vec<T> v(size);
  for (auto &el : v) el = read<T>();
  return v;
}

template <typename T> Vec<Vec<T>> read(int r_size, int c_size) {
  Vec<Vec<T>> v(r_size, Vec<T>(c_size));
  for (auto &r : v) r = read<T>(c_size);
  return v;
}
