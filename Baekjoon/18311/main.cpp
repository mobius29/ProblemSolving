#include <iostream>
#include <vector>

#define ends " "
#define endl "\n"
#define vi vector<int>
#define ll long long int
using namespace std;

int N{}, answer{};
ll K{};
vi len{};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  len.reserve(2 * N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> len[i];

    int rev_idx = 2 * N - (i - 1);
    len[rev_idx] = len[i];
  }

  for (int i = 1; i <= 2 * N; i++) {
    K -= len[i];
    if (K < 0) {
      answer = i;
      break;
    }
  }

  if (answer > N) {
    answer = 2 * N - answer + 1;
  }

  cout << answer << endl;

  return 0;
}
