#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern void func_800F0924_ovl07(u8* obj);
extern void func_800F0864_ovl07(u8* obj);
extern void func_800F0670_ovl07(u8* obj);
extern void func_800F0008_ovl07(u8* obj);

void func_800F0464_ovl07(u8* obj) {
    if (!(obj[0x70] & 8)) {
        obj[5] = 4;
        obj[6] = 0;
    } else {
        func_800EFCE4_ovl07(obj, obj[0x82]);
        func_800F0924_ovl07(obj);
        if (obj[0x7D] == 0) {
            func_800F0864_ovl07(obj);
        }
        func_800F0670_ovl07(obj);
        animate_object(obj);
        func_800F0008_ovl07(obj);
    }
}

extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern void func_800F0924_ovl07(u8* obj);
extern void func_800EFF18_ovl07(u8* obj);

void func_800F04E8_ovl07(u8* obj) {
    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        *(s32*)(obj + 0x2C) = 0x5000;
    }
    obj[0x67] = 1;
    func_800EFCE4_ovl07(obj, 4);
    if ((*(s32*)(obj + 0x70) & 5) != 5) {
        apply_object_motion(obj);
        if (*(s32*)(obj + 0x24) < 0) {
            obj[5] = 4;
            obj[6] = 0;
        } else if (!(*(u16*)(obj + 0x8A) & 0x80)) {
            obj[5] = 4;
            obj[6] = 0;
            *(s32*)(obj + 0x24) = 0;
        }
    } else {
        obj[5] = 4;
        obj[6] = 0;
        *(s32*)(obj + 0x24) = 0;
        if (obj[0x70] & 1) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
        }
    }
    func_800F0924_ovl07(obj);
    if (obj[0x7D] != 0) {
        *(s16*)(obj + 0x8E) = 1;
    }
    func_800EFF18_ovl07(obj);
}

extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern void func_800EFC30_ovl07(u8* obj);

void func_800F05D8_ovl07(u8* obj) {
    u8 flags;

    obj[0x67] = 1;
    func_800EFCE4_ovl07(obj, 3);
    flags = obj[0x70];
    if (!(flags & 4)) {
        func_800EFC30_ovl07(obj);
        if (*(s32*)(obj + 0x24) < 0) {
            obj[6] = 3;
            play_sound(5, 0x11, 0);
        }
    } else {
        obj[6] = 3;
        *(s32*)(obj + 0x24) = 0;
        if (flags & 1) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
        }
    }
    animate_object(obj);
}
