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
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int N = 100;
  vector<vector<int> > v(N * 5, vector<int>(N * 5, 0));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < N; j++) {
      v[i][j] = s[j] - '0';
    }
  }
  for (int k = 0; k < 5; k++) {
    for (int l = 0; l < 5; l++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          v[k * N + i][l * N + j] = ((l + k) + v[i][j]) % 9; 
          if (v[k * N + i][l * N + j] == 0) v[k * N + i][l * N + j] = 9;
        }
      }
    }
  }
  priority_queue<array<int, 3> > pq;
  pq.push({0, 0, 0});
  set<pair<int, int> > vis;
  long long res = 1e18;
  while (!pq.empty()) {
    array<int, 3> a = pq.top();
    pq.pop();
    if (vis.find({a[1], a[2]}) != vis.end()) continue;
    vis.insert({a[1], a[2]});

    if (a[1] == 5 * N - 1 && a[2] == 5*N - 1) {
      res = -a[0];
      break;
    }
    for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
        if (i == 0 && j == 0) continue;
        if (i != 0 && j != 0) continue;
        if (i + a[1] < 0 || i + a[1] >= 5 * N) continue;
        if (j + a[2] < 0 || j + a[2] >= 5 * N) continue;
       // cout << 5 * N << " " << i + a[1] << endl;
        pq.push({-v[i + a[1]][j + a[2]] + a[0], i + a[1], j + a[2]});
      }
    }
  }
  cout << res << endl;

	return 0;
}
