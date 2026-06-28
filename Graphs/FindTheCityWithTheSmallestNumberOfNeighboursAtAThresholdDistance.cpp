// 1334

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m=edges.size();
        vector<vector<int>> v(n, vector<int>(n, INT_MAX/2));
        for (int i=0; i<m; i++){
            v[edges[i][0]][edges[i][1]]=edges[i][2];
            v[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for (int i=0; i<m; i++){
            v[edges[i][0]][edges[i][0]]=0;
        }
        for (int k=0; k<n; k++){
            for (int i=0; i<n;i++){
                for (int j=0; j<n; j++){
                    if (v[i][k]==INT_MAX/2 || v[k][j]==INT_MAX) continue;
                    v[i][j]=min(v[i][j], v[i][k]+v[k][j]);
                }
            }
        }
        for (int i=0; i<n;i++){
            for (int j=0; j<n; j++){
                cout<< v[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<int> reachable(n, 0);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) continue;
                if (v[i][j]<=distanceThreshold) reachable[i]++;
            }
        }

        int ans= *min_element(reachable.begin(), reachable.end());
        for (int i=n-1; i>=0; i--){
            if (reachable[i]==ans) return i;
        }        
        return 0;
    }
};