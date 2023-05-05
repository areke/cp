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

void flash(int x, int y, vector<vector<int> > & v, set<pair<int, int> > & vis) {
  if (vis.find({x, y}) != vis.end()) return;
  if (v[x][y] != 0) {
    v[x][y]++;
    v[x][y] %= 10;
  }
  if (v[x][y] == 0) {
    vis.insert({x, y});
    for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
        if (i == 0 && j == 0) continue;
        if (i + x < 0 || i + x >= 10) continue;
        if (j + y < 0 || j + y >= 10) continue;
        flash(x + i, y + j, v, vis);
      }
    }
  } 
  
  
  return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  string line;
  long long res = 0;
  vector<vector<int> > v(10, vector<int>(10));
  for (int i = 0; i < 10; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 10; j++) {
      v[i][j] = s[j] - '0';
    }
  }
  for (int step = 0; step < 1000000; step++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        v[i][j]++;
        v[i][j] %= 10;
      }
    }
    set<pair<int, int> > vis;
    for (int i = 0; i < 10 ;i++) {
      for (int j = 0; j < 10; j++) {
        if (v[i][j] == 0) {
          flash(i, j, v, vis);
        }
      }
    }
    if (vis.size() == 100) {
      res = step + 1;
      break;
    }
  }
  cout << res << endl;
	return 0;
}
