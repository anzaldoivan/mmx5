#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

extern void func_80027288(void);
extern void func_80017D88(void);
extern void silence_sound(s32, s32);
extern void func_8002D004(void);
extern void func_8002CF20(void);
extern void read_dat_file(s32, s32);
extern void pump_file_loads(void);
extern void func_800234CC(void);
extern void select_file_load(void);
extern s32 load_stage(void);
extern s8 D_8009A426;
extern u8 D_80070ED0[];

void start_demo(u8* a0) {
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
    select_file_load();
    load_stage();
    *(u16*)(a0 + 4) = 0x960;
    a0[1]++;
}

extern void func_80013288(s32);
extern void func_80017668(void);
extern void func_80020950(void);
extern void func_80020A3C(void);
extern void func_80023500(void);
extern void func_80027238(void);
extern void func_800272B4(void);
extern void func_8002906C(void);
extern void func_8002A440(void);
extern void func_8002A4E4(void);
extern void func_8002A554(void);
extern void init_checkpoint_positions(void);
extern void func_8002B474(void);
extern void func_8002B520(void);
extern void func_8002D004(void);
extern void func_8003BAC8(void);

void func_8001E95C(u8* arg0) {
    u32 i;
    u8* p;

    func_8002C50C();
    func_8002D004();
    func_80017668();
    func_80023500();
    func_8002906C();
    init_checkpoint_positions();
    func_8002A440();
    func_8002A4E4();
    func_8002A554();
    func_8003BAC8();
    func_8002B474();
    func_8002B520();
    func_80027238();
    func_80020950();
    for (i = 2; i < 5; i++) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x12;
            p[2] = i;
        }
    }
    func_80020A3C();
    arg0[2] = 0;
    arg0[1]++;
    func_80013288(8);
    func_800272B4();
}

#define g_Player_as_s8 ((s8*)g_Player)

extern s8 D_8009A424;
extern void func_800132F8(s8 arg);
extern s32 func_80023728(void);
extern void run_demo_frame(void);
extern void func_800272B4(void);

void func_8001EA54(u8* arg0) {
    if (D_8009A424 == 0) {
        arg0[0xD] = 0;
    }
    if (--*(s16*)(arg0 + 4) == 0 || g_Player_as_s8[0] == 0 ||
        g_Player_as_s8[4] == 3) {
        func_800132F8(8);
        func_80023728();
        arg0[1]++;
    } else {
        random_byte();
        run_demo_frame();
    }
    func_800272B4();
}
#undef g_Player_as_s8

extern void func_80027288(void);
extern void func_80017D88(void);
extern void silence_sound(s32, s32);
extern void func_8002D004(void);
extern void func_8002CF20(void);
extern void func_800272B4(void);

void func_8001EAFC(u8* obj) {
    u8* p = D_8009A420;

    if (((s8*)p)[4] == 0) {
        obj[0xD] = 1;
        p[6] = 0;
        func_80027288();
        func_80017D88();
        silence_sound(0xFF, 0);
        func_8002C50C();
        func_8002D004();
        func_8002CF20();
        obj[0] = 3;
        obj[1] = 0;
    } else {
        func_800272B4();
    }
}
