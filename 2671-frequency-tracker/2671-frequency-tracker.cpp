class FrequencyTracker {
public:
    
    map<int,int> nos;
    map<int,int> freq;
    
    FrequencyTracker() {
        nos.clear();
        freq.clear();
    }
    
    void add(int number) {
        if(nos[number]!=0){
            freq[nos[number]]--;
        }
        nos[number]++;
        freq[nos[number]]++;
    }
    
    void deleteOne(int number) {
        if(nos[number]==0)return;
        freq[nos[number]]--;
        nos[number]--;
        if(nos[number]!=0){
            freq[nos[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if(freq[frequency]>0)return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */