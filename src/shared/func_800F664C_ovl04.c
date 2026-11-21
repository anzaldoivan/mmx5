#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

extern u8 D_80074DA0[];
extern u8 D_80101CE8_ovl04[];
extern u8 D_80101CEC_ovl04[];
extern u8 D_80101CF0_ovl04[];
extern u8 D_80101CF4_ovl04[];
extern u8 D_80101CF8_ovl04[];

void func_800F664C_ovl04(u8* obj) {
    s32 x;

    obj[4] = 1;
    x = *(s32*)(obj + 8);
    obj[6] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    obj[0x14] = g_Player[0x14];
    obj[0x93] = 0;
    obj[0x71] = 0;
    switch (*(s8*)(obj + 2)) {
    case 0:
        obj[0x16] = 6;
        obj[0x60] = 6;
        obj[5] = 2;
        obj[0x5C] = 1;
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_80101CE8_ovl04;
        *(u8**)(obj + 0x68) = D_80101CEC_ovl04;
        obj[0x15] = (x >= *(s32*)(g_Player + 8)) << 6;
        obj[0x91] = 7;
        *(s16*)(obj + 0x88) = 0;
        set_animation(obj, 10);
        break;
    case 1:
        obj[0x16] = 4;
        obj[5] = 5;
        obj[0x5C] = 4;
        obj[0x60] = 8;
        *(u8**)(obj + 0x68) = 0;
        *(u8**)(obj + 0x54) = D_80101CF4_ovl04;
        *(u8**)(obj + 0x50) = D_80101CF0_ovl04;
        *(s16*)(obj + 0x88) = 0;
        set_animation(obj, 9);
        break;
    case 2:
        obj[3] = 0;
        obj[5] = 6;
        obj[0x60] = 0x7F;
        *(u8**)(obj + 0x68) = 0;
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_80101CF8_ovl04;
        break;
    }
    obj[0x67] = 0;
    *(u8**)(obj + 0x58) = D_80074DA0;
    obj[0x8E] = 7;
    obj[0x8F] = 0;
    obj[0x90] = 0;
    obj[0x92] = 0;
}

extern void (*D_80101D24_ovl04[])(u8*);

void func_800F67F0_ovl04(u8* obj) {
    s8 st;
    s8 v;
    u8 f;

    st = *(s8*)(obj + 2);
    if (st == 1) {
        if (func_80031DD0(obj) < 0 || (*(s8**)(obj + 0x7C))[4] == 2) {
            ((s32(*)())func_8004FD24)(obj);
            obj[4] = 2;
            return;
        }
    } else if (st == 0) {
        v = (*(s8**)(obj + 0x7C))[4];
        if (v == 2) {
            obj[0x8F] = 8;
            set_animation(obj, 0xE);
            obj[4] = v;
            return;
        }
    } else if (st == 2) {
        s8 w = (*(s8**)(obj + 0x7C))[4];
        if (w == 2) {
            obj[4] = w;
            return;
        }
    }
    func_800317B8(obj);
    f = obj[0x71] | obj[0x70];
    obj[0x71] = f;
    obj[0x93] = f;
    D_80101D24_ovl04[*(s8*)(obj + 5)](obj);
    if (*(s8*)(obj + 2) != 2) {
        if (is_off_screen(obj, 0x20, 0x20) == 0) {
            func_8002D89C(obj);
        } else {
            obj[4] = 2;
        }
        if ((*(u32*)(obj + 4) & 0xFFFF00) == 0x20200) {
            obj[3] = 0;
        }
    } else {
        if (is_off_screen(obj, 0x80, 0x20) != 0) {
            clear_object_slot(obj);
        }
    }
}

extern void (*D_80101D40_ovl04[])(u8*);

void func_800F697C_ovl04(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_8002FB58(obj);
    D_80101D40_ovl04[*(s8*)(obj + 4)](obj);
    obj[0x71] = 0;
}
