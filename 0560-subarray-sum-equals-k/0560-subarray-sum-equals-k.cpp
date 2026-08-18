class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int presum=0,cnt=0,n=a.size();
        unordered_map<int,int> mp;
        mp.insert({0,1});
        for(int i=0;i<n;i++){
          presum+=a[i];
          if(mp.count(presum-k)) cnt+=mp[presum-k];
          if(mp.count(presum)) mp[presum]++; else mp.insert({presum,1});
        }
        return cnt;
    }
};