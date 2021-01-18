map<pair<ll,ll>,ll> umm;

ll bfs(ll s,ll t,vector<ll>& parent,ll n,vector<vector<ll>>& adj,vector<vector<ll>>& capacity){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll,ll>> q;
    q.push({s, 1e9});

    while(q.size()){
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for(ll next : adj[cur]){
            if(parent[next] == -1 && capacity[{cur,next}]){
                parent[next] = cur;
                ll new_flow = min(flow, capacity[{cur,next}]);
                if(next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
ll maxflow(ll s,ll t,ll n,vector<vector<ll>>& adj,map<pair<ll,ll>,ll>& capacity){
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;
    while(new_flow = bfs(s,t,parent,adj,capacity)){
        flow += new_flow;
        ll cur = t;
        while(cur != s){
            ll prev = parent[cur];
            capacity[{prev,cur}] -= new_flow;
            capacity[{cur,prev}] += new_flow;
            cur = prev;
        }
        umm[{parent[parent[t]],parent[t]}] = 1;
    }
    return flow;
}
bool bipartite(ll n,vector<ll>* edges,vector<ll>* arr){
    vector<ll> side(n, -1);
    bool is_bipartite = true;
    queue<ll> q;
    REP(st,0,n){
        if(side[st] == -1){
            q.push(st);
            side[st] = 0;
            while(q.size()){
                ll v = q.front();
                arr[side[v]].insert(v);
                q.pop();
                for(auto u : edges[v]){
                    if(side[u] == -1){
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } 
                    else {
                        is_bipartite &= (side[u] != side[v]);
                    }
                }
            }
        }
    }
    return is_bipartite;
}
void Min_Node_Cover(ll n,ll m,ll s,ll d,vector<ll>* edges){
	umm.clear();
    vector<ll> v[2];
	if(!bipartite(n,edges,v)){
		cout<<-1<<endl;
		return;
	}
	map<pair<ll,ll>,ll> capacity;
	vector<vector<ll>> adj;
    adj.resize(n+2,vector<ll>());

    REP(i,0,n+2){
		for(auto it:edges[i]){
			capacity[{i,it}] = 1;
			capacity[{it,i}] = 0;
			adj[i].push_back(it);
            adj[it].push_back(i);
		}
	}
	for(auto it:v[0]){
		adj[0].push_back(it);
		capacity[{0,it}] = 1;
		capacity[{it,0}] = 0;
	}
	for(auto it:v[1]){
		adj[it].push_back(n+1);
		capacity[{it,n+1}] = 1;
		capacity[{n+1,it}] = 0;
	}
	maxflow(s,d,n + 2,adj,capacity);
    
    // printing min node cover vertices
    // A minimum node cover of a graph is a minimum set of nodes such that each edge of the graph has at least one endpoint in the 
    // min node cover vertex set.
    for(auto it:umm){
        if(adj[(it.first).first].size() > adj[(it.first).second].size()){
            cout<<(it.first).first<<" ";
        }       
        else {
            cout<<(it.first).second<<" ";
        }
    }
    cout<<"\n";
    // All the vertices not present in min node cover are part of max independent set
    // This is the largest possible set of nodes such that no two nodes in this set are connected with an edge 
}
int main() 
{ 
	ll n,m;
	cin>>n>>m;
	vector<ll> edges[n+2];
	ll source = 0;
	ll dest = n+1;
	REP(i,0,m){
		ll x,y;
		cin>>x>>y;
		edges[x].push_back(y);
	}
	Min_Node_Cover(n,m,source,dest,edges);
	return 0;	
} 