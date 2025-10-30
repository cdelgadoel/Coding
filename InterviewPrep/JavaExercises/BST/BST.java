public class BST{
    private class Node{
        private Node left, right;
        private int value;
        // public Node(){
        //     this.left = this.right = null; 
        //     this.value = 0;
        // }
        public Node(int value){
            this.left = this.right = null; 
            this.value = value;
        }

        public Node getRight(){
            return this.right;
        }
        public Node getLeft(){
            return this.left;
        }
        public int getValue(){
            return this.value;
        }
        public void setValue(int value){
            this.value = value;
        }
        public void setRight(Node right){
            this.right = right;
        }
        public void setLeft(Node left){
            this.left = left;
        }
        public boolean shouldGoLeftOfMe(Node other){
            return other.value <= this.value;
        }
        public boolean shouldGoRightOfMe(Node other){
            return !shouldGoLeftOfMe(other);
        }
        
        public boolean equals(Node other){
            return this.value == other.value;
        }
        @Override
        public String toString(){
            StringBuilder sb = new StringBuilder();
            sb.append("Node with value: " + this.value + "\n");
            if(this.left != null)
                sb.append("Left:\n" + this.left.toString());
            if(this.right != null)
                sb.append("Right:\n" + this.right.toString());
            return sb.toString();
        }
    }

    private Node root;
    public BST(){
        root = null;
    }

    public void Add(int value){
        Node newNode = new Node(value);
        if(root == null){
            root = newNode;
            return;
        }

        Node it = root;
        while( (it.shouldGoRightOfMe(newNode) && it.right != null)
            || (it.shouldGoLeftOfMe(newNode) && it.left != null)){
            
            if(it.shouldGoLeftOfMe(newNode))
                it = it.getLeft();
            else
                it = it.getRight();
        }

        if(it.shouldGoLeftOfMe(newNode))
            it.setLeft(newNode);
        else
            it.setRight(newNode);
    }

    // public void Delete(int value){
    //     Node it = Search(value);
    //     if(it != null)

    // }

    public Node Search(int value){
        if(root == null)
            return null;
        Node searchNode = new Node(value);
        Node it = root;
        while( it != null && !it.equals(searchNode)){
            if(it.shouldGoLeftOfMe(searchNode))
                it = it.getLeft();
            else
                it = it.getRight();
        }
        return it;
    }

    @Override
    public String toString(){
        return root.toString();
    }


    public static void main(String args[]){
        BST b = new BST();
        b.Add(5);
        b.Add(2);
        b.Add(10);
        System.out.println(b.Search(20));
        System.out.println(b.toString());
    }
}