#include <algorithm>
#include <iostream>
#include <vector>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

void swap(vi &arr, const int i, const int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int _find_max_idx(vi &arr, const int start, const int end) {
  int max_idx = -1;
  int max_value = -1;
  for (int i = start; i <= end; i++) {
    if (max_value < arr[i]) {
      max_value = arr[i];
      max_idx = i;
    }
  }

  return max_idx;
}

void solve(const int N, int S, vi &arr) {
  for (int i = 0; i < N; i++) {
    int max_idx = _find_max_idx(arr, i, min(i + S, N - 1));
    for (int j = max_idx; j > i; j--) { swap(arr, j, j - 1); }

    S -= (max_idx - i);
    if (S == 0) break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N; // 0 < N <= 50
  cin >> N;

  vi arr(N, 0); // 0 < arr[i] <= 1_000_000
  for (int i = 0; i < N; ++i) { cin >> arr[i]; }

  int S; // 0 <= S <= 1_000_000
  cin >> S;

  solve(N, S, arr);
  for (auto num : arr) { cout << num << ends; }

  return 0;
}
