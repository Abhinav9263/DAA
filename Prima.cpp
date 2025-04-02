
Step 1: Initialization
Select an arbitrary starting vertex.
Create an empty set to hold the edges of the minimum spanning tree (MST).
Initialize a priority queue (or min-heap) to store edges based on their weights.
Step 2: Add Edges
Add all edges connected to the starting vertex into the priority queue.
Step 3: Select Minimum Edge
While the priority queue is not empty:
Extract the edge with the minimum weight from the queue.
Step 4: Check for Cycles
If the selected edge connects to a vertex that is not already in the MST:
Add the edge to the MST.
Add the newly connected vertex to the MST.
Add all edges connected to this new vertex into the priority queue.
Step 5: Repeat
Repeat steps 3 and 4 until all vertices are included in the MST.
Step 6: Output
The edges in the MST constitute the minimum spanning tree.



