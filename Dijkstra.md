# Shortest Path Algorithm (Dijkstra)

## Problem
You have several unique points. 
Each point is connected to one or more other points.
Each connection has a cost to traverse it.
You want to get from specific point to another specific point at the smallest possible cost. 

## Solution

### Problem model
The points and their connections are described by a weighted graph.
A weighted graph consists of many nodes. The nodes represent the points of the problem and are themselves represented by a unique alphanumerical identifier. 
Each node has one or many edges. The edges represent the connections of the problem.
Each edge has one weight. The weight represents the cost of the problem and is itself represented by a non-negatve integral number.  
Each edge has one endpoint. The endpoint is another node.

### Solution model
The start node is picked. 

From now on, each node that is picked is assigned one label. 
Each label has one field for a node, one field for a weight and one field for the status.
The node field is meant to hold the preceding node on the path from the destination node or nothing.  
The weight field is meant to hold the accumulated weight of the entire path from the destination node.
The status must be either tentative or permanent. 
When a label is first assigned to a node, the status is set to tentative. 

The desitination node is assigned a label.
The node field of the label is set to nothing. 
The weight field of the label is set to 0.
The destination node is picked as the current working node. 

The following steps are repeated until the current working node is the start node.

&nbsp;&nbsp;The node of each edge of the current working node is inspected.\
&nbsp;&nbsp;If it has a label and the status is permanent, the node of the next edge is inspected.\
&nbsp;&nbsp;Else the sum of the sum of the weihgt in the current working node's label and the weight of the edge is calculated.\
&nbsp;&nbsp;If the inspected node has a label, the calculated sum is compared to the weight in the inspected node's label.\
&nbsp;&nbsp;If the sum is less than the weight in label, the weight is set to the sum and the node field of the inspected nodes's tag is set to the current working node.\
&nbsp;&nbsp;If the inspected node has no label, one is assgined with the node field set to the current working node, the weight field to infinity and the status to tentative.\
&nbsp;&nbsp;
&nbsp;&nbsp;After all edges are inspected, the node with the smallest weight stored in its label has its status set to permanent and is picked as the next current working node.\
&nbsp;&nbsp;
Once the start node is picked as the current working node, the shortest path from start node to destination node is found.\
The path can be obtained by beginning with the start node, then repeatedly going to the preceding node, that is stored in the label until the destination node is reached.\
&nbsp;&nbsp;The node of each edge of the current working node is inspected.
&nbsp;&nbsp;f it has a label and the status is permanent, the node of the next edge is inspected.
&nbsp;&nbsp;lse the sum of the sum of the weihgt in the current working node's label and the weight of the edge is calculated.
&nbsp;&nbsp;f the inspected node has a label, the calculated sum is compared to the weight in the inspected node's label. 
&nbsp;&nbsp;f the sum is less than the weight in label, the weight is set to the sum and the node field of the inspected nodes's tag is set to the current working node. 
&nbsp;&nbsp;f the inspected node has no label, one is assgined with the node field set to the current working node, the weight field to infinity and the status to tentative.
&nbsp;&nbsp;
&nbsp;&nbsp;fter all edges are inspected, the node with the smallest weight stored in its label has its status set to permanent and is picked as the next current working node.
&nbsp;&nbsp;
Once the start node is picked as the current working node, the shortest path from start node to destination node is found. 
The path can be obtained by beginning with the start node, then repeatedly going to the preceding node, that is stored in the label until the destination node is reached. 
