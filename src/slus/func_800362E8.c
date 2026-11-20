#include "types.h"
#include "mmx5/globals.h"

extern void func_8003A9AC(u8* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern s32 func_800439A8(u8* obj);
extern s32 try_grab_ladder_from_air(u8* obj);
extern s32 func_800390A4(u8* p);
extern s32 try_enter_wall_cling(void* self);
extern s32 func_80038850(u8* self);
extern void func_8003D120(u8* obj);
extern void func_8003D344(void* arg0);

void func_800362E8(u8* arg0) {
    func_80043B88(arg0);
    if (arg0[0x89] & 8) {
        func_8003A9AC(arg0);
        return;
    }
    if (func_8003EFE0(arg0) == 0 && func_800439A8(arg0) == 0 &&
        try_grab_ladder_from_air(arg0) == 0 && func_800390A4(arg0) == 0 &&
        try_enter_wall_cling(arg0) == 0 && func_80038850(arg0) == 0) {
        animate_object(arg0);
        func_8003D120(arg0);
        func_8003D344(arg0);
        func_8003F2D8(arg0, 0xB);
    }
}
