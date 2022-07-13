We just have to find if our graph contains cycle or not because if graph contains cycle then all tnodes in cycle are interdependent and 1 course cannot be completed because its prerequisite is dependent on other course and it goes on .
We used coloring algorithm to find if there is cycle in graph or not.
​
Coloring Algorithm
vis[id]=0 is used for node which is not yet visited, vis[id]=1 is used for the node which is visited and currently its child nodes are being visited and vis[id]=2 done when all the child nodes of a node ("id") are visited and the function returns to parent node of node ("id"). So at that time it is marked as 2 because this node does not require any further traversing.