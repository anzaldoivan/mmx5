#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8* find_free_visual_obj(void);

void func_800F5414_ovl28(u8* obj) {
    s32 i;
    u8* p;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0);
        obj[7] = 0;
        obj[6]++;
        for (i = 0; i < 2; i++) {
            p = find_free_visual_obj();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 0xB;
                p[2] = i;
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + (i + 1) * 0x30 - 8;
                *(s16*)(p + 0xE) = 0x240;
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                func_8002C338(0x140, D_1F800030 + 0x320, 1);
                *(s16*)(p + 0x42) = 0x7CCD;
                p[0x15] = obj[0x15];
                *(u8**)(p + 0x50) = obj;
            }
        }
    }
}
