#ifndef __CONTEXT_H
#define __CONTEXT_H
#include <cstdio>
#include <memory>
struct Context {
    using FilePtr = std::shared_ptr<FILE>;
    Context (FILE* fp_,int trunkSize_):
        fp(fp_,::fclose),trunkSize(trunkSize_),running(true)
    {
    }
    FilePtr fp;
    int trunkSize;
    mutable bool running;
};
#endif// __CONTEXT_H
