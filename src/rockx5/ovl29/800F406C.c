#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;
extern s16 D_8009A1F8[];

void func_800F406C_ovl29(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(s16*)(p + 0xA) = a->unkA;
            *(s16*)(p + 0xE) = a->unkE;
            *(u8**)((u8*)a + 0x80) = p;
        }
        a->unk15 = 0;
        a->unk6++;
        D_8009A1F8[0x13] = 0xC80;
        D_8009A1F8[0x12] = 0xC80;
    }
}

void func_800F40FC_ovl29(u8* obj) {
    u8* child;

    if (**(s8**)(obj + 0x80) == 0) {
        obj[6]++;
        set_animation(obj, 0xF);
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 2;
            *(u8**)(child + 0x50) = obj;
        }
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 3;
            *(u8**)(child + 0x50) = obj;
        }
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 0;
            *(u8**)(child + 0x50) = obj;
        }
        obj[0x67] = 1;
        *(s32*)(obj + 0x2C) = 0xD00;
        *(s16*)(obj + 0x7C) = 0;
    }
}

void func_800F41DC_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 0x11);
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}

extern u8 D_800D1C00[];

void func_800F4244_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 0x12);
        D_800D1C00[0x24] = 1;
        D_800D1C00[0x25] = 0;
        *(s16*)(obj + 0x7E) = 3;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_80017BF4(void);
extern u8 D_800F988C_ovl29[];

void func_800F42D0_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x5C) < D_800D1CA2) {
        if (--*(s16*)(obj + 0x7E) == 0) {
            play_sound(0, 0xE, 0);
            *(s16*)(obj + 0x7E) = 3;
        }
        if (!(D_8009A420_as_s32 & 1)) {
            obj[0x5C]++;
        }
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        func_80017BF4();
        set_animation(obj, 0);
        obj[5] = 4;
        obj[6] = 0;
        *(u8**)(obj + 0x54) = D_800F988C_ovl29;
        func_8003D2C4();
        func_8002D9EC(obj, 0x40, 0x40);
    }
}
