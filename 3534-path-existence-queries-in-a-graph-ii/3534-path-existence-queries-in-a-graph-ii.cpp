class Solution {
public:
    int n,lg;
    vector<vector<int>>up;
    void bld(vector<int>&nxt){
        lg=__lg(n)+1;
        up.resize(lg,vector<int>(n,-1));
        up[0]=nxt;
        for(int j=1;j<lg;++j)
            for(int i=0;i<n;++i)    
                if(~up[j-1][i])
                    up[j][i]=up[j-1][up[j-1][i]];
    }
    int qry(int u,int v){
        if(u==v)
            return 0;
        if(u<v)
            swap(u,v);
        int dist=0;
        for(int j=lg-1;~j;--j){
            if(~up[j][v]&&up[j][v]<u){
                dist+=(1<<j);
                v=up[j][v];
            }
        }
        return dist+1;
    }
    vector<int>pathExistenceQueries(int _n,vector<int>&A,int maxDiff,vector<vector<int>>&queries) {
        n=_n;
        vector<pair<int,int>>sorted(n);
        for(int i=0;i<n;++i)
            sorted[i]={A[i],i};
        sort(begin(sorted),end(sorted));
        vector<int>ids(n,1);
        int id=1;
        for(int i=1;i<n;++i){
            if(sorted[i].first-sorted[i-1].first>maxDiff)
                ++id;
            ids[sorted[i].second]=id;
        }
        int r=0;
        vector<int>nxt(n,-1);
        for(int l=0;l<n;++l){
            while(r+1<n&&sorted[r+1].first-sorted[l].first<=maxDiff)
                ++r;
            nxt[l]=r;
        }
        vector<int>pos(n);
        for(int i=0;i<n;++i)
            pos[sorted[i].second]=i;
        bld(nxt);
        int m=queries.size(),i=0;
        vector<int>res(m,-1);
        for(auto&query:queries){
            int u=query[0],v=query[1];
            if(ids[u]==ids[v])
                res[i]=qry(pos[u],pos[v]);
            ++i;    
        }
        return res;
    }
};