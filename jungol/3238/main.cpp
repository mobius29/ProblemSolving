#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
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

struct Max {
  template <typename T> T operator()(T a, T b) const {
    return a > b ? a : b;
  }
};

template <typename T, typename Op = Max> struct Segment_Tree {
private:
  int N;
  Vec<T> tree;
  T identity;
  Op op;

public:
  Segment_Tree(const int N, T identity, Op op = Op{}) : N(N), tree(N * 2, identity), identity(identity), op(op) {
  }

  explicit Segment_Tree(const Vec<int> &arr, T identity, Op op = Op{})
      : N(arr.size()), tree(arr.size() * 2, identity), op(op), identity(identity) {
    ranges::copy(arr, tree.begin() + N);
    for (int i = N - 1; i >= 1; i--) { tree[i] = op(tree[2 * i], tree[2 * i + 1]); }
  }

  void update(int i, T val) {
    tree[i += N - 1] = val;
    for (i >>= 1; i >= 1; i >>= 1) { tree[i] = op(tree[2 * i], tree[2 * i + 1]); }
  }

  T query(int l, int r) const {
    T result_l = identity, result_r = identity;
    for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) result_l = op(result_l, tree[l++]);
      if (r & 1) result_r = op(tree[--r], result_r);
    }

    return op(result_l, result_r);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  constexpr auto MIN = numeric_limits<int>::min();

  auto [N, M] = read<int, int>();
  auto seg_tree = Segment_Tree(N, MIN);

  for (int q = 0; q < M; q++) {
    const auto inst = read<int>();

    if (inst == 1) {
      auto [k, val] = read<int, int>();
      seg_tree.update(k - 1, val);
    }
    if (inst == 2) {
      auto [s, e] = read<int, int>();
      auto result = seg_tree.query(s - 1, e - 1);
      if (result > MIN) { cout << result << endl; }
    }
    if (inst == 3) {
      auto k = read<int>();
      seg_tree.update(k - 1, MIN);
    }
  }

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
