package bericht;

import java.util.ArrayList;
import java.util.List;

public class Bericht {
	private List<Berichtsposition> positionen = new ArrayList<Berichtsposition>();
	
	public Bericht(Zeitraum z){
		List<Auftrag> auftr = Auftragsverwaltung.getAuftraege();
		for(Auftrag a:auftr){
			boolean inZ = a.liegtIn(z);
			if(inZ){
				Berichtsposition pos = new Berichtsposition(a);
				addPos(pos);
			}
		}
	}
	
	private void addPos(Berichtsposition pos){
		positionen.add(pos);
	}
	
	public void print() {
		for(Berichtsposition p:positionen) {
			p.print();
		}
	}
	
}
