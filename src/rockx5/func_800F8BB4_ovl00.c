#include "types.h"

extern u8 D_800FB448_ovl00[][6];
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F8BB4_ovl00(u8* obj) {
    u8* p;

    if (--*(s16*)(obj + 0x7C) == 0) {
        if (*(s16*)(obj + 0x7E) == 2) {
            func_800171E8(obj, 0);
            obj[5] = D_800FB448_ovl00[obj[0x8D]][obj[0x8E]++];
            obj[6] = 0;
        } else {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 3;
                p[2] = obj[0x7E];
                *(u8**)(p + 0x7C) = obj;
                func_80016490(2, 1, obj);
            }
        }
        if (++*(s16*)(obj + 0x7E) == 1) {
            *(s16*)(obj + 0x7C) = 0x14;
        } else {
            *(s16*)(obj + 0x7C) = 0x78;
        }
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
