# Get_Next_Line_42
This project is about programming a function that returns a line read from a file descriptor


A Good Guide regarding the concept is given by @raspurin. I would suggest everyone to look into it and understand it. 

I used a different implementation idea with Intrusive Linked List. Although it is not required but it helped me learn how to implement linked list.

## **A small visual of the concept:** ##

<img width="1891" alt="image" src="https://user-images.githubusercontent.com/66947064/183244165-8375f657-5c85-4c64-98e2-47e206932e70.png">

## Intrusive Link List: 

<img width="770" alt="image" src="https://user-images.githubusercontent.com/66947064/183244206-088c95b7-cccd-4488-ac0b-54adceb879b1.png">

Why I chose the hard way or what's the benefit doing this compared to the usual array and joining string approach:

<img width="734" alt="image" src="https://user-images.githubusercontent.com/66947064/183244646-b5e47b3f-01c0-4cea-9ad6-37642b9e6f7f.png">

 For more detailed idea.. Look into this: https://www.data-structures-in-practice.com/intrusive-linked-lists/


## Things/tools/resources I used while doing this : 

- **Debugging ( Use lldb or usual gdb)**
    Resource Link: A great resource from a fellow 42 Student from another campus(this gem was found in the slack 42 Channel. Its a gem of resources and         peer learning. Use it wisely :
    
    Link: **https://sebastienwae.github.io/debugging-42/ **

- **Intutive sense about Memory Allocation** (still learning) - Malloc or Calloc -->> 
     https://stackoverflow.com/questions/1538420/difference-between-malloc-and-calloc

- Static Variables and Allocating large memory to it .. :xD (You get **Timeout( !!! )** --> Don't be arrogant like me :xD)
 
**A Reasonable Answer by a fellow 42 Peer Ali : * *Why allocating large memory in the stack with static variable not worth it.* *

 If you are allocating a big chunk of memory as a static variable inside a function, that memory will be allocated to your software until you exit from it.  It is completely valid to do so if you are actively using that memory, like get_next_line. But if you are not using the memory you allocated, then your software will misuse the resources. I know that Mac will recognises this misuse and simply swap your memory usage to the hard drive, which causes your software to slow down. I assume that Linux and windows should have the same mechanism in place, but you have to ask others (someone with administration experience) to be sure. 
   
