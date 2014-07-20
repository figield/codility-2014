#include <stdlib.h>
 
// A better and portable way is to include <limits.h>
// But I failed to include this head file. I have to hard-code
// it here. Even if the CHAR_BIT is larger than 8, our
// program should works well, except for wasting some space.
// In history, there are some different standard for CHAR_BIT
// http://pubs.opengroup.org/onlinepubs/009695399/basedefs/limits.h.html
// http://pubs.opengroup.org/onlinepubs/7908799/xsh/limits.h.html
// But in all cases, CHAR_BIT is at least 8.
#define CHAR_BIT 8
 
int solution(int A[], int N) {
    unsigned char appeared[2000001/CHAR_BIT+1];
    // oneInByte is a pre-compute array. onesInByte[i] = j means there
    // are j 1s in the binary formation of integer i.
    unsigned short int onesInByte[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, \
            2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, \
            4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, \
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, \
            3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, \
            4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, \
            4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, \
            5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, \
            5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, \
            3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, \
            5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, \
            3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, \
            6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, \
            6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
    int index = 0;
    int result = 0;
 
    memset(appeared, 0, 2000001/CHAR_BIT+1);
 
    // Record the appeared values
    for(index = 0; index < N; ++index) {
        appeared[(A[index]+1000000)/CHAR_BIT] |= \
                            (1<<(int)((A[index]+1000000)%CHAR_BIT));
    }
 
    // Compute the number of distinct values
    for(index = 0; index < 2000001/CHAR_BIT+1; ++index){
        result += onesInByte[appeared[index]];
    }
 
    return result;
}
