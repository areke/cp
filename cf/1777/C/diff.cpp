32a33,34
>  
> 	vector<long long> ma(MAXI + 1, 0);
41,42c43,44
< 		long long high = MAXI;
< 		long long bad = 2 * MAXI;
---
> 		long long high = m;
> 		long long bad = 2 * m;
43a46
>  
47d49
< 			map<long long, int> ma;
50a53,55
> 			for (int i = 0; i <= m; i++) {
> 				ma[i] = 0;
> 			}
