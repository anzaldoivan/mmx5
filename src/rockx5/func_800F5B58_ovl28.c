#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F5B58_ovl28(u8* obj) {
    s32 mask;
    u8 dir;

    func_80017248(obj);
    func_8002DED4(obj);
    dir = obj[0x15];
    mask = 2;
    if (dir != 0 && (mask = 1, obj[0x15] != 0)) {
        if (*(s32*)(obj + 0x20) < 0x42000) {
            *(s32*)(obj + 0x20) = 0x42000;
        }
    } else if (*(s32*)(obj + 0x20) > -0x42000) {
        *(s32*)(obj + 0x20) = -0x42000;
    }
    if ((obj[0x70] & mask) || (s8)obj[0x45] == 2) {
        func_800171E8(obj, 0x1A);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x42000;
        } else {
            *(s32*)(obj + 0x20) = -0x42000;
        }
        *(s32*)(obj + 0x28) = -0x3000;
        *(s8*)(obj + 0x9A) = -1;
        obj[6]++;
        func_80016490(2, 0x72, obj);
    }
}
