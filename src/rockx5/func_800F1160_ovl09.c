#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A197;
extern void* D_800FAB04_ovl09[];

void func_800F1160_ovl09(u8* obj) {
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_80017248(obj);
        ((void (*)(u8*))D_800FAB04_ovl09[*(s8*)(obj + 5)])(obj);
    } else if (*(s8*)(obj + 5) >= 4) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_80017248(obj);
        ((void (*)(u8*))D_800FAB04_ovl09[*(s8*)(obj + 5)])(obj);
    }
    if (func_80031DD0(obj) < 0) {
        func_800171E8(obj, 0);
        *(s16*)(obj + 0x7C) = 0x78;
        *(s8*)(obj + 5) = 4;
        *(s32*)(obj + 0x54) = 0;
    }
    func_8002D9EC(obj, 0x20, 0x20);
}
