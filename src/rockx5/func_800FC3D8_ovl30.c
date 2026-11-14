#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800FD050_ovl30(s32, void*, u8*, s32);
extern u8 D_800FD798_ovl30[];
extern u8 D_800FD79C_ovl30[];
extern u8 D_800FD7A0_ovl30[];
extern u8 D_800FD7A4_ovl30[];
extern u8 D_800FD7A8_ovl30[];
extern u8 D_800FD7AC_ovl30[];
extern u8 D_800FD7B0_ovl30[];
extern u8 D_800FD7B4_ovl30[];
extern s32 D_8009A420;
extern u8 D_800FDBB4_ovl30[];

void func_800FC3D8_ovl30(u8* obj) {
    u8* a;
    u8* b;

    func_80017248(obj);
    switch (obj[0x47]) {
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
        a = D_800FD7A0_ovl30;
        b = D_800FD7A4_ovl30;
        break;
    case 0x5B:
    case 0x5C:
        a = D_800FD7A8_ovl30;
        b = D_800FD7AC_ovl30;
        break;
    case 0x5D:
        a = D_800FD7B0_ovl30;
        b = D_800FD7B4_ovl30;
        break;
    case 0x5E:
    case 0x5F:
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x54) = 0;
        goto done; // !FAKE: goto kept for the matching branch layout
    default:
        a = D_800FD798_ovl30;
        b = D_800FD79C_ovl30;
        break;
    }
    *(u8**)(obj + 0x50) = a;
    *(u8**)(obj + 0x54) = b;
done:
    if ((D_8009A420 & 0xF) == 0) {
        func_800FD050_ovl30(4, D_800FDBB4_ovl30, obj, 1);
    }
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 8;
        obj[6] = 0;
    }
}
