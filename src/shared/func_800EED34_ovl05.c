/* Shared body (DK-5), from the banked draft of func_800EED34_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern u8 D_800F4EBC_ovl05[];
extern void (*D_800F4FD8_ovl05[])(u8*);
extern void func_80017248(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800EF390_ovl05(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8* a0);
extern int func_8002D7A0();

void DEDUP_NAME(u8* obj) {
    signed char kind;

    func_80017248(obj);
    if (func_80031DD0(obj) < 0) {
        func_80054440(obj, 0x12);
        goto die;
    }
    kind = *(signed char*)(obj + 2);
    if ((kind == 0 && (obj[0x70] & 7)) || (kind == 1 && (obj[0x70] & 0xE)) ||
        (kind == 2 && (obj[0x70] & 0xD)) || (kind == 3 && (obj[0x70] & 0xB))) {
    die:
        func_8004FD24(obj);
        func_8004D4F4(4, D_800F4EBC_ovl05, obj);
        obj[4] = 2;
        return;
    }
    if (D_8009A197 == 0) {
        func_800EF390_ovl05(obj);
        D_800F4FD8_ovl05[*(signed char*)(obj + 5)](obj);
    }
    func_800317B8(obj);
    if (func_8002D800(obj) == 0) {
        func_8002D89C(obj);
        return;
    }
    func_8002D7A0(obj);
}
