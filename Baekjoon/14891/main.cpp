#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

#define endl '\n'
using namespace std;

using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;

using Cogwheel = array<bool, 8>;
using Cogwheels = array<Cogwheel, 4>;

void rotate_cogwheel(Cogwheel &cogwheel, int dir) {
  if (dir == -1) { rotate(cogwheel.begin(), cogwheel.begin() + 1, cogwheel.end()); }
  if (dir == 1) { rotate(cogwheel.begin(), cogwheel.end() - 1, cogwheel.end()); }
}

void rotate_cogwheels(Cogwheels &cogwheels, int start, int dir) {
  Vec<pii> rotate_list;
  rotate_list.push_back({ start, dir });

  int cur_dir = -dir;
  for (int i = start - 1; i >= 0 && cogwheels[i + 1][6] != cogwheels[i][2]; i--) {
    rotate_list.push_back({ i, cur_dir });
    cur_dir *= -1;
  }

  cur_dir = -dir;
  for (int i = start + 1; i < 4 && cogwheels[i - 1][2] != cogwheels[i][6]; i++) {
    rotate_list.push_back({ i, cur_dir });
    cur_dir *= -1;
  }

  for (const auto &rotation : rotate_list) {
    int idx = rotation.first, dir = rotation.second;
    rotate_cogwheel(cogwheels[idx], dir);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Cogwheels cogwheels; // true: S, false: N
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      char c;
      cin >> c;
      cogwheels[i][j] = c == '1';
    }
  }

  int K;
  cin >> K;
  while (K--) {
    int start, dir;
    cin >> start >> dir;
    rotate_cogwheels(cogwheels, start - 1, dir);
  }

  int result = 0, score = 1;
  for (const auto &cogwheel : cogwheels) {
    if (cogwheel[0]) result += score;
    score *= 2;
  }

  cout << result << endl;

  return 0;
}
