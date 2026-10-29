package bericht;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Auftragsverwaltung {
	private static List<Auftrag> auftraege = new ArrayList<Auftrag>();
	
	public static void createAuftrag(LocalDate datum) {
		auftraege.add(new Auftrag(datum));
	}
	
	public static List<Auftrag> getAuftraege(){
		return auftraege;
	}

}
