#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll ans = nums[0];
        ordered_set os;
        priority_queue<ll> pq;
        if(nums.size()==k)return (accumulate(nums.begin(), nums.end(), 0*1ll));
        k--;
        ll ans1 = 100000000000000;
        ll n = nums.size();
        ll st = 1;
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            // cout<<i<<endl;
            if (pq.size() < k) {
                pq.push(nums[i]);
                os.insert(nums[i]);
                sum += 1ll * nums[i];
            } else if (i - st <= dist) {
                if (nums[i] < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(nums[i]);
                    sum += nums[i];
                }
                os.insert(nums[i]);
            } else {
                
//                 here nums[st] is in the k smallest elements
                if(nums[st]<=(*(os.find_by_order(k-1)))){
//                     nums[i] is less than or equal to k-1 th element
                    sum-=nums[st];
                    os.erase(os.upper_bound(nums[st]));
                    os.insert(nums[i]);
                    if(nums[i]<=(*(os.find_by_order(k-1)))){
                        sum+=nums[i];
                    }
                    else{
                        sum+=(*(os.find_by_order(k-1)));
                    }
                }
                else{
                    os.erase(os.upper_bound(nums[st]));
                    if(nums[i]<(*(os.find_by_order(k-1)))){
                        sum-=(*(os.find_by_order(k-1)));
                        sum+=nums[i];
                    }
                    os.insert(nums[i]);
                }
                st++;
                
            }
            if(os.size()>=k){
                ans1=min(ans1,sum);
            }
        }
        return ans + ans1;
    }
};
