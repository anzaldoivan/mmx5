#include "types.h"
#include "mmx5/graphics.h"

extern u8 D_80075340[];

void func_800F1884_ovl10(Obj1884* arg0) {
    set_animation(arg0, 1);
    arg0->unk58 = D_80075340;
    arg0->unk6++;
}

void func_800F1BD4_ovl10(u8* arg0, u8 arg1);

void func_800F18C4_ovl10(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        func_800F1BD4_ovl10(arg0, 0x10);
        func_800F1BD4_ovl10(arg0, 0x12);
        func_800F1BD4_ovl10(arg0, 0x11);
        func_800F1BD4_ovl10(arg0, 0x13);
        *(s16*)(arg0 + 0x7C) = 0x28;
        arg0[6]++;
    }
}

void func_800F1934_ovl10(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        set_animation(obj, 2);
        obj[6]++;
    }
}

extern u8 D_80074EE0[];

void func_800F198C_ovl10(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 1) {
        *(u8**)(arg0 + 0x58) = D_80074EE0;
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
