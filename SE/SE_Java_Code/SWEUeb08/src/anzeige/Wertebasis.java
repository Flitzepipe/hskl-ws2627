package anzeige;

public class Wertebasis {
	
	// Dieser Wert soll angezeigt und verändert werden
	private int wert = 42;
	
	// Legt eine Anzeige an und öffnet sie
	private Anzeige anzeige = new Anzeige();
	
	public int getWert() {
		return wert;
	}
	
	public void setWert(int wert) {
		this.wert = wert;
		anzeige.setText("" + wert);
	}
	
	public void einsHoch() {
		setWert(wert+1);
	}
	
	public void einsRunter() {
		setWert(wert-1);
	}
	
}
