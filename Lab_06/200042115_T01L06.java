import java.util.*;

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

        int flag = 1;

        while (parent != null)
        {
            child = parent;

            if( key >= parent.key-3  &&  key <= parent.key+3)   // the condition of a valid reservation
            {
                flag = 0;
                break;
            }

            else
            {
                if (key < parent.key)
                    parent = parent.left;

                else
                    parent = parent.right;
            }

        }


        if(flag == 1)
        {
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
        }


        // Returns the pointer where the
        // new node is inserted
        return child;
    }


    static void Inorder(Node root)
    {
        if (root == null)
            return;
        else {
            Inorder(root.left);
            System.out.print(root.key + " ");
            Inorder(root.right);
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


        // Print inorder traversal of the BST
        Inorder(root);
        
    }

}


// 50 75 53 25 60 29 45 42 28 10 -1






/*static void LeftMostNode(Node root, int count)
    {

        for(int i=0 ; i<count ; i++)
        {
            Node node = root;

            Node parent = null;

            while(node != null)
            {
                parent = node;

                node = node.left;

            }

            System.out.println(parent.key);

            parent.key = 0;
        }



    }*/


// LeftMostNode(root, count);
