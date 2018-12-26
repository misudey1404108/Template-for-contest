#include                <bits/stdc++.h>
#include                <stdio.h>
#define fast()          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll              long long
#define pii             pair<ll,ll>
#define pb              push_back
#define all(a)          a.begin(),a.end()
#define pf              printf
#define Pi              2*acos(0.0)
#define bitcnt(x)       __builtin_popcountll(x)
#define pb              push_back
#define F               first
#define mpp             make_pair
#define S               second
#define ms(a,b)         memset(a, b, sizeof(a))
#define inf             1e10L
#define MAX             1000005
#define MOD             1000000007
#define MAXL            log2(100000)
#define valid(nx,ny,row,col) nx>=0 && nx<=row-1 && ny>=0 && ny<=col-1
///==Scanning====///
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

///==Arr,Vec Functions==///
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define Max(a) (*maxx_element(all(a)))
#define Min(a) (*min_element(all(a)))
#define fv(i,v)  for(int i=0;i<(int)v.size();i++)
#define fr(i,a,n) for(int i=a;i<=n;i++)
#define rf(i,n,a) for(int i=n;i>=a;i--)
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll countDivisor(ll n) {ll divisor = 0;for (ll i=1;i*i<=n;i++){if(i*i==n) divisor+= 1;else if(n%i==0) divisor+= 2;}return divisor;}
int bmod(int a,int b,int m){if(b==0)return 1;int x=bmod(a,b/2,m);x=(x*x)%m;if(b%2==1)x=(x*a)%m;return x;}
ll powr(ll n,ll m){ll ans=1;for(ll i=1;i<=m;i++) ans*=n;return ans;}
bool prime(ll n){for(ll i=2;i*i<=n;i++){if(n%i==0) return false;}return true;}
int Setbit(ll N,ll pos){return N=N | (1<<pos);}
int resetbit(ll N,ll pos){return N= N & ~(1<<pos);}
bool checkbit(ll N,ll pos){return (bool)(N & (1<<pos));}
ll fx[8]={0,+0,-1,+1,+1,-1,-1,+1};
ll fy[8]={1,-1,+0,+0,+1,+1,-1,-1};
using namespace std;
///for erase a element from vector->> //a.erase(remove(a.begin(), a.end(), 3) ,  a.end());
int suffixrank[22][(int)1e6];
int stp,cnt,n;
int rmq[201000][25];
int idx[201000];

struct node{
        int originalindex;
        int firsthalf;
        int secondhalf;

        bool operator < (const node& a) const{
            if( firsthalf == a.firsthalf ) return secondhalf < a.secondhalf;
            else return firsthalf < a.firsthalf;
        }

    };
vector< int > suffixarray(string input){

     n=input.size();

    vector < node > arr(n);
    for(int i = 0 ; i < n ; i++) suffixrank[0][i] = input[i] - 'a';

    for(cnt = 1 , stp = 1; cnt<n; cnt*=2, stp++){

        for(int i = 0; i<n; i++ ){
            arr[i].firsthalf = suffixrank[stp - 1][i];
            arr[i].secondhalf = i+cnt < n ? suffixrank[stp  - 1][i + cnt] : -1;
            arr[i].originalindex = i;
        }

        sort(arr.begin() , arr .end());

        suffixrank[stp][arr[0].originalindex]=0;
        for(int i=1, currank = 0; i < n; i++) {
            if(arr[i - 1].firsthalf != arr[i].firsthalf || arr[i - 1].secondhalf != arr[i].secondhalf)
                currank++;
        suffixrank[stp][arr[i].originalindex] = currank;
        }

    }
    vector <int> suf;
    for(ll i=0 ; i < n; i++) suf.pb(arr[i].originalindex);
    return suf;


}
vector<int> kasai(string s, vector<int> sa) {
    int n = s.size(), k = 0;
    vector<int> lcp(n, 0);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; ++i) rank[sa[i]] = i;

    for(int i = 0; i < n; ++i, k?k--:0) {
        if(rank[i] == n-1) { k = 0; continue; }
        int j = sa[rank[i]+1];
        while(i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
    }
    return lcp;
}
void init(const vector<int> &a)
{
	for (int i = 0; i < a.size(); ++i)
		rmq[i][0] = a[i];
	for (int i = 1; (1<<i)<=a.size(); ++i)
		for (int j = 0; j + (1 << i) - 1 < a.size(); ++j)
			rmq[j][i] = min(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
}

int query(int x, int y)
{
	int l = log2(y - x + 1);
	return min(rmq[x][l], rmq[y - (1 << l) + 1][l]);
}

int main()
{
    fast();

    vector<int> sufarr =suffixarray(s);
    vector<int> lcp=kasai(s,sufarr);

}




