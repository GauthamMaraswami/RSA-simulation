#include<bits/stdc++.h>
using namespace std;
void int64ToChar(char a[], int64_t n) {
  memcpy(a, &n, 8);
}

int64_t charTo64bitNum(char a[]) {
  int64_t n = 0;
  memcpy(&n, a, 8);
  return n;
}
int main()
{
string a="hello",b;
char c_temp[100],c_temp1[100];
 strcpy(c_temp, a.c_str()); 
int64_t temp=charTo64bitNum(c_temp);
   
cout<<temp;
 int64ToChar(c_temp1,temp);
b=c_temp;
cout<<b;


string c=a+b;
cout<<c;
return 0;
}
