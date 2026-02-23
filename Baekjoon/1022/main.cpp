#include <array>
#include <cstdlib>
#include <iostream>
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
  const int row_cnt = r2 - r1 + 1, col_cnt = c2 - c1 + 1;

  Vec2<int> ret(row_cnt, Vec<int>(col_cnt, 0));

  auto _check = [&](const int r, const int c) { return r1 <= r && r <= r2 && c1 <= c && c <= c2; };

  enum Dir { Up, Left, Down, Right };
  auto _move = [](int &r, int &c, Dir &dir) {
    r += dx[dir], c += dy[dir];
    if (r >= 0 && c >= 0) {
      if (r + 1 == c) dir = Up;
    } else if (abs(r) == abs(c)) {
      if (dir == Up) dir = Left;
      else if (dir == Left) dir = Down;
      else if (dir == Down) dir = Right;
      else if (dir == Right) dir = Up;
    }
  };

  int cur_r = 0, cur_c = 0, cur_v = 0, cur_filled = 0;
  Dir cur_dir = Right;

  while (cur_filled < row_cnt * col_cnt) {
    cur_v++;
    if (_check(cur_r, cur_c)) {
      ret[cur_r - r1][cur_c - c1] = cur_v;
      cur_filled++;
    }
    _move(cur_r, cur_c, cur_dir);
  }

  auto _get_digit = [](int n) {
    int ret = 0;
    while (n) { n /= 10, ret++; }
    return ret;
  };
  auto max_digit = _get_digit(cur_v);

  for (const auto &r : ret) {
    for (const auto &cell : r) {
      auto cur_digit = _get_digit(cell);
      for (int i = 0; i < max_digit - cur_digit; i++) cout << ends;
      cout << cell << ends;
    }
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
