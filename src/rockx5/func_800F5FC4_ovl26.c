#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern X4_S16Pair D_800F9F24_ovl26[][16];

void func_800F5FC4_ovl26(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_8002DF54(obj);
        if (*(s16*)(obj + 0xE) <=
            D_800F9F24_ovl26[obj[0x94]][*(s8*)(obj + 2)].lo) {
            *(s16*)(obj + 0xE) =
                D_800F9F24_ovl26[obj[0x94]][*(s8*)(obj + 2)].lo;
            func_800171E8(obj, 0);
            obj[6]++;
        }
    }
}
