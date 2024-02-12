#include<iostream>
using namespace std;
int fib(int n,int dp[]){
dp[0]=0;
dp[1]=1;
for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}

return dp[n];
}
int main(){
int n;
cout<<"Enter a no ";
cin>>n;
int dp[n+2];
for(int i=0;i<=n;i++){
    dp[i]=-1;
}

cout<<"fibonacci no of "<<n<<" is ";
cout<<fib(n,dp);



    return 0;
}
// output is
// Enter a no 8
// fibonacci no of 8 is 21
