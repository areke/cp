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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > res(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        res[a].push_back(b);
        res[b].push_back(a);
    }
    for (int i  = 1; i <= n; i++) {
        sort(res[i].begin(), res[i].end());
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i].size() << " ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " " ;
        }
        cout << endl;
    }
}