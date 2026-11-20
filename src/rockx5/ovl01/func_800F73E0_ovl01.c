#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern void (*D_800FD2EC_ovl01[])(u8*);
extern u8 D_800FD2D0_ovl01[];
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800F73E0_ovl01(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) != 5) {
        if (D_8009A197 == 0) {
            D_800FD2EC_ovl01[*(s8*)(obj + 5)](obj);
            animate_object(obj);
        }
        if (func_800317B8(obj) == 0 && func_80031DD0(obj) >= 0) {
            goto alive; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8004FD24(obj);
    func_8004D4F4(2, D_800FD2D0_ovl01, obj);
    obj[4] = 3;
    return;
alive: // !FAKE: label kept for the matching branch layout
    if (is_off_screen(obj, 0x200, 0x100) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 3;
}
