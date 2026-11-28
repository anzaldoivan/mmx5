#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A169;

void func_800F0254_ovl24(u8* a0) {
    u8* p = g_playthrough_state.u;
    u8* q;

    if (((s8*)p)[0x27] == 0 && !((D_8009A169 >> (((s8*)p)[0x26] - 1)) & 1)) {
        a0[2] = 1;
        return;
    }
    q = g_playthrough_state.u;
    if (q[0xA1] != q[0xCC]) {
        a0[2] = 5;
    } else {
        a0[1] = 3;
        a0[2] = 0;
    }
}

void func_800F02CC_ovl24(u8* arg0) {
    func_8002385C(0, 0xFF, 0);
    arg0[2]++;
}

#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800F0308_ovl24(u8* arg0) {
    if (D_800C9320.h & 0x8FF) {
        D_800D1C28_as_u8 = 0x7F;
        arg0[2]++;
    }
}
#undef D_800D1C28_as_u8

#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800F0344_ovl24(u8* arg0) {
    if (D_800C9320.h & 0x8FF) {
        D_800D1C28_as_u8 = 0x7F;
        arg0[1] = 3;
        arg0[2] = 0;
    }
}
