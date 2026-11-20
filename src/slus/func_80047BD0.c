#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_80045D44();
extern u8 D_80077064[];
extern u8 D_80077070[];
extern u8 D_8007B424[];

void func_80047BD0(u8* obj) {
    s8 kind;
    u8* q;
    u8* g;
    s32 k;

    *(u8**)(obj + 0x68) = D_80077070;
    kind = obj[2];
    obj[0x64] = 0;
    *(u8**)(obj + 0x50) = D_80077064 + kind * 4;
    *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x14);
    q = D_1F80001C.bytes + D_1F80001C.s32s[13];
    *(u8**)(obj + 0x30) = D_8007B424;
    *(s16*)(obj + 0x40) = 0x520;
    *(s16*)(obj + 0x42) = 0x7801;
    obj[0x16] = 1;
    *(u8**)(obj + 0x3C) = q;
    g = g_Player;
    obj[0x15] = g[0x15];
    if (kind == 0) {
        func_80045D44(obj, g, (s8)obj[1]);
        if (obj[0x15] == 0) {
            do {
                *(s32*)(obj + 0x20) = -0x50000;
                *(s32*)(obj + 0x28) = -0x2000;
            } while (0); // !FAKE: fences the sched hoist of the 0x2000 load
            k = 0x2000;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = k;
        } else {
            do {
                *(s32*)(obj + 0x20) = 0x50000;
                *(s32*)(obj + 0x28) = -0x2000;
            } while (0); // !FAKE: fences the sched hoist of the 0x2000 load
            k = 0x2000;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = k;
        }
    }
    obj[0x67] = 1;
    if (((s8*)obj)[2] == 0) {
        set_animation(obj, 0);
        play_sound(1, 0x12, obj);
        obj[5] = 0;
    } else {
        set_animation(obj, 2);
        obj[5] = 2;
        obj[0x8D] = 0x3C;
    }
    obj[4]++;
    func_8002D9EC(obj, 0x20, 0x20);
}
