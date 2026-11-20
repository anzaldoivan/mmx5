#include "types.h"

extern u8* find_free_visual_obj(void);

void func_8003D200(u8* arg0) {
    u8* p;
    u8 v;

    p = find_free_visual_obj();
    if (p != 0) {
        p[0] = 0x21;
        p[1] = 1;
        v = arg0[0x14];
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[0x14] = v;
    }
}
