#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80017248(u8* obj);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern void func_800FB308_ovl01(u8* obj);
extern u8 D_800FD578_ovl01[];
extern u8 D_800FD57C_ovl01[];
extern u8 D_800FD580_ovl01[];
extern u8 D_800FD584_ovl01[];
extern u8 D_800FD588_ovl01[];
extern u8 D_800FD58C_ovl01[];
extern u8 D_800FD590_ovl01[];
extern u8 D_800FD594_ovl01[];
extern u8 D_800FD598_ovl01[];
extern u8 D_800FD59C_ovl01[];
extern u8 D_800FD5A0_ovl01[];
extern u8 D_800FD5A4_ovl01[];

void func_800F918C_ovl01(u8* obj) {
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
        func_800FB308_ovl01(obj);
        *(u8**)(obj + 0x50) = D_800FD57C_ovl01;
        *(u8**)(obj + 0x54) = D_800FD578_ovl01;
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
        *(u8**)(obj + 0x50) = D_800FD57C_ovl01;
        *(u8**)(obj + 0x54) = D_800FD578_ovl01;
        break;
    case 14:
    case 15:
        *(u8**)(obj + 0x50) = D_800FD580_ovl01;
        *(u8**)(obj + 0x54) = D_800FD584_ovl01;
        break;
    case 16:
        *(u8**)(obj + 0x50) = D_800FD588_ovl01;
        *(u8**)(obj + 0x54) = D_800FD58C_ovl01;
        break;
    case 17:
        *(u8**)(obj + 0x50) = D_800FD590_ovl01;
        *(u8**)(obj + 0x54) = D_800FD594_ovl01;
    case 18:
        *(u8**)(obj + 0x50) = D_800FD590_ovl01;
        *(u8**)(obj + 0x54) = D_800FD594_ovl01;
        break;
    case 19:
        *(u8**)(obj + 0x50) = D_800FD598_ovl01;
        *(u8**)(obj + 0x54) = D_800FD59C_ovl01;
        break;
    case 20:
    case 21:
        *(u8**)(obj + 0x50) = D_800FD5A0_ovl01;
        *(u8**)(obj + 0x54) = D_800FD5A4_ovl01;
        break;
    }
}
