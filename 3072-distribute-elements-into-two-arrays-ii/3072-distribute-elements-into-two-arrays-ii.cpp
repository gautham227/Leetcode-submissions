#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// to find i th element find_by_order(i)
// to find no of elements smaller than k order_of_key(k)
// upper_bound s.upperbound(val)
// to remove ele s.erase(ele)
// in case of less_equal s.erase(s.find) wont work
// in this case upperbound acts as lowerbound and lowerbound acts as upperbound
// so to remove an element use s.erase(s.upperbound(ele))

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a,b;
        ordered_set x,y;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        x.insert(nums[0]);
        y.insert(nums[1]);
        for(int i=2;i<nums.size();i++){
            int cnt1=a.size()-x.order_of_key(nums[i]+1);
            int cnt2=b.size()-y.order_of_key(nums[i]+1);
            if(cnt1==cnt2){
                if(b.size()<a.size()){
                    b.push_back(nums[i]);
                    y.insert(nums[i]);
                }
                else{
                    a.push_back(nums[i]);
                    x.insert(nums[i]);
                }
            }
            else if(cnt1>cnt2){
                a.push_back(nums[i]);
                x.insert(nums[i]);
            }
            else{
                b.push_back(nums[i]);
                y.insert(nums[i]);
            }
        }
        for(int i=0;i<b.size();i++)a.push_back(b[i]);
        return a;
    }
};