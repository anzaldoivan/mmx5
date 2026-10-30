#include "types.h"

extern u8 D_8009A197;
extern void* D_800FC674_ovl01[];
extern u8 D_800FC65C_ovl01[];

extern void func_800F07B0_ovl01(void);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002FB58(u8* obj);

void func_800EFF34_ovl01(u8* o) {
    s32 r;

    if (D_8009A197 == 0) {
        func_800F07B0_ovl01();
        *(s32*)(o + 0x18) = *(s32*)(o + 0x8);
        *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
        ((void (*)(u8*))D_800FC674_ovl01[(s8)o[5]])(o);
    }
    if ((s8)o[5] != 4) {
        func_800317B8(o);
        r = func_80031DD0(o);
        if ((s8)o[2] == 4 && r > 0 && *(s32*)(o + 0x90) == 0) {
            *(s32*)(o + 0x88) = 1;
            *(s32*)(o + 0x90) = 1;
        }
        if (r < 0) {
            func_8004FD24(o);
            func_8004D4F4(5, D_800FC65C_ovl01, o);
            func_80054440(o, 0xC);
            o[4] = 2;
            return;
        }
        if (func_8002D938(o, 0x40, 0x40) == 0) {
            func_8002D9EC(o, 0x20, 0x20);
        } else {
            o[4] = 3;
        }
    }
    if ((o[0x70] & 0xC) == 0xC || (o[0x70] & 3) == 3) {
        func_8004FD24(o);
        func_8004D4F4(5, D_800FC65C_ovl01, o);
        o[4] = 2;
        return;
    }
    func_8002FB58(o);
}
