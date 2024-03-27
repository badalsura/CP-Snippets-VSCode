struct DSU {
    vector<int> par, rnk, sz;
    int c; //conncected components;
    DSU(int n) : par(n+1), rnk(n+1, 0), sz(n +1, 1), c(n) {
        for(int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int u) {
        return par[u] == u?u:par[u] == find(par[u]);
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
    int get_size(int u) {
        return sz[find(u)];
    }
    int count(){
        return c;
    }
    int merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v)return -1;
        else --c;
        if(rnk[u] > rnk[v])swap(u, v);
        par[u] = v;
        sz[v] += u;
        if(rnk[u] == rnk[v])rnk[v]++;
        return v;
    }
}