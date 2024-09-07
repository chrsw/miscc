// last_wrd_len:  find the length of the last word in a string
// idea taken from https://www.youtube.com/watch?v=5qGMrQKHdkI
// without watching the video
//
// $ gcc -c last_wrd_len.c
// $ gcc -DMAIN -o last_wrd_len last_wrd_len.c
//
// TODO: Test more cases


#ifdef MAIN
#include <stdio.h>
#include <stdlib.h>
#endif
#include <string.h>
#include <ctype.h>


int last_wrd_len(char *s);


#ifdef MAIN
int main(void)
{

    // test strings
    // char *s = "hello";
    //char *s = "test hello";
    char *s = "t goodbye";

    int l = last_wrd_len(s);
    printf("%d\n", l);
    return EXIT_SUCCESS; 
}
#endif


// find length of last word in a string
int last_wrd_len(char *s)
{
    int l, ll;
    char *sp;

    // get the length of string
    ll = l = strlen(s);
    if (l < 1) return l;
    
    // set string pointer to end of string, skip '\0'
    sp = s+l-1;

    // search backwards from end of string for first non-letter
    while ((l-- > 1) && isalpha(*sp--))
        ;
   
    // length of last word is string less current position 
    return ll - l;
}
