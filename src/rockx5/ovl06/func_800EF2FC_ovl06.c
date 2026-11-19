#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* find_free_visual_obj(void);
extern u8 D_800FDE84_ovl06[];
extern u8 D_800FDE8C_ovl06[];

void func_800EF2FC_ovl06(u8* obj) {
    u8* p;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        *(u8**)(obj + 0x68) = D_800FDE84_ovl06;
        set_animation(obj, 0x12);
        if (obj[0x8D] == 0) {
            g_Player[0xD8] = 0x39;
            g_Player[6] = 0;
        }
        play_sound(5, 0xF, 0);
    }
    if (((s8*)obj)[0x46] == 0) {
        if (obj[0x8C] == 0) {
            obj[0x61] = 0;
        }
        obj[5] = 1;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        obj[6] = 0;
        *(u8**)(obj + 0x54) = D_800FDE8C_ovl06;
        return;
    }
    if (obj[0x45] & 1) {
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = obj[0];
            p[1] = 0xC;
            p[2] = 7;
            *(s32*)(p + 8) = *(s32*)(obj + 8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            p[0x16] = obj[0x16];
            p[0x15] = obj[0x15];
            *(u8**)(p + 0x50) = obj;
        }
        obj[0x45] = 0;
        return;
    }
    animate_object(obj);
}
