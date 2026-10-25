#include "types.h"

extern s32 func_8006C3B8();
extern s32 OpenTh(s32, s32, s32);
extern s32 func_8006C3C8();

void func_80012E0C(s32 idx, s32 fn) {
    u8* p;

    func_8006C3B8();
    p = (u8*)((idx << 7) + 0x801F8100);
    *(s32*)(p + 8) = OpenTh(fn, *(s32*)(p + 0x10), *(s32*)(p + 0x44));
    func_8006C3C8();
    *(s16*)p = 2;
}
