#include "types.h"
#include "mmx5/graphics.h"

void func_800F173C_ovl05(u8* a0) {
    s8 n;

    switch (*(s8*)(a0 + 2)) {
    case 0:
    case 1:
    case 2:
        n = --*(s8*)(a0 + 0x92);
        if (n <= 0) {
            *(u16*)(a0 + 0x88) = *(u16*)(a0 + 0x8A) + 60;
        } else {
            *(u16*)(a0 + 0x88) = *(u16*)(a0 + 0x8A) + (n * 44 + 60);
        }
        break;
    case 3:
    case 4:
    case 5:
        *(u16*)(a0 + 0x88) = *(u16*)(a0 + 0x8A) + 90;
        break;
    }
    a0[6]++;
}

void func_800F17DC_ovl05(u8* a0) {
    s8 v;

    if (--*(s16*)(a0 + 0x88) == -1) {
        v = ((s8*)a0)[2];
        if (v >= 0) {
            if (v < 3) {
                *(s16*)(a0 + 0x88) = 30;
            } else if (v < 6) {
                *(s16*)(a0 + 0x88) = 60;
            }
        }
        a0[6]++;
    }
}

void func_800F183C_ovl05(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x88) - 1;
    *(u16*)(arg0 + 0x88) = t;
    if ((s16)t == -1) {
        arg0[6]++;
        return;
    }
    if (t & 1) {
        arg0[0x91] = 1;
        return;
    }
    arg0[0x91] = 2;
}

void func_800F188C_ovl05(u8* obj) {
    obj[0x91] = 1;
    switch (*(s8*)(obj + 2)) {
    case 0:
    case 3:
        obj[5] = 3;
        set_animation(obj, 0);
        break;
    case 1:
    case 4:
        obj[5] = 4;
        set_animation(obj, 3);
        break;
    case 2:
    case 5:
        obj[5] = 5;
        set_animation(obj, 6);
        break;
    }
    obj[6] = 0;
    obj[0x5C] = 12;
    obj[0x90] = 0;
    *(s16*)(obj + 0x8A) = 0;
}
