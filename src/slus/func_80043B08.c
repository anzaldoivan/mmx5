#include "types.h"

extern s32 func_80044328(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_800430FC(u8*);

s32 func_80043B08(u8* arg0) {
    if (func_80044328(arg0) == 0) {
        return 0;
    }
    func_8003B33C(arg0, 0x5E);
    func_80016490(1, 7, arg0);
    if (func_8002DF78() & 4) {
        func_8003CF74(arg0, 8);
    }
    arg0[5] = 0x34;
    arg0[6] = 0;
    func_800430FC(arg0);
    return 1;
}
