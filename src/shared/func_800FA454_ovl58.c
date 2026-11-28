#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void func_80013288(s32);
extern u8* D_800FB5F0_ovl58;

void func_800FA454_ovl58(u8* arg0) {
    u8* p;

    D_8009A1F8.u[3] = 0;
    D_8009A1F8.u[0xAB] = 0;
    p = alloc_class6_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xA;
        p[0x36] = 0x11;
        p[2] = 0;
        D_800FB5F0_ovl58 = p;
    }
    func_80013288(8);
    arg0[1]++;
}
