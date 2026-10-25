#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 D_8009A420;

void func_800F33BC_ovl02(u8* obj) {
    func_80017248(obj);
    *(s16*)(obj + 0x7C) += 1;
    if (*(s16*)(obj + 0x7C) >= 0x1F) {
        obj[3] = 0;
        obj[4]++;
    } else if (D_8009A420 & 1) {
        obj[3] = 0;
    } else {
        func_8002D9EC(obj, 0x20, 0x20);
    }
}
