#include<bits/stdc++.h>
using namespace std;
struct xgcda{
int gcd,x,y;


};
int recursive_gcd(int a,int b)
{
	if (a == 0)
        return b;
    return recursive_gcd(b % a, a);
}
int gcd(int a,int b)
{
	while(a>0)
	{
		int temp=a;
		a=b%a;
		b=temp;

	}
	return b;
}
struct xgcda xgcd(int a,int b)
{
	int xprev=0, x = 1;
	int yprev = 1,y= 0;
	struct xgcda temp1,ans;
    while (a)
	{
        int q = b / a;
		int temp;
		temp=x;
		x=xprev-q*x;
		xprev=temp;
		temp=y;
        y=yprev-q*y;
		yprev=temp;
		temp=a;
		a=b%a;
		b=temp;
	}
	ans.gcd=b;
	ans.x=xprev;
	ans.y=yprev;
	return ans;
}


struct xgcda recursive_xgcd(int a,int b)
{
	struct xgcda ans,temp;
	if (a == 0)
       { 
		ans.gcd=b;
		ans.x=0;
		ans.y=1;
		return ans;
		}
	temp=xgcd(b % a, a);
	ans.gcd=temp.gcd;
	ans.x=temp.y-(b/a)*temp.x;
	ans.y=temp.x;
    return ans;


}

int inverse(int a, int n)
{
	struct xgcda temp;
	temp= xgcd(a, n);

    if (temp.gcd != 1)
       {
		 cout<<"Inverse does not exist.";
		return INT_MAX;		
		}

return (temp.x % n + n) % n;

}

int main()
{
cout<<gcd(221,34);
//struct xgcda ans =recursive_xgcd(15, 35);
//cout<<ans.gcd<<ans.x<<ans.y<<endl;
//cout<<recursive_gcd(10,25);
//cout<< inverse(2,4)<<endl;
return 0;

}
