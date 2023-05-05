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
	
	long long n;
	cin >> n;
	bool can = true;

	vector<vector<long long> > res(2);
	int cnt = 0;
	for (int i = 1; i <= n / 2; i++) {
		res[cnt % 2].push_back(i);
		res[cnt % 2].push_back(n + (n % 2 == 0) - i);
		cnt++;
	}
	if (n % 4 == 0) {
		
		
		
		
		
	} else if ((n + 1) % 4 == 0) {
		res[cnt % 2].push_back(n);
	} else {
		can = false;
		cout << "NO" << endl;
	}
	if (can) {
		cout << "YES" << endl;
		for (int i = 0; i < 2; i++) {
			cout << res[i].size() << endl;
			for (int j = 0; j < res[i].size(); j++) {
				cout << res[i][j] << " \n"[j == res[i].size() - 1];
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
