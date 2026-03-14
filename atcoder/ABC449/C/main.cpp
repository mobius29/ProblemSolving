#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

using ll = long long;
template <typename T> using Vec = vector<T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, L, R;
  cin >> N >> L >> R;

  string S;
  cin >> S;

  Vec<int> alphabet_counts(26, 0);
  for (int i = L; i <= R; i++) { alphabet_counts[S[i] - 'a']++; }

  ll answer = 0;
  for (int i = 0; i < N - L; i++) {
    if (i != 0) {
      alphabet_counts[S[i + L - 1] - 'a']--;
      if (i < N - R) { alphabet_counts[S[i + R] - 'a']++; }
    }
    answer += alphabet_counts[S[i] - 'a'];
  }

  cout << answer << endl;

  return 0;
}
