#include <iostream>

#define ends ' '
#define endl '\n'
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    string str;
    cin >> str;

    if (str == "animal") {
      cout << "Panthera tigris" << endl;
    } else if (str == "tree") {
      cout << "Pinus densiflora" << endl;
    } else if (str == "flower") {
      cout << "Forsythia koreana" << endl;
    } else {
      break;
    }
  }

  return 0;
}
