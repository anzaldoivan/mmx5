#include "types.h"

extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern void func_80017248(u8* obj);
extern void func_8003AA4C(u8* arg0);

void func_80043DBC(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        func_8003D3A8(1, 0x21, 0, obj);
        obj[6]++;
    } else {
        func_80017248(obj);
    }
    if (((s8*)obj)[0x46] == 0) {
        func_8003AA4C(obj);
    }
}
