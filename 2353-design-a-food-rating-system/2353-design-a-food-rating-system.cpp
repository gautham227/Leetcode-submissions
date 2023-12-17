class FoodRatings {
public:
    map<string, string>mp;
    map<string, set<pair<int, string> > >comp;
    map<string, int> rat;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp[foods[i]]=cuisines[i];
            rat[foods[i]]=ratings[i];
        }
        
        for(int i=0;i<foods.size();i++){
            comp[cuisines[i]].insert({ratings[i], foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        int cur=rat[food];
        string cui=mp[food];
        comp[cui].erase(comp[cui].find({cur, food}));
        comp[cui].insert({newRating, food});
        rat[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        auto it=--comp[cuisine].end();
        int r=(*it).first;
        pair<int, string> p={r,"a"};
        it=comp[cuisine].lower_bound(p);
        return (*it).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */