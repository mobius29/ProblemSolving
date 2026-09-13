#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using u8 = uint8_t;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

constexpr array<int, 4> dx = { { -1, 0, 1, 0 } };
constexpr array<int, 4> dy = { { 0, -1, 0, 1 } };

bool is_prime(const int x) {
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return false;
  return true;
}

bool check(const string &str, int x) {
  Vec<int> mapping(26, -1);
  Vec<u8> is_occupied(10, false);

  for (int i = str.length() - 1; i >= 0; --i, x /= 10) {
    int n = x % 10, idx = str[i] - 'a';
    if (mapping[idx] == -1 && is_occupied[n] == false) mapping[idx] = n, is_occupied[n] = true;
    else if (mapping[idx] != n) return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string S;
  cin >> S;

  int l = S.length();
  if (l == 1) {
    cout << 2 << endl;
    return 0;
  }

  int answer = -1;
  int low = pow(10, l - 1), high = low * 10;
  for (int i = low + 1; i < high; i += 2) {
    if (!check(S, i)) continue;
    if (is_prime(i)) {
      answer = i;
      break;
    }
  }

  cout << answer << endl;

  return 0;
}
