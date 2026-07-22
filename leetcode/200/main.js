class Queue {
  constructor() {
    this.q = [];
    this.head = 0;
  }
  push(x) {
    this.q.push(x);
  }
  pop() {
    return this.q[this.head++];
  }
  size() {
    return this.q.length - this.head;
  }
}

const dx = [-1, 0, 1, 0];
const dy = [0, 1, 0, -1];

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function (grid) {
  const m = grid.length,
    n = grid[0].length;
  const isIn = (r, c) => 0 <= r && r < m && 0 <= c && c < n;
  const visited = Array.from({ length: m }, () => Array(n).fill(false));

  const findIsland = (sr, sc) => {
    const q = new Queue();
    q.push([sr, sc]);
    visited[sr][sc] = true;
    while (q.size()) {
      const [cr, cc] = q.pop();
      for (let i = 0; i < 4; i++) {
        const nr = cr + dx[i],
          nc = cc + dy[i];
        if (!isIn(nr, nc) || grid[nr][nc] !== "1" || visited[nr][nc]) continue;
        q.push([nr, nc]);
        visited[nr][nc] = true;
      }
    }
  };

  let answer = 0;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] !== "1" || visited[i][j]) continue;
      answer++;
      findIsland(i, j);
    }
  }
  return answer;
};
