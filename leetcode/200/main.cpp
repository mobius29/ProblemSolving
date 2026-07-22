#include <queue>
#include <vector>
using namespace std;

using pii = pair<int, int>;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

class Solution {
  int m, n;

  bool is_in(int r, int c) {
    return 0 <= r && r < m && 0 <= c && c < n;
  }

  void find_island(int r, int c, vector<vector<bool>> &is_visited, const vector<vector<char>> &grid) {
    queue<pii> q;
    q.push({ r, c }), is_visited[r][c] = true;

    while (!q.empty()) {
      auto [cr, cc] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = cr + dx[i], nc = cc + dy[i];
        if (!is_in(nr, nc) || grid[nr][nc] != '1' || is_visited[nr][nc]) continue;
        q.push({ nr, nc }), is_visited[nr][nc] = true;
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    this->m = grid.size(), this->n = grid[0].size();
    int answer = 0;
    vector<vector<bool>> is_visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != '1' || is_visited[i][j]) continue;

        answer += 1;
        find_island(i, j, is_visited, grid);
      }
    }

    return answer;
  }
};
