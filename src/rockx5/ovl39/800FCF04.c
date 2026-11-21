#include "types.h"
#include "mmx5/object.h"

void func_800FCF04_ovl39(u8* p) {
    if (((s8*)p)[2] == 0) {
        p[0x15] = 0;
        *(s16*)(p + 0xA) = 0x12E0;
        *(s32*)(p + 0x20) = -0x18000;
    } else {
        p[0x15] = 0x40;
        *(s16*)(p + 0xA) = 0x1140;
        *(s32*)(p + 0x20) = 0x18000;
    }
    *(s16*)(p + 0xE) = 0x820;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x2C) = 0;
    p[6]++;
}

void func_800FCF70_ovl39(EntFD048* arg0) {
    move_object(arg0);
    if ((arg0->unk2 == 0 && arg0->unkA < 0x1291) ||
        (arg0->unk2 == 1 && arg0->unkA >= 0x1190)) {
        arg0->unk6++;
    }
}

void func_800FCFE4_ovl39(u8* arg0) {
    if ((*(u8**)(arg0 + 0x7C))[0x85] != 0) {
        arg0[5] = 6;
        arg0[6] = 0;
    }
}
