#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

using ll = long long;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

template <typename T> T read();
template <typename T> Vec<T> read(int size);
template <typename T> Vec2<T> read(int r_size, int c_size);

constexpr array<int, 4> dx = { { -1, 0, 1, 0 } };
constexpr array<int, 4> dy = { { 0, -1, 0, 1 } };

using Input = tuple<int, int, int, int>;

void solve(const Input &inputs) {
  const auto [r1, c1, r2, c2] = inputs;
  const int R = r2 - r1 + 1, C = c2 - c1 + 1;

  Vec2<ll> A(R, Vec<ll>(C, 0ll));

  auto _value_at = [](ll r, ll c) {
    auto n = max(abs(r), abs(c));
    auto M = (2 * n + 1) * (2 * n + 1);

    if (r == n) return M - (n - c);
    if (r == -n) return M - (4 * n + c + n);
    if (c == n) return M - (6 * n + r + n);
    if (c == -n) return M - (2 * n + (n - r));

    return -1ll;
  };

  auto max_v = -1ll;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      A[i][j] = _value_at(i + r1, j + c1);
      max_v = max(max_v, A[i][j]);
    }
  }

  auto max_len = to_string(max_v).size();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) { cout << setw(max_len) << A[i][j] << ends; }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve(read<Input>());

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T, class = void> struct is_tuple_like : false_type {};
template <typename T> struct is_tuple_like<T, void_t<decltype(tuple_size<T>::value)>> : true_type {};
template <typename T> inline constexpr bool is_tuple_like_v = is_tuple_like<T>::value;

template <typename T, class = void> struct is_container : false_type {};
template <typename T>
struct is_container<T, void_t<decltype(begin(declval<T &>())), decltype(end(declval<T &>()))>> : true_type {};
template <> struct is_container<string> : false_type {};
template <typename T> inline constexpr bool is_container_v = is_container<T>::value;

template <typename T, class = void> struct has_size : false_type {};
template <typename T> struct has_size<T, void_t<decltype(declval<T &>().size())>> : true_type {};
template <typename T> inline constexpr bool has_size_v = has_size<T>::value;

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

template <typename T> T _read_container() {
  T ret{};
  for (auto &x : ret) x = read<decay_t<decltype(x)>>();
  return ret;
}

template <typename T> T read() {
  if constexpr (is_tuple_like_v<T>) {
    return _read_tuple_like<T>(make_index_sequence<tuple_size<T>::value>{});
  } else if constexpr (is_container_v<T> && has_size_v<T>) {
    return _read_container<T>();
  } else {
    return _read_primitive<T>();
  }
}

template <typename T> Vec<T> read(int size) {
  Vec<T> v(size);
  for (auto &el : v) el = read<T>();
  return v;
}

template <typename T> Vec2<T> read(int r_size, int c_size) {
  Vec2<T> v(r_size, Vec<T>(c_size));
  for (auto &r : v) r = read<T>(c_size);
  return v;
}
