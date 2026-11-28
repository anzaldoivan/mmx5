#include "types.h"
#include "mmx5/ovl10.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F5454_ovl10(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 2 && *(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 3);
    }
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) <= 0) {
        if (obj[0x88] == 0 && *(u16*)(obj + 0x92) == 0) {
            D_800FC1C8_ovl10.u[1] = 1;
            set_animation(obj, 0x20);
        } else {
            D_800FC1C8_ovl10.u[1] = 0;
            set_animation(obj, 0x10);
        }
        obj[6] = 2;
    }
}

extern void func_800F6250_ovl10(void*);
extern u8 D_800FB7E8_ovl10[];
extern u8 D_800FB7EC_ovl10[];
extern u8 D_800FB7F0_ovl10[];
extern u8 D_800FB7F4_ovl10[];

void func_800F5524_ovl10(u8* obj) {
    func_800F6250_ovl10(obj);
    animate_object(obj);
    if ((u8)(obj[0x47] - 0x43) < 6) {
        *(u8**)(obj + 0x50) = D_800FB7EC_ovl10;
        *(u8**)(obj + 0x54) = D_800FB7F4_ovl10;
    } else {
        *(u8**)(obj + 0x50) = D_800FB7E8_ovl10;
        *(u8**)(obj + 0x54) = D_800FB7F0_ovl10;
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[6] = 3;
    }
}

void func_800F55A4_ovl10(u8* obj) {
    u8* p;

    animate_object(obj);
    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x27;
        if (D_800FC1C8_ovl10.u[1] != 0) {
            p[2] = 1;
            *(s16*)(obj + 0x92) = 0x12C;
            p[4] = 7;
            *(s32*)(p + 0x24) = 0x40000;
        } else {
            p[2] = 0;
            p[4] = 4;
            *(s32*)(p + 0x24) = 0;
        }
        if (obj[0x15] != 0) {
            *(s32*)(p + 0x20) = 0x40000;
            *(s32*)(p + 8) = *(s32*)(obj + 8) + 0x300000;
        } else {
            *(s32*)(p + 0x20) = 0xFFFC0000;
            *(s32*)(p + 8) = *(s32*)(obj + 8) + 0xFFD00000;
        }
        *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
        *(s16*)(p + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        p[0x14] = obj[0x14];
        *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
        p[0x15] = obj[0x15];
        *(u8**)(p + 0x7C) = obj;
    }
    obj[6] = 4;
}

void func_800F56C4_ovl10(u8* obj) {
    animate_object(obj);
    if (*(signed char*)(obj + 0x45) == 1) {
        if (obj[0x8E] != 0) {
            obj[0x8E] = 0;
            obj[0x88] = 0;
            obj[5] = D_800FBE00_ovl10.u[(obj[0x8A] * 2 + obj[0x89]) * 5];
        } else {
            obj[5] = D_800FBE00_ovl10
                         .u[++obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
        }
        obj[6] = 0;
    }
}
