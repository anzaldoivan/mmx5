#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_800F5988_ovl00(s32, void*, u8*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_8002A600(s32, s32, s32);
extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);
extern void func_8001296C(s32);
extern u8 D_800FB26C_ovl00[];

void func_800F5D90_ovl00(u8* obj) {
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        obj[3] = 0;
        *(s32*)(obj + 0x7C) = 0x3C;
        obj[4] = 3;
        obj[6] = 0;
        func_800F5988_ovl00(0xF, D_800FB26C_ovl00, obj, 0);
        func_80016490(5, 5, 0);
        func_8002A600(0x20, 4, 1);
        func_8005019C(0x21, 2, obj, 0x18, 6);
        func_8005019C(0x22, 2, obj, 0x18, 6);
        func_8001296C(3);
    }
}
