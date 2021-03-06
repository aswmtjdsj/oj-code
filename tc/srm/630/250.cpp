class Egalitarianism3 {
    public:
        int ans;
        vector < vector<int> >  graph;
        bool visited[100];
        void dfs(vector <int> &nodes, vector<int>& okay) {
            ans = max(ans, (int) okay.size());
            for(auto i = nodes.begin(); i != nodes.end(); i++) {
                if(visited[*i]) continue;
                int tmp = -1;
                if(okay.size() >= 2) {
                    tmp = graph[okay[0]][okay[1]];
                }
                bool flag = true;
                for(auto j = okay.begin(); j != okay.end(); j++) {
                    if(tmp == -1) {
                        tmp = graph[*i][*j];
                    }
                    else if(graph[*i][*j] != tmp) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    int a = *i;
                    okay.PB(a);
                    visited[a] = true;
                    dfs(nodes, okay);
                    okay.pop_back();
                }
            }
        }

        int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
            if(n == 1 || n == 2) return n;
            graph.clear();
            graph.resize(n);
            for(int i = 0; i < n; i++) {
                graph[i].resize(n);
                for(int j = 0; j < n; j++) {
                    graph[i][j] = 1000000;
                }
                graph[i][i] = 0;
            }

            int e = a.size();
            for(int i = 0; i < e; i++) {
                a[i]--;
                b[i]--;
                graph[a[i]][b[i]] = len[i];
                graph[b[i]][a[i]] = len[i];
            }

            for(int k = 0; k < n; k++) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if(graph[i][k] + graph[k][j] < graph[i][j]) {
                            graph[i][j] = graph[i][k] + graph[k][j];
                        }
                    }
                }
            }
            ans = 0;
            vector<int> t;
            for(int i = 0; i < n; i++) t.PB(i);
            vector<int> okay;
            for(auto id = t.begin(); id != t.end(); id++) {
                int a = *id;
                okay.PB(a);
                fill(visited, visited + n, false);
                visited[a] = true;
                dfs(t, okay);
                okay.pop_back();
            }
            return ans;
        }
};