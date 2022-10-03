
class largeSmall
{
	
/* Linked list node */
static class Node
{
	int data;
	Node next;
}
static Node head = null;

// Function that returns the largest element
// from the linked list.
static int largestElement(Node head)
{
	
	// Declare a max variable and initialize
	// it with INT_MIN value.
	// INT_MIN is integer type and its value
	// is -32767 or less.
	int max = Integer.MIN_VALUE;

	// Check loop while head not equal to NULL
	while (head != null)
	{

		// If max is less than head->data then
		// assign value of head->data to max
		// otherwise node point to next node.
		if (max < head.data)
			max = head.data;
		head = head.next;
	}
	return max;
}

// Function that returns smallest element
// from the linked list.
static int smallestElement(Node head)
{
	
	// Declare a min variable and initialize
	// it with INT_MAX value.
	// INT_MAX is integer type and its value
	// is 32767 or greater.
	int min = Integer.MAX_VALUE;

	// Check loop while head not equal to NULL
	while (head != null)
	{

		// If min is greater than head->data then
		// assign value of head->data to min
		// otherwise node point to next node.
		if (min > head.data)
			min = head.data;

		head = head.next;
	}
	return min;
}

// Function that push the element in linked list.
static void push(int data)
{
	// Allocate dynamic memory for newNode.
	Node newNode = new Node();

	// Assign the data into newNode.
	newNode.data = data;

	// newNode->next assign the address of
	// head node.
	newNode.next = (head);

	// newNode become the headNode.
	(head) = newNode;
}

// Display linked list.
static void printList(Node head)
{
	while (head != null) {
		System.out.print(head.data + " -> ");
		head = head.next;
	}
	System.out.println("NULL");
}

// Driver code
public static void main(String[] args)
{
	// Start with empty list
	// head = new Node();

	// Using push() function to construct
	// singly linked list
	// 17->22->13->14->15
	push( 15);
	push( 14);
	push( 13);
	push( 22);
	push( 17);
	System.out.println("Linked list is : ") ;

	// Call printList() function to
	// display the linked list.
	printList(head);
	System.out.print("Maximum element in linked list: ");

	// Call largestElement() function to get
	// largest element in linked list.
	System.out.println(largestElement(head));
	System.out.print("Minimum element in linked list: ");

	// Call smallestElement() function to get
	// smallest element in linked list.
	System.out.print(smallestElement(head));
}
}

// This code is contributed by Prerna saini.
