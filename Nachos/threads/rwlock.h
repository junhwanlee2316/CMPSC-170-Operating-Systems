#ifndef __RWLOCK_H__
#define __RWLOCK_H__
#include<semaphore.h>
#include <pthread.h>
#include "synch.h"

class RWLock {
private:
    int AR;
    int WR;
    int AW;
    int WW;
    Lock *lock;
    Condition *okToRead;
    Condition *okToWrite;

public:
    RWLock();
    ~RWLock();

    // Reader
    void startRead();
    void doneRead();

    // Writer
    void startWrite();
    void doneWrite(); //hashchain.cc rwlock two synch.cc
};

#endif