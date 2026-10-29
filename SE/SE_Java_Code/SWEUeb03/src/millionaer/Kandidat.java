package millionaer;

public class Kandidat {
	private String name;
	private String adresse;
	private String beruf;
	private String geburtstag;

	public Kandidat(String name, String adresse, String beruf, String geburtstag) {
		this.name = name;
		this.adresse = adresse;
		this.beruf = beruf;
		this.geburtstag = geburtstag;
	}
	
	public String getName() {
		return this.name;
	}

}
