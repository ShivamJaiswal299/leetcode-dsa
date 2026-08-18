class Solution {
public:
    // bool isPalindrome(int x) {
    //   if(x<0) return false;
    //   if(x<10) return true;
    //   int digit=log10(x)+1;
    //   int front,back;
    //   for(int i=1;i<=digit/2;i++){
    //     back=(x/(int)pow(10,i-1))%10;
    //     front=(x/(int)pow(10,digit-i))%10;
    //     if(front!=back) return false;
    //   }
    //   return true;
    // }
    bool isPalindrome(int x) {
        string str = to_string(x);
        reverse(str.begin(),str.end());
        return str==to_string(x);
    }
};