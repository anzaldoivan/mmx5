#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F57A0_ovl26(u8* obj) {
    if (D_1F80004C.bytes[0x92] == 0) {
        func_80017248(obj);
        if (--*(s16*)(obj + 0x7E) != 0) {
            obj[6] = 0;
        } else {
            obj[6]++;
            func_800171E8(obj, 0x14);
        }
    }
}
