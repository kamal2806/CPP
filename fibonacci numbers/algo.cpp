#include<iostream>
using namespace std;
#define ll long long

// (Fn-1  Fn) = (Fn-2  Fn-1).(0 1)
//                           (1 1)

// P = (0 1)
//     (1 1)

// apply the properties of binary exponentiation 

ll a[2][2];
ll na[2][2];
void fib(ll n){
    na[0][0]=1,na[0][1]=0,na[1][1]=1,na[1][0]=0;
    ll temp[2][2];
    while(n){
        if(n%2){
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    temp[i][j]=0;
                    for(int k=0;k<2;k++){
                        temp[i][j] += na[i][k] * a[k][j];
                    }
                }
            }
            for(int i=0;i<2;i++)for(int j=0;j<2;j++)na[i][j]=temp[i][j];
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp[i][j]=0;
                for(int k=0;k<2;k++){
                    temp[i][j] += a[i][k] * a[k][j];
                }
            }
        }
        for(int i=0;i<2;i++)for(int j=0;j<2;j++)a[i][j]=temp[i][j];
        n/=2;
    }
}

ll fun(int n){
    if(n==0)return 0;
    a[0][0]=0,a[0][1]=1,a[1][0]=1,a[1][1]=1;
    fib(n);
    return na[0][0]+na[0][1];
}

// Fast Decoupling Method
// 

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        printf("%d %lld\n",i,fun(i));
    }
}
