//Define long long int as ll here as we use it in many places
typedef long long ll;
//We should define the "right" as give
#define MAX_ANS 2e9

ll gcd(ll a, ll b)
{
    if(a==0)
    return b;
    return gcd(b%a, a);
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}

/*

Here we find the no. of ugly nu,bers less than the number num. We use inclusion-Exclusion principle here.
AUBUC = A +B +C - (AnB)-(BnC)-(CnA)+ (AnBnC)  .i.e.
F(n) = num/A + num/B + num/C - num/(lcm(A,B) - num/(lcm(B,C) - num/lcm(C,A) + num/lcm(a,b,c).

We use this principle to find the count 'k' less than num.

*/
int count(ll num,ll a,ll b,ll c)
{
    int res= (num/a+num/b+num/c-(num/lcm(a,b))-(num/lcm(b,c))-(num/lcm(c,a))+num/(lcm(a,lcm(b,c))));
    return res;
}

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        
             int left=0, right= MAX_ANS, result=0;
             while(left<=right)
             {
                int mid=left+(right-left)/2;
                if(count(mid,a,b,c)>=n)
                {
                    result=mid;
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
             }
             return result;
    }
};
