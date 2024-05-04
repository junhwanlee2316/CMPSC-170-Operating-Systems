
How to test in Project 2:

1. type make under Nachos' code directory, which produces nachos under userprog directory.
 
2. Go to the test directory.
Assume the C code (e.g. hello.c) has been compiled to produce the MIPS binary (e.g. hello)
type this command under this test directory:

../userprog/nachos -x hello




Tests that pass the starter code:

- hello.c
- halt.c

Tests that do not pass the starter code, and will not be graded:

- console-read-test.c
- join1.c
- join2.c
- join3.c
- exec1.c
- exec2.c
- exec3.c



Tests that will be graded:

- close-test.c
- open-test.c
- exec-test.c
- join-test.c
- fork-test.c
- create-test.c
- yield-test.c
