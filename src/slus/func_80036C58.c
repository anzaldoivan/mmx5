#include "types.h"

extern s32 func_80043B88(u8* arg0);
extern void func_8003A9AC(u8* arg0);
extern void func_8003A94C(u8* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern void func_8003AC98(u8* obj);
extern void func_80017248(u8* obj);
extern void* D_80074724[];

void func_80036C58(u8* arg0) {
    func_80043B88(arg0);
    if (arg0[0x89] & 8) {
        func_8003A9AC(arg0);
        return;
    }
    if (*(s8*)(arg0 + 0xD3) != 0) {
        func_8003A94C(arg0);
        return;
    }
    if (*(s8*)(arg0 + 2) == 0) {
        if (func_8003EFE0(arg0) != 0) {
            return;
        }
        if (*(s8*)(arg0 + 0x8E) != 0) {
            func_8003AC98(arg0);
            return;
        }
    }
    func_80017248(arg0);
    ((void (*)(u8*))D_80074724[*(s8*)(arg0 + 6)])(arg0);
}
