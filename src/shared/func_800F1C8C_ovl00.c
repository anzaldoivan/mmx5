/* Shared body (DK-5), from the banked draft of func_800F1C8C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_80031DD0(u8* a0);
extern s32 func_800317B8(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8002FB58(u8* obj);
extern u8 D_8009A197;
extern void* D_800FAD10_ovl00[];
extern u8 D_80074EE0[];
extern u8 D_800FAA1C_ovl00[];
extern u8 D_800FAA20_ovl00[];
extern u8 D_80075200[];
extern u8 D_800FAC8C_ovl00[];

void DEDUP_NAME(u8* arg0) {
    u8* s;
    s32 r;
    u8 m;
    u8* t;

    if (D_8009A197 == 0) {
        *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
        func_80017248(arg0);
        ((void (*)(u8*))D_800FAD10_ovl00[(s8)arg0[5]])(arg0);
    }
    s = D_1F80004C.bytes;
    if (s[0x89] != 0) {
        *(u8**)(arg0 + 0x54) = s + 0x80;
        t = D_1F80004C.bytes + 0x80;
        *(u8**)(arg0 + 0x58) = D_80074EE0;
        *(u8**)(arg0 + 0x50) = t;
        r = func_80031DD0(arg0);
        func_800317B8(arg0);
        if (r != 0) {
            goto test; // !FAKE: goto kept for the matching branch layout
        }
    }
    *(u8**)(arg0 + 0x54) = D_800FAA1C_ovl00;
    *(u8**)(arg0 + 0x50) = D_800FAA20_ovl00;
    *(u8**)(arg0 + 0x58) = D_80075200;
    r = func_80031DD0(arg0);
    func_800317B8(arg0);
    if (r < 0) {
        func_80054440(arg0, 0x12);
        goto fail; // !FAKE: goto kept for the matching branch layout
    }
test:
    if (func_8002D938(arg0, 0x200, 0x200) != 0) {
        *(s16*)(arg0 + 0x7C) = 4;
        D_1F80004C.bytes[0x87] = 0;
        D_1F80004C.bytes[0x86] = 1;
        arg0[4] = 4;
        return;
    }
    func_8002D9EC(arg0, 0x70, 0x30);
    m = arg0[0x70];
    if ((m & 0xC) == 0xC || (m & 3) == 3) {
    fail:
        func_8004D4F4(4, D_800FAC8C_ovl00, arg0);
        arg0[3] = 0;
        *(s16*)(arg0 + 0x7C) = 0x19;
        *(s16*)(arg0 + 0x7E) = 5;
        D_1F80004C.bytes[0x87] = 0;
        arg0[4] = 6;
        return;
    }
    func_8002FB58(arg0);
}
