#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

template <typename T> using Option = std::optional<T>;
template <typename T> T read();

auto is_vowel = [](char c) { return string_view("aeiou").find(c) != string_view::npos; };

Option<string> get_first_syllable(const string &str) {
  auto first_vowel = find_if(all(str), is_vowel);
  if (first_vowel == str.end()) return nullopt;

  auto next_cons = find_if(first_vowel, str.end(), [](char c) { return !is_vowel(c); });
  if (next_cons == str.end()) return nullopt;

  return str.substr(0, distance(str.begin(), next_cons));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const string a = read<string>(), b = read<string>();

  auto res_a = get_first_syllable(a);
  auto res_b = get_first_syllable(b);

  if (res_a.has_value() && res_b.has_value()) {
    cout << (res_a.value() + res_b.value()) << endl;
  } else {
    cout << "no such exercise" << endl;
  }

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}
