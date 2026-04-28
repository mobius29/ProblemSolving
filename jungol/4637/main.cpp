#include <array>
#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#define ends ' '
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <typename T> using Vec = vector<T>;
template <typename T> using Vec2 = Vec<Vec<T>>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

constexpr array<int, 4> dx = { { -1, 0, 1, 0 } };
constexpr array<int, 4> dy = { { 0, -1, 0, 1 } };

template <typename T> T read();
template <typename T, typename... Sizes> T read(int size, Sizes... rest);
template <typename T1, typename T2, typename... Ts> tuple<T1, T2, Ts...> read();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Q = read<int>();

  set<int> s;
  while (Q--) {
    auto [c, n] = read<char, int>();

    if (c == 'i') s.insert(n);
    if (c == 'r') s.erase(n);
  }

  for (const auto &el : s) { cout << el << ends; }
  cout << endl;

  return 0;
}

// Helper functions
template <typename> struct is_std_vector : false_type {};
template <typename T, typename A> struct is_std_vector<vector<T, A>> : true_type {};
template <typename T> inline constexpr bool is_std_vector_v = is_std_vector<T>::value;

template <typename> struct is_std_pair : false_type {};
template <typename A, typename B> struct is_std_pair<pair<A, B>> : true_type {};
template <typename T> inline constexpr bool is_std_pair_v = is_std_pair<T>::value;

template <typename> struct is_std_tuple : false_type {};
template <typename... Ts> struct is_std_tuple<tuple<Ts...>> : true_type {};
template <typename T> inline constexpr bool is_std_tuple_v = is_std_tuple<T>::value;

template <typename Tuple, size_t... I> Tuple read_tuple_impl(index_sequence<I...>) {
  Tuple t;
  (..., (get<I>(t) = read<tuple_element_t<I, Tuple>>()));
  return t;
}

template <typename T> T read() {
  T val;
  if constexpr (is_std_pair_v<T>) val = { read<typename T::first_type>(), read<typename T::second_type>() };
  else if constexpr (is_std_tuple_v<T>) val = read_tuple_impl<T>(make_index_sequence<tuple_size_v<T>>{});
  else cin >> val;

  return val;
}

template <typename T, typename... Sizes> T read(int size, Sizes... rest) {
  T result(size);
  for (auto &x : result) x = read<typename T::value_type>(rest...);
  return result;
}

template <typename T1, typename T2, typename... Ts> tuple<T1, T2, Ts...> read() {
  return read_tuple_impl<tuple<T1, T2, Ts...>>(make_index_sequence<2 + sizeof...(Ts)>{});
}
