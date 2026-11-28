#include "types.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void player_spawn_visual(s32 a, s32 b, s32 c, s32 d);
extern void func_800464F0(u8* obj);
extern u8 D_80076E20[];
extern u8 D_80076E40[];

void func_80044E20(u8* obj) {
    u8* sp;
    s32 off;
    u8* src;
    u8* g;
    s16 v;
    s32 x;

    obj[0] = 0x21;
    obj[3] = 1;
    *(u8**)(obj + 0x68) = D_80076E40;
    *(u8**)(obj + 0x50) = D_80076E20;
    sp = D_1F80001C.bytes;
    src = *(u8**)(obj + 0x7C);
    off = *(s32*)(sp + 4);
    *(u8**)(obj + 0x30) = g_visual_animation_tables.u;
    g = g_Player;
    *(s16*)(obj + 0x40) = 0;
    obj[0x16] = 1;
    *(u8**)(obj + 0x3C) = sp + off;
    v = 0x7802;
    if (*(s32*)(g + 0xFC) & 0x300) {
        v = 0x7844;
    }
    *(s16*)(obj + 0x42) = v;
    if (*(s32*)(g + 0xFC) & 0x800) {
        *(s16*)(obj + 0x42) = 0x7844;
    }
    obj[0x15] = src[0x15];
    *(s32*)(obj + 0x84) = 0;
    func_800464F0(obj);
    *(s16*)(obj + 0x8) = 0;
    *(s16*)(obj + 0xC) = 0;
    x = *(s32*)(src + 0xFC) & 0x200;
    if (!x) {
        x = 0x60000;
    } else {
        x = 0x80000;
    }
    do {
        x |= 0xC000;
        *(volatile s32*)(obj + 0x20) =
            x; // !FAKE: volatile store keeps the field reload
    } while (0); // !FAKE: fence keeps the lbu after the store (C0294)
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    set_animation(obj, 0x15);
    obj[4]++;
    func_8002D9EC(obj, 0xC, 8);
    player_spawn_visual(0x21, 2, 0, 0);
}
