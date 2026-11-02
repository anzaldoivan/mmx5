#include "types.h"

extern s32 func_80043B88(u8* arg0);
extern void func_8003A9AC(u8* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern void func_8003A94C(u8* arg0);
extern s32 func_80039B50(u8* arg0);
extern void func_80017248(u8* obj);
extern void func_8003AE80(u8* arg0);
extern void func_8003F2D8(u8* arg0, s32 arg1);

void func_80036488(u8* arg0) {
    s32 t;

    func_80043B88(arg0);
    if (arg0[0x89] & 8) {
        func_8003A9AC(arg0);
        return;
    }
    if (*(s8*)(arg0 + 0xD3) != 0) {
        goto block_a94c; // !FAKE: goto kept for the matching branch layout
    }
    {
        if (func_8003EFE0(arg0) != 0) {
            return;
        }
        if (!(arg0[0x89] & 3)) {
        block_a94c: // !FAKE: label kept for the matching branch layout
            func_8003A94C(arg0);
            return;
        }
        if (func_80039B50(arg0) != 0) {
            return;
        }
        func_80017248(arg0);
        if (*(s8*)(arg0 + 0x45) & 0x80) {
            if (arg0[0x89] & 1) {
                arg0[0x15] = 0;
            } else {
                arg0[0x15] = 0x40;
            }
            arg0[0x45] &= 0x3F;
        }
        t = arg0[0x8A] - 1;
        arg0[0x8A] = t;
        if ((t << 24) == 0) {
            func_8003AE80(arg0);
            return;
        }
        func_8003F2D8(arg0, 0xD);
    }
}
