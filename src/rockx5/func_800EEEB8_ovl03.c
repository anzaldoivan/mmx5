#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 D_8009A420;

void func_800EEEB8_ovl03(u8* obj) {
    s32 lim;
    s32 over;

    *(s32*)(obj + 0x24) = 0;
    if (*(s8*)(obj + 0x2) == 0) {
        if (obj[0x70] & 2) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            obj[0x5] = 4;
            obj[0x6] = 0;
        }
        lim = -0x20000;
        over = *(s32*)(obj + 0x20) < lim;
    } else {
        if (obj[0x70] & 1) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            obj[0x5] = 4;
            obj[0x6] = 0;
        }
        lim = 0x20000;
        over = *(s32*)(obj + 0x20) > lim;
    }
    if (over) {
        *(s32*)(obj + 0x20) = lim;
    }
    if (D_8009A420 == D_8009A420 / 30 * 30) {
        func_80016490(5, 9, obj);
    }
    func_8002DED4(obj);
    func_80017248(obj);
}
