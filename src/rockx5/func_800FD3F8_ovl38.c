#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void func_800FD3F8_ovl38(u8* obj) {
    u8* p = *(u8**)(obj + 0x50);
    s32 r;

    if (*(s8*)(p + 4) == 2) {
        obj[3] = 0;
        obj[4]++;
        *(s16*)(p + 0x84) = 1;
    } else {
        func_80017248(obj);
        func_8002DED4(obj);
        r = func_8002D938(obj, 0x40, 0x40);
        if (r == 1) {
            *(s16*)(*(u8**)(obj + 0x50) + 0x84) = r;
            obj[4]++;
        }
    }
}
