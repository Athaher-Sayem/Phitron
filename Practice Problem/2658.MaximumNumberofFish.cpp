class Solution {
    public:
    
    bool vis[100][100];
    int n,m;
    vector<pair<int,int>> mov={{1,0},{-1,0},{0,-1},{0,1}};
    int maxfish=0;
    int cnt=0 ;
    bool valid(int i,int j){
        if (i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    
    }
    
    void dfs(int si,int sj, vector<vector<int>>& grid){
        vis[si][sj]=true;
        for(int i=0;i<4;i++){
            int ci=si+mov[i].first;
            int cj=sj+mov[i].second;
    
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]!=0){
                
                cnt += grid[ci][cj];
                maxfish=max(cnt,maxfish);
                dfs(ci,cj,grid);
            }
        }
    }
    
        int findMaxFish(vector<vector<int>>& grid) {
             n=grid.size();
        m=grid[0].size();
        
        memset(vis,false,sizeof(vis));
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(grid[i][j]!= 0 && !vis[i][j])
                       {
                        cnt = grid[i][j]; 
                        maxfish = max(maxfish, cnt);
                        dfs(i,j,grid);     
                    } 
            }
        } 
    
        return maxfish;
    
        }
    };