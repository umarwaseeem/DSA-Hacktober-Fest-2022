// For creating Stack we use a class named Stack
class Stack{

    // We use Array to implement Stack
    constructor() {
        this.items = [];
    }

    // Functions :
    // 1. Push -> Pushes the element into the items Array
    push(element)  // We pass element as parameter
    {  
        this.items.push(element); // And push it into Stack Array
    }

    // 2. Pop -> Returns the top most element in the stack and removes it from the stack
    pop() 
    {
        if(this.items.length === 0){ // If Stack is empty return Stack Underflow
            return "Stack Underflow";
    }
        return this.items.pop(); // Else Pop top most element
    }


    // 3. Peek -> Returns the top most element but doesn't delete it
    peek()
    {
        // Only displays the top element of Stack
        return this.items[this.items.length - 1]; 
    }

    // Extra Methods:
    // 1. isEmpty() -> Returns true if Stack is Empty
    isEmpty()
    {
        return this.items.length == 0;
    }

    // 2. Size -> Returns the size of the Stack
    size()
    {
        return this.items.length;
    }

    // 3. Clear -> Empty the Stack
    clear()
    {
        this.items = [];
    }
}

    // Create a new object of Stack
    let stack = new Stack();
    
    // Adding elements into Stack
    stack.push(5);
    stack.push(15);
    stack.push(25);

    console.log(stack.isEmpty()); // Returns false

    console.log(stack.size()); // Returns 3 as current size of stack

    console.log(stack.items); // Prints the whole stack [5, 15, 25]
    
    console.log(stack.peek()); // Returns 25 as it is top element but doesn't removes it from stack

    console.log(stack.pop()); // Returns 25 as it is top element and removes it from stack

    stack.clear(); // Now the stack becomes empty -> []
    console.log(stack.items); // Empty Stack -> []

    console.log(stack.size()); // Returns 0 as current size of stack

    console.log(stack.pop()); // Returns Stack Underflow