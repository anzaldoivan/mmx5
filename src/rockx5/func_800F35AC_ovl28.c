#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800F6A8C_ovl28(u8* obj);
extern u32 func_8002DF78(void);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A0A0[];

void func_800F35AC_ovl28(u8* o) {
    u8* p;
    u8* g;
    s32 ang;

    func_80017248(o);
    func_800F6A8C_ovl28(o);
    if (--*(s16*)(o + 0x7C) != 0) {
        return;
    }
    if (*(s16*)(o + 0x7E) == 5) {
        switch ((u8)(func_8002DF78() % 3)) {
        case 1:
            func_80016490(2, 0x7F, o);
            break;
        case 2:
            func_80016490(2, 0x80, o);
            break;
        }
    }
    p = func_8002D1A4();
    if (p != 0) {
        if (*(s16*)(o + 0x7E) == 1) {
            p[2] = 0x10;
        } else {
            p[2] = 0;
        }
        p[0] = 0x61;
        p[1] = 0x23;
        p[2] |= 1;
        *(u16*)(p + 0x40) = *(u16*)(o + 0x40);
        *(s32*)(p + 0x30) = *(s32*)(o + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
        p[0x15] = o[0x15];
        *(u16*)(p + 0xA) = *(u16*)(o + 0xA);
        g = D_8009A0A0;
        *(u16*)(p + 0xE) = *(u16*)(o + 0xE);
        ang = ratan2(*(s16*)(g + 0xE) - *(s16*)(o + 0xE),
                     *(s16*)(g + 0xA) - *(s16*)(o + 0xA));
        *(s32*)(p + 0x20) = rcos(ang);
        *(s32*)(p + 0x24) = -rsin(ang);
        *(u8**)(p + 0x7C) = o;
    }
    if (--*(s16*)(o + 0x7E) == 0) {
        o[6]++;
    } else {
        *(s16*)(o + 0x7C) = 0x18;
    }
}
