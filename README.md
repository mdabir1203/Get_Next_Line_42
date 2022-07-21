# Get_Next_Line_42

**N:B:** If you have any suggestions how to optimize and making it more cleaner . Please let me know :)


This project is about programming a function that returns **a line read from a file descriptor**

It is a similar function related to original c function called getline() -- >> 

1. You can read a string or a line through it in an input string
 
 Function Prototype:
 ` char *get_next_line(int fd) `
 
 Research Cheatsheets:
  Calloc vs Malloc 

<p float="left">
  <img src="https://user-images.githubusercontent.com/66947064/180113701-725339a3-8602-4041-8345-acb6292ca95d.png" width="500" />
  <img src="https://user-images.githubusercontent.com/66947064/180113620-7a67c849-809b-4b69-bf0a-c46b32b54152.png" width="500" /> 
</p>

 Functions used to implement similar to original C functions: 
 1. ft_calloc (To use the heap memory and initialize them) -->> This is more secure than malloc but lacks in speed performance.
 2. ft_memcpy
 3. ft_memset
 4. ft_bzero( To initialize values)
 5. ft_strcat (to append strings) -->> ft_strjoin can also be used. -->> found its faster than concatenation as no new strings has to be created. Also strcat might cause double printing of values. Avoid it.
 
 -->> Have 2 Macros -->> One for Buffer Size which determines how many characters should be read when func called and Max Line -->> To say how many characters we can take from the input. 
 
 # Static Variables : 
 
  Source: Tutorialpoint
 ![image](https://user-images.githubusercontent.com/66947064/180117081-77f5d9d3-b455-404d-afb2-549a65c28e44.png)

 ``Ques: If allocating a big memory for static variable is good or not ? ``
  ![image](https://user-images.githubusercontent.com/66947064/180116309-e9e7ace1-1696-4b45-b774-93ee8a061102.png)
 #Source: 42 Student

## Extras I learned:
#Checking Memory Leaks : Allocated memories must be freed !! 
 # MAC: 
   Run:  `export MallocStackLogging=1`
   Then: `$(NAME).out`
   After that:`leaks --atExit --list -- ./$(NAME).out $(ARGUMENTS -- if you have)`
       
   Also run:  `leaks --help` for better understanding !! 
      
      source: https://www.youtu`be.com/watch?v=bhhDRm926qA
# Linux:
               Use valgrind !! Too many resources out there :xD  
# Segfaults
         
# Use of a Debugger


Mac: 

      
