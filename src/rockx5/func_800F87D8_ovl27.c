#include "types.h"
#include "addr.h"

extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD90(u8*, s32, s32, s32);
extern u8 D_800FDA3C_ovl27[];
extern u8 D_800FDA44_ovl27[];
extern u8 D_800FDA4C_ovl27[];
extern u8 D_800FDA54_ovl27[];

void func_800F87D8_ovl27(u8* a0) {

    if (*(u16*)(a0 + 0x7C) & 1) {
        a0[3] ^= 1;
    }
    if (--*(s16*)(a0 + 0x7C) == 0) {
        switch ((s8)a0[2]) {
        case 1:
            func_8004D4F4(5, D_800FDA3C_ovl27, a0);
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x88] = 1;
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x8C] &= 0xF7;
            break;
        case 2:
            func_8004D4F4(5, D_800FDA4C_ovl27, a0);
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x88] = 1;
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x8C] &= 0xFB;
            break;
        case 3:
            func_8004D4F4(5, D_800FDA44_ovl27, a0);
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x88] = 1;
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x8C] &= 0xFD;
            break;
        case 4:
            func_8004D4F4(3, D_800FDA54_ovl27, a0);
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x89] = 0;
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x8C] &= 0xFE;
            break;
        }
        a0[3] = 0;
        a0[4] = 4;
        return;
    }
    if (--*(s16*)(a0 + 0x7E) == 0) {
        func_8004FD90(a0, 1, 0x1F, 0x1F);
        *(u16*)(a0 + 0x7E) = 4;
    }
    if (!(*(u16*)(a0 + 0x7C) & 0x1F)) {
        switch ((s8)a0[2]) {
        case 1:
            func_8004D4F4(3, D_800FDA3C_ovl27, a0);
            break;
        case 2:
            func_8004D4F4(3, D_800FDA4C_ovl27, a0);
            break;
        case 3:
            func_8004D4F4(3, D_800FDA44_ovl27, a0);
            break;
        case 4:
            func_8004D4F4(2, D_800FDA54_ovl27, a0);
            break;
        }
    }
}
