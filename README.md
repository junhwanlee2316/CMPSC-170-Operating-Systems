# Operating-Systems

## UCSB CMPSC 170

## Description

The design and implementation of operating systems and the topics include process/thread management, multiprogramming, memory management, files and storage systems. The programming assignments involve intensive C++/C programming to build an operating system on a simulated MIPS-style computer.

## Projects

1. **Implement a Basic Shell**
   - Basic process-related Unix system calls and use them for a basic shell implementation.
2. **Concurrent Hash Table with Pthreads**
   - Read the HashMap implementation code and test code.
   - Read/write operations in each of the following HashMap functions: put(), get(), remove(), and increment().
   - Added synchronization to put(), get(), remove(), and increment() so that this hashtable can be safely accessed by these functions used in multiple pthreads running concurrently.
3. **Thread Synchronization with Nachos**
   - Implemented the lock and condition synchronization primitives that are missing from NACHOS
   - Use the semaphore synchronization primitives in NACHOS and achieve proper synchronization in accessing a hashtable
4. **Process Management and System Calls**
   - Implemented various system calls such as Fork(), Yield(), Exit(int), Join(), Open(), Write(), Read(), and Close().
   - Developed functions in different source files including exception.cc, processmanager.cc, and addrspace.cc.
   - Ensured proper synchronization, error handling, and communication between processes for efficient system operation.
5. **Virtual Memory Manager**
   - Enhanced the VirtualMemoryManager::swapPageIn() function to incorporate the second-chance page replacement policy, ensuring efficient management of memory resources.
   - Implemented a systematic approach to find and replace victim pages, considering factors such as occupancy status, recent usage, and dirty page conditions, thereby optimizing memory utilization and data integrity.

## Copyright

As mentioned in the file header, some of the file contents are the intellectual property of the University of California, Santa Barbara (UCSB).

Copyright © [Year] University of California, Santa Barbara. All rights reserved.
