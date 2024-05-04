#include<stdio.h>
#include <pthread.h>
#include <iostream>


#include "rwlock.h"

RWLock::RWLock() {
    AR = 0;
    WR = 0;
    AW = 0;
    WW = 0;
    lock = new Lock("rwlock");
    okToRead = new Condition("okToRead");
    okToWrite = new Condition("okToWrite");
}

RWLock::~RWLock() {
    delete lock;
    delete okToRead;
    delete okToWrite;
}

void RWLock::startRead() {

    // acquire the lock
    lock->Acquire();

    // wait until it is available
    while (AW > 0 || WW > 0) {
        okToRead->Wait(lock);
    }

    // increment active reader
    AR++;

    // release the lock
    lock->Release();
}

void RWLock::doneRead() {

    // acquire the lock
    lock->Acquire();

    // decrement active reader
    AR--;

    // if no active readers, signal waiting writers
    if (AR == 0 && WW > 0) {
        okToWrite->Signal(lock);
    }

    // release the lock
    lock->Release();
}

void RWLock::startWrite() {

    // acquire the lock
    lock->Acquire();

    // increment waiting writers
    WW++;

    // wait for active reader and writer to finish
    while (AR > 0 || AW > 0) {
        okToWrite->Wait(lock);
    }

    // decrement waiting writers
    WW--;
    AW++;   // increment active writers

    // release the lock
    lock->Release();
}

void RWLock::doneWrite() {
    
    // acquire the lock
    lock->Acquire();

    // decrement active writers
    AW--;

    // signal waiting readers and writers
    if (WW > 0) {
        okToWrite->Signal(lock);
    } else {
        okToRead->Broadcast(lock);
    }

    // release the lock
    lock->Release();
}