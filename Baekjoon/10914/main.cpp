#include <iostream>
#include <string>

#define ends ' '
using namespace std;

template <typename T> T read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto n = read<int>();
  while (!cin.eof()) {
    auto word = read<string>();
    if (word.length() % 2 == 1) word.pop_back();

    for (int i = 0; i < word.length(); i += 2) {
      int y = word[i] - 'a', z = word[i + 1] - 'a';
      int x = (y + z - n + 26) % 26;
      cout << (char)(x + 'a');
    }
    cout << ends;
  }

  cout << endl;

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
