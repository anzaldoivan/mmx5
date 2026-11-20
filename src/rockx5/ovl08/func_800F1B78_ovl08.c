#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern s32 func_800326BC(u8* a0);
extern void func_80032F70(u8* a0);
extern s8 D_800D1C27;
extern void* D_800F3E74_ovl08[];

void func_800F1B78_ovl08(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (g_Player[0xF7] == 0) {
        animate_object(obj);
        ((void (*)(u8*))D_800F3E74_ovl08[*(s8*)(obj + 5)])(obj);
    } else if (D_800D1C27 != 0) {
        play_sound(5, 0x14, 0);
    }
    if (g_Player[0xF8] == 0) {
        s16 g = *(s16*)(g_Player + 0xA);
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
