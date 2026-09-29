class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortarr;
        for(int x:arr){
          sortarr.push_back(x);
        }
        sort(sortarr.begin(),sortarr.end());
        unordered_map <int,int> mp;
        int rank = 1;//counter 
        for(int x : sortarr) {
          if (mp.count(x)==0) mp[x] = rank++;
        }
        for(int i=0;i<arr.size();i++){
          arr[i]=mp[arr[i]];
        }
        return arr;
    }
};