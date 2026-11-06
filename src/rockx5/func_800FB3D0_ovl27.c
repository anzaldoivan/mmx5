#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void* D_800FDBA4_ovl27[];

void func_800FB3D0_ovl27(u8* o) {
    ((void (*)(u8*))D_800FDBA4_ovl27[*(s8*)(o + 6)])(o);
    func_800317B8(o);
    if (func_80031DD0(o) < 0) {
        func_8004FD24(o);
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (o[2] < 2) {
        if (*(s16*)(o + 0x88) == 0) {
            if (o[0x70] != 0 || (func_8002F8FC(o), o[0x70] != 0)) {
                func_8004FC64(o);
                o[4]++;
                return;
            }
        } else {
            *(s16*)(o + 0x88) = *(s16*)(o + 0x88) - 1;
        }
    }
    if (func_8002D938(o, 0x20, 0x20) == 1) {
    inc: // !FAKE: label kept for the matching branch layout
        o[4]++;
    }
}
