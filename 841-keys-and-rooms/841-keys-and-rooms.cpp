class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> s;
        set<int> keys;
        keys.insert(0);
        s.insert(0);
        while(!s.empty()){
            int top=*(s.begin());
            s.erase(s.begin());
            for(auto ele: rooms[top]){
                if(keys.find(ele)==keys.end()){
                    keys.insert(ele);
                    s.insert(ele);
                }
            }
        }
        return (keys.size()==(int)rooms.size());
    }
};