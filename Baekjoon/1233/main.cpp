#include <iostream>

#define endl "\n"

using namespace std;

int S1, S2, S3;
int cnt[81];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> S1 >> S2 >> S3;

  for (int s1 = 1; s1 <= S1; s1++)
    for (int s2 = 1; s2 <= S2; s2++)
      for (int s3 = 1; s3 <= S3; s3++)
        cnt[s1 + s2 + s3]++;

  int maxCnt = -1;
  int answer = -1;
  for (int i = 3; i <= 80; i++) {
    if (maxCnt < cnt[i]) {
      maxCnt = cnt[i];
      answer = i;
    }
  }

  cout << answer << endl;

  return 0;
}
