#include "types.h"
#include "mmx5/globals.h"

extern void func_80027288(void);
extern void func_80017D88(void);
extern void silence_sound(s32, s32);
extern void func_8002D004(void);
extern void func_8002CF20(void);
extern void read_dat_file(s32, s32);
extern void pump_file_loads(void);
extern void func_800234CC(void);
extern void func_80013458(void);
extern s32 func_80013674(void);
extern s8 D_8009A426;
extern u8 D_80070ED0[];

void func_8001E8A8(u8* a0) {
    a0[0xD] = 1;
    D_8009A426 = 1;
    func_80027288();
    func_80017D88();
    silence_sound(0xFF, 0);
    func_8002C50C();
    func_8002D004();
    func_8002CF20();
    read_dat_file(D_80070ED0[*(s8*)(a0 + 0xC)], 0x801F6000);
    pump_file_loads();
    func_800234CC();
    func_80013458();
    func_80013674();
    *(u16*)(a0 + 4) = 0x960;
    a0[1]++;
}
