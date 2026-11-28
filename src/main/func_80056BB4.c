#include "types.h"
#include "mmx5/globals.h"

extern s32 get_launch_variant(void);
extern u8 D_8009A428;
extern s8 D_8007D784[];
extern s16 D_8007D824[][4];

void func_80056BB4(u8* arg0) {
    u8* p = g_Player;
    s8* tbl;
    u8* base;
    u8* flags;
    s32 idx;
    s32 r;

    {
        s32 row;
        s32 byte;
        u8 mask;
        s32 off;

        idx = (s8)arg0[2];
        byte = idx >> 3;
        row = ((s8*)p)[2];
        mask = 1 << (idx % 8);
        base = g_playthrough_state.u;
        off = byte + (row << 5);
        flags = base + 0xCD;
        if ((flags[off] & mask) || D_8009A428 != 0) {
            arg0[4] = 2;
            return;
        }
    }
    tbl = D_8007D784;
    r = get_launch_variant() * 53;
    idx = (s8)arg0[2];
    if (tbl[idx + r] == -1 || idx >= 0x36) {
        arg0[4] = 2;
        return;
    }
    if (!(*(s16*)(p + 0xA) > D_8007D824[idx][0] &&
          *(s16*)(p + 0xA) < D_8007D824[idx][1] &&
          *(s16*)(p + 0xE) > D_8007D824[idx][2] &&
          *(s16*)(p + 0xE) < D_8007D824[idx][3])) {
        return;
    }
    {
        s32 byte = idx >> 3;
        s32 row = ((s8*)p)[2];
        u8 mask = 1 << (idx % 8);
        u8* cell = &flags[byte + (row << 5)];

        if (*cell & mask) {
            arg0[4] = 2;
            return;
        }
        *cell = mask | *cell;
    }
    ((s32(*)())func_8003D29C)(0x14, p[0x15]);
    arg0[4]++;
}
