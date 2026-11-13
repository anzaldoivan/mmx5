#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80017248(u8* obj);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern void func_800FCF40_ovl30(u8* obj);
extern u8 D_800FD760_ovl30[];
extern u8 D_800FD764_ovl30[];
extern u8 D_800FD768_ovl30[];
extern u8 D_800FD76C_ovl30[];
extern u8 D_800FD770_ovl30[];
extern u8 D_800FD774_ovl30[];
extern u8 D_800FD778_ovl30[];
extern u8 D_800FD77C_ovl30[];
extern u8 D_800FD780_ovl30[];
extern u8 D_800FD784_ovl30[];
extern u8 D_800FD788_ovl30[];
extern u8 D_800FD78C_ovl30[];

void func_800FADC4_ovl30(u8* obj) {
    u8* n;

    if (*(s16*)(obj + 0x7C) == 0) {
        *(s16*)(obj + 0x7E) = func_8002DF78() & 1;
    }
    func_80017248(obj);
    switch (*(s16*)(obj + 0x7C)) {
    case 0:
        func_80016490(2, 9, obj);
        n = func_8002D1A4();
        if (n != 0) {
            n[0] = 0x41;
            n[1] = 0x1F;
            n[2] = obj[0x7E] + 3;
            *(u16*)(n + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(n + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(n + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(n + 0x3C) = *(s32*)(obj + 0x3C);
            n[0x14] = obj[0x14];
            *(s32*)(n + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(n + 0xC) = *(s32*)(obj + 0xC);
            n[0x15] = obj[0x15];
            *(u8**)(n + 0x7C) = obj;
            n[4] = 0;
        }
        break;
    case 60:
        func_80016490(2, 9, obj);
        n = func_8002D1A4();
        if (n != 0) {
            n[0] = 0x41;
            n[1] = 0x1F;
            n[2] = ((obj[0x7E] + 1) & 1) + 3;
            *(u16*)(n + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(n + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(n + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(n + 0x3C) = *(s32*)(obj + 0x3C);
            n[0x14] = obj[0x14];
            *(s32*)(n + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(n + 0xC) = *(s32*)(obj + 0xC);
            n[0x15] = obj[0x15];
            *(u8**)(n + 0x7C) = obj;
            n[4] = 0;
        }
        break;
    case 100:
        func_800FCF40_ovl30(obj);
        *(u8**)(obj + 0x50) = D_800FD764_ovl30;
        *(u8**)(obj + 0x54) = D_800FD760_ovl30;
        *(s16*)(obj + 0x7C) = 20;
        obj[6] = 2;
        break;
    }
    (*(s16*)(obj + 0x7C))++;
    switch (obj[0x47]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        *(u8**)(obj + 0x50) = D_800FD764_ovl30;
        *(u8**)(obj + 0x54) = D_800FD760_ovl30;
        break;
    case 14:
    case 15:
        *(u8**)(obj + 0x50) = D_800FD768_ovl30;
        *(u8**)(obj + 0x54) = D_800FD76C_ovl30;
        break;
    case 16:
        *(u8**)(obj + 0x50) = D_800FD770_ovl30;
        *(u8**)(obj + 0x54) = D_800FD774_ovl30;
        break;
    case 17:
        *(u8**)(obj + 0x50) = D_800FD778_ovl30;
        *(u8**)(obj + 0x54) = D_800FD77C_ovl30;
    case 18:
        *(u8**)(obj + 0x50) = D_800FD778_ovl30;
        *(u8**)(obj + 0x54) = D_800FD77C_ovl30;
        break;
    case 19:
        *(u8**)(obj + 0x50) = D_800FD780_ovl30;
        *(u8**)(obj + 0x54) = D_800FD784_ovl30;
        break;
    case 20:
    case 21:
        *(u8**)(obj + 0x50) = D_800FD788_ovl30;
        *(u8**)(obj + 0x54) = D_800FD78C_ovl30;
        break;
    }
}
