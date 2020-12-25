#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ll long long int
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define i_os ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
#define INF (ll)1e18 + 100
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x − 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/
#define o_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

int main() {

	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		map<ll,ll> um;
		REP(i,0,m){
 			ll x;  cin>>x;
			um[x]++;
		}
		ll ans = 0, temp = 0;
		REP(i,0,60){
			if(n & (1LL<<i)){
				if(um[(1LL<<i)] > 0){
					um[(1LL<<i)]--;
					n ^= (1LL<<i);
				}
				else if(temp >= (1LL<<i)){
					temp -= (1LL<<i);
					n ^= (1LL<<i);	
				}
				else {
					auto it = um.upper_bound((1LL<<i));
					if(it == um.end()) break;
					else {
						ll val = (*it).first;
						while(val > (1LL<<i)){
							um[val]--;
							um[(val >> 1)] += 2;
							ans++;
							val = val >> 1;
						}
						um[(1LL<<i)]--;
						n ^= (1LL<<i);
					}
				}
			}
			temp += um[(1LL<<i)]*(1LL<<i);
		}
		if(n == 0){
			cout<<ans<<endl;
		} else cout<<-1<<endl;
	}	
	return 0;
}