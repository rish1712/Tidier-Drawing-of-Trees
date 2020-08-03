#include <vector>
using namespace std;
/*! Making a structure called node
*/
typedef struct node {
	int val;
	struct node *llink;
	struct node *rlink;
	struct node *father;
	int status;
	int modifier;
	int level;
	int x;
	int y;
	int offset;
	bool thread;
}node;
/*! Making a structure called extreme
*/
typedef struct extreme {
	node *adr;
	int offset;
	int level;
}extreme;
class tree
{
private:
	/*! Pointer to the root of the tree.*/
	node *root;
	/*! This is a private function which will make an array,such that the BST implemented from the array, is a balanced tree
	The return type of this function is void
	*/
	void ArrBST(vector <int> & , int , int, int);
	/*! This function returns the height of the tree
        the argument of this function is a pointer to a node of the tree
	*/
	int calcHeight(node *N);
	/*! This is an private function which generates a BST from a given input array,It is used by constructor calls
        this function return type is void
        the arguments of this function are the address of the vector and the no of vertices in the tree
	*/
	void initializer(vector <int>&, int n);
	/*! This function takes in the values of x and y of the parent node and draws the node
	as well as the line connecting it with the parent node
	The function does this recursively for each child of the node
	No parameters need to be passed when calling it
	*/
	void drawTree(int cx, int cy, node *N);
public:
	/*! this is a tree constructor which takes the address of the vector and the no of vertices in the tree
	*/
	tree(vector <int>&, int n);
	/*! this is a tree constructor which takes the no of vertices in the tree and the other argument will tell us whether the tree is balanced or not
        if balanced=TRUE then Balanced tree
        if balanced=FALSE then Random tree
	*/
	tree(int n, bool balanced);
	/*! This function sets up the initial conditions and calls the functions to implement tidier algorithm
	and draws the tree
	*/
	void Tidier();
	/*! Prints the tree in inorder
        the return type is void
	*/
	void printTree(node *N);
};
