package bericht;

import java.time.LocalDate;

public class Berichtsverwaltung {
	
	public static void main(String[] args) {
		Auftragsverwaltung.createAuftrag(LocalDate.of(2016, 3, 3));
		Auftragsverwaltung.createAuftrag(LocalDate.of(2017, 3, 3));
		Auftragsverwaltung.createAuftrag(LocalDate.of(2018, 3, 3));
		Auftragsverwaltung.createAuftrag(LocalDate.of(2017, 9, 17));
		
		Zeitraum zeitraum = new Zeitraum(LocalDate.of(2017, 1, 1), LocalDate.of(2017, 12, 31));
		Bericht b = new Bericht(zeitraum);
		
		b.print();
	}

}
