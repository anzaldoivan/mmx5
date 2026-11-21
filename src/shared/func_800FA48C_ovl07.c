#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/sound.h"
#include "addr.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_80101C10_ovl07_as_u8 ((u8*)D_80101C10_ovl07)

extern void func_800FCAD8_ovl07(u8* obj, s16 x, s16 y, s32 kind, s32 arg4);

void func_800FA48C_ovl07(u8* o) {
    if (((s8*)o)[0x45] != 0) {
        D_1F80004C.bytes[0x97] = 0;
        D_1F80004C.bytes[0x96] =
            D_80101C10_ovl07_as_u8[D_1F80004C.s8s[0x97] * 2];
        D_1F80004C.bytes[0x95] =
            (&D_80101C10_ovl07_as_u8[D_1F80004C.s8s[0x97] * 2])[1];
        play_sound(2, 0x24, o);
        if (o[0x15] == 0) {
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 1, 0);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 3, 0);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 2, 0);
        } else {
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 1, 1);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 3, 1);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 0, 1);
        }
        *(s16*)(o + 0x7C) = 0x14;
        o[0x6]++;
    }
}

extern void start_pad_vibration(s32);
extern void func_800FCAD8_ovl07(u8* obj, s16 x, s16 y, s32 kind, s32 arg4);
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void func_800FA5D8_ovl07(u8* obj) {
    s16 x;
    s16 y;

    if (((s8*)obj)[0x45] == 2) {
        start_pad_vibration(7);
        play_sound(2, 0x23, obj);
        x = D_80102014_ovl07 + 0x2250;
        y = D_80102016_ovl07 + 0x570;
        func_800FCAD8_ovl07(obj, x, y, 4, 0);
        D_1F80004C.bytes[0x97] = 2;
        D_1F80004C.bytes[0x96] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][0];
        D_1F80004C.bytes[0x95] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][1];
    } else if (((s8*)obj)[0x45] == 1) {
        *(s16*)(obj + 0x7C) = 2;
        obj[6]++;
    }
}

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_80102016_ovl07;
extern s16 D_80101BFC_ovl07[][2];
extern s16 D_80102014_ovl07;
extern s16 D_8009A202;

void func_800FA6D4_ovl07(u8* arg0) {
    u8 idx;
    s32 angle;

    set_animation(arg0, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(arg0, *(s16*)(arg0 + 0xA), *(s16*)(arg0 + 0xE), 2);
    idx = ((u32(*)())random_byte)() % 3;
    D_1F80004C.bytes[0x90] = idx;
    angle = ratan2(
        *(s16*)(arg0 + 0xE) - (D_80101BFC_ovl07[idx][1] + D_80102016_ovl07),
        (D_80101BFC_ovl07[idx][0] + D_80102014_ovl07) - *(s16*)(arg0 + 0xA));
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    *(s32*)(arg0 + 0x20) = rcos(angle) << 6;
    *(s32*)(arg0 + 0x24) = rsin(angle) << 6;
    switch (D_1F80004C.bytes[0x90]) {
    case 0:
        arg0[0x15] = 0x40;
        break;
    case 1:
        arg0[0x15] = 0;
        break;
    case 2:
        if (*(s16*)(arg0 + 0xA) - D_8009A202 >= 0xA1) {
            arg0[0x15] = 0;
        } else {
            arg0[0x15] = 0x40;
        }
        break;
    }
    arg0[6]++;
}

extern s16 D_80101BFC_ovl07[][2];
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void func_800FA848_ovl07(u8* arg0) {
    s32 x;
    s32 y;

    animate_object(arg0);
    move_object(arg0);
    x = D_80101BFC_ovl07[D_1F80004C.bytes[0x90]][0] + D_80102014_ovl07;
    if (*(s16*)(arg0 + 0xA) >= x - 8 && x + 8 >= *(s16*)(arg0 + 0xA)) {
        y = D_80101BFC_ovl07[D_1F80004C.bytes[0x90]][1] + D_80102016_ovl07;
        if (*(s16*)(arg0 + 0xE) >= y - 8 && y + 8 >= *(s16*)(arg0 + 0xE)) {
            D_1F80004C.bytes[0x92] = 0;
            switch (D_1F80004C.bytes[0x90]) {
            case 0:
                arg0[0x15] = 0;
                set_animation(arg0, 0x14);
                break;
            case 1:
                arg0[0x15] = 0x40;
                set_animation(arg0, 0x14);
                break;
            case 2:
                arg0[0x15] = 0;
                set_animation(arg0, 0x12);
                break;
            }
            arg0[6]++;
        }
    }
}

extern void func_800FCAD8_ovl07(u8* obj, s16 x, s16 y, s32 kind, s32 arg4);

static inline s16 func_800FA978_ovl07_rnd(void) {
    return (random_byte() & 0x1F) - 0x10;
}

void func_800FA978_ovl07(u8* obj) {
    s16 r;

    animate_object(obj);
    D_1F80004C.bytes[0x97] = 1;
    D_1F80004C.bytes[0x96] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][0];
    D_1F80004C.bytes[0x95] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][1];
    play_sound(2, 0x24, obj);
    switch (D_1F80004C.bytes[0x90]) {
    case 0:
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x60, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x40, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x20, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x20, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x40, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x60, 2, 0);
        break;
    case 1:
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x60, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x40, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x20, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x20, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x40, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x60, 0, 0);
        break;
    case 2:
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) - 0x60,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) - 0x40,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) - 0x20,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) + 0x20,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) + 0x40,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) + 0x60,
            *(s16*)(obj + 0xE), 1, 0);
        break;
    }
    *(s16*)(obj + 0x7C) = 0x14;
    obj[6]++;
}

extern void func_800FCA20_ovl07(u8* obj, s16 x, s16 y, u8 c);
extern u8 D_80101B9C_ovl07[][2];
extern u8 D_80101BBC_ovl07[][2];
extern u8 D_80101BDC_ovl07[][2];
extern s16 D_80101B78_ovl07[][2];
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void func_800FAEC4_ovl07(u8* a0) {
    s32 r;
    s32 i;
    u32 n;
    u8 c;
    u8 u; // never set: the target stores an unset s2 to 0x94

    if (*(s8*)(a0 + 0x45) != 0) {
        D_1F80004C.bytes[0x8E] = 0;
        r = random_byte();
        n = D_1F80004C.bytes[0x8A];
        if ((s32)(n * 2) / 3 < *(s8*)(a0 + 0x5C)) {
            i = r & 0xF;
            c = D_80101B9C_ovl07[i][0];
        } else if ((u8)(n / 3) < *(s8*)(a0 + 0x5C)) {
            i = random_byte() & 0xF;
            c = D_80101BBC_ovl07[i][0];
        } else {
            i = random_byte() & 0xF;
            c = D_80101BDC_ovl07[i][0];
        }
        D_1F80004C.bytes[0x93] = c;
        D_1F80004C.bytes[0x94] = u;
        func_800FCA20_ovl07(a0, D_80101B78_ovl07[c & 0xF][0] + D_80102014_ovl07,
                            D_80101B78_ovl07[c & 0xF][1] + D_80102016_ovl07, c);
        *(s16*)(a0 + 0x7C) = 2;
        a0[6]++;
    }
}

extern u8 D_8010178C_ovl07[][0x12];
extern u8 D_801017B0_ovl07[];
extern u8 D_801017C4_ovl07[];
extern u8 D_801017E4_ovl07[];

void func_800FB030_ovl07(u8* obj) {
    u8* t;
    u8 v;
    u8 w;

    if (D_1F80004C.bytes[0x8B] == 0) {
        if (((s8*)obj)[0x5C] < (D_1F80004C.bytes[0x8A] * 2) / 3) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[0][random_byte() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            D_1F80004C.bytes[0x8B] = 1;
            obj[5] = D_801017C4_ovl07[D_1F80004C.bytes[0x8D] +
                                      D_1F80004C.bytes[0x8C] * 10];
            obj[6] = 0;
            return;
        }
    } else if (D_1F80004C.bytes[0x8B] == 1) {
        if (((s8*)obj)[0x5C] < (u8)(D_1F80004C.bytes[0x8A] / 3)) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[1][random_byte() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            D_1F80004C.bytes[0x8B] = 2;
            obj[5] = D_801017E4_ovl07[D_1F80004C.bytes[0x8D] +
                                      D_1F80004C.bytes[0x8C] * 10];
            obj[6] = 0;
            return;
        }
    }

    switch (D_1F80004C.bytes[0x8B]) {
    case 0:
        D_1F80004C.bytes[0x8C]++;
        v = D_801017B0_ovl07[D_1F80004C.bytes[0x8C]];
        if (v == 0xFF) {
            D_1F80004C.bytes[0x8C] = 0;
            obj[5] = D_801017B0_ovl07[D_1F80004C.bytes[0x8C]];
        } else {
            obj[5] = v;
        }
        break;
    case 1:
        D_1F80004C.bytes[0x8D]++;
        t = D_1F80004C.bytes;
        w = D_801017C4_ovl07[t[0x8D] + t[0x8C] * 10];
        if (w == 0xFF) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[0][random_byte() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            t = D_1F80004C.bytes;
            obj[5] = D_801017C4_ovl07[t[0x8D] + t[0x8C] * 10];
        } else {
            obj[5] = w;
        }
        break;
    case 2:
        D_1F80004C.bytes[0x8D]++;
        t = D_1F80004C.bytes;
        w = D_801017E4_ovl07[t[0x8D] + t[0x8C] * 10];
        if (w == 0xFF) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[1][random_byte() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            t = D_1F80004C.bytes;
            obj[5] = D_801017E4_ovl07[t[0x8D] + t[0x8C] * 10];
        } else {
            obj[5] = w;
        }
        break;
    }
    obj[6] = 0;
}
