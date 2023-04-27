#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  /*
  Outputs the tree InOrder. i.e. left,key,right
  Args:
    root (node *) : The root of the tree to be printed out

  Returns:
    -
  */


  // Check that the root is not null
  if (root != nullptr) {
    // First traverse the left sub tree
    traverseInOrder(root->left);

    // Output the key of the root
    cout << root->key << " ";

    // Traverse the right sub tree
    traverseInOrder(root->right);
  }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  /*
  Inserts a new node with the key, returns the root
  Args:
    node (node *) : The root node of the tree to which the value is inserted
    key (int)     : The key of the node to be inserted

  Returns:
    node (node *) : The root of the tree

  */

  // Case 1: The root is null, i.e. the tree is empty
  if (node == nullptr) {
    // Create a new node by allocating memory
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    // Set the key of the new node
    new_node->key = key;

    return new_node;

  // Case 2: The key is less than root key
  } else if (key < node->key) {
    // Use recursion to insert the key into the left subtree
    node->left = insertNode(node->left, key);

    return node;

  // Case 3: The key is greater than the root key
  } else if (key > node->key) {
    // Use recursion to insert the key into the right subtree
    node->right = insertNode(node->right, key);

    return node;

  // Case 4: The key is equal to the root key  
  } else {
    // In this case do nothing since the key already exists within the BST
    return node;
    
  }

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  /*
  Deletes the node with key, returns root
  Args:
    root (node *) : The root of the tree
    key (int)     : Key of the node to be deleted

  Returns:
    root (node *) : The root of the updated tree
  */

  // Case 1: Root is null
  if (root == nullptr) {
    return root;

  // Case 2: Key is less than the root key
  } else if (key < root->key) {
    // Use recursion to delete key from the left subtree
    root->left = deleteNode(root->left, key);

    return root;

  // Case 3: Key is greater than the root key
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);

    return root;

  // Case 4 : Key is equal to the root key
  } else {
    // Consider three cases under this case

    // Case 4.1 : The root has no child nodes
    if (root->left == nullptr && root->right == nullptr) {
      // In this case, free the root and return the nullptr
      free(root);
      return nullptr;
      
    // Case 4.2 : The root has only one child
    // In that case return the child node that exists and free the root from memory
    } else if (root->left == nullptr) {
      node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == nullptr) {
      node *temp = root->left;
      free(root);
      return temp;

    // Case 4.3 : The root has both left and right child nodes
    } else {

      // First find the minimum of the right subtree to replace the current node with
      node *min = root->right;
      while (min->left != nullptr) {
        min = min->left;
      }

      // Set the key of the root to the min key
      root->key = min->key;

      // Delete the current node from the right subtree
      root->right = deleteNode(root->right, min->key);

      return root;
    }


  }
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}