package testen.schulklasse;

import java.util.List;
import java.util.ArrayList;


public class Schulklasse {
	
	private int jahrgang;
	private List<Schueler> schueler = new ArrayList<Schueler>();
	
	public Schulklasse(int jahrgang){
		this.jahrgang=jahrgang;
	}
	
	public int getJahrgang(){
		return jahrgang;
	}
	
	public void add(Schueler schueler){
		this.schueler.add(schueler);
	}
	
	public ArrayList<Schueler> getSchuelerMitNachname(String suchstring) {
		if(suchstring.length()<2){
			throw new IllegalArgumentException("Ungueltige Eingabe");
		}
		ArrayList<Schueler> gefundeneSchueler = new ArrayList<Schueler>();
		for(Schueler s:schueler){
			if(s.getNachname().contains(suchstring)){
				gefundeneSchueler.add(s);
			}
		}
		return gefundeneSchueler;
	}

}
