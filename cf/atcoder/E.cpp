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
#include <queue>
#include <list>
#include <cstring>

using namespace std;

void dfs(int x, int y, vector<string> & g, bool & res, vector<vector<bool> > & vis, set<int> & path) {
    if (g[x][y] == 'S')  {
        if (path.size() >= 4) {
            res = true;
        }
    }
    if (vis[x][y]) return;
    if (path.find(x * g[0].size() + y) != path.end()) return;
    path.insert(x * g[0].size() + y);

    vis[x][y] = 1;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 && j != 0) continue;
            if (i == 0 && j == 0) continue;
            if (x + i <0 || x + i >= g.size()) continue;
            if (y + j < 0 || y + j >= g[0].size()) continue;
            if (g[i + x][y + j] == '#') continue;
            dfs(i + x, y + j, g, res, vis, path);
        }
    }
    path.erase(path.find(x * g[0].size() + y));
}

int main() {
    int h, w;
    cin >> h >> w;
    //cout << h << " " << w << endl;
    vector<string> g(h);
    vector<vector<bool> > vis(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        cin >> g[i];
    }
    bool res = false;
    //cout << "OK" << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'S') {
                set<int> cyc;
                dfs(i, j, g, res, vis, cyc);
            }
        }
    }
    //cout << cnt << endl;
    if (res) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}