#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>

using ll = long long;

int query(int r, int c) {
  int ret;
  std::cout << "? " <<  r << " " << c << std::endl;
  std::cout.flush();
  std::cin >> ret;
  return ret + 1;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  int a = query(1, 1), b = query(n, m);

  if (m > n && a == m - b) {
    int c = query(1, a);
    std::cout << "! " << c << " " << a << std::endl;
  } else if (n > m && a == n - b) {
    int c = query(a, 1);
    std::cout << "! " << a << " " << c << std::endl;
  } else {
    int x = a, y = m - b;
    if (query(x, y) == 1)
      std::cout << "! " << x << " " << y << std::endl;
    else
      std::cout << "! " << n - b << " " << a << std::endl;
  }
}

int main() {
  int t;
  std::cin >> t;
  while (t--) solve();
}
