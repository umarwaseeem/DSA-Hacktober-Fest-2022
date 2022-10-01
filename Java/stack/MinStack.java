/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package stack;

/**
 * The Stack implementation that support getMin() operation that return the min value of the stack with O(1)
 * @author Warit Boonmasiri
 */
public class MinStack {
    Node head;

    public MinStack() {
        head = new Node(0, null, Integer.MAX_VALUE);
    }

    public void push(int val) {
        Node newHead = new Node(val, head, Math.min(val, head.min));
        head = newHead;
    }

    public int pop() {
        int toPop = head.val;
        head = head.next;
        return toPop;
    }

    public int top() {
        return head.val;
    }

    public int getMin() {
        return head.min;
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(10); //[10]
        System.out.println("min of stack is " +  minStack.getMin()); //should be 10
        minStack.push(5); //[10-5]
        System.out.println("min of stack is " +  minStack.getMin()); //should be 5
        minStack.push(20); //[10-5-20]
        System.out.println("min of stack is " +  minStack.getMin()); //should be 5
        minStack.push(2); //[10-5-20-2]
        System.out.println("min of stack is " +  minStack.getMin()); //should be 2
        minStack.pop(); //[10-5-20]
        System.out.println("min of stack is " +  minStack.getMin()); //should be 5
    }

    static class Node {
        int val;
        Node next;
        int min;

        Node(int val, Node next, int min) {
            this.val = val;
            this.next = next;
            this.min = min;
        }
    }
}