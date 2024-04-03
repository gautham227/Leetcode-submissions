#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define all(x) (x).begin(),(x).end()
#define srt(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define cpy(v2,v1) v2.assign(v1.begin(),v1.end())
#define maxv(a) *max_element(a.begin(), a.end())
#define minv(a) *min_element(a.begin(), a.end())
#define ff first
#define ss second
#define endl "\n"

//type definitions

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

//constants

const long long int inf = 1e18;
const int mod = 1000000007;
#define pi 3.141592653589793238462

template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index)  // Never change this
    {
        if (start == end)    {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
    {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    ll val; // may change
    Node1() { // Identity element
        val = 0;    // may change
    }
    Node1(ll p1) {  // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val = l.val | r.val;  // may change
    }
};

struct Update1 {
    ll val; // may change
    Update1(ll p1) { // Actual Update
        val = p1; // may change
    }
    void apply(Node1 &a) { // apply update to given node
        a.val = val; // may change
    }
};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<ll> nums1;
        for(int i=0;i<n;i++){
            nums1.pb(nums[i]);
        }
        SegTree<Node1, Update1> tree(n, nums1);
        
        ll ors=0;
        for(ll i=0;i<n;i++)ors|=nums1[i];
        
        if(ors<k)return -1;
        
        ll l=1, r=n;
        
        while(r-l>1){
            ll mid=l+(r-l)/2;
            ll maxi=0;
            for(ll i=0;i<n-mid+1;i++){
                maxi=max(maxi, 1ll*tree.make_query(i,i+mid-1).val);
            }
            if(maxi>=k){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ll maxi=0;
        for(int i=0;i<n-l+1;i++){
            maxi=max(maxi, 1ll*tree.make_query(i,i+l-1).val);
        }
        if(maxi>=k)return l;
        return r;
        
    }
};