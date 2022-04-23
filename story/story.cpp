#include "story.hpp"

Scenario *scen_01;
Scenario *scen_02;
Scenario *scen_03;
Scenario *scen_04;
Scenario *scen_05;
Scenario *scen_06;
Scenario *scen_07;
Scenario *scen_08;
Scenario *scen_09;
Scenario *scen_10;
Scenario *scen_11;
Scenario *scen_12;
Scenario *scen_13;
Scenario *scen_14;
Scenario *scen_15;
Scenario *scen_16;
Scenario *scen_17;
Scenario *scen_18;
Scenario *scen_19;
Scenario *scen_20;
Scenario *scen_21;

void storySetup()
{
    // scenario 1 text setup
    scen_01 = new Scenario(
        "Jij bent Zafir, geboren te Herat. Je bent 43 jaar.\n"
        "Door een aanslag van de Taliban, ben jij jouw familie kwijtgeraakt.\n"
        "Door het verder oprukken van de Taliban, besluit jij om het land uit te vluchten.\n\n\n"
        "Ik wist altijd al dat de taliban terug zou komen. Het was haast onvermijdelijk.\n"
        "In de tijd dat de Taliban minder prominent, mochten mijn vrouw en\n"
        "dochter vrij naar school en zonder man over straat lopen.\n"
        "Sinds de aanslag is er veel veranderd in mijn leven: mijn huis is verwoest; ik ben mijn\n"
        "familie kwijt en heb sindsdien veel verdriet en angst. Vanaf dit moment komt het vaak\n"
        "in mijn gedachten dat ik wil vluchten.\n"
        "Nu is alleen de vraag: hoe?\n");

    // scenario 2 text-setup
    scen_02 = new Scenario("Wellicht is het een optie om zelf te gaan vluchten, alleen weet ik nog niet waarheen?");

    // scenario 3 text-setup
    scen_03 = new Scenario("Ik zou door een smokkelaar Europa in kunnen worden gebracht. Alleen hoe wil ik in Europa komen?");

    // scenario 4 text-setup
    scen_04 = new Scenario("Misschien is het een goed idee als ik in de buurt van Afghanistan blijf.\nDus naar welk land zal ik gaan?");

    // scenario 5 text-setup
    scen_05 = new Scenario("Naar Europa klinkt als een goed idee, daar lijkt het me veilig!\nHoe zal ik Europa binnen proberen te komen?");

    // scenario 6 text-setup
    scen_06 = new Scenario("Ik kan ook direct naar Nederland door het NL actief evacuatieplan!\nHelaas kom ik hier niet voor in aanmerking.");

    // scenario 7 text-setup
    scen_07 = new Scenario(
        "Na een lange, zware tocht is het gelukt om de grens van Turkije te bereiken en\n"
        "omdat jij jouw paspoort bij je had, mocht je Turkije ook binnenkomen.\n\n"
        "Ik ben nu in Turkije! Hoe zal ik verder gaan? Griekenland of Over de zwarte zee?");

    // scenario 8 text-setup
    scen_08 = new Scenario(
        "Op wonderbaarlijke wijze is het me gelukt om door Iran heen in Syrië terecht te\n"
        "komen en met de boot in Italië. Voor de kust zelf kapseisde de boot, maar gelukkig\n"
        "waren we gered door de kustwacht. Ook ben ik in Italië in een Asielzoekerscentrum\n"
        "terecht gekomen.");

    // scenario 9 text-setup
    scen_09 = new Scenario(
        "Na een zware tocht is het me uiteindelijk toch gelukt om de grens van Turkije te bereiken.\n"
        "Wil ik nu Turkije binnengaan of voor de grens blijven in een kamp?");

    // scenario 10 text-setup
    scen_10 = new Scenario(
        "Je blijft voor de grens van Turkije in een kamp zitten. Hier blijf je circa 3 jaar en\n"
        "vervolgens keer je weer terug naar Afghanistan waar jij jouw oude werk weer oppakt.\n"
        "In Afghanistan is de rust weer wedergekeerd. Het begint zelfs werkelijk een.");

    // scenario 11 text-setup
    scen_11 = new Scenario(
        "Het lukt je om via Turkije Griekenland binnen te komen omdat je een paspoort hebt.\n"
        "Je kiest ervoor om in Griekenland te blijven omdat het je daar redelijk bevalt. Hier\n"
        "bouw jij opnieuw jouw leven op: je krijgt een baan en wordt hierdoor gelukkig.");

    // scenario 12 text-setup
    scen_12 = new Scenario("Ik ga kijken of ik verder Europa in kan komen.\nZal ik Nederland in proberen te komen of Duitsland?");

    // scenario 13 text-setup
    scen_13 = new Scenario(
        "Het lijkt met best handig als ik hier papieren ga aanvragen. Zal ik op een legale\n"
        "manier aan papieren komen of op illegale wijze?");

    // scenario 14 text-setup
    scen_14 = new Scenario(
        "Wellicht is ‘t het beste als de Italiaanse overheid niet weet dat ik een illegale\n"
        "immigrant ben.\n"
        "Ik zal dus kijken of ik ergens aan illegale papieren kan komen.\n"
        "Zal ik hierna naar Nederland of Duitsland gaan?");

    // scenario 15 text-setup
    scen_15 = new Scenario(
        "Je kijkt of je papieren kan aanvragen bij een gemeentehuis in de buurt. Alleen vindt\n"
        "het bestuur het niet acceptabel dat een illegale zo het land binnen is gekomen.\n"
        "Je wordt opgesloten in een gevangenis onder dermate slechte omstandigheden dat\n"
        "je in je cel komt te overlijden.");

    // scenario 16 text-setup
    scen_16 = new Scenario(
        "Het is me gelukt om via Turkije in Griekenland te komen.\n"
        "Er vond een herverdeling van Immigranten plaats en hierdoor ben ik in Oostenrijk\n"
        "terecht gekomen. Het lukt mij om de Duitse taal te leren en een succesvolle toekomst\n"
        "op te bouwen.");

    // scenario 17 text-setup
    scen_17 = new Scenario(
        "Het lukte mij om via de Zwarte Zee in Wit-Rusland te komen en via Wit-Rusland in\n"
        "Polen. Zal ik nu naar Nederland gaan of Duitsland?");

    // scenario 18 text-setup
    scen_18 = new Scenario(
        "Je gaat naar Duitsland om daar een toekomst op te bouwen. Je leert de Duitse taal\n"
        "en je gaat werken. Het lukt je om succesvol en gelukkig te worden.");

    // scenario 19 text-setup
    scen_19 = new Scenario(
        "Je gaat naar Nederland om daar een toekomst op te bouwen. Je leert de\n"
        "Nederlandse taal en je gaat werken. Het lukt je om succesvol en gelukkig te worden.");

    // scenario 20 text-setup
    scen_20 = new Scenario(
        "Je besloot om in de regio te blijven en naar Pakistan te gaan. Het leek jou veiliger\n"
        "dan Afghanistan en dit bleek ook zo te zijn. In Pakistan probeer je een toekomst op\n"
        "te bouwen, je krijgt er werk én het lukt je zelfs om weer een familie op te bouwen.");

    // scenario 21 text-setup
    scen_21 = new Scenario(
        "Je besloot om door Pakistan naar India te gaan en daar een nieuw leven op te\n"
        "bouwen. Het lukte je om er werk te vinden en vrienden te maken.");

    // scenario 1 options setup
    scen_01->setup({{"Zelf vlucht", scen_02}, {"Gesmokkeld worden", scen_03}}, {normInput, normInput});
    // scenario 1 gets
    scen_01->setGet({{0, "Paspoort"}});

    // scenario 2 options setup
    scen_02->setup({{"In de regio blijven", scen_04}, {"Buiten de regio gaan", scen_05}}, {normInput, normInput});
    // scenario 2 needs
    scen_02->setNeed({{1, "Paspoort"}});

    // scenario 3 options setup
    scen_03->setup({{"Richting Syrië en dan met de boot naar italië", scen_08}, {"Richting Turkije en dan over land naar Griekenland", scen_09}}, {normInput, normInput});

    // scenario 4 options setup
    scen_04->setup({{"Pakistan", scen_20}, {"India", scen_21}}, {normInput, normInput});

    // scenario 5 options setup
    scen_05->setup({{"NL actief evacuatieplan", scen_06}, {"Via Turkije", scen_07}}, {normInput, normInput});

    // scenario 6 options setup
    scen_06->setup({{"Alsnog gesmokkeld gaan", scen_03}, {"Alsnog via Turkije", scen_07}}, {normInput, normInput});

    // scenario 7 options setup
    scen_07->setup({{"Via Griekenland in de EU komen", scen_16}, {"Over de Zwarte Zee via Wit-Rusland Polen binnen gaan", scen_17}}, {normInput, normInput});

    // scenario 8 options setup
    scen_08->setup({{"Verder Europa in", scen_12}, {"Papieren aanvragen in Italië", scen_13}}, {normInput, normInput});
    // scenario 8 needs setup
    scen_08->setNeed({{0, "Paspoort"}});

    // scenario 9 options setup
    scen_09->setup({{"Turkije binnengaan", scen_11}, {"Voor de grens blijven", scen_10}}, {normInput, normInput});
    // scenario 9 needs setup
    scen_09->setNeed({{0, "Paspoort"}});

    // scenario 10 options setup
    scen_10->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});

    // scenario 11 options setup
    scen_11->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});

    // scenario 12 options setup
    scen_12->setup({{"Duitsland", scen_18}, {"Nederland", scen_19}}, {normInput, normInput});

    // scenario 13 options setup
    scen_13->setup({{"Illegale", scen_14}, {"Legale", scen_15}}, {normInput, normInput});
    // scenario 13 gets setup
    scen_13->setGet({{0, "Paspoort"}});

    // scenario 14 options setup
    scen_14->setup({{"Duitsland", scen_18}, {"Nederland", scen_19}}, {normInput, normInput});

    // scenario 15 options setup
    scen_15->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});

    // scenario 16 options setup
    scen_16->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});

    // scenario 17 options setup
    scen_17->setup({{"Duitsland", scen_18}, {"Nederland", scen_19}}, {normInput, normInput});

    // scenario 18 options setup
    scen_18->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});

    // scenario 19 options setup
    scen_19->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});

    // scenario 20 options setup
    scen_20->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});

    // scenario 21 options setup
    scen_21->setup({{"Opnieuw", nullptr}, {"Afsluiten", nullptr}}, {gameEnd, gameEnd});
}