#include <algorithm>
#include <iostream>
#include <string>
#define sync()                                                                                                         \
  ios_base::sync_with_stdio(0);                                                                                        \
  cin.tie(0)
#define endl "\n"
#define ends " "
#define all(x) (x).begin(), (x).end()
using namespace std;

int dp[101][101];

string solve(const string a, const string b) {
  // Fill LCS Table
  for (int i = 1; i <= a.length(); i++) {
    for (int j = 1; j <= b.length(); j++) {
      if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  string answer = "";

  // Reverse Tracking LCS Table for get string
  int n = a.length(), m = b.length();
  while (n > 0 && m > 0) {
    if (a[n - 1] == b[m - 1]) {
      answer.push_back(a[n - 1]);
      n--, m--;
      continue;
    }

    if (dp[n - 1][m] > dp[n][m - 1]) answer.push_back(a[n - 1]), n--;
    else answer.push_back(b[m - 1]), m--;
  }

  while (n > 0 || m > 0) {
    if (n > 0) answer.push_back(a[n - 1]), n--;
    else answer.push_back(b[m - 1]), m--;
  }

  reverse(all(answer));
  return answer;
}

int main() {
  sync();

  string a, b;
  while (!cin.eof()) {
    cin >> a >> b;
    cout << solve(a, b) << endl;
  }
}
