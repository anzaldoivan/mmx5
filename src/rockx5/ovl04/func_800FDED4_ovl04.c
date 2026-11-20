/* W40 draft: after 61 ticks, flag D_800D1C2A[1] and spawn two 0x41/0xB children (rockx5 ovl04). */
#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1C2A;

void func_800FDED4_ovl04(u8* o) {
    u8* c;

    animate_object(o);
    if (++o[0x8D] >= 0x3D) {
        (&D_800D1C2A)[1] = 2;
        c = func_8002D1A4();
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 0xB;
            *(u8**)(c + 0x7C) = o;
            c[2] = 1;
        }
        c = func_8002D1A4();
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 0xB;
            *(u8**)(c + 0x7C) = o;
            c[2] = 3;
        }
        o[6]++;
    }
}
