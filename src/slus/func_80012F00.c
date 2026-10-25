#include "types.h"

extern s32 func_8006C3B8();
extern s32 CloseTh(s32);
extern s32 func_8006C3C8();

void func_80012F00(s32 idx) {
    u8* p;

    p = (u8*)((idx << 7) + 0x801F8100);
    if (*(u16*)p != 0) {
        *(s16*)p = 0;
        func_8006C3B8();
        CloseTh(*(s32*)(p + 8));
        func_8006C3C8();
    }
}
