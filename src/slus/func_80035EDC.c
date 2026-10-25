#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003B33C(u8*, s32);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002DF54(u8* a0);
extern void func_8003D344(void* arg0);
extern u8 D_8009A1F8[];

void func_80035EDC(u8* obj) {
    u8* p;
    u16 v;

    func_80017248(obj);
    if (((s8*)obj)[6] == 0) {
        if (((s8*)obj)[0x46] == 0) {
            p = D_8009A1F8;
            v = *(u16*)(p + 0xE);
            *(s16*)(p + 0x28) = v;
            *(s16*)(p + 0x2A) = v;
            *(s16*)(p + 0x20) = v;
            *(s16*)(p + 0x22) = v;
            func_8003B33C(obj, 4);
            obj[6]++;
        }
    } else if (func_8002D938(obj, 0x20, 0x40) == 0) {
        func_8002DF54(obj);
        func_8003D344(obj);
    } else {
        obj[3] = 0;
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
    }
}
