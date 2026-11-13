#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);
extern s32 func_8002C338(s32, void*, s32);
extern signed char D_800D1CA2;
extern s32 D_8009A420;
extern s16 D_8009A0AA;
extern u8 D_8009A0A0[];
extern u8 D_800FE198_ovl28[][3];

void func_800F2F14_ovl28(u8* obj) {
    u32 r;
    s32 d;
    u8* q;
    s32 c;
    u8* b2;

    r = func_8002DF78() & 0xF;
    if (D_800D1CA2 / 2 < *(s8*)(obj + 0x5C)) {
        if (!(D_8009A420 & 1)) {
            u8* b = D_8009A0A0;
            s32 dz = *(s16*)(obj + 0xE) - *(s16*)(b + 0xE);

            if ((dz >= 0) ? (dz >= 0x30)
                          : (*(s16*)(b + 0xE) - *(s16*)(obj + 0xE) >= 0x30)) {
                if (r < 9) {
                    D_1F80004C.bytes[0x89] = 1;
                } else {
                    D_1F80004C.bytes[0x89] = 2;
                }
            } else {
                u8* b2 = D_8009A0A0;

                d = *(s16*)(obj + 0xA) - *(s16*)(b2 + 0xA);
                if (d >= 0) {
                    d = d < 0x60;
                } else {
                    d = *(s16*)(b2 + 0xA) - *(s16*)(obj + 0xA) < 0x60;
                }
                if (d) {
                    if (r < 9) {
                        D_1F80004C.bytes[0x89] = 3;
                    } else {
                        D_1F80004C.bytes[0x89] = 4;
                    }
                } else {
                    D_1F80004C.bytes[0x89] = 0;
                }
            }
        } else {
            d = *(s16*)(obj + 0xA) - D_8009A0AA;
            if ((d >= 0) ? (d >= 0x60)
                         : (D_8009A0AA - *(s16*)(obj + 0xA) >= 0x60)) {
                if (r < 8) {
                    D_1F80004C.bytes[0x89] = 1;
                } else {
                    D_1F80004C.bytes[0x89] = 2;
                }
            } else if (r < 4) {
                D_1F80004C.bytes[0x89] = 0;
            } else if (r < 8) {
                D_1F80004C.bytes[0x89] = 3;
            } else {
                D_1F80004C.bytes[0x89] = 4;
            }
        }
    } else {
        if (!(D_8009A420 & 1)) {
            u8* b = D_8009A0A0;
            s32 dz = *(s16*)(obj + 0xE) - *(s16*)(b + 0xE);

            if ((dz >= 0) ? (dz >= 0x30)
                          : (*(s16*)(b + 0xE) - *(s16*)(obj + 0xE) >= 0x30)) {
                if (r < 14) {
                    D_1F80004C.bytes[0x89] = 6;
                } else {
                    D_1F80004C.bytes[0x89] = 2;
                }
            } else {
                b2 = D_8009A0A0;
                d = *(s16*)(obj + 0xA) - *(s16*)(b2 + 0xA);
                if ((d >= 0)
                        ? (d >= 0x60)
                        : (*(s16*)(b2 + 0xA) - *(s16*)(obj + 0xA) >= 0x60)) {
                    if (r < 6) {
                        D_1F80004C.bytes[0x89] = 0;
                    } else {
                        D_1F80004C.bytes[0x89] = 5;
                    }
                } else if (r < 14) {
                    D_1F80004C.bytes[0x89] = 7;
                } else {
                    D_1F80004C.bytes[0x89] = 8;
                }
            }
        } else {
            d = *(s16*)(obj + 0xA) - D_8009A0AA;
            if ((d >= 0) ? (d >= 0x60)
                         : (D_8009A0AA - *(s16*)(obj + 0xA) >= 0x60)) {
                if (r < 4) {
                    D_1F80004C.bytes[0x89] = 6;
                } else if (r < 8) {
                    D_1F80004C.bytes[0x89] = 2;
                } else if (r < 12) {
                    D_1F80004C.bytes[0x89] = 0;
                } else {
                    D_1F80004C.bytes[0x89] = 5;
                }
            } else if (r < 8) {
                D_1F80004C.bytes[0x89] = 7;
            } else if (r < 12) {
                D_1F80004C.bytes[0x89] = 8;
            } else {
                D_1F80004C.bytes[0x89] = 6;
            }
        }
    }
    D_1F80004C.bytes[0x8A] = 0;
    q = D_1F80004C.bytes;
    obj[5] = D_800FE198_ovl28[q[0x89]][q[0x8A]];
    obj[6] = 0;
    q = D_1F80004C.bytes;
    if (D_800FE198_ovl28[q[0x89]][q[0x8A]] == 11) {
        q[0x8B] = 11;
        func_8002C338(0x13C, D_1F800030 + 0xA0, 1);
        func_8002C338(0x13D, D_1F800030 + 0xC0, 1);
    } else {
        c = D_800FE198_ovl28[q[0x89]][q[0x8A] + 1];
        switch (c) {
        case 5:
            q[0x8B] = c;
            func_8002C338(0x13C, D_1F800030 + 0x60, 1);
            func_8002C338(0x13D, D_1F800030 + 0x80, 1);
            break;
        case 9:
            q[0x8B] = c;
            func_8002C338(0x13C, D_1F800030 + 0x120, 1);
            func_8002C338(0x13D, D_1F800030 + 0x140, 1);
            break;
        case 10:
            q[0x8B] = c;
            func_8002C338(0x13C, D_1F800030 + 0xE0, 1);
            func_8002C338(0x13D, D_1F800030 + 0x100, 1);
            break;
        }
    }
    *(s16*)(obj + 0x42) = 0x7CCC;
}
