#include <stdio.h>
#include <inttypes.h>

int main()
{
 uint64_t  pvr_;

 asm ("mfpvr %[pvr_];" : [pvr_] "+r" (pvr_) );

 printf("PVR: %lx\n", pvr_);
}
