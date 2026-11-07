#include "types.h"

extern s32 func_8002FB58(u8* obj);
extern void func_800F9A88_ovl00(s32 arg0);
extern void func_800F9AD4_ovl00(s32 arg0);
extern void func_800F9B20_ovl00(u8* arg0);
extern u8 D_8009A1F8[];
extern void* D_800FB4A4_ovl00[];

void func_800F7EF0_ovl00(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_8002FB58(obj);
    ((void (*)(u8*))D_800FB4A4_ovl00[*(s8*)(obj + 0x4)])(obj);
    if (obj[0x90] != 0) {
        D_8009A1F8[0x57] = 0;
        if (*(s8*)(obj + 0x3) != 0) {
            if (*(u16*)(obj + 0x42) & 0x8000) {
                func_800F9AD4_ovl00(obj[0x47]);
            } else {
                func_800F9A88_ovl00(obj[0x47]);
            }
            D_8009A1F8[0x57] = 1;
            obj[0x3] = 0;
            func_800F9B20_ovl00(obj);
        }
    }
}
