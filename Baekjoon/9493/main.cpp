#include <cmath>
#include <stdio.h>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> using Vec = vector<T>;

Vec<int> solve(const int m, const int a, const int b) {
  Vec<int> ret(3, 0);

  int diff = round(3600.0 * m * (b - a) / (a * b));
  for (int i = 2; i > 0; i--) {
    ret[i] = diff % 60;
    diff /= 60;
  }
  ret[0] = diff;

  return ret;
}

int main() {
  int m, a, b;

  while (true) {
    scanf("%d %d %d", &m, &a, &b);
    if (m == 0 && a == 0 && b == 0) break;

    Vec<int> answer = solve(m, a, b);
    printf("%d:%02d:%02d\n", answer[0], answer[1], answer[2]);
  }

  return 0;
}
