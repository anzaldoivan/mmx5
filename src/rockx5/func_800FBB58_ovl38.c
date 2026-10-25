#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);

void func_800FBB58_ovl38(u8* obj) {
    func_80017248(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        func_8002DED4(obj);
    }
    func_8002FB58(obj);
    if (obj[0x70] & 8) {
        obj[6]++;
    }
}
