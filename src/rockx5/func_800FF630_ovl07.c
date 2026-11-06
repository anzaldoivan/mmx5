#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_80017248(u8* obj);
extern u8* func_8002D0E4(void);
extern void func_8002D89C(u8*);
extern void func_8002DF54(u8* a0);
extern u32* D_8007B2E8[];
extern s8 D_8009A0A2;
extern u8 D_800D1C28;

void func_800FF630_ovl07(u8* obj) {
    u8* e;
    u8* p;
    s32 off;

    func_8002DF54(obj);
    func_80017248(obj);
    if (*(s16*)(obj + 0xA) >= 0x1F20) {
        *(s16*)(obj + 0xA) = 0x1F20;
        e = func_8002D0E4();
        if (e != 0) {
            e[0] = 0x21;
            e[1] = 3;
            if (D_8009A0A2 == 0) {
                e[2] = 3;
            } else {
                e[2] = 0xC;
            }
            e[0x14] = obj[0x14];
            p = D_1F80001C.bytes;
            off = *(s32*)(p + 4);
            *(u32***)(e + 0x30) = D_8007B2E8;
            *(s16*)(e + 0x40) = 0;
            *(u16*)(e + 0x42) = 0x7802;
            e[0x16] = 0;
            *(u8**)(e + 0x3C) = p + off;
            *(s16*)(e + 0xA) = *(s16*)(obj + 0xA);
            *(s16*)(e + 0xE) = *(s16*)(obj + 0xE);
            e[0x15] = 0;
        }
        func_80016490(5, 0x25, obj);
        D_800D1C28 = 1;
        obj[4]++;
        return;
    }
    func_8002D89C(obj);
}
