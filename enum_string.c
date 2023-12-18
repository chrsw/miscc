// Source: https://stackoverflow.com/a/3168470

#undef DECL_ENUM_ELEMENT
#undef DECL_ENUM_ELEMENT_VAL
#undef DECL_ENUM_ELEMENT_STR
#undef DECL_ENUM_ELEMENT_VAL_STR
#undef BEGIN_ENUM
#undef END_ENUM

#ifndef GENERATE_ENUM_STRINGS
    #define DECL_ENUM_ELEMENT( element ) element,
    #define DECL_ENUM_ELEMENT_VAL( element, value ) element = value,
    #define DECL_ENUM_ELEMENT_STR( element, descr ) DECL_ENUM_ELEMENT( element )
    #define DECL_ENUM_ELEMENT_VAL_STR( element, value, descr ) DECL_ENUM_ELEMENT_VAL( element, value )
    #define BEGIN_ENUM( ENUM_NAME ) typedef enum tag##ENUM_NAME
    #define END_ENUM( ENUM_NAME ) ENUM_NAME; \
            const char* GetString##ENUM_NAME(enum tag##ENUM_NAME index);
#else
    #define BEGIN_ENUM( ENUM_NAME) const char * GetString##ENUM_NAME( enum tag##ENUM_NAME index ) {\
        switch( index ) { 
    #define DECL_ENUM_ELEMENT( element ) case element: return #element; break;
    #define DECL_ENUM_ELEMENT_VAL( element, value ) DECL_ENUM_ELEMENT( element )
    #define DECL_ENUM_ELEMENT_STR( element, descr ) case element: return descr; break;
    #define DECL_ENUM_ELEMENT_VAL_STR( element, value, descr ) DECL_ENUM_ELEMENT_STR( element, descr )

    #define END_ENUM( ENUM_NAME ) default: return "Unknown value"; } } ;

#endif


// Usage:
#include "enum.h"

#define GENERATE_ENUM_STRINGS  // Start string generation
  #include "enum.h"             
#undef GENERATE_ENUM_STRINGS   // Stop string generation

int main(int argc, char* argv[])
{
    Days TheDay = Monday;
    printf( "%d - %s\n", TheDay, GetStringDay(TheDay) ); //will print "1 - Monday"

    TheDay = Thursday;
    printf( "%d - %s\n", TheDay, GetStringDay(TheDay) ); //will print "500 - Thursday string"

    return 0;
}


// Edited code from original question:
int main()
{

  enum Days{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};

  Days TheDay;

  int j = 0;

  printf("Please enter the day of the week (0 to 6)\n");

  scanf("%d",&j);

  // Print day in string form here
 
  return 0;
}

