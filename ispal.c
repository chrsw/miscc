// Determine if a number is a palindrome

#include <stdbool.h>

int reverse(int n);
bool ispal(int n);

bool ispal(int n) {
    
    return n == reverse(n);	
}
