#include <string>
#include <vector>
using namespace std;

#include <cstdio>

class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ret;
    for (int i = 0; i < 12; i++) {
      int h = __builtin_popcount(i);
      for (int j = 0; j < 60; j++) {
        int m = __builtin_popcount(j);
        if (h + m == turnedOn) {
          char buf[10];
          snprintf(buf, sizeof(buf), "%d:%02d", i, j);
          ret.push_back(buf);
        }
      }
    }
    return ret;
  }
};
