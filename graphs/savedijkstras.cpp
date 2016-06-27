
300
300
0
600
 : 
300
2:37:03
300
0
0
CodeFights IDE
DESCRIPTION
RULES
README
CODEWRITING
SCORE: 300/300
Consider a big city located on n islands. There are bridges connecting the islands, but they all have only one-way traffic. To make matters worse, most of the bridges are closed at night, so there is at most one bridge with traffic going from any island A to any other island B.

There is a programmer who turns a penny by working nights as an Uber driver. One night his phone dies right after he picks up a rider going from island 0 to island (n - 1). He has the map of the city bridges in his laptop though (stored as a matrix of distances), so he decides to implement an algorithm that calculates the shortest path between those two islands and evaluate the cost based on the distance of the path. Assume that each mile of the trip is 1$.

Example

For

city = [[-1, 5, 20],
        [21, -1, 10],
        [-1, 1, -1]]
the output should be nightRoute(city) = 15.

city[i][j] equals the distance between the ith and the jth islands in miles, or -1 if there is no bridge with traffic from island i to island j.

nightRoute(city) should be 15, since the shortest distance from the 0th to the 2nd island is 15. The distance from the 0th to the 1st is city[0][1] = 5, and from the 1st to the 2nd is city[1][2] = 10.

Input/Output

[time limit] 500ms (cpp)
[input] array.array.integer city

The city is represented as a square matrix, where city[i][j] equals the distance between the ith and the jth islands in miles, or -1 if there is no bridge with traffic in that direction.

Constraints:
2 ≤ city.length ≤ 10,
city[i].length = city.length,
-1 ≤ city[i][j] ≤ 30.

[output] integer

The cost of the trip. It is guaranteed that there is a route from the 0th to the (n - 1)th island.

CODE.CPP
Saved


 >=0
22
    using namespace std;
23
    int minimum = INT_MAX;
24
    int min_Val;
25
    for(int i=0; i<distance.size(); i++) {
26
        if (spanningTree[i] == false && distance[i] < minimum && validPath(i,city,spanningTree)) {
27
            minimum = distance[i];
28
            min_Val = i;
29
        }
30
    }
31
    cout << "adding " << min_Val << endl;
32
    return min_Val;
33
}
34
int nightRoute(std::vector<std::vector<int>> city) {
35
   using namespace std;
36
    int m = city.size();
37
    vector<int> dist(m,INT_MAX);
38
    vector<bool> sptSet(m, false);
39
    dist[0] = 0;
40
    for (int count=0; count<m-1; count++) {
41
        
42
        int u = minDistance(dist, sptSet, city);
43
        sptSet[u] = true;
44
        for(int v=0; v<m; v++) {
45
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + city[u][v] < dist[v] && dist[u] >= 0 && city[u][v] >=0) {
46
                dist[v] = dist[u] + city[u][v];
47
                cout << "updating distance for " << v << " to " << dist[v] << endl;
48
            }
49
        }
50
    }
51
    for (int i=0; i<dist.size(); i++) {
52
        cout << i << " " << dist[i] << endl;
53
    }
54
    
55
    return dist[m-1];
56
    
57
​
58
​
59
}
60
​
Editor
Code completion
On
Off
Auto-brackets
On
Off
Editor type
Sublime
Theme
Dark
CORRECT
TESTS
CONSOLE
7/7
All tests passed
Sample tests: 4/4
Hidden tests: 3/3
Score: 300/300
RUN SAMPLE TESTS
⌘
