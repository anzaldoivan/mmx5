#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void (*D_800FE6E4_ovl28[])(u8* obj);
extern s16 D_8009A0AA;

void func_800F92EC_ovl28(u8* obj) {
    D_800FE6E4_ovl28[((s8*)obj)[6]](obj);
    if (D_8009A0AA > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}
