#include "types.h"
#include "addr.h"

extern s32 D_8009A420;
extern u8 D_8009A1F8[];
extern u8* func_8002D144(void);

void func_800FA490_ovl39(u8* arg0) {
    u8* child;

    if (!(D_8009A420 & 1)) {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x94) = 4;
    } else {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x94) = 0;
    }
    D_8009A1F8[0xA0] = 1;
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[5]++;
        child = func_8002D144();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x1A;
            *(u16*)(child + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(arg0 + 0xE);
            D_1F80004C.scr1334->unk80 = child;
        }
    }
    if (--*(s16*)(arg0 + 0x7E) == -1) {
        *(u16*)(arg0 + 0x42) ^= 0x8000;
        if (*(u16*)(arg0 + 0x42) & 0x8000) {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x96) = 0x200;
        } else {
            u8* p = D_8009A1F8;
            *(s16*)(p + 0x96) = 0;
        }
        D_8009A1F8[0xA0] = 1;
        arg0[0x61] -= 5;
        if ((s8)arg0[0x61] >= 0x1A) {
            arg0[0x61] = 0;
        }
        *(s16*)(arg0 + 0x7E) = ((s8)arg0[0x61] < 6) ? 5 : (s8)arg0[0x61];
    }
}
