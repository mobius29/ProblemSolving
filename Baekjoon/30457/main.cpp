#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

template <typename T> using Vec = vector<T>;

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto N = read<int>(), answer = 0;
  Vec<int> x(1001, 0);
  while (N--) {
    const auto a = read<int>();
    if (++x[a] <= 2) answer++;
  }

  cout << answer << endl;

  return 0;
}
