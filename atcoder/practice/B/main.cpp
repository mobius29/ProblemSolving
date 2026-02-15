#include <cstdio>
#include <string>

#define all(x) (x).begin(), (x).end()
using namespace std;

int N, Q;

bool compare(const char a, const char b) {
  printf("? %c %c\n", a, b);
  fflush(stdout);

  char answer;
  scanf(" %c", &answer);

  return answer == '<';
}

string merge_sort(const string &str) {
  size_t len = str.length();
  if (len == 1) return str;

  size_t mid = len / 2;

  string fs = merge_sort(str.substr(0, mid));
  string se = merge_sort(str.substr(mid));

  string ret = "";
  size_t fs_idx = 0, se_idx = 0;
  while (fs_idx < fs.length() && se_idx < se.length()) {
    if (compare(fs[fs_idx], se[se_idx])) ret += fs[fs_idx++];
    else ret += se[se_idx++];
  }

  while (fs_idx < fs.length()) ret += fs[fs_idx++];
  while (se_idx < se.length()) ret += se[se_idx++];

  return ret;
}

string sort5(string &str) {
  auto swap = [&str](int i, char j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  };

  if (!compare(str[0], str[1])) swap(0, 1);
  if (!compare(str[2], str[3])) swap(2, 3);
  if (!compare(str[0], str[2])) swap(0, 2), swap(1, 3);

  string ret = { str[0], str[2], str[3] };

  auto _insert = [](string s, char c) {
    if (compare(s[1], c)) {
      if (compare(s[2], c)) s += c;
      else s.insert(2, string{ c });
    } else {
      if (compare(s[0], c)) s.insert(1, string{ c });
      else s.insert(0, string{ c });
    }
    return s;
  };

  ret = _insert(ret, str[4]);
  ret = ret[0] + _insert(ret.substr(1), str[1]);

  return ret;
}

int main() {
  scanf("%d %d", &N, &Q);

  string s;
  for (int i = 0; i < N; i++) s += (char)('A' + i);

  string answer = N == 5 ? sort5(s) : merge_sort(s);
  printf("! %s\n", answer.c_str());

  fflush(stdout);
  return 0;
}
