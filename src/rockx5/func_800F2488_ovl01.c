#include "types.h"
#include "addr.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002FB58(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern u8 D_8009A197;
extern u8 D_800FC93C_ovl01[];
extern void* D_800FC958_ovl01[];

void func_800F2488_ovl01(u8* arg0) {
    u8 f;

    if (D_8009A197 == 0) {
        *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
        ((void (*)(u8*))D_800FC958_ovl01[*(s8*)(arg0 + 5)])(arg0);
    }
    func_800317B8(arg0);
    *(s32*)(D_1F80004C.bytes + 0x84) = func_80031DD0(arg0);
    if (*(s32*)(D_1F80004C.bytes + 0x84) < 0) {
        func_80054440(arg0, 0x12);
        goto block_9; // !FAKE: goto kept for the matching branch layout
    }
    if (func_8002D938(arg0, 0x80, 0x40) != 0) {
        arg0[4] = 3;
        return;
    }
    func_8002D9EC(arg0, 0x20, 0x20);
    f = arg0[0x70];
    if ((f & 0xC) == 0xC || (f & 3) == 3) {
    block_9: // !FAKE: label kept for the matching branch layout
        func_8004D4F4(5, D_800FC93C_ovl01, arg0);
        arg0[3] = 0;
        *(s16*)(arg0 + 0x7C) = 0x14;
        *(s16*)(arg0 + 0x7E) = 5;
        arg0[4] = 4;
        return;
    }
    func_8002FB58(arg0);
}
