#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8* find_free_visual_obj(void);
extern s32 func_8002B5B4(s32);

void func_800F4094_ovl28(u8* a0) {
    u8* p;
    u8* q;
    u8* o;
    s32 r0;
    s32 r1;
    s8 t;

    if (is_off_screen(a0, 0x20, 0x14) == 0) {
        if (func_800317B8(a0) == 0) {
            animate_object(a0);
            move_object(a0);
            func_8002D9EC(a0, 0x20, 0x14);
            if (a0[0x70] != 0 ||
                (((s32(*)())func_8002F8FC)(a0), a0[0x70] != 0)) {
                p = find_free_visual_obj();
                if (p != 0) {
                    p[0] = 0x61;
                    p[1] = 0xB;
                    p[2] = 7;
                    *(u16*)(p + 0x40) = *(u16*)(a0 + 0x40);
                    *(s32*)(p + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(p + 0x3C) = *(s32*)(a0 + 0x3C);
                    r0 = func_8002B5B4(0x40);
                    r1 = func_8002B5B4(0x40);
                    *(s16*)(p + 0x42) =
                        ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
                    if (a0[0x15] == 0) {
                        p[0x15] = 0x40;
                        *(s16*)(p + 0xA) = *(s16*)(a0 + 0xA) - 0x10;
                    } else {
                        p[0x15] = 0;
                        *(s16*)(p + 0xA) = *(s16*)(a0 + 0xA) + 0x10;
                    }
                    *(u16*)(p + 0xE) = *(u16*)(a0 + 0xE);
                    *(u8**)(p + 0x50) = a0;
                }
                a0[4]++;
            }
        } else {
            o = *(u8**)(a0 + 0x7C);
            if (o[0x8D] == 0) {
                o[0x8D] = 1;
                q = func_8002D1A4();
                if (q != 0) {
                    q[0] = 0x61;
                    q[1] = 0x23;
                    q[2] = 0xA;
                    *(s16*)(q + 0x42) = *(s16*)(a0 + 0x42) & 0x7FFF;
                    *(u16*)(q + 0x40) = *(u16*)(a0 + 0x40);
                    *(s32*)(q + 0x30) = *(s32*)(a0 + 0x30);
                    *(s32*)(q + 0x3C) = *(s32*)(a0 + 0x3C);
                    *(s32*)(q + 0x8) = *(s32*)(a0 + 0x8);
                    *(s32*)(q + 0xC) = *(s32*)(a0 + 0xC);
                    *(u8**)(q + 0x7C) = *(u8**)(a0 + 0x7C);
                }
            }
        }
        if (func_80031DD0(a0) < 0) {
            a0[4]++;
        }
    } else {
        a0[4]++;
    }
    t = (*(s8**)(a0 + 0x7C))[4];
    if (t == 2) {
        a0[4] = t;
    }
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8 D_800FE310_ovl28[];

void func_800F42F8_ovl28(u8* obj) {
    u8* p;

    if (is_off_screen(obj, 0x20, 0x14) == 0) {
        animate_object(obj);
        func_800317B8(obj);
        if (D_8009A420_as_s32 & 1) {
            func_8002C338(
                0x13E,
                (void*)((s32)D_1F800024 + (D_800FE310_ovl28[obj[0x8F]] << 5)),
                1);
            func_8002C338(
                0x13F,
                (void*)((s32)D_1F800024 + (D_800FE310_ovl28[obj[0x8F]] << 5)),
                1);
            if (++obj[0x8F] == 6) {
                obj[0x8F] = 0;
            }
        }
        move_object(obj);
        func_8002D9EC(obj, 0x20, 0x14);
        return;
    }
    if ((obj[2] >> 4) == 1) {
        p = *(u8**)(obj + 0x7C);
        p[0x8C]++;
    }
    obj[4]++;
}
