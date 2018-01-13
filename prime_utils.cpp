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
//primality tests.cpp

bool fermats_test(int n,int k=10)
   {
    if (n == 2)
        return true;
    if (n % 2==0)
        return false;

    for (int g=0;g<k;++g)
        {	srand(time(NULL));
			int a=rand()%(n-1)+2;
		//	a = random.randint(2, n-1)
		    if (exp(a, n - 1, n) != 1)
		        return false;
		}
    return true;
	}
  bool check_if_composite_using(int a,int d,int n,int s)
       {
		int  x = exp(a, d, n);
        if (x == 1 || x == n - 1)
            return false;  //probably prime
        for (int g=0;g<s;++g)
            {
				x = (x * x) % n  ;//check for each a^((2^i)*d)
	            if (x == n - 1)
	                return false;  // probably prime
		       
			}
			 return true ; // definitely composite
		}
bool miller_rabin(int n,int k=10){
  
    if (n == 2)
        return true;
    if (n == 1 || (n % 2) == 0)
        return false;

    int s= 0;
	int d=n-1;
 
    while  (d % 2!=0)
       {
		 	s += 1;
        	d /= 2;
		}
    

  
   // # Test for k random integers a
    for (int g=0;g<k;++g)
		{
			srand(time(NULL));
			int a=rand()%(n-1)+2;
      
        if (check_if_composite_using(a,d,n,s))
            return false; // # definitelyn composite
		}
    return true; // # probably prime

}



bool solovay_strassen(int n, int k=10)
    {

    if (n == 2)
        return true;
    if (n == 1 || (n % 2) == 0)
        return false;

    for (int g=0;g<k;++g){

			srand(time(NULL));
			int a=rand()%(n-1)+2;
       int  x = (jacobi(a, n) + n) % n; // # map -1 to n - 1
        if (x == 0 || exp(a, (n - 1)/2, n) != x)
            return false;
		}
return true;

}



//prime_utils.cpp

struct primes{
		int list[1000000];
		int size;
};

struct primes seive(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
  	for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
	struct primes ans;
		ans.size=0;

	for(int p=2;p<=n;p++)
	{
		if(prime[p]==true)
		{
			ans.list[ans.size]=p;
			ans.size++;	
			cout<<ans.list[ans.size-1]<<endl ;	
		}
	}
return ans;
//return 0;
}


int main()
{
//cout<<fermats_test(561);
//cout<<miller_rabin(29);
struct primes  res=seive(54);
//cout<<solovay_strassen(221);
//struct xgcda ans =recursive_xgcd(15, 35);
//cout<<ans.gcd<<ans.x<<ans.y<<endl;
//cout<<recursive_gcd(10,25);
//cout<< inverse(2,4)<<endl;
return 0;

}
