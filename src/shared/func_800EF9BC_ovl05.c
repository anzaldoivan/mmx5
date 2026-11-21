#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

extern u8 D_8009A197;
extern void (*D_800F52EC_ovl05[])(u8*);
extern u8 D_800F52B4_ovl05[];
extern void func_800F0990_ovl05(u8* obj);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);

void func_800EF9BC_ovl05(u8* obj) {
    s32 r;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_800F0990_ovl05(obj);
        animate_object(obj);
        D_800F52EC_ovl05[*(signed char*)(obj + 5)](obj);
    }
    func_800317B8(obj);
    D_1F80004C.bytes[0x85] = 0;
    r = func_80031DD0(obj);
    if (r < 0) {
        func_8004D4F4(6, D_800F52B4_ovl05, obj);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0xF;
        *(s16*)(obj + 0x7E) = 5;
        func_80054440(obj, 0x12);
        obj[4] = 5;
        return;
    }
    if (r > 0) {
        D_1F80004C.bytes[0x85] = 1;
    }
    if ((obj[0x70] & 0xC) == 0xC || (obj[0x70] & 3) == 3) {
        func_8004D4F4(6, D_800F52B4_ovl05, obj);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0xF;
        *(s16*)(obj + 0x7E) = 5;
        obj[4] = 5;
        return;
    }
    if (is_off_screen(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        obj[4] = 3;
    }
    func_8002FB58(obj);
}

extern s8 D_800D1C44;

void func_800EFB28_ovl05(u8* o) {
    s32 d;

    if (--*(s16*)(o + 0x7C) == -1 || D_1F80004C.bytes[0x85] != 0) {
        o[6]++;
    } else if (D_800D1C44 == 0) {
        d = D_8009A0AA - *(s16*)(o + 0xA);
        if ((d >= 0) ? (d < 0x90) : (*(s16*)(o + 0xA) - D_8009A0AA < 0x90)) {
            o[6]++;
        }
    } else {
        d = D_8009A0AA - *(s16*)(o + 0xA);
        if ((d >= 0) ? (d < 0x70) : (*(s16*)(o + 0xA) - D_8009A0AA < 0x70)) {
            o[6]++;
        }
    }
}

extern u8 D_800F52C8_ovl05[];

void func_800EFBFC_ovl05(u8* obj) {
    u8* p = g_Player;

    if (((*(s16*)(p + 0xA) - *(s16*)(obj + 0xA)) < 0
             ? (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA))
             : (*(s16*)(p + 0xA) - *(s16*)(obj + 0xA))) >= 3) {
        u8* q = g_Player;

        if (*(s16*)(q + 0xA) < *(s16*)(obj + 0xA)) {
            *(s32*)(obj + 0x20) = 0xFFFF0000;
        } else {
            *(s32*)(obj + 0x20) = 0x10000;
        }
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        *(u8**)(obj + 0x54) = D_800F52C8_ovl05;
        set_animation(obj, 0xE);
        D_1F80004C.bytes[0x84] = 1;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[6]++;
    }
}
