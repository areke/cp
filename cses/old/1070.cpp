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
#include <assert.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n <= 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        for (int i = 2; i <= n; i+=2) {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i+=2) {
            cout << i << " ";
        }
       
        cout << endl;
    }
}