#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

constexpr int INF = 0x3f3f3f3f;

constexpr array<pii, 4> dir = {
  make_pair(0, 1),  // Right
  make_pair(1, 0),  // Down
  make_pair(0, -1), // Left
  make_pair(-1, 0), // Up
};

class CCTV {
  void set_directions(int type) {
    this->dirs.push_back(0);
    if (type == 2 || type == 4 || type == 5) this->dirs.push_back(2);
    if (type == 3 || type == 4 || type == 5) this->dirs.push_back(1);
    if (type == 5) this->dirs.push_back(3);
  }

public:
  int r, c, type;
  Vec<int> dirs;

  CCTV(int r, int c, int type) {
    this->r = r, this->c = c, this->type = type;
    set_directions(type);
  }

  void rotate() {
    for (auto &dir : dirs) { dir = (dir + 1) % 4; }
  }

  int get_rotation_count() {
    if (type == 2) return 2;
    if (type == 5) return 1;
    return 4;
  }
};

int N, M;        // 1 <= N, M <= 8
Vec<CCTV> cctvs; // len(cctvs) <= 8
Vec2<int> room;

int check() {
  Vec2<bool> cannot_see(N, Vec<bool>(M, true));

  for (auto &cctv : cctvs) {
    for (auto &idx : cctv.dirs) {
      int dr = dir[idx].first, dc = dir[idx].second;
      for (int r = cctv.r, c = cctv.c; 0 <= r && r < N && 0 <= c && c < M; r += dr, c += dc) {
        cannot_see[r][c] = false;
        if (room[r][c] == 6) { break; }
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (room[i][j] == 0 && cannot_see[i][j]) ret++;
    }
  }

  return ret;
}

int dfs(int cur) {
  if (cur == cctvs.size()) { return check(); }

  int ret = INF, count = cctvs[cur].get_rotation_count();
  for (int i = 0; i < count; i++) {
    ret = min(ret, dfs(cur + 1));
    cctvs[cur].rotate();
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  room.assign(N, Vec<int>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> room[i][j];
      if (1 <= room[i][j] && room[i][j] <= 5) { cctvs.push_back(CCTV(i, j, room[i][j])); }
    }
  }

  int result = dfs(0);
  cout << result << endl;

  return 0;
}
