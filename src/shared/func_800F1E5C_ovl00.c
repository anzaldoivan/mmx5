/* Shared body (DK-5), from the banked draft of func_800F1E5C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_800F2F40_ovl00(u8* a0);
extern u8 D_8009A197;
extern void (*D_800FAD34_ovl00[])(u8*);

void DEDUP_NAME(u8* arg0) {
    s32 r;
    u8* p;

    if (D_8009A197 == 0) {
        *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
        D_800FAD34_ovl00[*(s8*)(arg0 + 5)](arg0);
        func_80017248(arg0);
    }
    *(u16*)(arg0 + 0xA) = *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xA);
    *(u16*)(arg0 + 0xE) = *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xE);
    func_800F2F40_ovl00(arg0);
    r = func_80031DD0(arg0);
    func_800317B8(arg0);
    if (r < 0) {
        if (*(s8*)(arg0 + 2) == 0x10) {
            if (arg0[0x15] == 0) {
                *(u16*)(arg0 + 0xA) += 0x1B;
            } else {
                *(u16*)(arg0 + 0xA) -= 0x1B;
            }
            *(u16*)(arg0 + 0xE) -= 8;
        } else {
            if (arg0[0x15] == 0) {
                *(u16*)(arg0 + 0xA) += 0x1F;
            } else {
                *(u16*)(arg0 + 0xA) -= 0x1F;
            }
            *(u16*)(arg0 + 0xE) -= 0x10;
        }
        func_8004FD24(arg0);
        arg0[3] = 0;
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x88] = 1;
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x8A] = 0;
        arg0[4] = 5;
        return;
    }
    func_8002D9EC(arg0, 0x30, 0x30);
    p = D_1F80004C.bytes;
    if (p[0x85] != 0) {
        *(u16*)(arg0 + 0x42) |= *(u16*)(*(u8**)(p + 0x80) + 0x42) & 0x8000;
    }
}
