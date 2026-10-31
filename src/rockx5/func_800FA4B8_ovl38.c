#include "types.h"

extern void func_800FCAA0_ovl38(u8*);
extern void func_800171E8(u8* obj, s32 state);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FD580_ovl38[];
extern u8 D_800FD584_ovl38[];
extern u8 D_800FD588_ovl38[];

void func_800FA4B8_ovl38(u8* obj) {
    s32 v;
    s32 a;
    s32 c;

    func_800FCAA0_ovl38(obj);
    func_800171E8(obj, 5);
    *(u8**)(obj + 0x50) = D_800FD580_ovl38;
    *(u8**)(obj + 0x54) = D_800FD584_ovl38;
    *(u8**)(obj + 0x68) = D_800FD588_ovl38;
    if (obj[0x15] == 0) {
        c = rcos(0x79C);
        a = 0x79C;
    } else {
        c = rcos(0x64);
        a = 0x64;
    }
    *(s32*)(obj + 0x20) = c * 16;
    *(volatile s32*)(obj + 0x24) =
        rsin(a) * 16; // !FAKE: volatile pins the store order
    v = *(
        volatile s32*)(obj +
                       0x20); // !FAKE: volatile keeps the lw below the 0x24 store
    if (v != 0) {
        *(s32*)(obj + 0x20) = v * 11 / 2;
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    v = *(s32*)(obj + 0x24);
    if (v != 0) {
        *(s32*)(obj + 0x24) = v * 11 / 2;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s16*)(obj + 0x7C) = 8;
    obj[6]++;
}
