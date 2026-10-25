#include "types.h"

extern void func_800FCB74_ovl38(ObjFC3F8* arg0, u8 arg1);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);

void func_800FC504_ovl38(ObjFC3F8* arg0) {
    s8 state = arg0->unk45;

    if (state == 1) {
        func_800FCB74_ovl38(arg0, 0);
        func_800FCB74_ovl38(arg0, 2);
        func_80016490(2, 0x9F, arg0);
    } else if (state == 2) {
        func_800171E8((u8*)arg0, 3);
        arg0->unk6++;
    }
}
