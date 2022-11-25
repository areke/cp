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

// [1, 2, 4, 5, 3, 6, 7]

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    prev_permutation(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

}