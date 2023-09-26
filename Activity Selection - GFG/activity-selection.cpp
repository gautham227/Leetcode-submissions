//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool cmp(vector<int> &a, vector<int>& b){
        return a[1]<b[1];
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<vector<int> >act;
        for(int i=0;i<start.size();i++){
            act.push_back({start[i], end[i]});
        }
        
        sort(act.begin(), act.end(), cmp);
        
        int ans=0;
        int last=-1;
        
        for(int i=0;i<act.size();i++){
            if(act[i][0]> last){
                last=act[i][1];
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends