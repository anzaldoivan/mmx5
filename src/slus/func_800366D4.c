#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80038850(u8* self);
extern s32 func_800390A4(u8* p);
extern s32 func_80039AE0(void* self);
extern s32 func_80039D2C(u8* obj);
extern void func_8003D120(u8*);
extern void func_8003D344(void* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern void func_8003F294(u8* arg0, s32 arg1);
extern void func_8003F2D8(u8* arg0, s32 arg1);
extern s32 func_80043904(u8* arg0);

void func_800366D4(u8* arg0) {
    if (*(s8*)(arg0 + 0xD3) != 0) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (arg0[0x89] & 4) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (!(*(u16*)(arg0 + 0x7C) & 0x80)) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (func_8003EFE0(arg0) == 0 && func_80043904(arg0) == 0 &&
        func_80039D2C(arg0) == 0 && func_800390A4(arg0) == 0 &&
        func_80039AE0(arg0) == 0 && func_80038850(arg0) == 0) {
        func_80017248(arg0);
        func_8003D120(arg0);
        func_8003D344(arg0);
        if (*(s32*)(arg0 + 0x24) <= 0) {
            func_8003F294(arg0, 0xB);
            *(s8*)(arg0 + 0x67) = -1;
            arg0[0x5] = 7;
            arg0[0x6] = 0;
            return;
        }
        func_8003F2D8(arg0, 0xE);
    }
}
