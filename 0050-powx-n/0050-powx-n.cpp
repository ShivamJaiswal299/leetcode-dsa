class Solution {
public:
  double myPow(double x, int n) {
    if(x==0) return 0.0;
    if(n==0) return 1.0;
    long long N = n; //cuz we will make -ve n into positive and then int can overflow (check the range of int , both left and right side)
    long double X=x;
    if(N<0){//making the x and n suitable
      X=1/X;
      N=-N;
    }
    return (double)helperfn(X,N);
  }
private:
  long double helperfn(long double x, long long n){
    if(n==0) return 1.0L;
    long double half = helperfn(x,n/2); //using the binary exponentiation
    if(n%2==0) return half*half;
    else return x*half*half;
  }
};
//WRONG SOLN - IGNORE
//     double myPow(double x, int n) {
//       long long N = n;
//       if(x==0) return (double)0;
//       if(n==0) return (double)1;
//       if(x>0){
//         if(n>0){
//           return powercal(x,n);
//         }else{
//           return powercal((double)1.0/x,-1*n);
//         }
//       }else {
//         if(n>0){
//           if( n % 2 == 0) return powercal(-1*x,n);
//           else return -1*powercal(-1*x,n);
//         }else{
//           if(n%2==0) return powercal((double)(-1.0)/x,-1*n);
//           else  return -1*powercal((double)(-1.0)/x,-1*n);
//         }
//       }
//     }
// private:
//     double powercal(double x, long long n){
//       if(n==0) return 1;
//       if((n-1)%2==0)return x*powercal(powercal(x,(n-1)/2),2);
//       else return x*powercal(powercal(x,(n-1)/2),2);
//     }