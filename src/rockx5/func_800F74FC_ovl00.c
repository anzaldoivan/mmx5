#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8003D2C4(void);
extern s32 func_80044DE0();
extern u8 D_80091C44;
extern u8 D_8009A240;
extern u8 D_800D1C00[];
extern u8 D_800FB3D8_ovl00[];

void func_800F74FC_ovl00(u8* obj) {
    s32 t;

    func_8002D9EC(obj, 0xFF, 0xFF);
    if (D_80091C44 == 0 && func_80044DE0() == 0) {
        D_800D1C00[0x16] = 0;
        D_800D1C00[0x13] = 0;
        D_800D1C00[0x19] = 0;
        D_800D1C00[0x18] = 0;
        D_800D1C00[0x17] = 0;
        D_800D1C00[0x14] = 0;
        D_800D1C00[0x15] = 0;
        if (*(s8*)(obj + 0x5C) < *(s8*)(D_800D1C00 + 0xA2)) {
            t = *(u16*)(obj + 0x7C) - 1;
            *(u16*)(obj + 0x7C) = t;
            if ((t << 16) == 0) {
                func_80016490(0, 0xE, 0);
                *(u16*)(obj + 0x7C) = 3;
            }
            obj[0x5C]++;
            func_8002D9EC(obj, 0xFF, 0xFF);
            return;
        }
        func_800171E8(obj, 0);
        *(u8**)(obj + 0x68) = D_800FB3D8_ovl00;
        func_8003D2C4();
        D_8009A240 = 4;
        func_8002D9EC(obj, 0xFF, 0xFF);
        obj[5] = 4;
        obj[6] = 0;
    }
}
