#include "types.h"

extern void func_800FCB74_ovl38(ObjFC3F8* arg0, u8 arg1);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(void*, s32);
extern void func_800FCAA0_ovl38(ObjFC3F8* arg0);

void func_800FC484_ovl38(ObjFC3F8* arg0) {
    s32 state = arg0->unk45;

    if (state == 1) {
        func_800FCB74_ovl38(arg0, 1);
        func_80016490(2, 0x9F, arg0);
        state = 0x32;
        arg0->unk7C = state;
    } else if (state == 2) {
        func_800171E8(arg0, 9);
        func_800FCAA0_ovl38(arg0);
        arg0->unk6++;
    }
}
