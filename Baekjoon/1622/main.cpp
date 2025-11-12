#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

string a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (!cin.eof()) {
    getline(cin, a);
    getline(cin, b);

    vector<int> x_a(26, 0), x_b(26, 0);

    for (auto c : a)
      x_a[c - 'a']++;

    for (auto c : b)
      x_b[c - 'a']++;

    vector<char> answer;
    for (int i = 0; i < 26; i++) {
      int cnt = min(x_a[i], x_b[i]);
      for (int j = 0; j < cnt; j++) {
        answer.push_back(static_cast<char>(i + 'a'));
      }
    }

    string str{answer.begin(), answer.end()};
    cout << str << endl;
  }

  return 0;
}
