#include "types.h"
#include "mmx5/globals.h"

extern u8* find_free_visual_obj(void);

void func_80055B78(u8* obj) {
    u8* g;
    u8* p;
    u8* q;
    u8* r;
    u8* w;
    u8 st;
    u8 id;

    g = g_Player;
    st = g[0xF5];
    *(s32*)(g + 8) = *(s32*)(obj + 8);
    if (st == 2) {
        id = 0x25;
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = id;
            p[2] = 0;
            {
                u8 t = obj[0x14];
                *(u8**)(p + 0x50) = obj;
                p[0x14] = t;
            }
        }
        q = find_free_visual_obj();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = id;
            q[2] = 1;
            {
                u8 t = obj[0x14];
                *(u8**)(q + 0x50) = obj;
                q[0x14] = t;
            }
        }
        r = find_free_visual_obj();
        if (r != 0) {
            r[0] = 0x41;
            r[1] = id;
            r[2] = st;
            {
                u8 t = obj[0x14];
                *(u8**)(r + 0x50) = obj;
                r[0x14] = t;
            }
        }
        w = find_free_visual_obj();
        if (w != 0) {
            w[0] = 0x41;
            w[1] = id;
            w[2] = 3;
            {
                u8 t = obj[0x14];
                *(u8**)(w + 0x50) = obj;
                w[0x14] = t;
            }
        }
        obj[5]++;
    }
}
