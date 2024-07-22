// print address of array elements

#include <stdio.h>
#define SIZE 6

int ia[SIZE] = {0,1,2,3,4,5};

int * process_array(int num[6]) {
    int i = 0;
    for (i = 0; i < 6; i++  )
        printf("%p\n", &num[i]);
   return &num[i]; 
}

void call_process(void) {

    int *ip;
    ip = process_array(ia);

}

int main(void) {

        call_process();
        return 0;
}
