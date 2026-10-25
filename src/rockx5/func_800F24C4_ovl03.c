#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_80016490(s32, s32, void*);
extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void func_800F24C4_ovl03(u8* obj) {
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        obj[6] = 2;
        func_80016490(5, 0x26, 0);
        if (((s8*)obj)[2] != 1) {
            func_8005019C(0x21, 2, obj, 0x18, 3);
            func_8005019C(0x22, 2, obj, 0x18, 3);
        }
    }
}
