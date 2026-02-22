#include <cstdlib>
#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

template <typename T> T read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str = "";
  while (true) {
    auto substr = read<string>();
    if (cin.eof()) break;

    str += substr;
  }

  int answer = 0;
  while (str.length() > 0) {
    auto it = str.find(",");
    answer += atoi(str.substr(0, it).c_str());
    if (it == string::npos) break;
    str = str.substr(it + 1);
  }

  cout << answer << endl;

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T _read_primitive() {
  T ret;
  cin >> ret;
  return ret;
}

template <typename T> T read() {
  return _read_primitive<T>();
}
