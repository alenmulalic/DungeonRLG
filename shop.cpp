#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "descriptions.h"
#include <vector>
#include "dungeon.h"

using namespace std; 


void gen_shop_objects(dungeon *d)
{
    object *o;
    // uint32_t room;
     pair_t p;
    std::vector<object_description> &v = d->object_descriptions;
    uint32_t i;
    memset(d->shop, 0, sizeof(d->shop));

    p[dim_y] = 0;
    p[dim_x] = 0;  
    for(i = 0; i < v.size(); i++){
        o = new object(v[i], p, d->objmap[p[dim_y]][p[dim_x]]);
        d->shop[i] = o;
        p[dim_y]++;
        p[dim_x]++; 
    }  
}

void gen_cost_array(dungeon *d){
    int i; 
    for(i = 0; i < 20; i++){
        if(d->shop[i] != NULL){
            d->shopCosts[i]  = d->shop[i]->get_damage_base() + d->shop[i]->get_damage_number() + 
            d->shop[i]->get_damage_sides() + d->shop[i]->get_defence() + d->shop[i]->get_speed() + 100;
        }
    }
}