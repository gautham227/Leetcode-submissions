class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        unordered_multiset<int> s;
        unordered_set<int> s1;
        for(auto ele: left){
            if(ele!=-1){s.insert(ele);s1.insert(ele);}
        }
        for(auto ele: right){
            if(ele!=-1){s.insert(ele);s1.insert(ele);}
        }
        if(s.size()!=s1.size() || s.size()!=n-1)return false;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()){
                ind=i;
                break;
            }
        }
        unordered_set<int> s2;
        s2.insert(ind);
        queue<int> q;
        q.push(ind);
        while(q.size()>0){
            int ind1=q.front();
            q.pop();
            s2.insert(ind1);
            if(left[ind1]!=-1)q.push(left[ind1]);
            if(right[ind1]!=-1)q.push(right[ind1]);
        }
        return ((int)s2.size()==n);
    }
};