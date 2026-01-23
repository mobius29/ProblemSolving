#include <iostream>
#include <vector>

#define endl "\n"
#define vi vector<int>
#define vc vector<char>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int R, C;
  cin >> R >> C;

  vector<vc> spaces(R, vc(C, 0));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) { cin >> spaces[i][j]; }
  }

  vi answers(5, 0);
  for (int i = 0; i <= R - 2; i++) {
    for (int j = 0; j <= C - 2; j++) {
      bool has_building = false;
      int cnt_car = 0;
      for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
          if (spaces[i + r][j + c] == '#') has_building = true;
          else if (spaces[i + r][j + c] == 'X') cnt_car++;
        }
      }
      if (has_building) continue;
      answers[cnt_car]++;
    }
  }

  for (auto count : answers) { cout << count << endl; }

  return 0;
}
