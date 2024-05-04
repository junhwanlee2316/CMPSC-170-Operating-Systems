#include<stdio.h>
#include <pthread.h>
#include <iostream> 


#include "rwlock.h"

//Your solution to implement each of the following methods
//
RWLock::RWLock(): readers(0), writing(false) {}

RWLock::~RWLock() {}

void RWLock::startRead() {
    std::unique_lock<std::mutex> lock(mtx);
    while (writing) {
        cv.wait(lock);
    }
    readers++;
    //mtx.unlock();
}

void RWLock::doneRead() {
    std::unique_lock<std::mutex> lock(mtx);
    readers--;
    if (readers == 0) {
        cv.notify_one();
    }
}

void RWLock::startWrite() {
    std::unique_lock<std::mutex> lock(mtx);
    while (writing || readers > 0) {
        cv.wait(lock);
    }
    writing = true;
}
void RWLock::doneWrite() {
    std::unique_lock<std::mutex> lock(mtx);
    writing = false;
    cv.notify_all();
}
