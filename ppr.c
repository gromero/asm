#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h> 

int main(int argc, char **argv)
{
 uint64_t  ppr_;
 int i;

 asm ("or 31, 31, 31;");

 for (i = 0; i < 10; i++) {
   asm ("mfppr %[ppr_];" : [ppr_] "+r" (ppr_) );
   if (i == atoi(argv[1]))
     printf("PPR: %lx\n", ppr_); // print PPR but also trigger a sc
   if (i == atoi(argv[1] + 1))
     printf("PPR: %lx\n", ppr_); // print PPR after we trigged a sc
 }
}
