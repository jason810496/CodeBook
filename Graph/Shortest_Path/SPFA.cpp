vector<pair<int,int>> g[200005]; // adjacent list
int update[200005]; // couting the update(relex) times of vertexs.
int in_queue[200005];
int v,e; // the counts of vertex and edge.

int dis[200005]; // shortest path

void SPFA(int start)
{
    queue<int> q;
    q.push(start);
    in_queue[start] = 1;

    while( q.size() != 0 )
    {
        int ouo = q.front();
        q.pop();
        in_queue[ouo] = 0;
        for( auto i : g[ouo] )
        {
            if( dis[ouo] + i.second < dis[i.first] ) // relex
            {
                dis[i.first] = dis[ouo] + i.second;
                update[i.first]++;
                if( in_queue[i.first] == 0 )
                {
                    q.push(i.first);
                    in_queue[i.first] = 1;
                }
            }
        }
    }

    for(int i=1;i<=v;i++)
    {
        if( update[i] > v - 1 ) // the graph have one or more negative circle.
    }
}
