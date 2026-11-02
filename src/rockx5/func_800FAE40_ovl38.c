#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004FD24(u8* a0);
extern void func_800FCAA0_ovl38(u8*);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FD594_ovl38[];
extern u8 D_800FD598_ovl38[];

void func_800FAE40_ovl38(u8* arg0) {
    s32 dx;
    s32 dy;
    u8* p;
    u8* q;
    s32 v;

    func_80017248(arg0);
    dx = rcos(*(s16*)(D_1F80004C.bytes + 0x84)) << 4;
    dy = rsin(*(s16*)(D_1F80004C.bytes + 0x84)) << 4;
    *(s16*)(D_1F80004C.bytes + 0x84) += 0x22;
    *(s16*)(D_1F80004C.bytes + 0x84) &= 0xFFF;
    if (dx != 0) {
        dx *= 50;
    } else {
        dx = 0;
    }
    if (dy != 0) {
        dy *= 50;
    } else {
        dy = 0;
    }
    *(s32*)(arg0 + 8) = *(s32*)(*(u8**)(D_1F80004C.bytes + 0x80) + 8) + dx;
    *(s32*)(arg0 + 0xC) = *(s32*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xC) - dy;
    p = *(u8**)(D_1F80004C.bytes + 0x80);
    if (*(s8*)(p + 4) == 2) {
        func_8004FD24(arg0);
        arg0[3] = 0;
        arg0[4] = 4;
        arg0[5] = 0;
        return;
    }
    if (p[0x47] == 0x2E) {
        arg0[3] = 0;
        *(u8**)(arg0 + 0x54) = 0;
        *(u8**)(arg0 + 0x50) = 0;
    } else {
        arg0[3] = 1;
        *(u8**)(arg0 + 0x54) = D_800FD598_ovl38;
        *(u8**)(arg0 + 0x50) = D_800FD594_ovl38;
    }
    func_800317B8(arg0);
    if (func_80031DD0(arg0) < 0) {
        v = *(s8*)(arg0 + 2);
        switch (v) {
        case 1:
            q = *(u8**)(D_1F80004C.bytes + 0x80);
            v = q[0x91] & 0xFE;
            break;
        case 2:
            q = *(u8**)(D_1F80004C.bytes + 0x80);
            v = q[0x91] & 0xFD;
            break;
        case 3:
            q = *(u8**)(D_1F80004C.bytes + 0x80);
            v = q[0x91] & 0xFB;
            break;
        default:
            goto skip; // !FAKE: goto kept for the shared byte store
        }
        q[0x91] = v;
    skip: // !FAKE: label past the shared byte store
        arg0[3] = 0;
        func_8004FD24(arg0);
        arg0[4] = 4;
        arg0[5] = 0;
        return;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s16*)(arg0 + 0x7C) = 30;
        func_800FCAA0_ovl38(arg0);
    }
}
