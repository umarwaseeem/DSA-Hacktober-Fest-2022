package LinkedList;

public class Duplicate {

    private  Node head;
    private Node tail;

   private static class Node {
        private int value;
        private Node next;

     public Node(int value) {
            this.value = value;
        }

    public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.value + " -> ");
            temp = temp.next;
        }
        System.out.println("END");
    }


   public void insertFirst(int val) {
    Node node = new Node(val);
 
    node.next = head;

    head = node;

    System.out.println(head.value);
}
   
public void dup(){

 Node node = head;

  while(node.next!=null)
  {
    if(node.value == node.next.value)
    node.next = node.next.next;

    else
    node= node.next;
  } 

tail = node;
tail.next = null;
}

public static void main(String[] args) {
    
    Duplicate D = new Duplicate();

  
   D.insertFirst(1);
   D.insertFirst(2);
   D.insertFirst(3);
   D.insertFirst(4);
   D.insertFirst(5);
   D.insertFirst(6);
   D.insertFirst(7);
   D.insertFirst(8);

   D.display();
   
 d.dup();
  
   D.display();

}

    
}
