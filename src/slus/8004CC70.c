#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern s16 D_800E9560;

void func_8004CC70(u8* arg0) {
    u8* p = g_Player;

    arg0[3] = 1;
    *(s32*)(arg0 + 0x38) = *(s32*)(p + 0x38);
    *(s32*)(arg0 + 0x3C) = *(s32*)(p + 0x3C);
    *(s32*)(arg0 + 0x30) = *(s32*)(p + 0x30);
    *(s16*)(arg0 + 0x40) = 0x500;
    *(s16*)(arg0 + 0x42) = 0x7843;
    arg0[0x16] = 1;
    arg0[0x15] = p[0x15];
    arg0[0x47] = p[0x47];
    *(s32*)(arg0 + 0x8) = *(s32*)(p + 0x8);
    *(s32*)(arg0 + 0xC) = *(s32*)(p + 0xC);
    D_800E9560 = 8;
    if (arg0[0x15] != 0) {
        *(s16*)(arg0 + 0xA) += 8;
    } else {
        *(s16*)(arg0 + 0xA) -= 8;
    }
    arg0[5] = 0;
    arg0[0x8E] = 0;
    *(s16*)(arg0 + 0x8C) = 0;
    arg0[4]++;
    p[0xA6]++;
}

/* slus func_8004CD40: twin of func_800462D4 (dup1200), counter at +0xA6. */

void func_8004CD40(s8* e) {
    g_Player[0xA6]--;
    clear_object_slot(e);
}
