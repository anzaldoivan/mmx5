#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002DF78(void);
extern u8 D_800770AC[];
extern u8 D_8009A1F8[];
extern s16 D_8009A206;

void func_80049200(u8* obj) {
    s32 t;

    func_80017248(obj);
    t = *(u16*)(obj + 0x92) + 1;
    *(u16*)(obj + 0x92) = t;
    if (*(s8*)(obj + 5) == 0) {
        func_8002DF54(obj);
        obj[3] = 1;
        if (*(s16*)(obj + 0xE) - D_8009A206 >= 0x141) {
            obj[3] = 0;
            if (*(s16*)(obj + 0x92) >= 0x12D) {
                obj[4] = 2;
                return;
            }
            *(void**)(obj + 0x50) = 0;
            obj[5]++;
        }
    } else if ((s16)((s16)t % 60) == 0) {
        u8* d;
        s32 r;

        func_80016490(1, 0x10, obj);
        *(void**)(obj + 0x50) = D_800770AC;
        r = func_8002DF78();
        d = D_8009A1F8;
        *(s16*)(obj + 0xA) = *(u16*)(d + 0xA) + (r % 150) * 2 + 0xA;
        *(s16*)(obj + 0xE) = *(u16*)(d + 0xE) - 0x50;
        obj[5]--;
    }
}
