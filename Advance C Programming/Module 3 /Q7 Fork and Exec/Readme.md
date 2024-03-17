# Q7 What is the difference between exec and fork ?

Fork and exec are two system calls that are used to create new processes in Unix-like operating systems.
      Fork    |     Exec
------------- | -------------
Creates a new process that is a copy of the calling process | creates a new process that replaces the current process
The new process has the same memory space as the parent process  | The new process has a different memory space as that of parent
The parent and child processes can execute independently of each other | The parent process is terminated when the exec() system call is successful
