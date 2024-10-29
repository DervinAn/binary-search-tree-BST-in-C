#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int data) {
    // if the tree is empty, return a new-node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise recur down the tree (bottom)
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }


    return root;
}

void display_BST(struct Node* racine){

    if(racine == NULL) return;
    printf("%d",racine->data);
    display_BST(racine->left);
    display_BST(racine->right);

}
void display_BST_inLevel(struct Node* racine){

    if(racine == NULL) return;
    printf("%d",racine->data);
    printf("%d",racine->left->data);
    printf("%d",racine->right->data);
    display_BST_inLevel(racine->left);
    display_BST_inLevel(racine->right);

}



// Function to draw the BST
void drawTree(struct Node* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 5;

    // Process right child first
    drawTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" "); // Print space for tree structure
    }
    printf("%d\n", root->data); // Print node data

    // left child
    drawTree(root->left, space);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 13);
    insert(root, 28);
    insert(root, 37);
    insert(root, 44);
    insert(root, 53);
    insert(root, 66);
    insert(root, 84);






    printf("In-order traversal of the binary search tree: ");
    //inOrder(root);
    display_BST(root);
    printf("\n");
    drawTree(root,0);

    return 0;
}














// Function to print the binary search tree in in-order traversal
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
