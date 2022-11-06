class LinkedListItem {
    constructor(value, next) {
      this.value = value;
      this.next = next;
    }
  }
  
  class LinkedList {
    constructor() {
      this.head = null;
    }
    prepend(value) {
      const newItem = new LinkedListItem(value, this.head);
      this.head = newItem;
    }
    find(value) {
      if (!this.head) {
        return null;
      }
      let currentNode = this.head;
      while (currentNode) {
        if (currentNode.value === value) {
          return currentNode;
        }
        currentNode = currentNode.next;
      }
    }
    deleteHead() {
      if (this.head) {
        if (this.head.next) {
          const secondNode = this.head.next;
          this.head = secondNode;
        } else {
          this.head = null;
        }
      }
    }
    print() {
      let currentNode = this.head;
      while (currentNode) {
        console.log(currentNode.value);
        currentNode = currentNode.next;
      }
    }
  }