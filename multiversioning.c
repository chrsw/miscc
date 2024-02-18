// multiversioning.c

#include <stdio.h>

__attribute__ ((target ("default")))
const char* foo () { return "default"; }

__attribute__ ((target ("sse4.2")))
const char* foo () { return "sse4.2"; }

__attribute__ ((target ("arch=x86-64")))
const char* foo () { return "x86-64-v1"; }

__attribute__ ((target ("arch=x86-64-v2")))
const char* foo () { return "x86-64-v2"; }

__attribute__ ((target ("arch=x86-64-v3")))
const char* foo () { return "x86-64-v3"; }

__attribute__ ((target ("arch=x86-64-v4")))
const char* foo () { return "x86-64-v4"; }

int main ()
{
  printf("%s\n", foo());
  return 0;
}