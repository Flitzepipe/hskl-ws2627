package fachklassen;

import java.util.ArrayList;
import java.util.List;

public class Standort {
	private int standortNr;
	private String bezeichnung;
	private String ort;
	private List<Gebaeude> gebaeude = new ArrayList<Gebaeude>();
	
	public int getStandortNr() {
		return standortNr;
	}
	public void setStandortNr(int standortNr) {
		this.standortNr = standortNr;
	}
	public String getBezeichnung() {
		return bezeichnung;
	}
	public void setBezeichnung(String bezeichnung) {
		this.bezeichnung = bezeichnung;
	}
	public String getOrt() {
		return ort;
	}
	public void setOrt(String ort) {
		this.ort = ort;
	}
	
	public List<Gebaeude> getGebaeude() {
		return this.gebaeude;
	}
	
	public void setGebaeude(List<Gebaeude> gebaeude) {
		this.gebaeude = gebaeude;
	}
	
	public void addGebaeude(Gebaeude gebaeude) {
		this.gebaeude.add(gebaeude);
	}
	
	/**
	 * Gibt nur die Daten des Standorts aus, ohne Gebäude
	 */
	public void print() {
		System.out.println("\n\nGebe Standortdaten aus:\n");
		System.out.println("Standort Nr. " + standortNr + ". " + bezeichnung + ", " + ort);
	}
	
	/**
	 * Gibt die Daten des Standorts und der dortigen Gebäude aus.
	 * HIerzu müssen die Gebäude instanziiert sein.
	 */
	public void printAlles() {
		System.out.println("\n\nGebe Standortdaten mit Gebäuden aus:\n");
		System.out.println("Standort Nr. " + standortNr + ". " + bezeichnung + ", " + ort);
		System.out.println("\nGebäude an diesem Standort:");
		for(Gebaeude g:gebaeude) {
			g.print();
		}
	}

}
