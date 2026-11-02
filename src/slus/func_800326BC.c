#include "types.h"

extern s32 func_80032844(u8* a, u8* b);
extern void func_800330C4(u8* a, u8* b);
extern s32 func_8002EF68(u8* a, u8* b);
extern u8 D_80096D98[];
extern u8 D_80098120[];

void func_800326BC(u8* obj) {
    u8* p;
    s32 mask;
    u32 i;

    mask = 1;
    if (*(s32*)(obj + 0x68) != 0) {
        i = 0;
        p = D_80096D98;
        do {
            if (((s8*)p)[0] != 0 && ((s8*)p)[1] == 0x22) {
                func_80032844(obj, p);
                if (*(s32*)(obj + 0x90) & mask) {
                    func_800330C4(obj, p);
                }
                if (func_8002EF68(obj, p) == 8) {
                    *(s32*)(obj + 0x90) = *(s32*)(obj + 0x90) | mask;
                } else {
                    *(s32*)(obj + 0x90) = *(s32*)(obj + 0x90) & ~mask;
                }
            }
            p += 0x9C;
            i++;
            mask <<= 1;
        } while (i < 0x20);
        mask = 1;
        i = 0;
        p = D_80098120;
        do {
            if (((s8*)p)[0] != 0 && (((s8*)p)[1] == 3 || ((s8*)p)[1] == 5)) {
                func_80032844(obj, p);
                if (*(s32*)(obj + 0x94) & mask) {
                    func_800330C4(obj, p);
                }
                if (func_8002EF68(obj, p) == 8) {
                    *(s32*)(obj + 0x94) = *(s32*)(obj + 0x94) | mask;
                } else {
                    *(s32*)(obj + 0x94) = *(s32*)(obj + 0x94) & ~mask;
                }
            }
            p += 0x9C;
            i++;
            mask <<= 1;
        } while (i < 0x20);
    }
}
