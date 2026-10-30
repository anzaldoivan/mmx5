/* Shared body (DK-5), from the banked draft of func_800EF204_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800F0C98_ovl00();
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern void func_80017248(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002FB58(u8* obj);
extern u8 D_8009A197;
extern u8 D_800FA86C_ovl00[];
extern void* D_800FA88C_ovl00[];
extern void* D_800FA89C_ovl00;

void DEDUP_NAME(u8* obj) {
    u8* scr;
    s32 r;

    func_800F0C98_ovl00();
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        scr = D_1F80004C.bytes;
        if (scr[0x85] != 0) {
            (*(u8**)(scr + 0x80))[0x84] = 0;
        }
        func_8004FD24(obj);
        func_8004D4F4(3, D_800FA86C_ovl00, obj);
        func_80054440(obj, 0x12);
        obj[4] = 3;
        return;
    }
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (D_8009A197 == 0) {
        ((void (*)(u8*))D_800FA88C_ovl00[((s8*)obj)[5]])(obj);
        func_80017248(obj);
    } else if (((s8*)obj)[5] == 4) {
        ((void (*)(u8*))D_800FA89C_ovl00)(obj);
    }
    if (((s8*)obj)[2] >= 2) {
        r = func_8002D938(obj, 0xC0, 0x40);
    } else {
        r = func_8002D938(obj, 0x40, 0x40);
    }
    if (r == 1) {
        scr = D_1F80004C.bytes;
        if (scr[0x85] != 0) {
            (*(u8**)(scr + 0x80))[0x84] = 0;
        }
        D_1F80004C.bytes[0x93] = r;
        obj[4] = 3;
        return;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    if ((obj[0x70] & 0xC) == 4) {
        scr = D_1F80004C.bytes;
        if (scr[0x85] != 0) {
            (*(u8**)(scr + 0x80))[0x84] = 0;
        }
        func_8004FD24(obj);
        func_8004D4F4(3, D_800FA86C_ovl00, obj);
        obj[4] = 3;
        return;
    }
    func_8002FB58(obj);
}
