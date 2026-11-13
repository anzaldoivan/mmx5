#include "types.h"
#include "addr.h"

extern u8 D_800AA9A8[];
extern u8 D_800C9588[];
extern u8 D_800E8588[];
extern u8 D_800E8D88[];
extern u8 D_800E9188[];
extern u8 D_8009A428;
extern u8 D_8009A0A0[];
extern u8 D_8009A3B8[];
extern u8 D_800942A8[];
extern u8 D_80093E10[];
extern u8 D_80092090[];
extern u8 D_80098120[];
extern u8 D_80096D98[];
extern u8 D_80094398[];
extern u8 D_800C6A10[];
extern u8 D_800D1F40[];
extern u8 D_800994A0[];
extern u8 D_800D1DC0[];
extern u8 D_8009F9A0[];

extern void func_80025828(void);
extern void func_800272FC(void);
extern s32 func_800306E0(u8* a0);
extern void func_80024C60(u8* a0);
extern void func_80027370(u8* p);
extern void func_8002553C(u8* a0);
extern void func_80025240(u8* a0);
extern void func_80024B88(void);

void func_80024698(void) {
    s8* p;
    s16 save;
    s32 kind;

    D_1F800124 = 0;
    ((u8**)&D_1F800000)[0x40] = D_800AA9A8 + D_1F800000 * 0xA000;
    ((u8**)&D_1F800000)[0x41] = D_800C9588 + D_1F800000 * 0x2000;
    ((u8**)&D_1F800000)[0x42] = D_800E8588 + D_1F800000 * 0x400;
    ((u8**)&D_1F800000)[0x43] = D_800E8D88 + D_1F800000 * 0x200;
    ((u8**)&D_1F800000)[0x44] = D_800E9188 + D_1F800000 * 0xB4;
    if (D_8009A428 == 0) {
        func_80025828();
    }
    func_800272FC();

    p = (s8*)D_8009A0A0;
    if (p[3] != 0) {
        kind = p[5];
        save = *(s16*)(p + 0xA);
        if (kind == 0x1B || (kind == 0x3D && func_800306E0((u8*)p) == 0x2E)) {
            if (p[2] == 0) {
                if (((u8*)p)[0x15] == 0x40) {
                    (*(s16*)(p + 0xA))++;
                }
            } else if (((u8*)p)[0x15] == 0) {
                (*(s16*)(p + 0xA))++;
            }
        }
        func_80024C60((u8*)p);
        if (p[2] == 0 && (u8)(((u8*)p)[0xFA] - 1) < 4) {
            func_80027370((u8*)p);
        }
        *(s16*)(p + 0xA) = save;
    }
    if (p[2] == 0) {
        p = (s8*)D_800942A8;
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
        p += 0x50;
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
        p += 0x50;
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    for (p = (s8*)D_8009A3B8; p >= (s8*)D_8009A3B8 - 0xC0; p -= 0x60) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    if ((s8)D_80093E10[0] != 0 && (s8)D_80093E10[3] == 1) {
        func_80024C60(D_80093E10);
    }
    for (p = (s8*)D_80092090; p < (s8*)D_80092090 + 0x1D40; p += 0x9C) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    for (p = (s8*)D_80098120; p < (s8*)D_80098120 + 0x1380; p += 0x9C) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    for (p = (s8*)D_80096D98; p < (s8*)D_80096D98 + 0x1380; p += 0x9C) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    for (p = (s8*)D_80094398; p < (s8*)D_80094398 + 0x2A00; p += 0x70) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    for (p = (s8*)D_800C6A10; p < (s8*)D_800C6A10 + 0x2900; p += 0xA4) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    for (p = (s8*)D_800D1F40; p < (s8*)D_800D1F40 + 0x3000; p += 0x60) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    for (p = (s8*)D_800994A0; p < (s8*)D_800994A0 + 0xC00; p += 0x60) {
        if (p[3] != 0) {
            func_80024C60((u8*)p);
        }
    }
    p = (s8*)D_800D1DC0;
    if (p[3] != 0) {
        func_80024C60((u8*)p);
    }
    p += 0xB0;
    if (p[3] != 0) {
        func_80024C60((u8*)p);
    }
    for (p = (s8*)D_8009F9A0; p < (s8*)D_8009F9A0 + 0x1800; p += 0x60) {
        if (p[3] != 0) {
            if (((u8*)p)[0] & 2) {
                func_8002553C((u8*)p);
            } else {
                func_80025240((u8*)p);
            }
        }
    }
    func_80024B88();
}
