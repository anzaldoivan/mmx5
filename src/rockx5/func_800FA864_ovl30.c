#include "types.h"

extern void func_800FCF80_ovl30(u8* obj);
extern void func_800FCF40_ovl30(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FD7F8_ovl30[];
extern signed char D_800D1CA2;
extern u8 D_800FD768_ovl30[];
extern u8 D_800FD76C_ovl30[];

void func_800FA864_ovl30(u8* obj) {
    signed char t;
    signed char h;

    if (D_800FD7F8_ovl30[*(signed char*)(obj + 0x91) + obj[0x90] * 6] >= 0x11) {
        func_800FCF80_ovl30(obj);
    }
    func_800FCF40_ovl30(obj);
    t = D_800D1CA2 / 3;
    h = *(signed char*)(obj + 0x5C);
    if (h < t * 2 && t < h) {
        obj[0x89] = 1;
        func_800171E8(obj, 13);
        obj[0x96] = 1;
        obj[5] = 7;
        obj[6] = 0;
        return;
    }
    if (*(signed char*)(obj + 0x92) == 2 || *(signed char*)(obj + 0x92) == 4) {
        func_800171E8(obj, 13);
        obj[0x96] = 0;
        obj[5] = 4;
        obj[6] = 0;
        return;
    }
    switch (D_800FD7F8_ovl30[*(signed char*)(obj + 0x91) + obj[0x90] * 6]) {
    case 0:
        func_800171E8(obj, 0);
        obj[6] = 1;
        *(s16*)(obj + 0x7C) = 60;
        break;
    case 1:
        func_800171E8(obj, 13);
        obj[0x96] = 0;
        obj[5] = 4;
        obj[6] = 0;
        break;
    case 2:
        func_800171E8(obj, 13);
        obj[0x96] = 1;
        obj[5] = 4;
        obj[6] = 0;
        break;
    case 3:
        func_800171E8(obj, 13);
        obj[0x96] = 1;
        obj[5] = 7;
        obj[6] = 0;
        break;
    case 4:
        func_800171E8(obj, 6);
        obj[5] = 2;
        obj[6] = 0;
        *(u8**)(obj + 0x50) = D_800FD768_ovl30;
        *(u8**)(obj + 0x54) = D_800FD76C_ovl30;
        break;
    case 5:
        func_800171E8(obj, 11);
        *(s16*)(obj + 0x7C) = 36;
        *(s16*)(obj + 0x7E) = 2;
        obj[5] = 6;
        obj[6] = 0;
        break;
    }
    obj[0x91]++;
}
