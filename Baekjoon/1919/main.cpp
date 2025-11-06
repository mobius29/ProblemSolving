#include <iostream>
#include <string>

#define endl "\n"
using namespace std;

int answer;
int alphabets[2][26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < 2; i++) {
    string str;
    cin >> str;

    for (auto c : str)
      alphabets[i][c - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    answer += abs(alphabets[0][i] - alphabets[1][i]);
  }
  cout << answer << endl;

  return 0;
}
