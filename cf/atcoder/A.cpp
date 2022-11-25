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
    string s;
    cin >> s;
    int ind = -2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') ind = i;
    }
    cout << ind + 1 << endl;
}