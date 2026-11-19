#include "types.h"
#include "mmx5/weapon.h"
#include "mmx5/globals.h"

extern void func_8003AA4C(u8* arg0);

void func_80043DBC(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        player_spawn_weapon(1, 0x21, 0, obj);
        obj[6]++;
    } else {
        animate_object(obj);
    }
    if (((s8*)obj)[0x46] == 0) {
        func_8003AA4C(obj);
    }
}
