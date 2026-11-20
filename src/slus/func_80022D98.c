#include "types.h"
#include "mmx5/globals.h"

extern void func_8002F338(void);
extern void read_player_input(void);
extern void func_80022960(void);
extern void func_80035040(void);
extern void func_80022084(void);
extern void update_layer_objects(void);
extern void func_80021F64(void);
extern void func_800221B0(void);
extern void func_800222D0(void);
extern void func_800224F8(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void func_8002AE50(void);
extern void func_800223E4(void);
extern void run_text_box(void);
extern void func_8002A440(void);
extern void func_8002A4E4(void);
extern void func_8002A554(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_80022EDC(void);
extern void func_80022F3C(void);
extern void func_80022F90(void);
extern void func_80017348(u8* a0, s32 a1, s32 a2);

void func_80022D98(void) {
    u8* p;

    func_8002F338();
    read_player_input();
    p = g_Player;
    func_80022960();
    func_80035040();
    func_80022084();
    update_layer_objects();
    func_80021F64();
    func_800221B0();
    func_800222D0();
    func_800224F8();
    func_80022618();
    func_8002272C();
    func_8002AE50();
    func_800223E4();
    run_text_box();
    func_8002FB58(p);
    func_8002A440();
    func_8002A4E4();
    func_8002A554();
    func_8002C2C0();
    func_8002BD8C();
    func_80022EDC();
    func_80022F3C();
    func_80022F90();
    func_80017348(p, 0x140, 0);
}
