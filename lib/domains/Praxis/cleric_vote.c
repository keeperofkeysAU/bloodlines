#include <lib.h>
#include <voting.h>
#include <daemons.h>

inherit "/domains/town/room/voters";

void create() {
    ::create();
    SetProperty("light", 1);
    SetProperty("no castle", 1);
    SetProperty("indoors", 1);
    SetShort( "Voting hall of the clerics");
    SetLong( (: this_object(), "new_long" :));
    SetItems(
            (["list" : "During election time, it lists all candidates."]) );
    SetExits( 
            (["west" : "/domains/Praxis/cleric_hall"]) );
}

    string new_long() {
        if(VOTING_D->election_day()) 
            return "This is the room where Clerics can put in their bid for office. "
                "If you wish to run for office, just type in the command "
                "'enter' and you will be added to the list.  A list of candidates "
                "is posted on the wall.  Type 'list candidates' to see the list.";
        else return "This is the voting chamber of the Hall of Clerics.  "
            "Clerics will gather here for the next election: "+VOTING_D->query_vote_date()+".";
    }
void init(){
    ::init();
}