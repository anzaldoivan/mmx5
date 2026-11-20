#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* find_free_visual_obj(void);

void func_80055AD0(u8* obj) {
    u8* g;
    u8* p;

    if (obj[0x72] & 8) {
        set_animation(obj, 1);
        g = g_Player;
        func_8003D29C(0x18, g[0x15]);
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 0;
            {
                u8 t = obj[0x14];
                *(u8**)(p + 0x50) = obj;
                p[0x14] = t;
            }
        }
        {
            s32 v = *(s32*)(obj + 8);
            g[0xF5] = 1;
            *(s32*)(g + 8) = v;
        }
        obj[5]++;
    }
}
