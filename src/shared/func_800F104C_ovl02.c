/* Shared body (DK-5), from the banked draft of func_800F104C_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"

#include "addr.h"
extern u8 D_8009A0A0[];
extern void (*D_800F4738_ovl02[])(u8*);
extern u8 D_800F4624_ovl02[];
extern u8 D_800F4628_ovl02[];
extern u8 D_800F4620_ovl02[];
extern u8 D_800F4714_ovl02[];
extern u8 D_800753E0[];
extern u8 D_80074EE0[];
extern void func_80017248(u8* obj);
extern void func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8002FB58(u8* a0);

void DEDUP_NAME(u8* obj) {
    u8* p = D_8009A0A0;
    s32 mode;
    s32 r;

    if (p[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_80017248(obj);
        D_800F4738_ovl02[*(signed char*)(obj + 5)](obj);
        if (--D_1F80004C.bytes[0x81] == 0xFF) {
            D_1F80004C.bytes[0x81] = 8;
            if (*(s16*)(p + 0xA) < *(s16*)(obj + 0xA)) {
                obj[0x15] = 0;
            } else {
                obj[0x15] = 0x40;
            }
        }
    }
    func_800317B8(obj);
    mode = D_1F80004C.bytes[0x82];
    if (mode != 0) {
        if (mode == 1) {
            *(u8**)(obj + 0x54) = D_800F4624_ovl02;
        } else if (mode == 2) {
            *(u8**)(obj + 0x54) = D_800F4628_ovl02;
        }
        *(u8**)(obj + 0x58) = D_800753E0;
        r = func_80031DD0(obj);
        if (r < 0) {
            func_80054440(obj, 0x12);
            goto die; // !FAKE: nested branch joins the shared die block as the target does; untested without
        }
        if (r == 0) {
            *(u8**)(obj + 0x54) = D_800F4620_ovl02;
            *(u8**)(obj + 0x58) = D_80074EE0;
            func_80031DD0(obj);
        }
    } else {
        *(u8**)(obj + 0x54) = D_800F4620_ovl02;
        *(u8**)(obj + 0x58) = D_80074EE0;
        func_80031DD0(obj);
    }
    if (func_8002D938(obj, 0x40, 0x40) != 0) {
        obj[4] = 3;
        return;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    if ((obj[0x70] & 0xC) == 0xC || (obj[0x70] & 3) == 3) {
    die:
        func_8004D4F4(5, D_800F4714_ovl02, obj);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0x14;
        *(s16*)(obj + 0x7E) = 5;
        obj[4] = 4;
        return;
    }
    func_8002FB58(obj);
}
