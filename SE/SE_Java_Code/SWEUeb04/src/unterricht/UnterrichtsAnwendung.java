package unterricht;

public class UnterrichtsAnwendung {
    public static void main(String[] args) {
        Lehrer meier = new Lehrer("Hans", "Meier");
        Lehrer mueller = new Lehrer("Susanne", "Mueller");
        Lehrer schmidt = new Lehrer("Sabine", "Schmidt");
        Fach mathe = new Fach("Mathematik");
        Fach englisch = new Fach("Englisch");
        Fach deutsch = new Fach("Deutsch");
        meier.addFach(mathe);
        meier.addFach(deutsch);
        mueller.addFach(deutsch);
        mueller.addFach(mathe);
        mueller.addFach(englisch);
        schmidt.addFach(deutsch);
        schmidt.addFach(englisch);
        Raum r1 = new Raum(1, "");
        Raum r2 = new Raum(2, "");
        Raum r3 = new Raum(2, "Biosaal");
        Schulklasse achtA = new Schulklasse("8a", meier, r2);
        Schulklasse siebenB = new Schulklasse("7b", schmidt, r1);
        
        Wochenstunde w1 = new Wochenstunde(3, "Freitag");
        Wochenstunde w2 = new Wochenstunde(6, "Montag");
        Wochenstunde w3 = new Wochenstunde(5, "Mittwoch");
		Wochenstunde w4 = new Wochenstunde(2, "Dienstag");
        
        Unterricht u1 = achtA.createUnterricht(mathe, meier);
        Unterricht u2 = achtA.createUnterricht(deutsch, schmidt);
        Unterricht u3 = siebenB.createUnterricht(englisch, mueller);
        Unterricht u4 = siebenB.createUnterricht(deutsch, mueller);
        // Unterricht u5 = achtA.createUnterricht(mathe, schmidt);   // 8a hat bereits Mathematik
        
        if (u1 != null) {
            u1.addUnterrichtsstunde(w1);
        }
                if(u2 != null) {
            u2.addUnterrichtsstunde(w2);
            u2.addUnterrichtsstunde(w3);
        }
        if (u3 != null) {
            u3.addUnterrichtsstunde(w1);
            u3.addUnterrichtsstunde(w2, r3);
        }
        if(u4 != null) {
            u4.addUnterrichtsstunde(w3);
            // u4.addUnterrichtsstunde(w2);  // Zeitkonflikt
			u4.addUnterrichtsstunde(w4);  
        }
        
        siebenB.printStundenplan();
        achtA.printStundenplan();
    }

}
