
package testen.schulklasse;


public class Schueler {
	
	private String vorname;
	private String nachname;
	
	public Schueler(String vorname, String nachname){
		this.vorname = vorname;
		this.nachname = nachname;
	}
	
	public String getVorname(){
		return vorname;
	}
	
	public String getNachname(){
		return nachname;
	}

}
