package bericht;

public class Berichtsposition {
	private Auftrag auftrag;
	private int nr;
	private static int zaehler=1;
	
	public Berichtsposition(Auftrag auftrag){
		this.auftrag = auftrag;
		nr = zaehler++;
	}
	
	public void print() {
		System.out.println("Berichtsposition Nr. " + nr + " für Auftrag Nr. " + auftrag.getNr());
	}
	
}
