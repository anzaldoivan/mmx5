#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002385C(s32, s32, s32);
extern u8* func_8002D27C(void);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);
extern u8 D_800D1C00[];

void func_800F741C_ovl00(u8* obj) {
    u8* p;

    if (*(s16*)(obj + 0xE) >= 0x11C) {
        *(s16*)(obj + 0xE) = 0x11C;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        D_800D1C00[0x24] = 1;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x37;
        }
        func_8002385C(1, 0xFF, D_800D1C00[0x2E]);
        D_800D1C00[0x2E] = 1;
        D_800D1C00[0x16] = 1;
        D_800D1C00[0x13] = 1;
        D_800D1C00[0x19] = 1;
        D_800D1C00[0x18] = 1;
        D_800D1C00[0x17] = 1;
        D_800D1C00[0x14] = 1;
        D_800D1C00[0x15] = 1;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
