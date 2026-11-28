#include "types.h"

extern u8* find_free_visual_obj(void);

void func_800556B0(u8* obj, s8 a, s8 b) {
    u8* p;

    p = find_free_visual_obj();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = a;
        p[2] = b;
        {
            u8 t = obj[0x14];
            *(u8**)(p + 0x50) = obj;
            p[0x14] = t;
        }
    }
}
