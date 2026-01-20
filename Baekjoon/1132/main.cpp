#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define ends " "
#define endl "\n"
#define ll long long int
#define vs vector<string>
using namespace std;

ll solve(const int n, const vs &nums) {
  ll counts[10] = { 0 };
  bool is_beginning[10] = { 0 };

  for (auto &str : nums) {
    int last_idx = str.length() - 1;
    for (int i = last_idx; i >= 0; i--) {
      int idx = str[i] - 'A';

      counts[idx] += pow(10, last_idx - i);
      if (i == 0) is_beginning[idx] = true;
    }
  }

  int zero_idx = -1;
  for (int i = 0; i < 10; i++) {
    if (is_beginning[i]) continue;
    if (zero_idx == -1 || counts[i] < counts[zero_idx]) { zero_idx = i; }
  }
  counts[zero_idx] = 0;

  sort(begin(counts), end(counts));

  ll ret = 0;
  for (ll i = 0; i < 10; i++) { ret += i * counts[i]; }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vs nums(N);
  for (int i = 0; i < N; i++) { cin >> nums[i]; }

  cout << solve(N, nums) << endl;

  return 0;
}
