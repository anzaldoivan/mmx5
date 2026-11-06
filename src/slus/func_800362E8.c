#include "types.h"

extern s32 func_80043B88(u8* arg0);
extern void func_8003A9AC(u8* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern s32 func_800439A8(u8* obj);
extern s32 func_80039D2C(u8* obj);
extern s32 func_800390A4(u8* p);
extern s32 func_80039AE0(void* self);
extern s32 func_80038850(u8* self);
extern void func_80017248(u8* obj);
extern void func_8003D120(u8* obj);
extern void func_8003D344(void* arg0);
extern void func_8003F2D8(u8* arg0, s32 arg1);

void func_800362E8(u8* arg0) {
    func_80043B88(arg0);
    if (arg0[0x89] & 8) {
        func_8003A9AC(arg0);
        return;
    }
    if (func_8003EFE0(arg0) == 0 && func_800439A8(arg0) == 0 &&
        func_80039D2C(arg0) == 0 && func_800390A4(arg0) == 0 &&
        func_80039AE0(arg0) == 0 && func_80038850(arg0) == 0) {
        func_80017248(arg0);
        func_8003D120(arg0);
        func_8003D344(arg0);
        func_8003F2D8(arg0, 0xB);
    }
}
