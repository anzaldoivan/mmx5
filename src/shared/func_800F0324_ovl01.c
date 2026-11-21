#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

void func_800F0324_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 10;
        obj[6] = 1;
    }
}

extern s32 D_800FC574_ovl01[];
extern s32 D_800FC578_ovl01[];
extern void func_800F0810_ovl01(Obj0364*);

void func_800F0364_ovl01(Obj0364* obj) {
    if (obj->mode == 2) {
        obj->p54 = D_800FC574_ovl01;
        obj->p50 = D_800FC578_ovl01;
    }
    if (--obj->timer == 0) {
        func_800F0810_ovl01(obj);
        set_animation(obj, 2);
        obj->h7E = 3;
        obj->state = 2;
    }
}

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void func_800F03EC_ovl01(Ent03EC* obj) {
    if (--obj->x84 == 0) {
        obj->x84 = 20;
    }
    animate_object(obj);
    if (--obj->x7E == 0) {
        func_8005019C(1, 2, obj, 8, 1);
        obj->x7E = 3;
    }
    if (obj->x45 != 0) {
        if (obj->x15 == 0) {
            obj->x20 = -0x40000;
        } else {
            obj->x20 = 0x40000;
        }
        obj->x6 = 3;
    }
}

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void func_800F049C_ovl01(u8* obj) {
    s32 m;
    s32 k;

    if (--*(s32*)(obj + 0x84) == 0) {
        *(s32*)(obj + 0x84) = 20;
    }
    if (--*(s16*)(obj + 0x7E) == 0) {
        func_8005019C(1, 2, obj, 8, 1);
        *(s16*)(obj + 0x7E) = 2;
    }
    animate_object(obj);
    move_object(obj);
    k = 9;
    if (obj[0x15] == 0) {
        k = 10;
        m = obj[0x70] & 10;
    } else {
        m = obj[0x70] & 9;
    }
    if (m == k) {
        *(s16*)(obj + 0x7C) = 60;
        obj[5] = 6;
        obj[6] = 0;
    }
}

extern u8 D_800FC65C_ovl01[];
extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800F0568_ovl01(u8* obj) {
    if (--*(s16*)(obj + 0x7E) == 0) {
        func_8005019C(1, 2, obj, 8, 1);
        *(s16*)(obj + 0x7E) = 2;
    }
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_8004FD24(obj);
        func_8004D4F4(5, D_800FC65C_ovl01, obj);
        obj[4] = 2;
    }
}
