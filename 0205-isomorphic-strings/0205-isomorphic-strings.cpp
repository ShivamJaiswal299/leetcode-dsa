class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map <char,char> ST , TS;
      for(int i=0; i<s.length() ; i++){
        char schar = s[i];
        char tchar = t[i];
        if(!(ST.count(schar))){//kya schar ST main hai?if not then go in
          ST[schar] = tchar;
        }
        else{ //if its already exist in map then go in 
          if(ST[schar] != tchar) return false;
        }
        if(!(TS.count(tchar))){
          TS[tchar] = schar;
        }
        else{
          if(TS[tchar] != schar) return false;

        }
      }
    return true;
    }
};