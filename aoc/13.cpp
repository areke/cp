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

vector<vector<bool> > fold(vector<vector<bool> > v, pair<char, int> f) {
  if (f.first == 'x') {
    vector<vector<bool> > res(v.size());
    for (int i = 0; i < v.size(); i++) {
      for (int j = f.second + 1; j < v[i].size(); j++) {
        int ind = f.second - (j - f.second);
        if (ind >= 0) {
          v[i][j] = v[i][ind] || v[i][j];
          res[i].push_back(v[i][j]);
        }
      }
    }
    return res;
  } else {
    vector<vector<bool> > res(f.second, vector<bool>(v[0].size()));
    for (int i = 0; i < v[0].size(); i++) {
      for (int j = f.second - 1; j >= 0; j--) {
        if (f.second + (f.second - j) < v.size()) {
          v[j][i] = v[j][i] || v[f.second + (f.second - j)][i];
          res[j][i] = v[j][i];
        }
      }
    }
    return res;
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  vector<pair<int, int> > vv;
  int n = 0, m = 0;
  for (int i = 0; i< 750; i++) {
    int xx, yy;
    cin >> xx >> yy;
    vv.push_back({xx, yy});
    n = max(xx, n);
    m = max(yy, m);
  }
  
  vector<vector<bool> > v(m + 1, vector<bool>(n + 1, false));
  for (int i = 0; i < vv.size(); i++) {
    v[vv[i].second][vv[i].first] = true;
  }

  vector<pair<char, int> > f;
  for (int i = 0; i < 12; i++) {
    char x;
    int y;
    cin >> x >> y;
    f.push_back({x, y});
  }
  for (int i = 0; i < f.size(); i++) {
    v = fold(v, f[i]);
    
  }
  for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k < v[j].size(); k++) {
        if (v[j][k]) cout << '#';
        else cout <<'.';
      }
      cout << endl;
    }
  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j]) res++;
    }
  }
  cout << res << endl;
	return 0;
}
