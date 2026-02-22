#include <array>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <utility>

#define endl '\n'
using namespace std;

using pii = pair<int, int>;

template <typename T> T read();

int solve(const int &a, const int &b) {
  auto last_computer = 1;
  for (int i = 0; i < b; i++) { last_computer = (last_computer * a) % 10; }
  return last_computer == 0 ? 10 : last_computer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto T = read<int>();
  while (T--) {
    auto [a, b] = read<pii>();
    cout << solve(a, b) << endl;
  }

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T, class = void> struct is_tuple_like : false_type {};
template <typename T> struct is_tuple_like<T, void_t<decltype(tuple_size<T>::value)>> : true_type {};
template <typename T> inline constexpr bool is_tuple_like_v = is_tuple_like<T>::value;

template <typename T> T _read_primitive() {
  T ret;
  cin >> ret;
  return ret;
}

template <typename T, size_t... Is> T _read_tuple_like(index_sequence<Is...>) {
  T ret{};
  ((get<Is>(ret) = read<decay_t<decltype(get<Is>(declval<T &>()))>>()), ...);
  return ret;
}

template <typename T> T read() {
  if constexpr (is_tuple_like_v<T>) {
    return _read_tuple_like<T>(make_index_sequence<tuple_size<T>::value>{});
  } else {
    return _read_primitive<T>();
  }
}
