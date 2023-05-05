#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;



// erase with upper bound. see https://codeforces.com/blog/entry/88193
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> multi_ordered_set;
