#include "types.h"

void func_800F7360_ovl28(Unk800F7360Obj* obj, Unk800F7360Arg* arg) {
    if (obj->unk54 != 0) {
        obj->unk54--;
    } else {
        obj->unk54 = 3;
        obj->unk8 = obj->unk5C->unk18;
        obj->unkC = obj->unk5C->unk1C;
    }
    if (arg->unk9A < 0) {
        obj->unk5++;
    }
}

void func_800F73C8_ovl28(u8* a0, u8* a1) {
    if (*(signed char*)(a1 + 0x9A) > 0) {
        *(s16*)(a0 + 0x54) = 3;
        *(s16*)(a0 + 0x56) = 8;
        *(s16*)(a0 + 0x58) = (5 - *(signed char*)(a0 + 2)) * 2;
        *(s32*)(a0 + 0x8) = *(s32*)(a1 + 0x8);
        *(s32*)(a0 + 0xC) = *(s32*)(a1 + 0xC);
        *(u8*)(a0 + 4) = 1;
        *(u8*)(a0 + 5) = 0;
    } else if (*(s16*)(a0 + 0x56) != 0) {
        (*(s16*)(a0 + 0x56))--;
        if (*(s16*)(a0 + 0x56) & 1) {
            u8* p = *(u8**)(a0 + 0x5C);
            *(s32*)(a0 + 0x8) = *(s32*)(p + 0x18);
            *(s32*)(a0 + 0xC) = *(s32*)(p + 0x1C);
        }
    } else {
        (*(u8*)(a0 + 5))++;
    }
}

void func_800F7478_ovl28(u8* a0, u8* a1) {
    s32* p;

    if (*(signed char*)(a1 + 0x9A) > 0) {
        *(s16*)(a0 + 0x54) = 3;
        *(s16*)(a0 + 0x56) = 8;
        *(s16*)(a0 + 0x58) = (5 - *(signed char*)(a0 + 2)) * 2;
        *(s32*)(a0 + 8) = *(s32*)(a1 + 8);
        *(s32*)(a0 + 0xC) = *(s32*)(a1 + 0xC);
        a0[4] = 1;
        a0[5] = 0;
        return;
    }
    if (*(s16*)(a0 + 0x58) != 0) {
        p = *(s32**)(a0 + 0x5C);
        *(s32*)(a0 + 8) = p[6];
        *(s32*)(a0 + 0xC) = p[7];
        *(s16*)(a0 + 0x58) -= 1;
    } else {
        a0[3] = 0;
        a0[4] = 0;
        if (*(signed char*)(a0 + 2) == 2) {
            a1[0x9A] = 0;
        }
    }
}
