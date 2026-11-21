#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "addr.h"

void func_800F55E0_ovl26(u8* obj) {
    set_animation(obj, 0x14);
    obj[6]++;
}

#include "shared/func_800F5614_ovl26.c"

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern u8* func_8002C938();

void func_800F5668_ovl26(u8* obj) {
    u8* p;
    u8 b;

    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        start_pad_vibration(5);
        play_sound(2, 0x63, obj);
        p = func_8002C938();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x3A;
            p[2] = 2;
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s16*)(p + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
            p[0x5C] = obj[0x5C];
            b = obj[0x15];
            p[0x15] = b;
            if (b == 0) {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0xE;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0xE;
            }
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) - 0x1E;
            *(u8**)(p + 0x80) = obj;
            D_1F80004C.bytes[0x92] = 1;
        }
        func_8002A600(0x32, 4, 1);
        set_animation(obj, 0x12);
        obj[6]++;
    }
}

void func_800F57A0_ovl26(u8* obj) {
    if (D_1F80004C.bytes[0x92] == 0) {
        animate_object(obj);
        if (--*(s16*)(obj + 0x7E) != 0) {
            obj[6] = 0;
        } else {
            obj[6]++;
            set_animation(obj, 0x14);
        }
    }
}

void func_800F5818_ovl26(u8* obj) {
    s32 x;
    s32 v;
    u8 n;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        if (*(s16*)(obj + 0xA) < 0x990) {
            x = *(s32*)(obj + 8);
            v = 0x40;
            obj[0x15] = v;
            v = 0x9100000 - x;
            v = ((((0x9100000 - x) < 0) ? (x - 0x9100000) : (0x9100000 - x)) +
                 1) /
                108;
            *(s32*)(obj + 0x20) = -v;
        } else {
            x = *(s32*)(obj + 8);
            obj[0x15] = 0;
            v = ((((0xA100000 - x) < 0) ? (x - 0xA100000) : (0xA100000 - x)) +
                 1) /
                108;
            *(s32*)(obj + 0x20) = v;
        }
        do {
            *(s32*)(obj + 0x24) = 0x2C000;
            n = obj[6];
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0xD00;
        } while (0); // !FAKE: keeps the obj[6] load above the stores
        obj[6] = n + 1;
    }
}

#define func_800F5614_ovl26 func_800F5938_ovl26
#include "shared/func_800F5614_ovl26.c"
#undef func_800F5614_ovl26

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern u8* func_8002C938();

void func_800F598C_ovl26(u8* obj) {
    u8* p;
    u8 b;
    u16 e;

    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        start_pad_vibration(5);
        play_sound(2, 0x63, obj);
        p = func_8002C938();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x3A;
            p[2] = 2;
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s16*)(p + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
            p[0x5C] = obj[0x5C];
            b = obj[0x15];
            p[0x15] = b;
            if (b == 0) {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0xE;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0xE;
            }
            e = *(u16*)(obj + 0xE);
            *(u8**)(p + 0x80) = obj;
            *(s16*)(p + 0xE) = e - 0x1E;
            D_1F80004C.bytes[0x92] = 1;
        }
        func_8002A600(0x32, 4, 1);
        obj[6]++;
        set_animation(obj, 0x14);
    }
}

extern u8 D_800F9628_ovl26[];

void func_800F5AC0_ovl26(u8* obj) {
    if (D_1F80004C.bytes[0x92] == 0) {
        animate_object(obj);
        if ((s8)obj[0x45] == 1) {
            *(u8**)(obj + 0x50) = D_800F9628_ovl26;
            obj[0x60] = 0x20;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0x2C000;
            *(s32*)(obj + 0x2C) = 0xD00;
            obj[6]++;
        }
    }
}

void func_800F5B48_ovl26(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (*(s16*)(obj + 0xA) < 0x990) {
        D_1F80004C.bytes[0x96] = 1;
        if (*(s16*)(obj + 0xA) < 0x910) {
            *(s16*)(obj + 0xA) += 1;
        } else if (*(s16*)(obj + 0xA) > 0x910) {
            *(s16*)(obj + 0xA) -= 1;
        }
    } else {
        D_1F80004C.bytes[0x96] = 0;
        if (*(s16*)(obj + 0xA) < 0xA10) {
            *(s16*)(obj + 0xA) += 1;
        } else if (*(s16*)(obj + 0xA) > 0xA10) {
            *(s16*)(obj + 0xA) -= 1;
        }
    }
    if (*(s16*)(obj + 0xE) < 0x123D) {
        *(s32*)(obj + 0x68) = 0;
        set_animation(obj, 0x16);
        obj[6]++;
    }
}

void func_800F5C18_ovl26(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 4;
        obj[6] = 0;
    }
}
