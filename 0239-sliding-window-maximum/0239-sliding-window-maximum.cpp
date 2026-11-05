class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
      int n = a.size();
      deque<int>maxq;   // keeps values in decreasing order
      vector<int> ans;
      int low=0,high=0;
      while(high<n){
        int x = a[high];
        // remove smaller values from back, they can never be max
        while(!maxq.empty() && x>maxq.back()){
          maxq.pop_back();
        }
        maxq.push_back(x);
        
        // window size is k
        if(high-low+1 == k){
          ans.push_back(maxq.front());   // front is the max
          // if the leaving element is the max, remove it
          if(a[low]==maxq.front()) maxq.pop_front();
          low++;
        }
        high++;
        
      }
      return ans;
    }
};