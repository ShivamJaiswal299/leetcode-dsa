class Solution {
public:
//METHOD 1 - HASHMAP APPROACH, here space is o(n) but no need of sorting and hence indices are maintained 
    vector<int> twoSum(vector<int>& a, int key) {
      unordered_map <int,int> mp;
      for(int i=0;i<a.size();i++){
        int compliment = key - a[i];
        if(mp.count(compliment)) return {i,mp[compliment]};
        else mp.insert({a[i],i});
      }
      return{-1,-1};
    }
//METHOD 2 - 2 POINTERS APPROACH, here sorting is required and indices are not maintained but give space o(1), so we take left and right pointer on both the corners of the vector, if sum of both pointers is greater than key we decrement right else if its smaller then we increment left until key is found
};