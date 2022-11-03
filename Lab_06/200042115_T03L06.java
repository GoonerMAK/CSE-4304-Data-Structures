import java.util.Scanner;


class BinarySearchTree
{
    static class Node
    {
        int key;
        Node left, right;
    }

    static Node newNode(int data)
    {
        Node node = new Node();

        node.key = data;

        node.left = null;
        node.right = null;

        return node;
    }




    static Node insert(Node root, int key)
    {
        // Create a new Node containing
        // the new element
        Node new_node = newNode(key);

        // Pointer to start traversing from root and
        // traverses downward path to search
        // where the new node to be inserted
        Node parent = root;

        // Pointer child maintains the trailing
        // pointer of parent
        Node child = null;

        while (parent != null)
        {
            child = parent;


            if (key < parent.key)
                parent = parent.left;

            else
                parent = parent.right;

        }



        // If the root is null i.e. the tree is empty
        // The new node is the root node
        if (child == null)
            child = new_node;

        // If the new key is less than the leaf node key
            // Assign the new node to be its left child
        else if (key < child.key)
            child.left = new_node;

        // else assign the new node its right child
        else
            child.right = new_node;


        // Returns the pointer where the
        // new node is inserted
        return child;
    }



    /* Compute the "height" of a tree -- the number of nodes along the longest path from the root node
       down to the farthest leaf node.*/
    static int height(Node root)
    {
        if (root == null)
            return 0;
        else
        {
            /* compute  height of each subtree */
            int left_height = height(root.left);
            int right_height = height(root.right);

            /* use the larger one */
            if (left_height > right_height)
                return (left_height + 1);
            else
                return (right_height + 1);
        }
    }


    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int n, i=0;

        Node root = null;

        while( (n = input.nextInt()) != -1 )
        {
            if(i==0)
            {
                root = insert(root, n);
                i++;
            }

            else
            {
                insert(root, n);
            }

        }


        System.out.println(height(root) - 1);

    }

}


// 50 75 53 25 60 29 45 42 28 10 -1