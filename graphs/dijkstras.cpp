
/*
int findRoute(std::vector<std::vector<int>> &city, int index) {
    using namespace std;
    if (index == city.size()-1) return 1000000;
    int m = city.size();
    int n = city[0].size();
    int nextFind = city[index][index+1] + findRoute(city, index+1);
    cout << nextFind << endl;
    return min(city[index][n-1], nextFind);
}*/
int minDistance(std::vector<int> & distance, std::vector<bool> & spanningTree) {
    using namespace std;
    int minimum = INT_MAX;
    int min_Val;
    for(int i=0; i<distance.size(); i++) {
        if (spanningTree[i] == false && distance[i] < minimum) {
            minimum = distance[i];
            min_Val = i;
        }
    }
    cout << "adding " << min_Val << endl;
    return min_Val;
}
int nightRoute(std::vector<std::vector<int>> city) {
   using namespace std;
    int m = city.size();
    vector<int> dist(m,INT_MAX);
    vector<bool> sptSet(m, false);
    dist[0] = 0;
    for (int count=0; count<m-1; count++) {
        
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for(int v=0; v<m; v++) {
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + city[u][v] < dist[v] && dist[u] >= 0) {
                dist[v] = dist[u] + city[u][v];
            }
        }
    }
    for (int i=0; i<dist.size(); i++) {
        cout << i << " " << dist[i] << endl;
    }
    
    return dist[m-1];
    


}

