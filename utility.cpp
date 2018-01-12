#include<bits/stdc++.h>
using namespace std;

unsigned long long int exp( unsigned long long int  x, int n,  unsigned long long int p=1000007)
{
	unsigned long long int ans = 1;
     x = x % p;

    while (n > 0){
        if (n & 1){
            ans = (ans * x) % p;
		}	
        x = (x * x) % p;
        n = n >> 1;
	}

return ans;
}


 int jacobi(int a,int  b)
    {

    if (b <= 0)
        {
			cout<<"b has to be >= 1"<<endl;
			exit(-1);	
		}
    if (b%2!=1)
        {
			cout<<"b has to be odd"<<endl;
			exit(-1);	
		}


   int ans = 1;
    if (a < 0)
        {
			int a = -a;
        	if (b % 4 == 3)
            	ans = -ans;
		}
    while( a != 0){
        while ( ~a % 2){
			a /= 2;
            if ((b % 8) >=3&& (b%8)<= 5)
                ans = -ans;
		}
		int temp=a;
		a=b;
		b=temp;
        if (a % 4 == 3 and b % 4 == 3)
            ans = -ans;
        a = a % b;
	}
    if (b == 1)
        return ans;
    else
		return 0;
}
int main()
{
//cout<<exp(3,51,678);
cout<<jacobi(3,15);
//struct xgcda ans =recursive_xgcd(15, 35);
//cout<<ans.gcd<<ans.x<<ans.y<<endl;
//cout<<recursive_gcd(10,25);
//cout<< inverse(2,4)<<endl;
return 0;

}
