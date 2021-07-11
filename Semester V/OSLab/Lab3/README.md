### Questions
1. Write a C program to block a parent process until the child completes using a wait system call.  
2. Write a C program to load the binary executable of the previous program in a child process using the exec system call.  
3. Write a program to create a child process. Display the process IDs of the process, parent,and child (if any) in both the parent and child processes.  
4. Create a zombie (defunct) child process (a child with exit () call, but no corresponding wait () in the sleeping parent) and allow the init process to adopt it (after parent terminates). Run the process as a background process and run the “ps” command.  