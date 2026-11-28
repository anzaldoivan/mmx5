#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FF1E4_ovl06[];
extern u8 D_800FF1E8_ovl06[];
extern s16 D_800FF4F4_ovl06[][2];

void func_800F86E8_ovl06(u8* obj) {
    s32 i;
    s32 ang;
    s32 t;
    s32 t1;
    s32 t2;
    s32 c;
    s32 sn;
    s16 v;

    i = obj[0x15] == 0;
    ang = ratan2(
        *(s16*)(obj + 0xE) - (D_800FF4F4_ovl06[i][1] + D_800FF94E_ovl06),
        (D_800FF4F4_ovl06[i][0] + D_800FF94C_ovl06) - *(s16*)(obj + 0xA));
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    c = rcos(ang);
    t1 = c << 4;
    *(s32*)(obj + 0x20) = ((c << 5) + t1) << 1;
    sn = rsin(ang);
    t2 = sn << 4;
    *(s32*)(obj + 0x24) = ((sn << 5) + t2) << 1;
    animate_object(obj);
    move_object(obj);
    v = *(s16*)(obj + 0xA);
    t = D_800FF4F4_ovl06[i][0] + D_800FF94C_ovl06;
    if (v >= t - 4 && t + 4 >= v) {
        v = *(s16*)(obj + 0xE);
        t = D_800FF4F4_ovl06[i][1] + D_800FF94E_ovl06;
        if (v >= t - 4 && t + 4 >= v) {
            set_animation(obj, 0xE);
            *(u8**)(obj + 0x50) = D_800FF1E4_ovl06;
            *(u8**)(obj + 0x54) = D_800FF1E8_ovl06;
            *(s16*)(obj + 0x7C) = 0x32;
            obj[6]++;
        }
    }
}

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void func_800F8864_ovl06(u8* obj) {
    u8 flags;
    s32 hit;

    animate_object(obj);
    apply_object_motion(obj);
    func_8002FB58(obj);
    flags = obj[0x70];
    if (flags & 8) {
        start_pad_vibration(5);
        func_8002A600(0x5A, 4, 2);
        play_sound(2, 7, obj);
        set_animation(obj, 0x1E);
        *(u8**)(obj + 0x50) = D_800FF1CC_ovl06;
        *(u8**)(obj + 0x54) = D_800FF1D0_ovl06;
        *(s16*)(obj + 0x7C) = 0;
        obj[6] = 5;
        return;
    }
    if (obj[0x15] == 0x40) {
        if (flags & 1) {
            goto set; // !FAKE: goto kept for the matching branch layout
        }
        hit = flags & 4;
    } else {
        hit = *(s32*)(obj + 0x70) & 6;
    }
    if (hit != 0) {
    set:
        start_pad_vibration(5);
        func_8002A600(0x5A, 4, 2);
        set_animation(obj, 0x14);
        *(s32**)(obj + 0x50) = D_800FF1DC_ovl06.w;
        *(s32**)(obj + 0x54) = D_800FF1E0_ovl06.w;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x3000;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
}
