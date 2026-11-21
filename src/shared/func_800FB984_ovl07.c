#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;

void func_800FB984_ovl07(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
        set_animation(a, 2);
        a->unk6++;
    }
}

extern u8 D_80091C44;

void func_800FBA00_ovl07(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        set_animation(obj, 0);
        D_1F80004C.bytes[0x92] = 0;
        *(s16*)(obj + 0x7C) = 0x50;
        *(s16*)(obj + 0x7E) = 0x17;
        obj[6]++;
    }
}

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);

void func_800FBA6C_ovl07(u8* obj) {
    s8 v;
    u8* p;

    if (--*(s16*)(obj + 0x7E) == -1) {
        *(s16*)(obj + 0x7E) = 3;
        play_sound(2, 0x24, obj);
        func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 0);
    }
    v = *(s8*)(obj + 0x45);
    if (v == 1) {
        p = D_1F80004C.bytes;
        if (p[0x92] == 0) {
            p[0x92] = v;
            func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 1);
        }
    }
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(s16*)(obj + 0x7C) = 100;
        obj[6]++;
    }
    animate_object(obj);
}

void func_800FBB4C_ovl07(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        D_1F80004C.bytes[0x92] = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
    }
    animate_object(obj);
}

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);

void func_800FBBAC_ovl07(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        set_animation(obj, 2);
        D_1F80004C.bytes[0x92] = 1;
        func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
        obj[0x15] = 0;
        *(s16*)(obj + 0x7C) = 6;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
    }
    animate_object(obj);
}

extern void func_80044DD0(s32 a0);
extern u16 D_80093E68;
extern s16 D_8009A220[];
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern signed char D_800D1C0C;
extern u16 D_800D50DE;

void func_800FBC2C_ovl07(u8* arg0) {
    animate_object(arg0);
    if (--((s16*)arg0)[0x3E] == -1) {
        ((s16*)arg0)[0x3E] = 6;
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        D_800C9310 |= 1;
        if (D_800D50DE < 0xB) {
            if (D_800D1C0C != 0xC) {
                D_8009A220[1] = 0x440;
            }
            func_80044DD0(0);
            ((s16*)arg0)[0x3E] = 2;
            arg0[6]++;
        }
    }
}

extern s32 func_80044DE0();

void func_800FBCF8_ovl07(u8* obj) {
    u8* sc;
    s8 n;

    animate_object(obj);
    if (func_80044DE0() != 0) {
        return;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        play_sound(0, 0xE, 0);
        *(s16*)(obj + 0x7C) = 2;
    }
    n = ++*(s8*)(obj + 0x5C);
    sc = D_1F80004C.bytes;
    if (n == sc[0x8A]) {
        sc[0x89] = 1;
        *(s16*)(D_1F80004C.bytes + 0x84) = *(s16*)(obj + 0xE) - 0x50;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x2C) = 0;
        ((s32(*)())func_8003D2C4)();
        obj[6]++;
    }
}

void func_800FBDC8_ovl07(u8* obj) {
    u8* p;

    animate_object(obj);
    move_object(obj);
    p = D_1F80004C.bytes;
    if (*(s16*)(p + 0x84) >= *(s16*)(obj + 0xE)) {
        p[0x92] = 0;
        obj[5] = 3;
        obj[6] = 0;
    }
}
