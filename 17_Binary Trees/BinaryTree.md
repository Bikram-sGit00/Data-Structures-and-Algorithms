# 🌳 Binary Tree — Basics & Introduction

A **Binary Tree** is a non-linear data structure where each node can have **at most two children**:

- Left Child
- Right Child

Unlike arrays and linked lists, a binary tree does not store elements sequentially.

---

## 1. What is a Binary Tree?

A Binary Tree is a hierarchical data structure made up of nodes.

Each node contains:

1. Data
2. Pointer to the left child
3. Pointer to the right child

For example:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

Here:

- `1` is the **Root**
- `2` and `3` are children of `1`
- `4` and `5` are children of `2`
- `6` and `7` are children of `3`

Each node can have:

- `0` children
- `1` child
- `2` children

But never more than 2 children.

---

# 2. Why is it called a "Binary" Tree?

The word **Binary** means **two**.

In a Binary Tree, every node can have at most two children:

```text
             Node
            /    \
        Left      Right
```

So every node has two possible child positions:

```text
left  → first child
right → second child
```

A child can also be missing:

```text
       1
      /
     2
```

Here, node `1` has:

- Left child → `2`
- Right child → `NULL`

---

# 3. Basic Structure of a Binary Tree Node

In C++, we usually create a `struct` for a tree node.

```cpp
struct Node {
    int data;

    Node* left;
    Node* right;
};
```

### What does this mean?

```cpp
int data;
```

Stores the value of the node.

```cpp
Node* left;
```

Stores the address of the left child.

```cpp
Node* right;
```

Stores the address of the right child.

So visually:

```text
        Node
     ┌─────────┐
     │  data   │
     ├─────────┤
     │  left ──┼──────→ Left Child
     ├─────────┤
     │ right ──┼──────→ Right Child
     └─────────┘
```

---

# 4. Creating a Node

We can create a node dynamically using `new`.

```cpp
Node* root = new Node();

root->data = 1;
root->left = NULL;
root->right = NULL;
```

Now we have:

```text
       1
      / \
    NULL NULL
```

---

# 5. Creating a Node Using a Constructor

A cleaner way is to define a constructor inside the structure.

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
```

Now we can simply write:

```cpp
Node* root = new Node(1);
```

This automatically creates:

```text
       1
      / \
    NULL NULL
```

Because the constructor does:

```cpp
data = value;
left = NULL;
right = NULL;
```

---

# 6. Complete Basic Node Structure

This is the structure you will commonly see in Binary Tree problems:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};
```

This is the basic building block of a Binary Tree.

---

# 7. How to Create a Complete Binary Tree Manually

Suppose we want to create:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

We can create it manually like this:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

}
```

---

# 8. Understanding `root->left`

This line:

```cpp
root->left = new Node(2);
```

means:

> Create a new node containing `2` and make it the left child of `root`.

Initially:

```text
       1
      / \
    NULL NULL
```

After:

```cpp
root->left = new Node(2);
```

we get:

```text
       1
      /
     2
```

Similarly:

```cpp
root->right = new Node(3);
```

gives:

```text
       1
      / \
     2   3
```

---

# 9. Understanding `root->left->left`

Consider:

```cpp
root->left->left = new Node(4);
```

Break it from left to right:

```text
root
  ↓
1
  ↓ left
2
  ↓ left
4
```

So:

```cpp
root->left->left
```

means:

> Go to the root → go to its left child → go to that node's left child.

Therefore:

```cpp
root->left->left = new Node(4);
```

creates:

```text
       1
      /
     2
    /
   4
```

---

# 10. Tree Structure Created Using Pointers

The complete tree:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

is actually connected using pointers.

Conceptually:

```text
root
 ↓
[1]
 ↓left       ↓right
[2]          [3]
 ↓ ↓          ↓ ↓
[4][5]       [6][7]
```

Every connection between two nodes is created using a pointer.

---

# 11. Binary Tree vs Linked List

A Binary Tree is also made using dynamically allocated nodes, similar to a linked list.

### Singly Linked List

A linked-list node usually has:

```cpp
struct Node {
    int data;
    Node* next;
};
```

It has one pointer:

```text
[data | next]
```

### Binary Tree

A tree node has two pointers:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

It has:

```text
[data | left | right]
```

So the basic idea is similar:

```text
Linked List:

[data] → [data] → [data]


Binary Tree:

              [data]
             /      \
         [data]    [data]
```

The important difference is that a Binary Tree branches into two possible directions.

---

# 12. Important Terminology

Consider:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

## Root

The topmost node is called the **Root**.

```text
             1 ← Root
```

There is only one root in a tree.

---

## Parent

A node directly above another node is its **Parent**.

```text
       1
      /
     2
```

Here:

- `1` is parent of `2`

---

## Child

A node directly below another node is its **Child**.

```text
       1
      /
     2
```

Here:

- `2` is child of `1`

---

## Sibling

Nodes having the same parent are called **Siblings**.

```text
       1
      / \
     2   3
```

Here:

- `2` and `3` are siblings.

---

## Leaf Node

A node having **no children** is called a Leaf Node.

```text
             1
           /   \
          2     3
         / \
        4   5
```

Leaf nodes:

```text
4, 5, 3
```

Because they have:

```text
left = NULL
right = NULL
```

---

## Internal Node

A node having at least one child is generally called an **Internal Node**.

In the above tree:

```text
1, 2
```

are internal nodes.

---

# 13. Depth

The **depth** of a node is the number of edges from the root to that node.

Example:

```text
             1
           /   \
          2     3
         /
        4
       /
      8
```

Depth:

```text
Node 1 → depth 0
Node 2 → depth 1
Node 4 → depth 2
Node 8 → depth 3
```

So:

```text
Root always has depth = 0
```

---

# 14. Height

The **height of a node** is the number of edges on the longest path from that node to a leaf.

For example:

```text
             1
            /
           2
          /
         3
        /
       4
```

The height of the tree is:

```text
3
```

because the longest path contains 3 edges:

```text
1 → 2 → 3 → 4
```

### Important

There are two conventions for height:

### Edge-based convention

```text
Leaf height = 0
```

### Node-based convention

```text
Leaf height = 1
```

In most DSA problems, the convention will be clear from the problem or function being used.

---

# 15. Subtree

Every node can itself be considered the root of a smaller tree.

Example:

```text
             1
           /   \
          2     3
         / \
        4   5
```

The subtree rooted at `2` is:

```text
       2
      / \
     4   5
```

This idea is extremely important for recursion.

A Binary Tree can often be thought of as:

```text
Root
+
Left Subtree
+
Right Subtree
```

This is one of the most important ideas to understand before solving tree problems.

---

# 16. Basic Properties of a Binary Tree

For a Binary Tree:

### Maximum children of one node

```text
2
```

### Maximum nodes at level `L`

If root is at level `0`:

```text
2^L
```

For example:

```text
Level 0 → 1 node  → 2^0
Level 1 → 2 nodes → 2^1
Level 2 → 4 nodes → 2^2
Level 3 → 8 nodes → 2^3
```

---

# 17. Maximum Number of Nodes

If the height is `h` using the edge-based definition, the maximum number of nodes is:

```text
2^(h + 1) - 1
```

Example:

```text
h = 2

Maximum nodes
= 2^(2 + 1) - 1
= 8 - 1
= 7
```

Tree:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

---

# 18. Types of Binary Trees

These types will become important as we progress.

## 1. Full Binary Tree

Every node has either:

```text
0 children
OR
2 children
```

Never exactly one child.

Example:

```text
        1
       / \
      2   3
     / \
    4   5
```

---

## 2. Complete Binary Tree

All levels are completely filled except possibly the last level.

The last level is filled from:

```text
Left → Right
```

Example:

```text
             1
           /   \
          2     3
         / \   /
        4   5 6
```

This concept is especially important for **Heaps**.

---

## 3. Perfect Binary Tree

Every internal node has exactly two children and all leaf nodes are at the same level.

Example:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

---

## 4. Balanced Binary Tree

A Binary Tree is balanced when the height of the left and right subtrees remains reasonably close.

Example:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

Balanced trees help keep operations efficient.

---

## 5. Skewed Binary Tree

When nodes mostly extend in one direction.

### Left-skewed

```text
        1
       /
      2
     /
    3
   /
  4
```

### Right-skewed

```text
1
 \
  2
   \
    3
     \
      4
```

A skewed tree behaves almost like a linked list.

---

# 19. Binary Tree Representation

There are two common ways to represent a Binary Tree.

### 1. Linked Representation

Using pointers:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

This is the representation we will mainly use for LeetCode/GFG tree problems.

---

### 2. Array Representation

A tree can also be represented using an array.

For a complete binary tree, if a node is stored at index `i`:

```text
Left Child  → 2*i + 1
Right Child → 2*i + 2
```

when using **0-based indexing**.

This is the representation commonly used for **Heaps**.

For normal Binary Tree problems, pointer-based representation is much more common.

---

# 20. Creating a Tree Function

Instead of manually creating every node inside `main()`, we can write a function.

Example:

```cpp
Node* createTree() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    return root;
}
```

Then:

```cpp
int main() {

    Node* root = createTree();

}
```

Now `root` points to the complete tree.

---

# 21. How LeetCode Gives the Tree

In LeetCode, we usually **do not create the tree ourselves**.

LeetCode already creates the tree and passes its root to our function.

For example:

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Solve the problem here

    }
};
```

Here:

```cpp
TreeNode* root
```

is already pointing to the root of the given Binary Tree.

We only need to solve the problem.

---

# 22. LeetCode's TreeNode Structure

LeetCode commonly uses:

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
```

Conceptually, it is the same structure we created:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

The main difference is just the naming:

```text
Our code             LeetCode

data       →         val
Node       →         TreeNode
```

The basic idea is exactly the same.

---

# 23. Why Trees Are Usually Solved Using Recursion

A Binary Tree naturally contains smaller Binary Trees.

For example:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

We can think of it as:

```text
             1
           /   \
      Left      Right
    Subtree    Subtree
```

The left subtree is itself a Binary Tree:

```text
       2
      / \
     4   5
```

The right subtree is also a Binary Tree:

```text
       3
      / \
     6   7
```

So the structure naturally leads to **recursion**.

A very common pattern is:

```cpp
solve(root)
```

which performs something on:

```text
root
left subtree
right subtree
```

This recursive thinking will be extremely important in upcoming Binary Tree problems.

---

# 24. The Three Important Tree Traversals

Once we start solving Binary Tree problems, we will frequently visit every node.

The three fundamental Depth First Search traversals are:

### Preorder

```text
Root → Left → Right
```

### Inorder

```text
Left → Root → Right
```

### Postorder

```text
Left → Right → Root
```

Example:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

### Preorder

```text
1 2 4 5 3 6 7
```

### Inorder

```text
4 2 5 1 6 3 7
```

### Postorder

```text
4 5 2 6 7 3 1
```

We will study these properly with code and patterns when we start the traversal problems.

---

# 25. Breadth First Search (Level Order)

Another important way of traversing a tree is **Level Order Traversal**.

It visits nodes level by level:

```text
             1          ← Level 0
           /   \
          2     3       ← Level 1
         / \   / \
        4   5 6   7     ← Level 2
```

Traversal:

```text
1 → 2 → 3 → 4 → 5 → 6 → 7
```

Level Order is generally implemented using a:

```text
Queue
```

We will study this separately.

---

# 26. Important Binary Tree Pattern

Most Binary Tree problems can eventually be understood using a few major ideas:

```text
                    Binary Tree
                        |
          ┌─────────────┴─────────────┐
          |                           |
         DFS                         BFS
          |                           |
   ┌──────┼──────┐                    |
   |      |      |                    |
Preorder Inorder Postorder        Level Order
   |
   └──── Usually Recursion
```

Later, we will build on these ideas to solve problems involving:

- Height / Depth
- Diameter
- Balanced Tree
- Maximum Path Sum
- Lowest Common Ancestor
- Views of Binary Tree
- Boundary Traversal
- Zigzag Traversal
- Root-to-Leaf problems
- Tree Construction
- Binary Search Trees
- and more

---

# 27. Time Complexity of Basic Traversal

If a traversal visits every node exactly once:

```text
Number of nodes = N
```

Then:

```text
Time Complexity = O(N)
```

because every node is processed once.

For recursive DFS:

```text
Space Complexity = O(H)
```

where `H` is the height of the tree.

Why?

Because recursion stores the current path in the call stack.

For a balanced tree:

```text
H ≈ log N
```

For a skewed tree:

```text
H ≈ N
```

So the recursive space can be:

```text
Balanced tree → O(log N)

Skewed tree   → O(N)
```

---

# 28. Binary Tree vs Binary Search Tree

These two names are easy to confuse.

### Binary Tree

Only condition:

```text
Each node has at most 2 children.
```

There is **no ordering requirement**.

Example:

```text
        10
       /  \
      50   2
```

This is still a valid Binary Tree.

---

### Binary Search Tree (BST)

A BST has an ordering rule:

```text
Left subtree < Root < Right subtree
```

Example:

```text
        10
       /  \
      5    15
```

This is a Binary Search Tree.

We will study BSTs separately after Binary Tree fundamentals.

---

# 29. Important Things to Remember

Before starting Binary Tree problems, remember these basics:

```text
1. A Binary Tree node contains:
   data + left pointer + right pointer

2. Every node can have at most 2 children.

3. The topmost node is the Root.

4. A node with no children is a Leaf.

5. Every subtree is itself a Binary Tree.

6. Tree problems frequently use recursion.

7. DFS traversals:
   Preorder  → Root → Left → Right
   Inorder   → Left → Root → Right
   Postorder → Left → Right → Root

8. BFS:
   Level Order → Queue

9. Normal tree representation:
   Node* left
   Node* right

10. LeetCode usually gives us the root.
    We normally only write the solution function.
```

---

# 30. Basic Binary Tree Template

For practicing locally, this is a good basic template to remember:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int main() {

    // Create the root node
    Node* root = new Node(1);

    // Create the left and right children
    root->left = new Node(2);
    root->right = new Node(3);

    // Create children of node 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Create children of node 3
    root->right->left = new Node(6);
    root->right->right = new Node(7);

}
```

The tree created is:

```text
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
```

---

# 🧠 Final Mental Model

Whenever you see a Binary Tree, first think:

```text
                    root
                   /    \
               left      right
              /   \      /   \
             ...  ...   ...  ...
```

Every node follows the same structure:

```text
Node
├── data
├── left
└── right
```

And the most important idea is:

> **A Binary Tree is a collection of nodes where every node can have a left child and a right child, and each child can itself be the root of another Binary Tree.**

This recursive structure is the foundation for almost every Binary Tree problem we will solve later.
