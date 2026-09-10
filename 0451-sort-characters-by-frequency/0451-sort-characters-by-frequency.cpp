class Solution {
public:
    static bool comparebyfreq(pair<char,int>&a,pair<char,int>&b){ //idk why static is used, says this function doesnt depend on Solution object. 
      return a.second>b.second;//if it returns true that means a will come before b.
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c : s) mp[c]++;
        vector<pair<char,int>> a(mp.begin(),mp.end());//this means everything from mp.begin to mp.end has been copied to vector a.
        //as we once heard we can change how the sort fn works but ourself.
        sort(a.begin(),a.end(),comparebyfreq);
        //as it is sorted in decreasing order , now storing it in result.
        string result = "";
        for(auto x: a) for(int i=1;i<=x.second;i++) result+=x.first;
        return result;
    }
};