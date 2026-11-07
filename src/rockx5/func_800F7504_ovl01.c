#include "types.h"

extern u8 D_8009A197;
extern void (*D_800FD2E4_ovl01[])(u8*);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F7504_ovl01(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) != 5) {
        if (D_8009A197 == 0) {
            D_800FD2E4_ovl01[*(s8*)(obj + 5)](obj);
            func_80017248(obj);
        }
        func_800317B8(obj);
        if (func_80031DD0(obj) >= 0) {
            if (obj[0x70] != 0 || (func_8002F8FC(obj), obj[0x70] != 0)) {
                func_8004FC64(obj);
                obj[4] = 3;
                return;
            }
            if (func_8002D938(obj, 0x60, 0x20) == 0) {
                func_8002D9EC(obj, 0x50, 0x10);
                return;
            }
        }
    }
    obj[4] = 3;
}
