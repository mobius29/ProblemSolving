#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define ends " "
#define endl "\n"
#define vi vector<int>
using namespace std;

const vector<string> DAYS = {"Mon", "Tue", "Wed", "Thu", "Fri"};
int T, N;

int input() {
  string day;
  int hour;
  cin >> day >> hour;

  auto it = find(DAYS.begin(), DAYS.end(), day);
  int index = it - DAYS.begin();

  return 24 * index + hour;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T >> N;

  int sleep_time = 0;
  for (int i = 0; i < N; i++) {
    int sleep = input();
    int wakeup = input();

    sleep_time += (wakeup - sleep);
  }

  int sleep_left = max(T - sleep_time, 0);
  cout << (sleep_left > 48 ? -1 : sleep_left) << endl;

  return 0;
}
