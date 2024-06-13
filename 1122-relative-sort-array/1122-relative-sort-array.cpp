struct maxele {
public:
    int ele = 1000 + 5;
};

class Solution {
public:
    static map<int, maxele> mp;

    static bool cmp(int a, int b) {
        if(mp[a].ele!=mp[b].ele) return (mp[a].ele < mp[b].ele);
        return (a<b);
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        mp.clear();
        for (int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]].ele = i;
        }

        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};

// Define the static member
map<int, maxele> Solution::mp;
