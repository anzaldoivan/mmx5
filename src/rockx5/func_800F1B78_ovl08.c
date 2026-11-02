#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern s32 func_800326BC(u8* a0);
extern void func_80032F70(u8* a0);
extern void func_80033024(u8* a0);
extern u8 D_8009A0A0[];
extern s8 D_800D1C27;
extern void* D_800F3E74_ovl08[];

void func_800F1B78_ovl08(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (D_8009A0A0[0xF7] == 0) {
        func_80017248(obj);
        ((void (*)(u8*))D_800F3E74_ovl08[*(s8*)(obj + 5)])(obj);
    } else if (D_800D1C27 != 0) {
        func_80016490(5, 0x14, 0);
    }
    if (D_8009A0A0[0xF8] == 0) {
        s16 g = *(s16*)(D_8009A0A0 + 0xA);
        s16 o = *(s16*)(obj + 0xA);
        if (((g - o) < 0 ? (o - g) : (g - o)) < 0x31) {
            func_8003240C(obj);
        }
    }
    func_80032F70(obj);
    func_80033024(obj);
    func_800326BC(obj);
    func_8002D9EC(obj, 0x20, 0x20);
    func_8003258C(obj);
}
