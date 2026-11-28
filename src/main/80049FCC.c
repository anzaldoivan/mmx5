#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"

extern int func_80045D44();
extern u8 D_8007B488[];
extern s32 D_80077144[];

void func_80049FCC(u8* obj) {
    u8* p = g_Player;
    u8* t;
    s32 off;

    obj[3] = 1;
    *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x2C);
    t = D_1F80001C.bytes;
    off = *(s32*)(t + 0x60);
    *(u8**)(obj + 0x30) = D_8007B488;
    *(s16*)(obj + 0x40) = 0x540;
    *(s16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 2;
    *(u8**)(obj + 0x3C) = t + off;
    obj[0x15] = p[0x15];
    set_animation(obj, 0);
    *(s32**)(obj + 0x50) = &D_80077144[((s8*)obj)[0x45]];
    func_80045D44(obj, p, ((s8*)obj)[1]);
    if (obj[0x15] != 0) {
        *(u16*)(obj + 0xA) += 0x84;
    } else {
        *(u16*)(obj + 0xA) -= 0x84;
    }
    play_sound(1, 0x18, obj);
    *(s16*)(obj + 0x8C) = 0;
    obj[4]++;
}

extern int func_80045D44();
extern s32 D_80077144[];

void func_8004A0D4(u8* obj) {
    u8* p = g_Player;

    if (*(s8*)(p + 0x8E) == 0) {
        set_animation(obj, 1);
        *(s32*)(obj + 0x50) = 0;
        obj[4] = 2;
    } else {
        animate_object(obj);
        func_80045D44(obj, p, ((s8*)obj)[1]);
        if (obj[0x15] != 0) {
            *(u16*)(obj + 0xA) += 0x84;
        } else {
            *(u16*)(obj + 0xA) -= 0x84;
        }
        *(s32**)(obj + 0x50) = &D_80077144[((s8*)obj)[0x45]];
    }
}

void func_8004A184(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[3] = 0;
        obj[4] = 3;
    }
}

extern void silence_sound(s32, s32);

void func_8004A1C0(u8* obj) {
    u8* p;

    silence_sound(1, 0x18);
    p = g_Player;
    p[0x98]--;
    p[0x99]--;
    clear_object_slot(obj);
}
