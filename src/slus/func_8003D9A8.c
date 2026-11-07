#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8003DAA4(s32 arg0);
extern void func_8003DAF4(s32 arg0);

void func_8003D9A8(u8* obj) {
    u32 i;
    s8 state;
    s32 t;
    s32 m;

    if (!(obj[0xD7] & 3)) {
        i = 0;
        do {
            i++;
            t = func_8002DF78() & 0x1F;
            m = -0x80;
            func_8003DAA4(t | m);
            m = 0; // !FAKE: dead second set of m stops loop.c hoisting the constant
        } while (i < 4);
    }
    state = *(s8*)(obj + 0xD6);
    if (state != 3) {
        if (*(s8*)(obj + 0xD7) == 0) {
            func_8003DAF4(state);
            if (*(s8*)(obj + 0xD6) == 2) {
                func_8003DAF4(3);
            }
            obj[0xD7] = 0x12;
            obj[0xD6]++;
            return;
        }
        obj[0xD7]--;
        return;
    }
    obj[0xD7] = 0x14;
    obj[5]++;
}
