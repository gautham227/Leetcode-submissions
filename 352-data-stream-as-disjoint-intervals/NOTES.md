}
}
}
else{
if(it==s.begin()){
if((*it)[0]==value+1){
range[1]=((*it)[1]);
s.erase(it);
s.insert(range);
}
}
}
}
vector<vector<int>> getIntervals() {
vector<vector<int> > ans;
for(auto ele: s)ans.push_back(ele);
return ans;
}
};
​
/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges* obj = new SummaryRanges();
* obj->addNum(value);
* vector<vector<int>> param_2 = obj->getIntervals();
*/
```