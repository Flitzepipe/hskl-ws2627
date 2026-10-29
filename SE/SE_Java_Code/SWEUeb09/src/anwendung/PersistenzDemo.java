package anwendung;

import fachklassen.Standort;
import persistenz.StandortDAO;

public class PersistenzDemo {
	
	public static void main(String[] args) {
		
		int standortNr = 3;    // Mögliche Werte: 1, 2, 3
		
		StandortDAO standortDAO = new StandortDAO();
		Standort standort = standortDAO.getStandort(standortNr);
		
		if(standort!=null) {
			standort.print();           // Nur Standortdaten
			standort.printAlles();      // Standort mit Gebäuden
			standort.printAlles();      // Nochmals Standort mit Gebäuden
		} else {
			System.out.println("Kein Standort gefunden.");
		}
		
	
	}

}
