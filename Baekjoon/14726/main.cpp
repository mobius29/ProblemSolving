#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int sum = 0;
    for (int i = 0; i < 16; i++) {
      int n;
      scanf("%1d", &n);
      if (i % 2 == 0) {
        n = n * 2;
        if (n >= 10) n = (n / 10 + n % 10);
      }
      sum += n;
    }

    printf("%c\n", sum % 10 == 0 ? 'T' : 'F');
  }

  return 0;
}
