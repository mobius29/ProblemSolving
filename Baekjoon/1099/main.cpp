#include <algorithm>
#include <array>
#include <iostream>
#include <tuple>
#include <type_traits>
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

template <typename T> T read();
template <typename T> Vec<T> read(int size);
template <typename T> Vec2<T> read(int r_size, int c_size);

constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

int solve(const string &str, const int &N, const Vec<string> &words) {
  Vec<int> dp(str.length() + 1, INF);

  auto _check = [&](const int &start, const string &word) {
    Vec<int> str_count(26, 0), word_count(26, 0);
    for (int i = 0; i < word.size(); i++) {
      auto str_idx = str[start + i] - 'a', word_idx = word[i] - 'a';
      str_count[str_idx]++;
      word_count[word_idx]++;
    }

    for (int i = 0; i < 26; i++) {
      if (str_count[i] != word_count[i]) return false;
    }

    return true;
  };

  auto _get_cost = [&](const int &start, const string &word) {
    int ret = 0;
    for (int i = 0; i < word.size(); i++) {
      if (str[start + i] != word[i]) ret++;
    }
    return ret;
  };

  for (int i = 0; i < str.length(); i++) {
    for (auto &word : words) {
      if (i > 0 && dp[i] == INF) continue;

      auto last_idx = i + word.size();
      if (last_idx > str.length() || !_check(i, word)) continue;

      auto cost = _get_cost(i, word);
      if (i == 0) dp[last_idx] = min(dp[last_idx], cost);
      else { dp[last_idx] = min(dp[last_idx], dp[i] + cost); }
    }
  }

  int answer = dp.back() == INF ? -1 : dp.back();
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto [str, N] = read<pair<string, int>>();
  auto words = read<string>(N);

  cout << solve(str, N, words) << endl;

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
