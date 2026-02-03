#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 1; i <= 2 * N - 1; i++) {
    for (int j = 1; j <= N; j++) {
      if ((i <= N && i + j > N) || (i > N && i - j < N)) cout << '*';
      else cout << ends;
    }
    cout << endl;
  }

  return 0;
}
