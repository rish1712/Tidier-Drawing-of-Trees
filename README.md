# Tidier-Drawing-of-Trees
Tidier Drawings of Trees as suggested by  EDWARD M. REINGOLD AND JOHN S. TILFORD in C++ using Open Gl libraries.
# Basic-Methodology
The major part in implementing this algorithm is the postorder traversal of the tree. During the traversal the procedure performs three tasks at each node T: first it determines how close together the subtrees of T can be placed; second, it keeps track of nodes that may need to be threaded later; and third, it inserts a thread if one is required.
Threads are a method for reducing the amount of time it takes to scan a subtree for its contour by creating links between nodes on the contour if one is not already the child of the other. We can also take advantage of the fact that, if the one tree is deeper than the other, we only need to descend as far as the shorter tree. Anything deeper than that will not affect the separation necessary between the two trees, since there can be no conflicts between them. Using threads and only traversing as deeply as we need to.
## How-the-Algorithm-Works<br>
### Tree Class
This class is the crux of the whole project. The setup_tdr function calculates all offsets for the tidier algorithm. This class contains the method which basically does a post order traversal for the tree and find the relative distance between them. After all these calculations Bresenham line and circle drawing algorithm are called which are implemented in Primitive Class.
### Primitive Class<br>
This class implements the Bresenham line and circle drawing algorithm which are used in making trees.
### Main Method
The main function basically handles the input for the different Tree models. We have tried to implement 3 different models as follows:
-<br>A balanced binary tree<br>
-A random tree using random genrator<br>
-A BST
