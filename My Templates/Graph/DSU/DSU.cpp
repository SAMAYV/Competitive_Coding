struct subset {
	int rank;
	int parent;
	int size;
};

void initialise(subset* s,ll n){
	REP(i,0,n){
		s[i].parent = i;
		s[i].rank = 0;
		s[i].size = 1;
	}
}

int find(int x,subset* s){
	if(s[x].parent==x)
		return x;
	s[x].parent = find(s[x].parent,s);
	return s[x].parent;
}

// union by rank
void unio(int x,int y,subset* s){
	int p1 = find(x,s);
	int p2 = find(y,s);
	if(s[p1].rank == s[p2].rank){
		s[p1].rank++;
		s[p2].parent = p1;
	}
	else if(s[p1].rank > s[p2].rank){
		s[p2].parent = p1;
	}
	else {
		s[p1].parent = p2;	
	}
}

// union by size
void unio(int x,int y,subset* s){
    int p1 = find(x,s);
	int p2 = find(y,s);
	if(s[p1].size >= s[p2].size){
		s[p2].parent = p1;
		s[p1].size += s[p2].size;
	}
	else {
		s[p1].parent = p2;	
		s[p2].size += s[p1].size;
	}
}