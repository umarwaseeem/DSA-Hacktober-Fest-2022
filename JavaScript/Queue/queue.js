// Like Stack we also create a class named Queue for creating Queue
class Queue{

    // Similar to stack, we use array to implement queue
    constructor()
    {
        this.items = [];
    }

    // Functions in Queue:
    // 1. Enqueue -> To add element at the rear of the Queue
    enqueue(element)
    {
        return this.items.push(element);
    }

    // 2. Dequeue -> To return element from front of the Queue and remove it
    dequeue()
    {
        if(this.items.length == 0){
            return "Underflow"; // If Queue is empty return Underflow
        }
        return this.items.shift(); // Shift method removes the element from queue
    }

    // 3. front() -> This returns the front element of the Queue without removing it
    front()
    {
        if(this.items.length == 0){
            return "No elements present";
        }
        return this.items[0];
    }

    // Extra Methods to make tasks easier:
    // 1. isEmpty() -> Returns true if Queue is empty
    isEmpty()
    {
        return this.items.length == 0;
    }

    // 2. size() -> Returns the size of Queue
    size()
    {
        return this.items.length;
    }

    // 3. clear() -> Empty the Queue
    clear()
    {
        this.items = [];
    }
}

    // Create object of Queue Class
    let queue = new Queue();

    // For empty Queue
    console.log(queue.dequeue()); // Returns Underflow

    console.log(queue.isEmpty()); // Returns true


    // Adding elements in Queue
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);
    queue.enqueue(25);

    console.log(queue.front()); // Returns 5 as it was inserted first in queue but doesn't removes it

    console.log(queue.items); // Returns all items of queue

    queue.dequeue(); //Returns front element -> 5 and removes it from queue

    console.log(queue.isEmpty()); // Returns false as queue is not empty

    console.log(queue.size()); // Returns 4

    queue.clear(); // queue becomes empty -> []
    console.log(queue.items); // Returns empty array -> []
