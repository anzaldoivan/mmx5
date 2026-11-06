#include "types.h"

extern void func_8003A9AC(void);
extern void func_8003A94C(u8* obj);
extern s32 func_8003EFE0(u8* arg0);
extern s32 func_800439A8(u8* obj);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8003D344(void* arg0);
extern void func_8003F2D8(u8* arg0, s32 arg1);

void func_80036920(u8* obj) {
    s32 t;

    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    if (*(s8*)(obj + 0xD3) != 0) {
        func_8003A94C(obj);
        return;
    }
    if (func_8003EFE0(obj) == 0 && func_800439A8(obj) == 0) {
        func_80017248(obj);
        func_8002DED4(obj);
        func_8003D344(obj);
        t = obj[0x8A] - 1;
        obj[0x8A] = t;
        if ((t << 24) == 0) {
            *(s32*)(obj + 0x20) = 0;
            obj[5] = 7;
            obj[6] = 0;
            return;
        }
        func_8003F2D8(obj, 0xB);
    }
}
