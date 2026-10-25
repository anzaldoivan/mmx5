#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800EFA5C_ovl18(u8* obj) {
    u8* parent;

    func_80017248(obj);
    parent = *(u8**)(obj + 0x50);
    if (((s8*)parent)[6] >= 2) {
        if (((s8*)obj)[2] == 0) {
            if (((s8*)parent)[2] == 10) {
                func_800171E8(obj, 10);
            } else {
                func_800171E8(obj, 5);
            }
            obj[5]++;
        } else {
            obj[4]++;
        }
    }
}
