#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
//using namespace boost::multiprecision;
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
#define vii vector<pair<ll,ll>>
#define F first
#define S second
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
const ll MOD2 =998244353
;
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ld EPS = 1e-9;
#define PI 3.1415926535897932384626433832795


//-----------------------------Code----------------------------------------------------------

ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcdF(ll a,ll b) { if (b==0) return a; return gcdF(b, a%b); }
ll lcm(ll a,ll b) { return a/gcdF(a,b)*b; }
bool prim(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }


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

#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Solution {
    private:
      bool isVowel(char c) {
        c = std::tolower(c); // convert to lowercase for easier comparison
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool isValid(string word) {
        // first lets check first condition about size
        if(word.size()<3) return false;
        // check anything except num and character
        f(i,0,word.size()){
            if(isalpha(word[i])) continue;
            else if(isdigit(word[i])) continue;
            else return false;
            
        }
        ll v=0,c=0;
        for(auto it : word){
            if(isalpha(it)){
                if(isVowel(it)) v++;
                else c++;
                
            }
        }
        return v>0 and c>0;
        
        
    }
};