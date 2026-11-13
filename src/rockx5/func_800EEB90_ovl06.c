#include "types.h"

extern u8* func_8002D0E4(void);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D078();
extern s32 func_8002B5B4(s32);
extern void func_80016D54(s32, s32);

void func_800EEB90_ovl06(u8* obj) {
    u8* p;
    u8* q;
    u8 r;
    u8 c;
    u32 i;
    u32 bits;
    s32 v;

    if (obj[0x97] & 2) {
        return;
    }
    if ((*(u16*)(obj + 0x96) & 0xC000) == 0x8000) {
        return;
    }
    switch (obj[0x94]) {
    case 0:
        v = *(u16*)(obj + 0x88) & 0x30;
        if (v == 0) {
            return;
        }
        obj[0x94] = 1;
        obj[0x95] = 0x3C;
        *(u16*)(obj + 0xA6) = v;
        return;
    case 1:
        if ((*(u16*)(obj + 0x88) & *(u16*)(obj + 0xA6)) == 0) {
            obj[0x94] = 0;
            *(u16*)(obj + 0xA6) = 0;
            return;
        }
        if (--obj[0x95] != 0) {
            return;
        }
        obj[0x94] = 2;
        if (*(s8*)(obj + 2) == 0) {
            return;
        }
        if ((*(volatile u16*)(obj + 0x96) & 0xC000) !=
            0x4000) { // !FAKE: volatile forces the reload
            return;
        }
        q = func_8002D0E4();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = 0x16;
            q[2] = 0x10;
            *(u16*)(q + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(q + 0xE) = *(u16*)(obj + 0xE);
            *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(q + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(q + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            q[0x16] = obj[0x16];
            *(u8**)(q + 0x50) = obj;
            q[0x15] = obj[0x15];
        }
        func_80016490(5, 8, 0);
        return;
    case 2:
        if ((*(u16*)(obj + 0x88) & *(u16*)(obj + 0xA6)) != 0) {
            return;
        }
        if (*(s8*)(obj + 2) != 0 && (*(u16*)(obj + 0x96) & 0xC000) == 0x4000 &&
            obj[5] != 3 && obj[5] != 6 && obj[5] != 9 && obj[5] != 10 &&
            obj[5] != 11 && obj[5] != 13 && obj[5] != 16 && obj[5] != 17) {
            bits = obj[0x7F];
            for (i = 0; i < 3; i++, bits >>= 1) {
                if (bits & 1) {
                    continue;
                }
                c = i;
                if (obj[0x86] < 3) {
                    p = func_8002D078();
                    if (p != 0) {
                        p[0] = 0x41;
                        p[1] = 0x3C;
                        p[2] = c;
                        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
                        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
                        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                        r = func_8002B5B4(0x81);
                        *(u16*)(p + 0x42) = ((r * 4 + 0x18) % 16) |
                                            ((((r + 6) / 4) + 0x1E0) << 6);
                        p[0x16] = obj[0x16];
                        *(u8**)(p + 0x7C) = obj;
                        p[0x15] = obj[0x15];
                    }
                }
                obj[0x7F] |= 1 << i;
            }
            obj[0x7E] = 0x10;
            func_80016490(5, 6, 0);
            obj[0x94] = 0;
            *(u16*)(obj + 0xA6) = 0;
        } else {
            obj[0x94] = 0;
            *(u16*)(obj + 0xA6) = 0;
            func_80016D54(5, 8);
        }
        return;
    }
}
