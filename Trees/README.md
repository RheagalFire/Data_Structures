## TREES

### Patterns and Algorithms 

#### Hieght and Diameter
  - Hieght = Distance from Leaf node to root node.
    - Recurse Left Hieght and Right Hieght for each recursion call increase by 1 and check the max of         left and right hieght.
    ```
    if(root==NULL)
    {
      return 0;
    }
    int lhieght=Hieght(root->left);
    int rhieght=Hieght(root->right);
    return max(lhieght,rhieght)+1;
    ```
 - Diameter = Distance Between two farthest leaf Nodes. 
   - Calculate left and right Hieght and sum them to get the current Hieght. 
   - Two Cases = LH+RH+1(when diam passes through root Node) else max(ldiam,rdiam)
   - Calculate left and right diameter. 
   - Return the max(current_Hieght,max(ldiam,rdiam))
    ```
    if(root==NULL)
	{
		return 0;
	}

	int lhieght=Hieght(root->left);
	int rhieght=Hieght(root->right);
	int cur_h=lhieght+rhieght+1;

	int ldiam=diameter(root->left);
	int rdiam=diameter(root->right);

	return max(cur_h,max(ldiam,rdiam));
	
    ```  
    
#### Flatten a Binary Tree

- Base condition Root==NULL or root->right and root->left == NULL
- Check if the Node has a Left subtree.
- Store the Right stree of the current node in a temp variable.
- Make the Right of Node point to left of that Node hence detaching the left stree of that Node making it NULL.
- Traverse the currently transitioned left -> right tree until the end and Join the temp with the tail.
  ```
	  void flatten(Node* root)
	{
		if(root==NULL || (root->left==NULL && root->right==NULL))
		{
			return;
		}
		if(root->left!=NULL)
		{
			flatten(root->left);
			Node* temp=root->right;
			root->right=root->left;
			root->left=NULL;

			Node* t=root->right;
			while(t->right!=NULL)
			{
				t=t->right;
			}
			t->right=temp;
		}
		flatten(root->right);

	}
  ```
  
