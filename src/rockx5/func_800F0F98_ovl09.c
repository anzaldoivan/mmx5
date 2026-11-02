#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D800(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern u8 D_8009A197;
extern void* D_800FAB5C_ovl09[];

void func_800F0F98_ovl09(u8* o) {
    u8 f;

    if (D_8009A197 == 0) {
        *(s32*)(o + 0x18) = *(s32*)(o + 0x8);
        *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
        ((void (*)(u8*))D_800FAB5C_ovl09[*(s8*)(o + 5)])(o);
        func_80017248(o);
        if (--*(s16*)(o + 0x8C) == 0) {
            o[4] = 2;
            return;
        }
    } else if (o[0x47] == 5) {
        func_80017248(o);
    }
    f = o[0x70];
    if ((f & 0xC) == 0xC || (f & 3) == 3) {
        func_8004FD24(o);
        goto end; // !FAKE: goto kept for the matching branch layout
    }
    if (*(s8*)(o + 0x45) == 3) {
        *(s32*)(o + 0x8) = *(s32*)(o + 0x18);
        *(s32*)(o + 0xC) = *(s32*)(o + 0x1C);
    }
    func_800317B8(o);
    *(u16*)(o + 0x42) &= 0x7FFF;
    if (func_80031DD0(o) < 0) {
        *(s32*)(o + 0x54) = 0;
        *(s32*)(o + 0x50) = 0;
        func_8004FD24(o);
        goto end; // !FAKE: goto kept for the matching branch layout
    }
    if (func_8002D800(o) == 0) {
        if (*(s16*)(o + 0x8C) < 0x3D && !(*(u16*)(o + 0x8C) & 1)) {
            o[3] = 0;
            return;
        }
        func_8002D9EC(o, 0x20, 0x20);
        return;
    }
end:
    o[4] = 2;
}
