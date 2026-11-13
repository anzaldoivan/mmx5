#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern void func_800FB1BC_ovl27(u8* e, s32 arg1);
extern void* D_800FDAE0_ovl27[];
extern u8 D_800FDA3C_ovl27[];
extern u8 D_800FDA44_ovl27[];
extern u8 D_800FDA4C_ovl27[];
extern u8 D_800FDA54_ovl27[];
extern u8 D_80074EE0[];
extern u8 D_80076240[];
extern u8 D_80076380[];
extern u8 D_800762E0[];
extern u8 D_80076420[];

void func_800F8328_ovl27(u8* a0) {
    s32 r;
    u8* p;
    u8* q;
    u8 t;

    D_1F80004C.bytes[0x8C] = a0[5];
    func_80017248(a0);
    ((void (*)(u8*))D_800FDAE0_ovl27[(s8)a0[5]])(a0);
    func_800317B8(a0);
    r = func_80031DD0(a0);
    p = D_1F80004C.bytes;
    if (*(s16*)(p + 0x84) != 0) {
        (*(s16*)(p + 0x84))--;
    }
    if (r != 0) {
        if (r > 0) {
            if (r != 0x7F) {
                *(u8**)(a0 + 0x58) = D_80074EE0;
                if ((u32)(r - 0x19) < 2) {
                    D_1F80004C.bytes[0x88] = 2;
                } else {
                    D_1F80004C.bytes[0x88] = 0x1E;
                }
                switch ((s8)a0[2]) {
                case 1:
                    (*(u8**)(D_1F80004C.bytes + 0x80))[0x84] = a0[0x5C];
                    if (r == 4 || r == 0xD || r == 0x23) {
                        q = D_1F80004C.bytes;
                        if (*(s16*)(q + 0x84) == 0) {
                            *(s16*)(q + 0x84) = 0x78;
                            D_1F80004C.bytes[0x88] = 0xB4;
                            func_800FB1BC_ovl27(a0, 0);
                        }
                    }
                    break;
                case 2:
                    (*(u8**)(D_1F80004C.bytes + 0x80))[0x86] = a0[0x5C];
                    if (r == 2 || r == 0xB || r == 0x21) {
                        q = D_1F80004C.bytes;
                        if (*(s16*)(q + 0x84) == 0) {
                            *(s16*)(q + 0x84) = 0x78;
                            D_1F80004C.bytes[0x88] = 0xB4;
                            func_800FB1BC_ovl27(a0, 1);
                        }
                    }
                    break;
                case 3:
                    (*(u8**)(D_1F80004C.bytes + 0x80))[0x85] = a0[0x5C];
                    if (r == 5 || r == 0xE || r == 0x24) {
                        q = D_1F80004C.bytes;
                        if (*(s16*)(q + 0x84) == 0) {
                            *(s16*)(q + 0x84) = 0x78;
                            D_1F80004C.bytes[0x88] = 0xB4;
                            func_800FB1BC_ovl27(a0, 2);
                        }
                    }
                    break;
                case 4:
                    (*(u8**)(D_1F80004C.bytes + 0x80))[0x87] = a0[0x5C];
                    if (r == 6 || r == 0xF || r == 0x25 || r == 0x40) {
                        q = D_1F80004C.bytes;
                        if (*(s16*)(q + 0x84) == 0) {
                            *(s16*)(q + 0x84) = 0x78;
                            D_1F80004C.bytes[0x88] = 0xB4;
                            func_800FB1BC_ovl27(a0, 3);
                        }
                    }
                    break;
                }
            }
        } else {
            switch ((s8)a0[2]) {
            case 1:
                func_8004D4F4(3, D_800FDA3C_ovl27, a0);
                (*(u8**)(D_1F80004C.bytes + 0x80))[0x84] = 0;
                break;
            case 2:
                func_8004D4F4(3, D_800FDA4C_ovl27, a0);
                (*(u8**)(D_1F80004C.bytes + 0x80))[0x86] = 0;
                break;
            case 3:
                func_8004D4F4(3, D_800FDA44_ovl27, a0);
                (*(u8**)(D_1F80004C.bytes + 0x80))[0x85] = 0;
                break;
            case 4:
                func_8004D4F4(2, D_800FDA54_ovl27, a0);
                (*(u8**)(D_1F80004C.bytes + 0x80))[0x87] = 0;
                break;
            }
            a0[4] = 6;
            *(s16*)(a0 + 0x7C) = 0x5A;
            *(s16*)(a0 + 0x7E) = 4;
            *(u16*)(a0 + 0x42) &= 0x7FFF;
            func_8004FD24(a0);
            *(s32*)(a0 + 0x20) = 0;
            a0[3] = 0;
            return;
        }
    }
    t = D_1F80004C.bytes[0x88];
    if (t != 0) {
        D_1F80004C.bytes[0x88] = t + 0xFF;
        if (t & 2) {
            *(u16*)(a0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(a0 + 0x42) &= 0x7FFF;
        }
        if (D_1F80004C.bytes[0x88] == 0) {
            *(u16*)(a0 + 0x42) &= 0x7FFF;
            switch ((s8)a0[2]) {
            case 1:
                *(u8**)(a0 + 0x58) = D_80076240;
                break;
            case 2:
                *(u8**)(a0 + 0x58) = D_80076380;
                break;
            case 3:
                *(u8**)(a0 + 0x58) = D_800762E0;
                break;
            case 4:
                *(u8**)(a0 + 0x58) = D_80076420;
                break;
            }
        }
    }
    if ((s8)a0[2] == 4) {
        func_8002FB58(a0);
    }
}
