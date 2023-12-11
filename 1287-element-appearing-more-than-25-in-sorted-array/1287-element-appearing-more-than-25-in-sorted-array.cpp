#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

//--------------------------------* TYPES----------------------------------------------------*/

#define ll long long
#define ld long  double                               
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

//------------------------------* FUNCTIONS *-----------------------------------------------/
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define sza(x) ((ll)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()



const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
#define PI 3.1415926535897932384626433832795



//-----------------------------Code----------------------------------------------------------

ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }


//----------------------------Print-----------------------------------------------------------


void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }


//----------------------------Loops-----------------------------------------------------------

#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f sp u.s<<endl;}
#define forn(i,n) for(auto i=0; i<n; i++)
#define fort(i,n) for(auto i=0; i<=n; i++)
#define forbn(i,n) for(auto i=n-1; i>=0; i--)
#define test int tc; cin>>tc; while(tc--)



//----------------------------Speed-----------------------------------------------------------



#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//---------------------------Prime Sieve------------------------------------------------------

vector<bool> is_prime;
void sieve(ll n){

is_prime.resize(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

}

//----------------------------Count Factors---------------------------------------------------

int countFactors(int n) {
    int count = 0;
    
    for (int i = 1; i * i <= n; i++) {

        if(count>3) return 0;
        if (n % i == 0) {
           
            count++;

          
            if (i != n / i) {
                count++;
            }
        }
    }

    return count;
}

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        ll n= arr.size();
        map<ll,ll> mp;
        for(auto it : arr) mp[it]++;
        int size = n*0.25;
        for(auto it : mp){
            if(it.second > size) return it.first;
        }
        return -1;
        
    }
};