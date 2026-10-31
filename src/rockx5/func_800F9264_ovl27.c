#include "types.h"
#include "addr.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern s16 D_800FDA58_ovl27[][2];

void func_800F9264_ovl27(u8* obj) {
    s32 a;
    s32 v;
    s32 x;
    s32 y;

    x = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0];
    y = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1];
    a = ratan2(*(s16*)(obj + 0xE) - y, x - *(s16*)(obj + 0xA));
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) = rcos(a) << 4;
    *(s32*)(obj + 0x24) = rsin(a) << 4;
    v = *(s32*)(obj + 0x20);
    if (v != 0) {
        *(s32*)(obj + 0x20) = v * 3 / 2;
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    v = *(s32*)(obj + 0x24);
    if (v != 0) {
        *(s32*)(obj + 0x24) = v * 3 / 2;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    func_8002DF54(obj);
    if (D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0] - 3 <= *(s16*)(obj + 0xA) &&
        D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0] + 3 >= *(s16*)(obj + 0xA) &&
        D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1] - 3 <= *(s16*)(obj + 0xE) &&
        D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1] + 3 >= *(s16*)(obj + 0xE)) {
        *(s16*)(obj + 0xA) = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0];
        *(s16*)(obj + 0xE) = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1];
        func_800171E8(obj, 0xB);
        obj[6]++;
    }
}
