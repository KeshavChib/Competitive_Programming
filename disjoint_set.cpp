// a template for disjoint set data structure...
class DisjointSet{
    vector<int> size, parent;
    public:
    int comp;
    DisjointSet(int n){
        comp = n;
        size.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
            
    bool join(int u, int v){
        int p1 = findParent(u);
        int p2 = findParent(v);
        if(p1 == p2) return false;
        if(size[p1] > size[p2]){
            parent[p2] = p1;
            size[p1] += size[p2];
        }
        else{
            parent[p1] = p2;
            size[p2] += size[p1];
        }
        comp--;
        return true;
    }
};
