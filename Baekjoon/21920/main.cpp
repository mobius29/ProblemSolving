#include <algorithm>
#include <stdio.h>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef vector<int> vi;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int N;
  scanf("%d", &N);

  vi A(N);
  for (auto &a : A) scanf("%d", &a);

  int X;
  scanf("%d", &X);

  vector<bool> visited(1000001, false);
  double sum = 0, cnt = 0;

  for_each(all(A), [&visited, &sum, &cnt, &X](const int &a) {
    if (visited[a] || gcd(a, X) == 1) {
      visited[a] = true;
      cnt++, sum += a;
    }
  });

  printf("%.6f\n", sum / cnt);

  return 0;
}
