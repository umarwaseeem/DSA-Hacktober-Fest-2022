# importing "collections" for deque operations
import collections
 
# initializing deque
de = collections.deque([1,2,3])
 
# using append() to insert element at right end
# inserts 4 at the end of deque
de.append(4)
 
# printing modified deque
print("The deque after appending at right is : ")
print(de)
 
# using appendleft() to insert element at left end
# inserts 6 at the beginning of deque
de.appendleft(6)
 
# printing modified deque
print("The deque after appending at left is : ")
print(de)
 
# using pop() to delete element from right end
# deletes 4 from the right end of deque
de.pop()
 
# printing modified deque
print("The deque after deleting from right is : ")
print(de)
 
# using popleft() to delete element from left end
# deletes 6 from the left end of deque
de.popleft()
 
# printing modified deque
print("The deque after deleting from left is : ")
print(de)