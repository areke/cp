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
	int tests;
	cin >> tests;
	while (tests--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int alpha[26] = {0};
		for (int i = 0; i < s.length(); i++) {
			alpha[s[i] - 'a']++;
		}
		string res = "";
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 26; j++) {
				if ((alpha[j] / k < 1 && alpha[j] <= i) || j >= s.length() / k) {
					res += (j + 'a');
					break;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
