#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern u8* func_8002D078();

void func_800F0568_ovl06(u8* obj) {
    u8* child;
    u8* g;
    u8 st;
    s32 t;
    u8 f;
    u16 h;
    u16 v;
    s32 mask;
    s32 m1;
    s8 s6;

    if (!(D_8009A420_as_s32 & 3) && (random_byte() & 1)) {
        random_byte();
    }
    s6 = *(s8*)(obj + 6);
    if (s6 == 0) {
        obj[6] = s6 + 1;
        child = func_8002D078();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x3E;
            child[2] = 1;
            *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            child[0x16] = obj[0x16];
            *(u8**)(child + 0x7C) = obj;
            child[0x15] = obj[0x15];
        }
        set_animation(obj, 9);
        if (obj[0x8D] == 0) {
            g = g_Player;
            g[0xD8] = 0x37;
            g[6] = 0;
        }
        play_sound(5, 0xB, 0);
    }
    st = obj[0xA8];
    t = obj[0x90] - 1;
    obj[0x90] = t;
    if (!(st & 8)) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    f = obj[0x97];
    if (!(f & 2)) {
        if ((st & 3) || (obj[0x45] & 1)) {
            if ((s8)t < 0) {
                obj[5] = 8;
                obj[6] = 0;
            } else {
                goto add; // !FAKE: goto kept for the matching branch layout
            }
        } else {
            if (!(f & 8)) {
                m1 = 2;
                if (obj[0x15] != 0) {
                    m1 = 1;
                }
                v = *(u16*)(obj + 0x88) & m1;
            } else {
                mask = 2;
                if (obj[0x15] != 0) {
                    mask = 1;
                }
                h = *(u16*)(obj + 0x88);
                if (h & mask) {
                    goto add; // !FAKE: goto kept for the matching branch layout
                }
                v = h & 0x100;
            }
            if (v != 0) {
            add:
                *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
            }
        }
        animate_object(obj);
        return;
    }
    animate_object(obj);
}
