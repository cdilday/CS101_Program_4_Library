#include        <stdio.h>
#include        <strings.h>
#include        <stdlib.h>   /* this includes malloc, free, rand, etc. */

#define EQ ==
#define NEQ !=
#define LEQ <=
#define GEQ >=
/* I try to use these in boolean expressions.  One of the problems with C */
/* is that "(x = y)" when you mean "(x == y)" is almost always is true    */
/* AND also assigns the value of y to x.  Since this is almost impossible */
/* to debug, I try to use the above abbreviations for comparison operators. */

#define AND &&
#define OR ||

#define streq(s, t) (! strcmp(s, t))
#define strneq(s, t) (strcmp(s, t))

typedef int     Boolean;
#define TRUE 1
#define FALSE 0
/* these three things give me a "poor man's" boolean type */
/* with constants TRUE and FALSE */

typedef char *  String;
typedef FILE *  FilePtr;
/* these are two other commonly used types. */

