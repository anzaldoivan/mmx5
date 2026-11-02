#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8* func_8002D0E4(void);
extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern s16 D_8009A0AA;

static inline s32 func_800F2C20_ovl28_mask(u8 c) {
    s32 m;

    m = 2;
    if (c != 0) {
        m = 1;
    }
    return m;
}

void func_800F2C20_ovl28(u8* obj) {
    u8* p;
    s32 r0;
    s32 r1;
    s32 m;
    s8 t;
    s32 d;
    u8 c;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 3) {
        return;
    }
    func_8002DED4(obj);
    p = func_8002D0E4();
    if (p != 0 && *(s8*)(obj + 0x45) == 4) {
        p[0] = 0x61;
        p[1] = 0xB;
        p[2] = 5;
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        r0 = func_8002B5B4(0x40);
        r1 = func_8002B5B4(0x40);
        *(s16*)(p + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        p[0x15] = obj[0x15];
        if (p[0x15] == 0) {
            *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0x30;
        } else {
            *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x30;
        }
        *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) + 0x10;
        *(u8**)(p + 0x50) = obj;
    }
    if (*(s8*)(obj + 0x45) == 1 && (t = *(s8*)(obj + 7)) == 2) {
        obj[7] = 3;
        obj[6] = 5;
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0xB;
            p[2] = t;
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            p[0x15] = obj[0x15];
            if (p[0x15] == 0) {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x20;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0x20;
            }
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) + 8;
            *(u8**)(p + 0x50) = obj;
        }
    } else {
        c = obj[0x15];
        m = func_800F2C20_ovl28_mask(c);
        if (c != 0) {
            if (*(s32*)(obj + 0x20) < 0x42000) {
                *(s32*)(obj + 0x20) = 0x42000;
            }
        } else if (*(s32*)(obj + 0x20) > -0x42000) {
            *(s32*)(obj + 0x20) = -0x42000;
        }
        if ((((obj[0x70] & m) ||
              ((d = D_8009A0AA - *(s16*)(obj + 0xA)) >= 0
                   ? (d < 0x41)
                   : (*(s16*)(obj + 0xA) - D_8009A0AA < 0x41))) &&
             *(s8*)(obj + 0x45) == 2) ||
            --*(s16*)(obj + 0x7C) == 0) {
            func_800171E8(obj, 0x19);
            func_80016490(2, 0x72, obj);
            obj[6]++;
        }
    }
}
