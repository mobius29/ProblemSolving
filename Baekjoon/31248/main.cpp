#include <iostream>
#include <vector>

#define ends ' '
#define endl '\n'
using namespace std;

using pcc = pair<char, char>;
template <typename T> using Vec = vector<T>;

template <typename T> T read();

void hanoi3(int N, char src, char dest, char sub, Vec<pcc> &moves) {
  if (N <= 0) return;

  hanoi3(N - 1, src, sub, dest, moves);
  moves.emplace_back(src, dest);
  hanoi3(N - 1, sub, dest, src, moves);
}

void hanoi4(int N, int src, int dest, int sub, Vec<pcc> &moves) {
  if (N <= 0) return;

  if (N == 1) {
    moves.emplace_back(src, 'D');
    return;
  }

  hanoi3(N - 2, src, dest, sub, moves);

  moves.emplace_back(src, sub);
  moves.emplace_back(src, 'D');
  moves.emplace_back(sub, 'D');

  hanoi4(N - 2, dest, sub, src, moves);
}

Vec<pcc> solve(const int &N) {
  Vec<pcc> ret;
  hanoi4(N, 'A', 'C', 'B', ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const auto N = read<int>();
  const auto moves = solve(N);

  cout << moves.size() << endl;
  for (auto &[from, to] : moves) { cout << from << ends << to << endl; }

  return 0;
}

// --------------------- Helper Functions ---------------------

template <typename T> T read() {
  T tmp;
  cin >> tmp;
  return tmp;
}
