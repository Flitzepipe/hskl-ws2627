package fachklassen;

public class Gebaeude {
	private int gebaeudeNr;
	private String bezeichnung;
	private String zweck;
	private Person verantwortlicher=null;
	
	public int getGebaeudeNr() {
		return gebaeudeNr;
	}
	public void setGebaeudeNr(int gebaeudeNr) {
		this.gebaeudeNr = gebaeudeNr;
	}
	public String getBezeichnung() {
		return bezeichnung;
	}
	public void setBezeichnung(String bezeichnung) {
		this.bezeichnung = bezeichnung;
	}
	public String getZweck() {
		return zweck;
	}
	public void setZweck(String zweck) {
		this.zweck = zweck;
	}
	
	public Person getVerantwortlicher() {
		return verantwortlicher;
	}

	public void setVerantwortlicher(Person verantwortlicher) {
		this.verantwortlicher = verantwortlicher;
	}

	public void print() {
		System.out.println("Gebäude Nr. " + gebaeudeNr + ", " + bezeichnung + ", " + zweck);
		// Wird erst für dritten Teil benötigt
		if (verantwortlicher != null) {
			System.out.println("   - Verantwortlich: " + verantwortlicher.getPersonNr() + ". "
					+ verantwortlicher.getVorname() + " " + verantwortlicher.getNachname());
		}
	}
	
	
	

}
