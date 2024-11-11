// Binary search tree
#include <stdio.h>
#include <stdlib.h>

struct BstTree
{
    int data;
    struct BstTree *left, *right;
};

struct BstTree *insert_bst(struct BstTree *tree, int value)
{
    if (tree == NULL)
    {
        tree = (struct BstTree *)malloc(sizeof(struct BstTree));
        tree->data = value;
        tree->left = tree->right = NULL;
        return tree;
    }
    else if (value < tree->data)
    {
        tree->left = insert_bst(tree->left, value);
    }
    else
    {
        tree->right = insert_bst(tree->right, value);
    }
    return tree;
}

// finding a the node for deletion
struct BstTree *find(struct BstTree *tree, int value, struct BstTree **loc, struct BstTree **parent)
{
    struct BstTree *ptr, *save;
    if (tree == NULL)
    {
        (*loc) = (*parent) = NULL;
        return NULL;
    }
    else if (tree->data == value)
    {
        (*loc) = tree;
        (*parent) = NULL;
        return tree;
    }
    else if (value < tree->data)
    {
        ptr = tree->left;
        save = tree;
    }
    else
    {
        ptr = tree->right;
        save = tree;
    }
    while (ptr != NULL)
    {
        if (value == ptr->data)
        {
            (*loc) = ptr;
            (*parent) = save;
            return tree;
        }
        else if (value < ptr->data)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else
        {
            save = ptr;
            ptr = ptr->right;
        }
    }
    return tree;
}

struct BstTree *delA(struct BstTree *tree, struct BstTree *loc, struct BstTree *parent)
{
    struct BstTree *child;
    if ((loc->right == NULL) && (loc->left == NULL))
    {
        child = NULL;
    }
    else if (loc->left != NULL)
    {
        child = loc->left;
    }
    else
    {
        child = loc->right;
    }

    if (parent != NULL)
    {
        if (loc == parent->left)
            parent->left = child;
        else
            parent->right = child;
    }
    else
    {
        tree = child;
    }

    free(loc);
    return tree;
}

struct BstTree *delB(struct BstTree *tree, struct BstTree *loc, struct BstTree *parent)
{
    struct BstTree *save, *ptr, *suc, *parentSuc;
    ptr = loc->right;
    save = loc;
    while (ptr->left != NULL)
    {
        save = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parentSuc = save;
    delA(tree, suc, parentSuc);

    if (parent != NULL)
    {
        if (loc == parent->left)
            parent->left = suc;
        else
            parent->right = suc;
    }
    else
    {
        tree = suc;
    }

    suc->left = loc->left;
    suc->right = loc->right;
    free(loc);
    return tree;
}

struct BstTree *delfrom_bst(struct BstTree *tree, int value)
{
    struct BstTree *loc = NULL, *parent = NULL;
    find(tree, value, &loc, &parent);
    if (loc == NULL)
    {
        printf("Value not found \n");
        return tree;
    }
    if ((loc->right != NULL) && (loc->left != NULL))
    {
        return delB(tree, loc, parent);
    }
    else
    {
        return delA(tree, loc, parent);
    }
}

void traverseInorder(struct BstTree *tree)
{
    if (tree != NULL)
    {
        traverseInorder(tree->left);
        printf("%d ", tree->data);
        traverseInorder(tree->right);
    }
}

void traversePreorder(struct BstTree *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        traversePreorder(tree->left);
        traversePreorder(tree->right);
    }
}

void traversePostorder(struct BstTree *tree)
{
    if (tree != NULL)
    {
        traversePostorder(tree->left);
        traversePostorder(tree->right);
        printf("%d ", tree->data);
    }
}

int internal_count(struct BstTree *tree)
{
    if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
    {
        return 0;
    }
    else
    {
        return (internal_count(tree->left) + internal_count(tree->right) + 1);
    }
}
int nodeCount(struct BstTree *tree)
{
    if (tree == NULL)
        return 0;
    else
        return (nodeCount(tree->left) + nodeCount(tree->right) + 1);
}

int smallest(struct BstTree *tree)
{
    if (tree == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    if (tree == NULL || tree->left == NULL)
    {
        return tree->data;
    }
    else
    {
        return smallest(tree->left);
    }
}

int largest(struct BstTree *tree)
{
    if (tree == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    if (tree == NULL || tree->right == NULL)
    {
        return tree->data;
    }
    else
    {
        return largest(tree->right);
    }
}

int calcHeight(struct BstTree *tree)
{
    int leftH, rightH;
    if (tree == NULL)
        return 0;
    else
    {
        leftH = calcHeight(tree->left);
        rightH = calcHeight(tree->right);
        if (leftH > rightH)
            return (leftH + 1);
        else
            return (rightH + 1);
    }
}

int leafCount(struct BstTree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 1;
    }
    else
    {
        return (leafCount(tree->left) + leafCount(tree->right));
    }
}

int main()
{
    struct BstTree *tree;
    tree = NULL;
    int value, choice, count;
    do
    {
        printf("\n Menu \n");
        printf("01. Insertion \n");
        printf("02. Preorder traversel \n");
        printf("03. Inorder Traversel \n");
        printf("04. Postorder Traversel \n");
        printf("05. Deletion of a node \n");
        printf("06. Counting Leaf node \n");
        printf("07. Counting internal nodes \n");
        printf("08. Counting total nodes \n");
        printf("09. Calculating height \n");
        printf("10. Find minimum value \n");
        printf("11. Find Maximum value \n");
        printf("12. Exit \n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value :");
            scanf("%d", &value);
            tree = insert_bst(tree, value);
            break;
        case 2:
            traversePreorder(tree);
            break;
        case 3:
            traverseInorder(tree);
            break;
        case 4:
            traversePostorder(tree);
            break;
        case 5:
            printf("Enter the value you want to delete:");
            scanf("%d", &value);
            tree = delfrom_bst(tree, value);
            break;
        case 6:
            count = leafCount(tree);
            printf("Total no of the Leaf nodes : %d", count);
            break;
        case 7:
            count = internal_count(tree);
            printf("Total no of the internal nodes : %d", count);
            break;
        case 8:
            count = nodeCount(tree);
            printf("Total no of nodes : %d", count);
            break;
        case 9:
            count = calcHeight(tree);
            printf("The height of the tree : %d", count);
            break;

        case 10:
            count = smallest(tree);
            if (count != -1) // Check if tree is empty
                printf("Smallest value: %d\n", count);
            break;

        case 11:
            count = largest(tree);
            if (count != -1)
                printf("Largest value: %d\n", count);
            break;
        case 12:
            printf("Exit ");
            break;
        default:
            printf("Invalid operation ");
            break;
        }
    } while (choice != 12);

    return 0;
}