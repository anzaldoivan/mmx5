#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F5B48_ovl26(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s16*)(obj + 0xA) < 0x990) {
        D_1F80004C.bytes[0x96] = 1;
        if (*(s16*)(obj + 0xA) < 0x910) {
            *(s16*)(obj + 0xA) += 1;
        } else if (*(s16*)(obj + 0xA) > 0x910) {
            *(s16*)(obj + 0xA) -= 1;
        }
    } else {
        D_1F80004C.bytes[0x96] = 0;
        if (*(s16*)(obj + 0xA) < 0xA10) {
            *(s16*)(obj + 0xA) += 1;
        } else if (*(s16*)(obj + 0xA) > 0xA10) {
            *(s16*)(obj + 0xA) -= 1;
        }
    }
    if (*(s16*)(obj + 0xE) < 0x123D) {
        *(s32*)(obj + 0x68) = 0;
        func_800171E8(obj, 0x16);
        obj[6]++;
    }
}
