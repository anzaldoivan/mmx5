#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F2CA8_ovl11(u8* obj) {
    func_80017248(obj);
    if (++D_1F80004C.bytes[0x81] == 60) {
        func_800171E8(obj, 1);
        obj[5] = 2;
        obj[6] = 0;
    }
}
