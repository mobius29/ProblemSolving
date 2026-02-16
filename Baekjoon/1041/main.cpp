#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
template <typename T> using Vec = vector<T>;

template <typename T> T read();
template <typename T> Vec<T> read(int size);

enum { A, B, C, D, E, F };

ll solve(const ll N, const Vec<ll> &dice) {
  if (N == 1) { return accumulate(all(dice), 0ll) - ranges::max(dice); }

  ll x = min(dice[A], dice[F]);
  ll y = min(dice[B], dice[E]);
  ll z = min(dice[C], dice[D]);

  ll min_1 = min({ x, y, z }), min_2 = min({ x + y, y + z, z + x }), min_3 = x + y + z;
  return min_1 * (5 * (N - 2) * (N - 2) + 4 * (N - 2)) + min_2 * (8 * N - 12) + min_3 * 4;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const auto N = read<ll>();     // 1 <= N <= 1,000,000
  const auto dice = read<ll>(6); // 1 <= dice_i <= 50

  cout << solve(N, dice) << endl;

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
  if constexpr (is_tuple_like_v<T>) return _read_tuple_like<T>(make_index_sequence<tuple_size<T>::value>{});
  else if constexpr (is_container_v<T> && has_size_v<T>) return _read_container<T>();
  else { return _read_primitive<T>(); }
}

template <typename T> Vec<T> read(int size) {
  Vec<T> v(size);
  for (auto &el : v) el = read<T>();
  return v;
}
