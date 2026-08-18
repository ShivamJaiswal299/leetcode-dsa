class Solution {
public:
    int reverse(int x) {
        int temp=x,rev=0;
        while(temp!=0){
          if((rev>INT_MAX/10 || (rev==INT_MAX/10) && temp%10>7) || (rev<INT_MIN/10 || (rev==INT_MIN/10) && temp%10>7)) return 0;
          rev=rev*10+temp%10;
          temp/=10;
        }
        
        return rev;
    }
};
