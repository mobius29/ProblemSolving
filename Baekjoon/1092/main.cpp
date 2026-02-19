#include <algorithm>
#include <array>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;

template <typename T> using Vec = vector<T>;

template <typename T> T read();
template <typename T> Vec<T> read(int size);

int solve(const int N, const int M, Vec<int> limits, Vec<int> boxes) {
  sort(all(limits), greater<int>());
  sort(all(boxes), greater<int>());

  if (limits[0] < boxes[0]) return -1;

  Vec<int> pos(N, 0);
  Vec<bool> moved(M, false);
  int moved_cnt = 0;

  int minutes = 0;
  while (moved_cnt < M) {
    minutes++;

    for (int i = 0; i < N; i++) {
      for (int &cur = pos[i]; cur < M; cur++) {
        if (!moved[cur] && limits[i] >= boxes[cur]) {
          moved[cur++] = true;
          moved_cnt++;
          break;
        }
      }
    }
  }

  return minutes;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto N = read<int>();       // 1 <= N <= 50
  auto limits = read<int>(N); // weight_limits[i] <= 1,000,000

  auto M = read<int>();      // 1 <= M <= 10,000
  auto boxes = read<int>(M); // 1 <= weights_boxes[i] <= 1,000,000

  cout << solve(N, M, limits, boxes) << endl;

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
