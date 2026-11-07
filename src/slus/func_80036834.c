#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_80039B50(u8* arg0);
extern s32 func_80039BA8(u8* arg0);
extern void func_8003A94C(u8* obj);
extern void func_8003A9AC(void);
extern void func_8003AEF0(u8* arg0);
extern void func_8003D344(void* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern void func_8003F2D8(u8* arg0, s32 arg1);
extern s32 func_80043B08(u8* arg0);

void func_80036834(u8* obj) {
    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    if (*(s8*)(obj + 0xD3) == 0) {
        if (func_8003EFE0(obj) != 0) {
            return;
        }
        if (func_80043B08(obj) != 0) {
            return;
        }
        if (obj[0x89] & 3) {
            goto rest; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8003A94C(obj);
    return;
rest: // !FAKE: label kept for the matching branch layout
    if (func_80039B50(obj) != 0) {
        return;
    }
    if (func_80039BA8(obj) != 0) {
        func_80017248(obj);
        func_8002DF54(obj);
        func_8003D344(obj);
        func_8003F2D8(obj, 0xF);
        return;
    }
    func_8003AEF0(obj);
}
