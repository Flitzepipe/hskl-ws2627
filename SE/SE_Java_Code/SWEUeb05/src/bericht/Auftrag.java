package bericht;

import java.time.LocalDate;

public class Auftrag {
	private LocalDate datum;
	private int nr;
	private static int zaehler=1;
	
	public Auftrag(LocalDate datum) {
		this.datum = datum;
		nr = zaehler++;
	}
	
	public boolean liegtIn(Zeitraum zeitraum){
		return(zeitraum.enthaelt(this.datum));
	}
	
	public int getNr() {
		return nr;
	}

}
