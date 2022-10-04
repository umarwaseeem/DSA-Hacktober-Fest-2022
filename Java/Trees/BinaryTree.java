public class BinaryTree {
    int info;
    BinaryTree left;
    BinaryTree right;

    public BinaryTree(int info, BinaryTree left, BinaryTree right) {
        this.info = info;
        this.left = left;
        this.right = right;
    }

    public static void prefixCourse(BinaryTree bt) {
        if (bt != null) {
            System.out.print(bt.info + " ");
            prefixCourse(bt.left);
            prefixCourse(bt.right);
        }
    }

    public static void infixCourse(BinaryTree bt) {
        if (bt != null) {
            infixCourse(bt.left);
            System.out.print(bt.info + " ");
            infixCourse(bt.right);
        }
    }

    public static void postfixCourse(BinaryTree bt) {
        if (bt != null) {
            postfixCourse(bt.left);
            postfixCourse(bt.right);
            System.out.print(bt.info + " ");
        }
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree(1,
                new BinaryTree(2, new BinaryTree(4, null, null), new BinaryTree(5, null, null)),
                new BinaryTree(3, new BinaryTree(6, null, null), new BinaryTree(7, null, null)));
        System.out.print("Prefix course: ");
        prefixCourse(bt);
        System.out.println();
        System.out.print("Infix course: ");
        infixCourse(bt);
        System.out.println();
        System.out.print("Postfix course: ");
        postfixCourse(bt);
        System.out.println();
    }

}
