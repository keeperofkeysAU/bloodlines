#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(10);
    SetShort("campus sewer");
    SetLong("You are in the stinking underground tunnels of "+
            "the Virtual Campus sewer system. The air here is quite foul, "+
            "and periodic blasts of steam from wall-mounted vents make it "+
            "very hot and very humid. There is a foot-high stream of dark liquid "+
            "covering the bottom of this tunnel, running west to east along "+
            "the tunnel's length.");
    SetItems( ([ ({"tunnel","tunnels"}) : "You are in a sewer tunnel."+
                "It's foul, dark, and hot.",
                ({"sewer","sewer system"}) : "Though evidently in good repair "+
                "and of modern construction, this is still a sewer tunnel, "+
                "and it's hostile to human comfort.",
                ({"steam","vent","vents","wall-mounted vents"}): "Apparently "+
                "there is industrial machinery nearby that exhausts hot steam "+
                "through vents in the walls.",
                "air" : "It is rank with the reek of decomposing waste.",
                ({"wall","walls"}) : "The walls of the sewer tunnel are made "+
                "of concrete and appear well-built and sturdy.", 
                ({"stream","liquid","stream of liquid","dark liquid"}) : "Whatever "+
                "this stuff is, water is not its main component. It's some kind "+
                "of foul-smelling liquid waste, flowing along the bottom "+
                "of the tunnel.",
                ({"sewage","waste","garbage"}) : "It appears that the fluid on the "+
                "bottom of this tunnel is the result of garbage and waste "+
                "processing. In liquid form, this garbage flows "+
                "east from here.",
                ]) );
    SetSmell( ([ "default" : "The stench of sewage and waste hangs here."]) );
    SetListen("default","You hear faint echoes of dripping water.");
    set_heart_beat(10);
}

void init(){
    ::init();
}

int SteamBlast(){
    object *temparr,*stuff,*lstuff;
    int i;
    stuff=all_inventory();
    lstuff = ({});
    for(i=0;i<sizeof(stuff);i++){
        temparr= ({ stuff[i] });
        if(living(stuff[i]) && !sizeof(lstuff)) lstuff = ({stuff[i]});
        if(living(stuff[i]) && sizeof(lstuff) > 0 && member_array(stuff[i],lstuff) == -1) lstuff += ({stuff[i]});
    }
    for(i=0;i<sizeof(lstuff);i++){
        if(sizeof(lstuff) > 0 && !creatorp(lstuff[i]) ) lstuff[i]->eventReceiveDamage(0, 7,random(30)+10, "torso");

    }
    tell_room(this_object(), "You are hit by a blast of scalding-hot steam!");
    return 1;
}

void heart_beat(){
    if(random(10) == 1) SteamBlast();
    return;
}
