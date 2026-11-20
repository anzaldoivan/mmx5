#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern u8* find_free_visual_obj(void);
extern u8* func_8002D078();
extern s32 player_check_dash_jump_walk(u8* arg0);
extern void func_800444B4(u8* a0);

void func_80041EF8(u8* obj) {
    u8* p;
    u8* q;
    s8 t;

    if (*(s8*)(obj + 6) == 0) {
        q = find_free_visual_obj();
        if (q != 0) {
            q[0] = 1;
            q[1] = 3;
            q[2] = 0xE;
            q[0x14] = obj[0x14];
            *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
            *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(q + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(q + 0x42) = 0x7802;
            q[0x16] = 0;
            *(s32*)(q + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(q + 0xC) = *(s32*)(obj + 0xC);
            q[0x15] = obj[0x15];
        }
        obj[6]++;
    } else if (*(s8*)(obj + 6) == 1) {
        animate_object(obj);
        if (*(s8*)(obj + 0x45) & 0x80) {
            p = func_8002D078();
            if (p != 0) {
                p[0] = 0x21;
                p[1] = 0x3A;
                p[0x14] = obj[0x14];
                p[0x15] = obj[0x15];
            }
            obj[6]++;
            play_sound(1, 0xE, obj);
        }
    } else {
        t = *(s8*)(obj + 0x45);
        if (t == 1 && *(s8*)(obj + 0xD3) == 0) {
            obj[0x8E] = 0;
            if (player_check_dash_jump_walk(obj) != 0) {
                return;
            }
            obj[0x8E] = t;
        }
        animate_object(obj);
        func_800444B4(obj);
    }
}
