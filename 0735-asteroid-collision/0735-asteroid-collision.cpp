class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> stk;
      for(int x:asteroids){
        bool alive = true;
        while(alive && !stk.empty() && x<0 && stk.top()>0){
          if(stk.top()<-x) stk.pop();
          else if(stk.top()==-x){
            stk.pop();
            alive=false;
          }
          else{
            alive=false;
          }
        }
        if(alive) stk.push(x);
      }
      vector <int> ans;
      while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};