#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

void func_800F9468_ovl28(u8* obj) {
    if (((s8*)obj)[2] == 0) {
        set_animation(obj, 3);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        *(s16*)(obj + 0x7C) = 0;
        obj[6] = 1;
    } else {
        set_animation(obj, 3);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[7] = 0;
        obj[6] = 4;
    }
}

void func_800F9514_ovl28(u8* obj) {
    s8 kind;
    u8* p;

    kind = *(s8*)(obj + 0x45);
    if (kind == 1) {
        play_sound(2, 0x8B, obj);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = kind;
            *(u8**)(p + 0x7C) = obj;
        }
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 2;
            *(u8**)(p + 0x7C) = obj;
        }
    }
    if (++*(s16*)(obj + 0x7C) == 40) {
        set_animation(obj, 3);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
}

void func_800F960C_ovl28(u8* obj) {
    s8 kind;
    u8* p;

    kind = *(s8*)(obj + 0x45);
    if (kind == 1) {
        play_sound(2, 0x8B, obj);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = kind;
            *(u8**)(p + 0x7C) = obj;
        }
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 2;
            *(u8**)(p + 0x7C) = obj;
        }
    }
    if (++*(s16*)(obj + 0x7C) == 40) {
        set_animation(obj, 4);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[6]++;
    }
}

#include "shared/func_800F9704_ovl28.c"

void func_800F9794_ovl28(u8* arg0) {
    u8* p;

    if (*(s8*)(arg0 + 0x45) == 1) {
        play_sound(2, 0x91, arg0);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 3;
            *(u8**)(p + 0x7C) = arg0;
        }
    }
    if (*(s8*)(arg0 + 0x46) == 0) {
        set_animation(arg0, 2);
    }
    if (*(s8*)(arg0 + 7) == 1) {
        set_animation(arg0, 3);
        if (D_8009A0AA > *(s16*)(arg0 + 0xA)) {
            arg0[0x15] = 0x40;
        } else {
            arg0[0x15] = 0;
        }
        arg0[6]++;
    }
}

void func_800F9864_ovl28(u8* obj) {
    u8* p;

    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x91, obj);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 3;
            *(u8**)(p + 0x7C) = obj;
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 2);
    }
    if (*(s8*)(obj + 7) == 2) {
        set_animation(obj, 4);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[6]++;
    }
}

#define func_800F9704_ovl28 func_800F9934_ovl28
#include "shared/func_800F9704_ovl28.c"
#undef func_800F9704_ovl28
