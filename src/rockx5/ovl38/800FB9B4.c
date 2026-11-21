#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

#define func_800F3E90_ovl26 func_800FB9B4_ovl38
#include "shared/func_800F3E90_ovl26.c"
#undef func_800F3E90_ovl26

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;

void func_800FB9EC_ovl38(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
        set_animation(a, 0);
        a->unk6++;
    }
}

extern s32 func_80024548(s32);
extern u8 D_800D1C00[];

void func_800FBA68_ovl38(u8* obj) {
    u8* child;
    u8* t;
    u8* g;
    s32 k;
    s32 n;

    child = *(u8**)(D_1F80004C.bytes + 0x80);
    if (*(signed char*)child == 0) {
        t = D_1F80009C;
        *(u8**)(obj + 0x3C) = t + *(s32*)t;
        g = D_800D1C00;
        g[0x24] = 1;
        g[0x25] = 1;
        *(u8**)(g + 0x20) = obj;
        g[0xA2] = 0x40;
        func_80024548(1);
        n = obj[6];
        obj[0x15] = 0;
        k = 0x1268;
        *(s16*)(obj + 0xA) = k;
        k = 0x7C0;
        obj[3] = 1;
        *(s16*)(obj + 0xE) = k;
        n++;
        obj[6] = n;
    }
}

void func_800FBB10_ovl38(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s32*)(obj + 0x24) = -0x8000;
        obj[6]++;
    }
    animate_object(obj);
}

void func_800FBB58_ovl38(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        apply_object_motion(obj);
    }
    ((s32(*)())func_8002FB58)(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
    }
}

extern u8 D_800D1C00[];

void func_800FBBC8_ovl38(u8* obj) {
    set_animation(obj, 1);
    func_8002385C(0x48, 0xFF, D_800D1C00[0x2E]);
    D_800D1C00[0x2E] = 1;
    obj[6]++;
}

#include "shared/func_800FBC24_ovl38.c"

extern s32 func_80044DE0();

void func_800FBC68_ovl38(u8* arg0) {
    if (func_80044DE0() == 0) {
        set_animation(arg0, 1);
        arg0[6]++;
    }
}

extern void func_800FCD04_ovl38(u8* obj, s32 arg1);

void func_800FBCAC_ovl38(u8* obj) {
    u8* scr;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(s16*)(D_1F80004C.bytes + 0x84) = 0;
        func_800FCD04_ovl38(obj, 0);
        play_sound(2, 0xA2, obj);
    } else {
        scr = D_1F80004C.bytes;
        if (*(s16*)(scr + 0x84) == 1) {
            *(s16*)(scr + 0x84) = 0;
            *(s16*)(obj + 0x7C) = 2;
            obj[6]++;
        }
    }
}

void func_800FBD40_ovl38(EntBD40* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        play_sound(0, 0xE, 0);
        obj->unk7C = 2;
    }
    if (++obj->unk5C >= D_800D1CA2) {
        ((s32(*)())func_8003D2C4)();
        obj->unk6++;
    }
}

void func_800FBDD4_ovl38(u8* obj) {
    animate_object(obj);
    D_1F80004C.bytes[0x8D] = 1;
    obj[5] = 3;
    obj[6] = 0;
}
