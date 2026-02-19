#include <cstdio>
#include <vector>

#define endl '\n'
using namespace std;

template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

int solve(const int N, const int M, Vec<Vec2<bool>> &matrixes) {
  auto _flip = [&](int x, int y) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int cx = x + i, cy = y + j;
        matrixes[0][cx][cy] = matrixes[0][cx][cy] ? 0 : 1;
      }
    }
  };

  auto _is_same = [&]() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (matrixes[0][i][j] != matrixes[1][i][j]) return false;
      }
    }

    return true;
  };

  int ret = 0;
  for (int i = 0; i <= N - 3; i++) {
    for (int j = 0; j <= M - 3; j++) {
      if (matrixes[0][i][j] != matrixes[1][i][j]) {
        _flip(i, j);
        ret++;
      }
    }
  }

  return _is_same() ? ret : -1;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  Vec<Vec2<bool>> matrixes;
  for (int k = 0; k < 2; k++) {
    Vec2<bool> matrix(N, Vec<bool>(M, false));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        int x;
        scanf("%1d", &x);

        matrix[i][j] = x == 1;
      }
    }

    matrixes.push_back(matrix);
  }

  printf("%d\n", solve(N, M, matrixes));

  return 0;
}
