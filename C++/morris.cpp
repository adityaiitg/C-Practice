#include<bits/stdc++.h>
using namespace std;
typedef struct Node { 
	int val; 
	struct Node* left; 
	struct Node* right; 
} Node; 
	/* Constructed binary tree is 
			5 
		   / \ 
	      3   6 
         / \ 
	    1   4 
*/
vector<int> MorrisTraversal(Node* root) 
{ 
    vector<int> ans;
	Node *current, *pre; 
	if (root == NULL) 
		return ans;
	current = root; 
	while (current != NULL) { 
		if (current->left == NULL){ 
			ans.push_back(current->val); 
			current = current->right; 
		} 
			/* Constructed binary tree is 
			5 
		   / \ 
	      c3   6 
         / \ 
	   p1   4 
*/
		else { 
			/* Find the inorder predecessor of current */
			pre = current->left; 
			while (pre->right != NULL && pre->right != current) 
				pre = pre->right; 

			/* Make current as the right child of its inorder 
			predecessor */
			if (pre->right == NULL) { 
				pre->right = current; 
				current = current->left; 
			}
	/* Constructed binary tree is 
			5 
		   / \ 
	      c3   6 
         / \ 
	    1   4p 
*/
			/* Revert the changes made in the 'if' part to restore 
			the original tree i.e., fix the right child 
			of predecessor */
			else { 
				pre->right = NULL; 
				ans.push_back(current->val);
				current = current->right;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	}
	/* End of while */
	return ans;
} 

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the 
given data and NULL left and right pointers. */
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->val = data; 
	node->left = NULL; 
	node->right = NULL; 

	return (node); 
} 
#define TreeNode Node
vector<int> inorderTraversal(TreeNode* A) {
    vector<int> ans;
    TreeNode* curr=A;
    TreeNode* prev;
    while(curr!=NULL){
       if(curr->left==NULL){
           ans.push_back(curr->val);
           curr=curr->right;
       }else{
           prev=curr->left;
           while(prev->right!=NULL&&prev->right!=curr){
               prev=prev->right;
           }
           if(prev->right==NULL){
               prev->right=curr;
               curr=curr->left;
           }else{
               prev->right=NULL;
               ans.push_back(curr->val);
               curr=curr->right;
           }
       }
    }
   return ans;
}

int main() 
{ 

	/* Constructed binary tree is 
			5 
		   / \ 
	      3   6 
         / \ 
	    1   4 
*/
	Node* root = newNode(5); 
	root->left = newNode(3); 
	root->right = newNode(6); 
	root->left->left = newNode(1); 
	root->left->right = newNode(4); 

	vector<int> B=MorrisTraversal(root); 
    for(int i=0;i<B.size();i++){
		cout<<B[i]<<endl;
	}
	return 0; 
} 
