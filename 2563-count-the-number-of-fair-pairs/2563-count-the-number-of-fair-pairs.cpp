#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ordered_set ms;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans+=ms.order_of_key(upper-nums[i]+1)-ms.order_of_key(lower-nums[i]);
            ms.insert(nums[i]);
        }
        return ans;
    }
};