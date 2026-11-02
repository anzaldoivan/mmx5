#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern u8* func_8002D0E4(void);
extern s8 D_800731D4[][5];
extern u32* D_8007B2E8[];

void func_800321EC(u8* arg0, s32 arg1) {
    s32 id;
    u8* p;

    id = (s8)arg0[1];
    if (D_800731D4[id][1] == 4) {
        return;
    }
    if (arg1 < 0) {
        if (id == 0x17) {
            return;
        }
        if (D_800731D4[id][2] != 0) {
            *(s8*)(arg0 + 0x98) = -1;
        }
        func_80016490(0, 6, arg0);
        id = 0;
    } else {
        if (D_800731D4[id][2] != 0) {
            if (arg1 == 0) {
                arg0[0x98] = 1;
            } else if (D_800731D4[id][3] == 0) {
                arg0[0x98] = 1;
            }
        }
        switch (D_800731D4[id][1]) {
        case 0:
            func_80016490(1, (u8)D_800731D4[id][4], arg0);
            break;
        case 1:
            if (arg1 == 0) {
                func_80016490(1, 9, arg0);
            } else {
                func_80016490(1, 10, arg0);
            }
            break;
        case 2:
        case 3:
            func_80016490(5, (u8)D_800731D4[id][4], arg0);
            break;
        case 4:
            break;
        }
        id = D_800731D4[id][0];
    }
    p = func_8002D0E4();
    if (p == 0) {
        return;
    }
    p[0] = 0x21;
    p[1] = 3;
    p[2] = id;
    if ((s8)arg0[0x14] < 0) {
        p[0x14] = 0;
    } else {
        p[0x14] = arg0[0x14];
    }
    *(u8**)(p + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[1];
    *(u32***)(p + 0x30) = D_8007B2E8;
    *(s16*)(p + 0x40) = 0;
    *(s16*)(p + 0x42) = 0x7802;
    p[0x16] = 1;
    *(u16*)(p + 0xA) = *(u16*)(arg0 + 0x80);
    *(u16*)(p + 0xE) = *(u16*)(arg0 + 0x82);
    p[0x15] = arg0[0x15] ^ 0x40;
}
