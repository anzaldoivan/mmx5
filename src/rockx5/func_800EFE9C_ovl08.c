#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016D54(s32, s32);

void func_800EFE9C_ovl08(u8* obj) {
    u8 mode;

    if (!(obj[2] & 0x10)) {
        func_8002DF54(obj);
    }
    func_80017248(obj);
    if (--*(s32*)(obj + 0x8C) == 0) {
        func_800171E8(obj, 3);
        *(s32*)(obj + 0x20) = 0;
        func_80016D54(2, 0x51);
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    mode = obj[0x90];
    if (mode != 0) {
        if (--obj[0x91] == 0) {
            if (mode == 2) {
                obj[0x91] = 0x30;
                if (--obj[0x92] == 0) {
                    obj[0x92] = mode;
                    func_800171E8(obj, 3);
                    *(s32*)(obj + 0x20) = 0;
                    func_80016D54(2, 0x51);
                    obj[5] = 5;
                    obj[6] = 0;
                    return;
                }
            } else {
                obj[0x91] = 0x60;
            }
            *(s16*)(obj + 0x7C) = 0x14;
            *(s32*)(obj + 0x24) = 0;
            obj[5] = 4;
            obj[6] = 0;
        }
    }
    if (obj[0x15] == 0) {
        if (obj[0x70] & 2) {
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    } else if (obj[0x70] & 1) {
    tail:
        *(s16*)(obj + 0x7C) = 0x14;
        *(s32*)(obj + 0x24) = 0;
        obj[5] = 4;
        obj[6] = 0;
    }
}
