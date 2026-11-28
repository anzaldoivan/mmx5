#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern s32 func_80045E2C(void);
extern void func_8004F874(u8* obj);
extern u8 D_8007B5DC[][3];

void func_8004F1FC(u8* obj) {
    s32 i;
    s8 st;
    u8* g;
    u8* h;
    u8* v;
    u8 b;

    st = ((s8*)obj)[2];
    obj[3] = 1;
    if (st == 9) {
        i = 0;
    } else if (st == 18) {
        i = 1;
    } else if (st == 20) {
        i = 2;
    } else if (st == 0) {
        i = 3;
    } else if (st == 19 || st == 46) {
        i = 2;
    }
    v = D_1F80001C.bytes + D_1F80001C.s32s[D_8007B5DC[i][0]];
    *(u8**)(obj + 0x30) = g_visual_animation_tables.u;
    *(s16*)(obj + 0x40) = 0;
    *(s16*)(obj + 0x42) = 0x7802;
    *(u8**)(obj + 0x3C) = v;
    if (i == 3) {
        *(s16*)(obj + 0x42) = func_80045E2C();
        g = g_Player;
        if (*(s32*)(g + 0xFC) & 0x800) {
            *(s16*)(obj + 0x42) = 0x7844;
        }
    }
    h = g_Player;
    obj[0x16] = 0;
    b = h[0x15];
    obj[0x5C] = 0;
    obj[0x15] = b;
    func_8004F874(obj);
    *(s16*)(obj + 0x8) = 0;
    *(s16*)(obj + 0xC) = 0;
    set_animation(obj, D_8007B5DC[i][1]);
    play_sound(1, D_8007B5DC[i][2], obj);
    obj[4]++;
    func_8002D9EC(obj, 0x40, 0x20);
}
