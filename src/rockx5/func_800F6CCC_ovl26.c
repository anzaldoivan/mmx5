#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800F7664_ovl26(u8* obj, s16 x, s16 y, u8 arg3);

void func_800F6CCC_ovl26(u8* obj) {
    func_8002DF54(obj);
    if (obj[0x70] == 0) {
        func_8002F8FC(obj);
    }
    switch ((s8)obj[2]) {
    case 0:
        if (obj[0x70] & 2) {
            func_800F7664_ovl26(obj, *(s16*)(obj + 0xA) - 0x18,
                                *(s16*)(obj + 0xE), obj[2] + 1);
            obj[6]++;
        }
        break;
    case 2:
        if (obj[0x70] & 1) {
            func_800F7664_ovl26(obj, *(s16*)(obj + 0xA) + 0x18,
                                *(s16*)(obj + 0xE), obj[2] + 1);
            obj[6]++;
        }
        break;
    case 4:
        if (obj[0x70] & 4) {
            func_800171E8(obj, 0xE);
            func_800F7664_ovl26(obj, *(s16*)(obj + 0xA),
                                *(s16*)(obj + 0xE) - 0x78, obj[2] + 1);
            obj[6]++;
        }
        break;
    case 6:
        if (obj[0x70] & 8) {
            func_800171E8(obj, 0xE);
            func_800F7664_ovl26(obj, *(s16*)(obj + 0xA),
                                *(s16*)(obj + 0xE) + 0x78, obj[2] + 1);
            obj[6]++;
        }
        break;
    }
    obj[0x70] = 0;
}
