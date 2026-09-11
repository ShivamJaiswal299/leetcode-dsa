class Solution{
public:
    int myAtoi(string s) {
      if(s.length()==0) return 0;//zero length check.
      int sign=1;
      int i=0;
      while(i<s.length()){
        if(s[i]==' ') i++;
        else break; //stopping when ' ' finishes
      }
      if(s[i]=='+' || s[i]=='-') {//sign check
        if(s[i]=='-') sign=-1;
        i++;
      }
      long long ans=0;
      for( ;i<s.length();i++){
        if('0'<=s[i] && s[i]<='9') {
          ans=ans*10+(s[i]-'0');
          if(sign*ans>INT_MAX) return INT_MAX; //checking everytime for overflow for int so that it never grows
          else if(sign*ans<INT_MIN) return INT_MIN;
          }
        else break;
      }
      ans*=sign;
      return ans;
    }
};