#include <algorithm>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int solve(vector<pii> &meetings) {
  int result = 0;

  int last_finish = 0;
  for (auto [start, finish] : meetings) {
    if (start >= last_finish) {
      last_finish = finish;
      result++;
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<pii> meetings(N);
  for (int i = 0; i < N; ++i) { cin >> meetings[i].first >> meetings[i].second; }

  sort(meetings.begin(), meetings.end(), [](pii &a, pii &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  });

  cout << solve(meetings) << '\n';
}
