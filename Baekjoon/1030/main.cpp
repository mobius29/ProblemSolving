#include <cmath>
#include <iostream>
#include <vector>
#define sync()                                                                                                         \
  ios_base::sync_with_stdio(0);                                                                                        \
  cin.tie(0)
#define endl "\n"
using namespace std;

vector<vector<bool>> target_area;

bool is_black_cell(const int size, const int r, const int c, const int N, const int K) {
  if (size == 1) return false;
  int n = size / N;

  int pad_before = n * ((N - K) / 2), pad_after = n * ((N + K) / 2);
  if (pad_before <= r && r < pad_after && pad_before <= c && c < pad_after) { return true; }

  return is_black_cell(size / N, r % n, c % n, N, K);
}

int main() {
  sync();
  int s, N, K, R1, R2, C1, C2;
  cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

  int size = pow(N, s);
  for (int r = R1; r <= R2; r++) {
    for (int c = C1; c <= C2; c++) { cout << (is_black_cell(size, r, c, N, K) ? 1 : 0); }
    cout << endl;
  }

  return 0;
}
