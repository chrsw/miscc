// findpal:  look for words that are palindromes
// input:    plain text standard input
// output:   list of words that are palindromes


// a palindrome is a word that is spelled the same way backwards and
// forwards e.g., civic, madam, radar, defied
//
// algorithm: check the first and last character of a word.
//            if they're the same check the next 2nd character and
//            next to last character in the word.
//            do this for word length ÷ 2.
//            length divided by 2 is rounded down.
//            for example. civic is length 5, 5 ÷ 2 = 2. so 2 sets of
//            characters will be checked and the middle characters
//            doesn't need to be checked..
