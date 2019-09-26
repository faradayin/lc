/**
 * 0:  has not been colored yet
 * 1:  Blue
 * -1: Red
 * 
 * for each node:
 *  if it has not been colored, use a color to color it, use a different color to color its adjacent nodes
 *  if it has beeb colored, check if it is the same as the color we are going to use
 * 
 */
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        shared_ptr<vector<int>> colors(new vector<int>(n, 0));//使用智能指针管理堆里的数组
        for(int i=0; i<n; i++)
        {
            if((*colors)[i] == 0 && !validColor(graph, colors, 1, i))//当前结点用1着色，DFS 深度优先处理其邻接结点
            {
                return false;
            }
                
        }
        return true;
    }

private:
    bool validColor(vector<vector<int>>& graph, shared_ptr<vector<int>> colors, int color, int node)
    {
        if((*colors)[node] != 0)
        {
            return (*colors)[node] == color;
        }
        (*colors)[node] = color;
        for(int adj: graph[node])
        {
            if(!validColor(graph, colors, -color, adj))
                return false;
        }
        return true;
    }
};

//不要拖延了！
//做，就是现在；
//不做，以后大概也不会想做
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        for(int i=0; i<n; i++)
        {
            if(colors[i] == 0)//has not been colored
            {
                queue<int> todo;
                todo.push(i);//入队
                colors[i] = 1; 
                while(!todo.empty()) //BFS 队列管理未处理node
                {
                    int node = todo.front();
                    todo.pop();
                    for(int adj : graph[node])
                    {
                        if(colors[adj] == 0)
                        {
                            colors[adj] = -colors[node];
                            todo.push(adj);
                        }
                        else if(colors[adj] == colors[node]) return false;

                    }
                }
            }
        }
        return true;//all colored
    }
};