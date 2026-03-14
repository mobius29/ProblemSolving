#include <cstdio>
#include <numbers>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
  double D;
  scanf("%lf", &D);

  double answer = (D / 2) * (D / 2) * numbers::pi;
  printf("%.6lf\n", answer);

  return 0;
}
