#include <iostream>
#include "Date.h"
#include "Division.h"
#include "Fighter.h"
#include "Match.h"
#include "MatchScore.h"
#include "Tournament.h"

int main()
{
    // fighter objects
    Fighter fighter1 = Fighter("Daniel", "Nieuwerf", true, Date(25, 1, 1998),
        "United Kingdom", "Blue", 22, "Checkmat Fightzone London");
    Fighter fighter2 = Fighter("Francesco", "Bartelotta", true, Date(25, 1, 1998),
        "Italy", "Blue", 25, "Checkmat Fightzone London");
    Fighter fighter3 = Fighter("Daniel", "Filipschi", true, Date(25, 1, 1998),
        "Moldovia", "Blue", 22, "Checkmat Fightzone London");
    Fighter fighter4 = Fighter("Mateusz", "Dziemian", true, Date(25, 1, 1998),
        "United Kingdom", "Blue", 22, "10th planet");
    Fighter fighter5 = Fighter("Georgi", "Dmitrov", true, Date(25, 1, 1998),
        "Italy", "Blue", 25, "Ivam Maciel BJJ");
    Fighter fighter6 = Fighter("Junior", "Fernandes", true, Date(25, 1, 1998),
        "Moldovia", "Blue", 22, "Checkmat Fightzone London");
    Fighter fighter7 = Fighter("Jorge", "El Scorpio", true, Date(25, 1, 1998),
        "United Kingdom", "Blue", 22, "Checkmat Fightzone London");
    Fighter fighter8 = Fighter("Sam", "Gibbs", true, Date(25, 1, 1998),
        "Italy", "Blue", 25, "AEON");
    Fighter fighter9 = Fighter("Nathan", "Kay", true, Date(25, 1, 1998),
        "Moldovia", "Blue", 22, "Grand Union");
    Fighter fighter12 = Fighter("Marcus", "Lopes", true, Date(25, 1, 1998),
        "Brazil", "Blue", 22, "ICON");
    Fighter fighter10 = Fighter("Lee", "Renaut", true);
    Fighter fighter11 = Fighter("Paulo", "Miyao", true);
    Fighter dfighter1 = Fighter();

    fighter1.setWins(22);
    fighter1.setLosses(6);
    
    // create Tournament
    auto tourn1 = Tournament("English Open No-gi", Date(20, 4, 2020), Date(20, 4, 2020));
    tourn1.setIBJJFNoGiDivisions();     //set tournament divisions

    // add participants to the tournament
    tourn1.addParticipant(fighter1, Division("BLUE", 73.5, true, false));
    tourn1.addParticipant(fighter2, Division("BLUE", 73.5, true, false));
    tourn1.addParticipant(fighter3, Division("BLUE", 73.5, true, false));
    tourn1.addParticipant(fighter12, Division("BLUE", 73.5, true, false));
    tourn1.addParticipant(fighter4, Division("PURPLE", 73.5, true, false));
    tourn1.addParticipant(fighter5, Division("PURPLE", 73.5, true, false));
    tourn1.addParticipant(fighter6, Division("PURPLE", 73.5, true, false));
    tourn1.addParticipant(fighter7, Division("PURPLE", 73.5, true, false));
    tourn1.addParticipant(fighter8, Division("PURPLE", 73.5, true, false));
    tourn1.addParticipant(fighter9, Division("PURPLE", 73.5, true, false));
    tourn1.addParticipant(fighter10, Division("BLACK", 67.5, true, false));
    tourn1.addParticipant(fighter11, Division("BLACK", 67.5, true, false));
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());
    tourn1.addParticipant(Fighter(), Division());

    // print participants list
    tourn1.printParticipantsList();

    // create brackets
    system("cls");
    tourn1.createBrackets();



}