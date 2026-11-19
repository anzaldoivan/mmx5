#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A197;
extern void* D_800FAB04_ovl09[];

void func_800F1160_ovl09(u8* obj) {
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        animate_object(obj);
        ((void (*)(u8*))D_800FAB04_ovl09[*(s8*)(obj + 5)])(obj);
    } else if (*(s8*)(obj + 5) >= 4) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        animate_object(obj);
        ((void (*)(u8*))D_800FAB04_ovl09[*(s8*)(obj + 5)])(obj);
    }
    if (func_80031DD0(obj) < 0) {
        set_animation(obj, 0);
        *(s16*)(obj + 0x7C) = 0x78;
        *(s8*)(obj + 5) = 4;
        *(s32*)(obj + 0x54) = 0;
    }
    func_8002D9EC(obj, 0x20, 0x20);
}
