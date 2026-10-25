#include "types.h"

extern void func_80017248(u8* obj);
extern void func_80032F70(u8* a0);
extern s32 func_8003240C(u8* a0);
extern s32 func_800326BC(u8* a0);
extern void func_8003258C(u8* a0);
extern void func_80033024(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void (*D_8007C380[])(u8*);

void func_80055718(u8* obj) {
    func_80017248(obj);
    D_8007C380[(s8)obj[5]](obj);
    func_80032F70(obj);
    func_8003240C(obj);
    func_800326BC(obj);
    func_8003258C(obj);
    func_80033024(obj);
    func_8002D9EC(obj, 0x88, 0x88);
}
