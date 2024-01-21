/* vim:ts=4:sw=4:et:so=10:ls=2:
 *
 * tztest.c
 *      A brief description of the file.
 *
 * Description:
 *      TBD
 *
 */

#include <time.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

        int i = 0;
        time_t timep;
        
        printf("Greetings!\n");
        
        for (i = 0; i < 10; i++) {
                time(&timep);
                localtime(&timep);
        }

        printf("Godspeed, dear friend!\n");
        return 0;
}
