#ifndef __FILE_H
#define __FILE_H
#include <cstdio>
class File {
    public :
        File (const char* fname,const char* mode)
            :file_(::fopen(fname,mode)){
            }
        int seek(size_t offset, int mode){
            return ::fseek(file_,offset,mode);
        }
        size_t tell (){
            return ::ftell(file_);
        }
        size_t read (char * buf, size_t size){
            return ::fread(buf,size,1,file_);
        }
        size_t write (char *buf,size_t size){
            return ::fwrite(buf,size,1,file_);
        }
        ~File(){
            ::fclose(file_);
        }
    private:
        FILE * file_;
};

#endif// __FILE_H
