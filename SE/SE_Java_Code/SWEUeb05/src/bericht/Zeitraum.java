package bericht;

import java.time.LocalDate;

public class Zeitraum {
	private LocalDate beginn;
	private LocalDate ende;
	
	public Zeitraum(LocalDate beginn, LocalDate ende) {
		this.beginn = beginn;
		this.ende = ende;
	}
	
	public boolean enthaelt(LocalDate datum) {
		return( (datum.isAfter(beginn) || datum.isEqual(beginn))
			&& (datum.isBefore(ende) || datum.isEqual(ende)));
	}
	
	

}
