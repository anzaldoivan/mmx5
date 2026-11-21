#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_800750C0[];
extern u8 D_8009A0B4;
extern u8 D_800F9694_ovl29[];
extern u8 D_800F9540_ovl29[];

void func_800F1EE0_ovl29(u8* obj) {
    s32 one;

    obj[0x5C] = 6;
    obj[0x60] = 3;
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x61] = 0;
    obj[0x14] = D_8009A0B4;
    *(u8**)(obj + 0x30) = D_800F9694_ovl29;
    obj[0x16] = 6;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x54) = D_800F9540_ovl29;
    *(u8**)(obj + 0x50) = D_800F9540_ovl29;
    switch (((s8*)obj)[2]) {
    case 1:
        set_animation(obj, 1);
        obj[5] = 3;
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x90) = 1;
        break;
    case 2:
        set_animation(obj, 0);
        obj[0x7A] = 1;
        obj[0x61] = 1;
        obj[5] = 2;
        obj[0x15] = 0;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 100;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 3:
        set_animation(obj, 0);
        one = 1;
        obj[5] = 2;
        obj[0x7A] = one;
        obj[0x15] = 0x40;
        obj[0x61] = one;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 100;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 4:
        set_animation(obj, 0);
        obj[0x7A] = 1;
        obj[0x61] = 1;
        obj[5] = 2;
        obj[0x15] = 0;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 140;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 5:
        set_animation(obj, 0);
        one = 1;
        obj[5] = 2;
        obj[0x7A] = one;
        obj[0x15] = 0x40;
        obj[0x61] = one;
        *(s32*)(obj + 0x80) = 0;
        *(s32*)(obj + 0x84) = 140;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 6:
        set_animation(obj, 0);
        obj[0x7A] = 1;
        obj[5] = 2;
        obj[0x61] = 1;
        obj[0x15] = 0;
        *(s32*)(obj + 0x80) = 1;
        *(s32*)(obj + 0x84) = 40;
        *(s32*)(obj + 0x90) = 0;
        break;
    case 7:
        set_animation(obj, 0);
        obj[0x7A] = 1;
        obj[5] = 2;
        obj[0x61] = 1;
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x80) = 1;
        *(s32*)(obj + 0x84) = 40;
        *(s32*)(obj + 0x90) = 0;
        break;
    default:
        set_animation(obj, 1);
        obj[5] = 3;
        obj[0x15] = 0;
        *(s32*)(obj + 0x90) = 1;
        break;
    }
    obj[4] = 1;
    obj[6] = 0;
}

extern u8 D_8009A197;
extern void (*D_800F96D8_ovl29[])(u8*);
extern u8 D_800F96B8_ovl29[];
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8005446C(u8* a0, s32 a1, s16 a2, s16 a3);

void func_800F2144_ovl29(u8* obj) {
    s32 r;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800F96D8_ovl29[((s8*)obj)[5]](obj);
    }
    if (*(s32*)(obj + 0x90) != 0) {
        ((void (*)())func_800317B8)(obj);
        *(s32*)(obj + 0x94) = ((s8*)obj)[5];
        if (func_80031DD0(obj) < 0) {
            func_8004FD24(obj);
            func_8004D4F4(5, D_800F96B8_ovl29, obj);
            if (!(obj[2] & 1)) {
                func_8005446C(obj, 0xE, *(s16*)(obj + 0xA) - 10,
                              *(s16*)(obj + 0xE));
            } else {
                func_8005446C(obj, 0xE, *(s16*)(obj + 0xA) + 10,
                              *(s16*)(obj + 0xE));
            }
            r = 2;
            goto store; // !FAKE: goto kept for the matching branch layout
        }
    }
    if (is_off_screen(obj, 0x40, 0x40) == 0) {
        if ((*(s32*)(obj + 4) & 0xFFFF00) != 0x200) {
            func_8002D9EC(obj, 0x20, 0x20);
        }
        return;
    }
    r = 3;
store:
    obj[4] = r;
}
