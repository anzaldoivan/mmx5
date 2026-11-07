#include "types.h"
#include "addr.h"

extern s32 D_8009A420;
extern u8 D_8009A1F8[];
extern u16 D_800D50DE;

void func_800FA60C_ovl39(u8* arg0) {
    s8* obj;
    u8* base;
    s32 one;

    if (!(D_8009A420 & 1)) {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x94) = 4;
    } else {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x94) = 0;
    }
    base = D_8009A1F8;
    one = 1;
    base[0xA0] = one;
    if (D_800D50DE == 0x1F) {
        *(s16*)(base + 0x96) = 0x300;
        base[0xA0] =
            one; // !FAKE: redundant store (deleted post-reload) keeps one global in $a3
    }
    arg0[3] = 0;
    obj = D_1F80004C.scr1334->unk80;
    if (obj[0] != 0) {
        if (obj[7] == 0) {
            if (--*(s16*)(arg0 + 0x7E) == -1) {
                *(u16*)(arg0 + 0x42) ^= 0x8000;
                if (*(u16*)(arg0 + 0x42) & 0x8000) {
                    *(s16*)(D_8009A1F8 + 0x96) = 0x200;
                } else {
                    *(s16*)(D_8009A1F8 + 0x96) = 0;
                }
                D_8009A1F8[0xA0] = 1;
                *(s16*)(arg0 + 0x7E) = 5;
            }
        }
    } else {
        arg0[5]++;
    }
}
