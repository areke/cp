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
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<vector<int> > res(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = (i * j) % n;
		}
	}
	for (int i = 0; i < n; i++) {
		b[i] = (n + res[i][i] - b[i]) % n;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = (n + res[i][j] - b[j]) % n;
			cout << res[i][j];
			if (j ==  n - 1) cout << endl;
			else cout << " ";
		}
	}

	return 0;
}
