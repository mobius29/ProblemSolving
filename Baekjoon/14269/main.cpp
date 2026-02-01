#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

struct Enemy {
  int a, b, c;

  friend istream &operator>>(istream &is, Enemy &e) {
    return is >> e.a >> e.b >> e.c;
  }

  bool operator<(const Enemy &right) const {
    return c < right.c;
  }
};

int solve(vector<Enemy> &enemies) {
  sort(all(enemies));

  multiset<int> swords;
  for (const auto &enemy : enemies) {
    if (swords.find(enemy.a) == swords.end()) swords.emplace(enemy.a);
  }

  for (const auto &[a, b, c] : enemies) {
    auto iter = swords.find(a);
    swords.erase(iter);

    auto iter_lower = swords.lower_bound(b);
    if (iter_lower == swords.end() || *iter_lower > c) { swords.emplace(c); }

    swords.emplace(a);
  }

  return swords.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Enemy> enemies(n);
  for (auto &enemy : enemies) cin >> enemy;

  cout << solve(enemies) << endl;

  return 0;
}
