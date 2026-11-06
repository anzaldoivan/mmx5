#include "types.h"

extern void func_80054FE4(u8* obj);
extern void func_80055718(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_80032F70(u8* obj);
extern void func_80033024(u8* obj);
extern void func_8003240C(u8* obj);
extern void func_800326BC(u8* obj);
extern void func_8003258C(u8* obj);
extern u8 D_800767E0[];
extern u8 D_8007C364[];
extern u8 D_8007C36C[];

void func_80055450(u8* obj) {
    u8* src;
    u8 n;
    u16 t;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (*(s8*)(obj + 2) != 0x10) {
        if (*(s8*)(obj + 4) == 0) {
            func_80054FE4(obj);
            return;
        }
        func_80055718(obj);
        return;
    }
    src = *(u8**)(obj + 0x7C);
    if (*(s8*)src == 0) {
        func_8002D6FC(obj);
        return;
    }
    n = obj[4];
    if (*(s8*)(obj + 4) == 0) {
        *(u8**)(obj + 0x68) = D_8007C364;
        *(u8**)(obj + 0x54) = D_8007C36C;
        obj[0xA2] = 1;
        *(u8**)(obj + 0x58) = D_800767E0;
        obj[0x75] = 1;
        *(u16*)(obj + 0xA) = *(u16*)(src + 0xA);
        t = *(u16*)(src + 0xE);
        obj[4] = n + 1;
        *(u16*)(obj + 0xE) = t - 0x4E;
    }
    func_80032F70(obj);
    func_80033024(obj);
    func_8003240C(obj);
    func_800326BC(obj);
    func_8003258C(obj);
}
