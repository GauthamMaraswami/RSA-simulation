#include<bits/stdc++.h>
using namespace std;
//function to find exponentation 
/*

return  x^n mod p
 EXAMPLES
    ========
    >>> exp(2,47)
    199807
    >>> exp(3,51,678)
    93
    """
*/
uint64_t exp( uint64_t  x, uint64_t n,  uint64_t p=1000007)
{
	uint64_t ans = 1;
    x = x % p;

    while (n > 0)
	{
        if (n & 1)
		{
            ans = (ans * x) % p;
		}	
        x = (x * x) % p;
        n = n >> 1;
	}
	return ans;
}
/*
calculates the jacobi symbol of the 
EXAMPLES
    ========
    >>> jacobi(1001, 9907)
    -1
    >>> jacobi(19, 45)
    1
    >>> jacobi(8,21)
    -1
    >>> jacobi(3, 15)
    0
    >>> jacobi(13, 28)
    Traceback (most recent call last):
    ValueError: b has to be odd
    >>> jacobi(28, 13)
    -1
*/
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
    while( a != 0)
	{
        while ( ~a % 2)
		{
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

/*Fermat's Primality test
    Returns True(probably prime) if n is prime, Flase if n is composite.
    Args:
        n: integer to be tested for primality
        k: number of iterations of the Fermat's Primality Test
 EXAMPLES
    ========
    >>> fermats_test(5)
    True
    >>> fermats_test(4)
    False
    >>> fermats_test(341)
    False
    The test may fail for n = 561 = 3.11.17, the smallest Carmichael number if
    we add the condition that the chosen 'a' values have to be co-prime to n.
    >>> fermats_test(561)
    False*/
bool fermats_test(int n,int k=10)
   {
    if (n == 2)
        return true;
    if (n % 2==0)
        return false;

    for (int g=0;g<k;++g)
        {	srand(time(NULL));
			uint64_t a=rand()%(n-1)+2;
		//	a = random.randint(2, n-1)
		    if (exp(a, n - 1, n) != 1)
		        return false;
		}
    return true;
	}
  bool check_if_composite_using(uint64_t a,uint64_t d,uint64_t n,uint64_t s)
       {
		uint64_t x = exp(a, d, n);
        if (x == 1 || x == n - 1)
            return false;  //probably prime
        for (uint64_t g=0;g<s;++g)
            {
				x = (x * x) % n  ;//check for each a^((2^i)*d)
	            if (x == n - 1)
	                return false;  // probably prime
		       
			}
			 return true ; // definitely composite
		}
/*
"Miller Rabin Primality Test
    Return False if n is composite, True(probably prime) otherwise.
EXAMPLES
    ========
    >>> miller_rabin(561)
    False
    >>> miller_rabin(29)
    True
    >>> miller_rabin(221)
    False
*/
bool miller_rabin(uint64_t n,uint64_t k=10){
  
    if (n == 2)
        return true;
    if (n == 1 || (n % 2) == 0)
        return false;

  uint64_t s= 0;
	uint64_t d=n-1;
 
    while  (d % 2!=0)
       {
		 	s += 1;
        	d /= 2;
		}
    

  
   // # Test for k random integers a
    for (int g=0;g<k;++g)
		{
			srand(time(NULL));
			uint64_t a=rand()%(n-1)+2;
      
        if (check_if_composite_using(a,d,n,s))
            return false; // # definitelyn composite
		}
    return true; // # probably prime

}

/*
Solovay Strassen Primality Test
    Returns False is n is composite, True(probably prime) otherwise.
EXAMPLES
    >>> solovay_strassen(561)
    False
    >>> solovay_strassen(29)
    True
    >>> solovay_strassen(221)
    False
*/

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
/*
Seive of Eratosthenes
    Returns a list of primes less than n
*/
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

	for(uint64_t p=2;p<=n;p++)
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

//gcd.cpp
struct xgcda{
uint64_t gcd,x,y;


};
/*Euclid's algorithm for gcd 
 EXAMPLES
    ========
    >>> gcd(7, 19)
    1
    >>> gcd(221,34)
    17
*/
int recursive_gcd(int a,int b)
{
	if (a == 0)
        return b;
    return recursive_gcd(b % a, a);
}
/*Euclid's algorithm for gcd (Recursive)
 EXAMPLES
    ========
    >>> gcd(7, 19)
    1
    >>> gcd(221,34)
    17
*/
uint64_t gcd(uint64_t a,uint64_t b)
{
	while(a>0)
	{
		uint64_t temp=a;
		a=b%a;
		b=temp;

	}
	return b;
}
/*Extended Euclidean Algorithm (Recursive)
    Args:
        a: int
        b: int
    NOTES
    =====
    We can represent gcd(a,b) = a.x + b.y
    This function returns gcd(a, b), x, y
    Why does it work?
    a.x + b.y = (b % a).x1 + a.y1
              = (b - (b//a).a).x1 + a.y1
              = a.(y1 - (b//a).x1) + b.x1
    REFERENCES
    ==========
    http://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
    EXAMPLES
    ========
    >>> xgcd(15, 35)
    (5, -2, 1)
    >>> xgcd(30, 20)
    (10, 1, -1)
*/
struct xgcda xgcd(uint64_t a,uint64_t b)
{
	uint64_t xprev=0, x = 1;
	uint64_t yprev = 1,y= 0;
	struct xgcda temp1,ans;
    while (a)
	{
        uint64_t q = b / a;
		uint64_t temp;
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

/*"""Extended Euclidean Algorithm (Iterative)
    Args:
        a: int
        b: int
    NOTES
    =====
    We can represent gcd(a,b) = a.x + b.y
    This function returns gcd(a, b), x, y
    REFERENCES
    ==========
    https://anh.cs.luc.edu/331/notes/xgcd.pdf
    EXAMPLES
    ========
    >>> xgcd(15, 35)
    (5, -2, 1)
    >>> xgcd(30, 20)
    (10, 1, -1)
    """*/
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
/* """Modular Multiplicative Inverse
    Args:
        a: integer whose inverse is to be found
        n: modular base
    NOTES
    =====
    Returns the modular multiplicative inverse of 'a' under mod n
    Return value is always positive
    EXAMPLES
    ========
    >>> inverse(2, 5)
    3
    >>> inverse(17, 39)
    23
    >>> inverse(2,4)
    Traceback (most recent call last):
    Exception: Inverse does not exist.
    """*/
uint64_t inverse(uint64_t a, uint64_t n)
{
	struct xgcda temp;
	temp= xgcd(a, n);

    if (temp.gcd != 1)
       {
		 cout<<"Inverse does not exist.";
		exit(0);	
		}

return (temp.x % n + n) % n;

}
//gcd.cpp end
/*returns the Euler Totient Function of n
    phi(n) = number of positive integers co-prime with n.
    Args:
        n: integer
    REFERENCES
    ==========
    http://www.geeksforgeeks.org/eulers-totient-function/
    EXAMPLES
    ========
    >>> phi(10)
    4
    >>> phi(7)
    6
    >>> phi(33500000)
    13200000
*/
uint64_t phi(uint64_t n)
{
    uint64_t result = 1;
    for (uint64_t i=2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}
/*
""generate a large a prime number by incremental search
    Args:
        bit_size: number of bits in generated prime. If you want a 100 bit long
                  prime set bit_size = 100
        primality_test: primality_test to use
*/
uint64_t generate_large_prime(int bits_size,string primality_test="miller_rabin")
 {
   // # Get a random bit_size bit integer


	srand(time(NULL));
	uint64_t range = pow(2,bits_size-1);
	uint64_t num = range + rand()%(range);
	if(num%2==0)
		num++;

	if(primality_test=="miller_rabin")
	{
		while(miller_rabin(num,100)==false){
			num+=2;
			if(num>=range*2)
				num = range + rand()%(range);
		}
	}
	else if(primality_test=="solovay_strassen")
	{
		while(solovay_strassen(num,50)==false){
			num+=2;
			if(num>=range*2)
				num = range + rand()%(range);
		}
	}
	else if(primality_test=="fermats_test")
	{
		while(fermats_test(num,50)==false){
			num+=2;
			if(num>=range*2)
				num = range + rand()%(range);
		}
	}
return num;
    
}
//RSA.cpp
//int to char converter 
void int64ToChar(char a[], int64_t n) {
	uint64_t ans=0;
int ctr=4;
	while(ctr<4)
	{
		uint64_t temp =n%100;
		  n/=100;
		a[ctr]=temp;
	}
}
//char to int  converter 
int64_t charTo64bitNum(char a[]) {
  int64_t n = 0;
  for(uint64_t i=0;i<3;++i)
	{
		int az=a[i];
		//cout<<az;
		n=n*100+az;
	}
	//cout<<n;
  return n;
}


//implimentation of rsa
class RSA
{
private:
	int bit_size;
	unsigned long long p,q,n,phi,pvtkey,publickey;
	string primality_test;
public:

	 RSA( int size=128, string primality_test="miller_rabin")
       {
        this->bit_size = size;
        if (primality_test == "miller_rabin")
           {
			 this->primality_test = "miller_rabin";
			}
        else if(primality_test == "solovay_strassen"){

            this->primality_test = "solovay_strassen";
		}
       this->p = generate_large_prime(this->bit_size, this->primality_test);   //generation of p large prime
        this->q = generate_large_prime(this->bit_size, this->primality_test);  //generation of q large prime
        while (this->p==this->q){											//make sure p!=q
            this->q = generate_large_prime(this->bit_size, this->primality_test);
		}
        this->n = this->p * this->q;										//find n = p*q
        this->phi = (this->p - 1) * (this->q - 1);							//find phi for given n
        generateandsetkeys();
	}
	void generateandsetkeys()
	{	
		
		srand(time(NULL));												//get random number
	uint64_t n = rand()%(this->phi-2) + 1;								//get random number less than phi
	while(gcd(n,this->phi)!= 1){										//see that the random number generated has gcd 1 with phi
		n = rand()%(this->phi-2) + 1;						
	}
	
	this->publickey = n;												//assign public key as n
	this->pvtkey = inverse(n,this->phi);								//assign private key as inverse(n)
	}
	
	
unsigned long long getPublicKey(){										//just to get the public key

	//cout<<this->publickey<<"\n"<<this->pvtkey;	
	unsigned long long ans=this->publickey;											
	return ans;
}

uint64_t encrypt_block(uint64_t plain_text_block){						//encrypt the code by raising the message to the power of public key 
	uint64_t cipher_text_block;
	cipher_text_block = exp(plain_text_block,this->publickey,this->n);
	return cipher_text_block;
}

uint64_t decrypt_block(uint64_t cipher_text_block){						//decrypt the code by raising the message to the power of private key
	uint64_t plain_text_block;
	plain_text_block = exp(cipher_text_block,this->pvtkey,this->n);
	return plain_text_block;
}

string process_string(string message){									//to divide the message into blocks and covert to integer array
     char c_temp[100],message2[5];
	 strcpy(c_temp, message.c_str()); 
	int length=strlen(c_temp);
	//cout<<length;
	uint64_t message1[100];
	int ctr=0;
	string strans;
    for(uint64_t i=0;i<length;i+=3)
		{
			strncpy(message2, c_temp + i, 3);
			message1[ctr]=charTo64bitNum(message2);
			++ctr;
			//cout<<message1[ctr-1]<<endl;
			uint64_t ans=encrypt_block(message1[ctr]);
			strans += std::to_string(ans);
			strans+="z";

		}

return strans;
}

string recover_string(string encrypted_message)					//to decrypt the message and get back data by coverting to charcter array and joining the pieces
{
char c_temp[100],message2[100];
	 strcpy(c_temp, encrypted_message.c_str()); 
	int length=strlen(c_temp);
	//cout<<c_temp<<endl;
	uint64_t message1;
	int ctr=0;
	string strans;
	int st=0;
	
	for(uint64_t i=0;i<length;i++)
		{
			if(c_temp[i]=='z')
				{
						strncpy(message2, c_temp + st, i-st);
						st=i+1;
						uint64_t buf =atoi(message2);
						uint64_t decrypted=decrypt_block(buf);
						char c_temp1[100];
						 int64ToChar(c_temp1,decrypted);
 						//cout<<decrypted<<"zoomcar"<<c_temp1<<endl<<"test"<<endl;

				}
			
		}

return "baboo";

}

};


    




int main()
{
//cout<<fermats_test(561);
//cout<<miller_rabin(29);
RSA r1(10);

uint64_t abc=r1.encrypt_block(90);
uint64_t cab=r1.decrypt_block(abc);
cout<<abc<<"ans"<<cab;
string temp=r1.process_string("ZZZZZZZZZz");
cout<<temp<<endl<<endl;
cout<<r1.recover_string(temp);
//cout<<solovay_strassen(221);
//struct xgcda ans =recursive_xgcd(15, 35);
//cout<<ans.gcd<<ans.x<<ans.y<<endl;
//cout<<recursive_gcd(10,25);
//cout<< inverse(2,4)<<endl;
return 0;

}
