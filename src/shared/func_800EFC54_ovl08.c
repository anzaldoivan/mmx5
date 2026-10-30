/* Shared body (DK-5), from the banked draft of func_800EFC54_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_80074EE0[];
extern u8 D_800750C0[];
extern void* D_800F3D30_ovl08[];
extern s32 D_800F4000_ovl08;
extern s32 D_800F4004_ovl08;
extern s32 D_800F4008_ovl08;
extern s32 D_800F400C_ovl08;
extern u8 D_800F3B68_ovl08[];
extern u8 D_800F3B80_ovl08[];
extern u8 D_800F3B84_ovl08[];
extern u8 D_800F3B88_ovl08[];
extern u8 D_800F3D18_ovl08[];
extern void func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80016D54(s32, s32);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8002FB58(u8* obj);

void DEDUP_NAME(u8* obj) {
    u8* g = D_8009A0A0;
    s32 st;
    s32 r;
    u8* q;

    if (g[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        ((void (*)(u8*))D_800F3D30_ovl08[((s8*)obj)[5]])(obj);
    }
    st = ((s8*)obj)[5];
    if (st != 3) {
        *(s32*)(obj + 0x84) = *(s32*)(g + 0x8);
        *(s32*)(obj + 0x94) = st;
        if (((s8*)obj)[4] != 2) {
            if (obj[0x8B] == 0) {
                *(s32*)(obj + 0x50) = D_800F4000_ovl08;
            } else {
                *(s32*)(obj + 0x50) = D_800F4004_ovl08;
            }
            func_800317B8(obj);
            *(s32*)(obj + 0x50) = D_800F400C_ovl08;
            func_800317B8(obj);
        }
        if (obj[0x8B] == 0) {
            *(u8**)(obj + 0x58) = D_80074EE0;
            *(u8**)(obj + 0x54) = D_800F3B80_ovl08;
            *(u8**)(obj + 0x68) = D_800F3B68_ovl08;
        } else {
            *(u8**)(obj + 0x58) = D_80074EE0;
            *(u8**)(obj + 0x54) = D_800F3B84_ovl08;
            *(u8**)(obj + 0x68) = D_800F3B88_ovl08;
        }
        r = func_80031DD0(obj);
        if (r >= 0) {
            q = D_800750C0;
            *(s32*)(obj + 0x54) = D_800F4008_ovl08;
            *(u8**)(obj + 0x58) = q;
            r = func_80031DD0(obj);
        }
        if (r < 0) {
            if (r != -0x38) {
                func_80054440(obj, 0x11);
            }
            goto dead; // !FAKE: goto kept for the matching branch layout
        }
        if (((s8*)obj)[4] != 2) {
            if (func_8002D938(obj, 0x60, 0x60) != 0) {
                func_80016D54(2, 0x51);
                obj[4] = 4;
                return;
            }
            func_8002D9EC(obj, 0x40, 0x40);
        }
    }
    if ((obj[0x70] & 0xC) == 0xC || (obj[0x70] & 3) == 3) {
    dead:
        *(s32*)(obj + 0x68) = 0;
        func_8004FD24(obj);
        func_8004D4F4(4, D_800F3D18_ovl08, obj);
        *(s16*)(obj + 0x7C) = 0x20;
        *(s16*)(obj + 0x7E) = 6;
        obj[3] = 0;
        func_80016D54(2, 0x51);
        obj[4] = 2;
        return;
    }
    func_8002FB58(obj);
}
