We are able to do this question using both DFS and BFS.
Just one important thing we have to consider here that, Suppose we are standing on any particular node and we want to make a copy of the node then we have to keep a record that whether the copy of this node is already created or not.
See, we try to move in neighbor and creating a copy of node, so if two nodes are neighbour of each other, say 1 and 2, then node 1 say okay, node 2 is my neighbour so when i move to this then i have to create a copy and we create a copy of node 2 and since we are on the node 1so for node 1 we also create a copy.
Now, we move further to node 2, then node 2 say okay, i have to create my copy, but as well as since 1 is also my neighbour so i also have to create the copy of node1.
In this way, for only both of the nodes, we create copies and this is the problem that we want to avoid.
Also, if we create a copy, then being a good neighbor, we find whether our neighbor have a copy or not, so we will travel all around our adjcant.
See commented code for more explanation.