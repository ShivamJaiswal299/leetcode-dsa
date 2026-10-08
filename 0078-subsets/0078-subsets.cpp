class Solution {
//LOGIC IS SIMPLE , FOR EVERY ELEMENT MAKE 2 CASES , ONE- ADDING THE CURRENT ELEMENT AND TWO- SKIPPING THE CURRENT ELEMENT MAKING THE THE TREE STRUCTURE LOOK LIKE THIS-
/*
                                      []                         ← decide 3
                   ┌-------------------┴-------------------┐
                  []                                      [3]    ← decide 2
         ┌---------┴---------┐                   ┌---------┴---------┐
        []                  [2]                 [3]               [3,2]   ← decide 1
     ┌----┴----┐         ┌----┴----┐         ┌----┴----┐         ┌----┴----┐
    []        [1]       [2]      [2,1]      [3]      [3,1]      [3,2]    [3,2,1]
     ✔         ✔         ✔         ✔         ✔         ✔         ✔         ✔
*/
public:
    vector<vector<int>> subsets(vector<int>& a) {
      vector<vector<int>> ans; //FINAL ANS
      vector<int> curr;//CURR WILL STORE THE TEMPERORY VECTOR SETS CREATED
      helper(a,curr,ans);
      return ans;
    }
private:
    void helper(vector<int>&a, vector<int>&curr , vector<vector<int>> &ans){
      if(a.empty()){ //IF A BECOMES EMPTY, ADD IT TO ans AND RETURN
        ans.push_back({curr});
        return;
      }
      //TAKING THE LAST ELEMENT OUT
      int element = a.back();
      a.pop_back();
      //FOR THE 2 CASES CALL THE FUNCTION WHILE ADDING ELEMENT IN ONE CASE
      helper(a,curr,ans);
      curr.push_back(element);
      helper(a,curr,ans);
      //IMP STEP - MAKING THE CURR AND a SAME AGAIN SO THAT OTHER CASES CAN BE PERFORMED
      curr.pop_back();
      a.push_back(element);
    }
};