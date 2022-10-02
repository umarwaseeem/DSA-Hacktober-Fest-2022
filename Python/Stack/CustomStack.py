# Create Your Own Stack with Custom Size and data

size = int(input("Enter The Size Of The Stack."))  # Size input
stack = []
while True:
    print("Press 1 to Push into stack.")
    print("Press 2 to Pop from stack.")
    print("Press 0 to exit.")

    op = int(input())
    if op == 1:
        if len(stack) == size:
            print("Cannot push into stack because stack is full.")
        else:
            val = int(input("Enter the value to push into stack."))
            stack.append(val)
    elif op == 2:
        if not stack:
            print("Cannot pop from stack because stack is empty.")
        else:
            print(stack.pop())
    else:
        print("exiting.....")
        break
    print("Current State of the stack.")
    for i in range(len(stack) - 1, -1, -1):
        print("\t| {} |".format(stack[i]))
