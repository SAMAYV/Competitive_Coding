#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long 
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
#define MAX 1e6
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x − 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/
#define o_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

void eulerian_circuit(vector<ll>* edges,ll n){
	unordered_map<ll,ll> um;
	REP(i,0,n){
		um[i] = edges[i].size();
	}
	stack<ll> s;
	vector<ll> v;
	s.push(0);
	ll curr = 0;
	while(s.size()){
		if(um[curr] > 0){
			s.push(curr);
			um[curr]--;
			ll next = edges[curr].back();
			edges[curr].pop_back();
			curr = next;
		}
		else {
			v.push_back(curr);
			curr = s.top();
			s.pop();
		}
	}
	cout<<'\n';
	reverse(v.begin(),v.end());
	REP(i,0,v.size()){
		cout<<v[i] + 1;
		if(i != v.size() - 1) cout<<"->";
	}
	cout<<endl;
}
int main() 
{ 
	ll n,e;
	cin>>n>>e;
	vector<ll> edges[n];
	REP(i,0,e){
		ll x,y;
		cin>>x>>y;
		edges[x-1].push_back(y-1);
	}
	eulerian_circuit(edges,n);
	return 0;	
} 