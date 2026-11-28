#include "types.h"
#include "mmx5/object.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl07.h"

extern void func_800FCC54_ovl07(void);
extern void func_80024548(s32);
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern s32 D_80093DD0[];
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void func_800F9BB0_ovl07(u8* obj) {
    s32 i;
    u16 x;
    u16 y;

    if (**(s8**)(D_1F80004C.bytes + 0x80) != 0) {
        return;
    }
    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    D_80093E68 = 0;
    D_8009A42E = 0;
    D_800D50DE = 0;
    for (i = 2; i < 16; i++) {
        D_80093DD0[i] = 0;
    }
    func_800FCC54_ovl07();
    D_800C9310.b |= 1;
    g_playthrough_state.u[0x24] = 1;
    g_playthrough_state.u[0x25] = 0;
    *(u8**)(g_playthrough_state.u + 0x20) = obj;
    g_playthrough_state.u[0xA2] = 0x30;
    if (*(s8*)(g_playthrough_state.u + 0xC) == 0xC) {
        func_80024548(-1);
    } else {
        func_80024548(1);
    }
    D_1F80004C.bytes[0x8A] = g_playthrough_state.u[0xA2];
    obj[0x15] = 0;
    *(s32*)(obj + 0x2C) = 0x1000;
    ((Obj800F2688*)obj)->unk7C = 6;
    obj[3] = 1;
    ((Obj800F2688*)obj)->unk7E = 0;
    x = D_80102014_ovl07;
    y = D_80102016_ovl07;
    *(s16*)(obj + 0xA) = x + 0x22A0;
    *(s16*)(obj + 0xE) = y + 0x480;
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    obj[6]++;
}

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern s32 get_launch_variant(void);

void func_800F9D38_ovl07(u8* obj) {
    u8* p;

    if (!(*(u16*)(obj + 0x7E) & 0xF)) {
        if (--*(s16*)(obj + 0x7C) == -1) {
            ((s16*)obj)[0x3E] = 6;
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
            D_800C9310.b |= 1;
            if (D_800D50DE >= 0x1F) {
                *(u16*)(obj + 0x7E) |= 1;
            }
        }
    }
    if (!(*(u16*)(obj + 0x7E) & 0xF0)) {
        apply_object_motion(obj);
        if (D_1F80004C.bytes[0x91] & 8) {
            *(u16*)(obj + 0x7E) |= 0x10;
        }
    }
    if (*(s16*)(obj + 0x7E) == 0x11) {
        D_1F80004C.bytes[0x92] = 0;
        set_animation(obj, 2);
        D_1F80004C.bytes[0x92] = 1;
        func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
        obj[0x15] = 0;
        p = g_playthrough_state.u;
        if (*(s8*)(p + 0xC) != 0xC) {
            if (get_launch_variant() == 0) {
                func_8002385C(0x2C, 0xFF, p[0x2E]);
            } else {
                func_8002385C(0x5E, 0xFF, p[0x2E]);
            }
            g_playthrough_state.u[0x2E] = 1;
        }
        obj[6]++;
    }
    animate_object(obj);
}

extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern s8 D_800D1C44;
extern s16 D_8009A0AE;

void func_800F9F08_ovl07(u8* obj) {
    set_animation(obj, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    *(u16*)(D_1F80004C.bytes + 0x84) = 0;
    func_800FC9E0_ovl07(obj);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    if (D_800D1C44 == 0) {
        if (D_8009A0AE < *(s16*)(obj + 0xE)) {
            *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xE);
            D_1F80004C.bytes[0x8F] = 0;
            *(s32*)(obj + 0x24) = 0x2000;
            *(s32*)(obj + 0x2C) = -0x1000;
            obj[6] = 1;
            return;
        } else {
            *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xE);
            D_1F80004C.bytes[0x8F] = 1;
            *(s32*)(obj + 0x24) = -0x2000;
            *(s32*)(obj + 0x2C) = 0x1000;
            obj[6] = 1;
            return;
        }
    }
    if (obj[0x15] == 0) {
        *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xA);
        D_1F80004C.bytes[0x8F] = 0;
        *(s32*)(obj + 0x20) = -0x2000;
        *(s32*)(obj + 0x28) = 0x1000;
    } else {
        *(u16*)(D_1F80004C.bytes + 0x84) = *(u16*)(obj + 0xA);
        D_1F80004C.bytes[0x8F] = 0x40;
        *(s32*)(obj + 0x20) = 0x2000;
        *(s32*)(obj + 0x28) = 0x1000;
    }
    obj[6] = 2;
}

extern s16 D_8009A0AE;

void func_800FA094_ovl07(u8* obj) {
    u8* p;
    s32 v;

    animate_object(obj);
    p = D_1F80004C.bytes;
    if (p[0x8F] == 0) {
        if (((*(s16*)(obj + 0xE) - *(s16*)(p + 0x84)) < 0
                 ? (*(s16*)(p + 0x84) - *(s16*)(obj + 0xE))
                 : (*(s16*)(obj + 0xE) - *(s16*)(p + 0x84))) >= 0x50 &&
            D_8009A0AE > *(s16*)(obj + 0xE)) {
            goto store; // !FAKE: goto kept for the matching branch layout
        }
        p = D_1F80004C.bytes;
        v = p[0x91] & 4;
    } else {
        if (((*(s16*)(obj + 0xE) - *(s16*)(p + 0x84)) < 0
                 ? (*(s16*)(p + 0x84) - *(s16*)(obj + 0xE))
                 : (*(s16*)(obj + 0xE) - *(s16*)(p + 0x84))) >= 0x50 &&
            D_8009A0AE < *(s16*)(obj + 0xE)) {
            goto store; // !FAKE: goto kept for the matching branch layout
        }
        p = D_1F80004C.bytes;
        v = p[0x91] & 8;
    }
    if (v != 0) {
    store:
        obj[6] = 3;
    } else {
        apply_object_motion(obj);
    }
}

void func_800FA1C4_ovl07(u8* obj) {
    u8* p;
    s32 a;
    s32 b;
    s32 d;

    animate_object(obj);
    p = D_1F80004C.bytes;
    if (p[0x8F] == 0) {
        a = *(s16*)(obj + 0xA);
        b = *(s16*)(p + 0x84);
        d = a - b;
        if (((d >= 0) ? (d >= 0x30) : (b - a >= 0x30)) &&
            D_8009A0AA + 0x10 > (s16) * (u16*)(obj + 0xA)) {
            obj[6] = 3;
            return;
        }
        p = D_1F80004C.bytes;
        d = p[0x91];
        d &= 2;
    } else {
        a = *(s16*)(obj + 0xA);
        b = *(s16*)(p + 0x84);
        d = a - b;
        if (((d >= 0) ? (d >= 0x30) : (b - a >= 0x30)) &&
            D_8009A0AA - 0x10 < (s16) * (u16*)(obj + 0xA)) {
            obj[6] = 3;
            return;
        }
        p = D_1F80004C.bytes;
        d = p[0x91];
        d &= 1;
    }
    if (d) {
        obj[6] = 3;
    } else {
        apply_object_motion(obj);
    }
}
