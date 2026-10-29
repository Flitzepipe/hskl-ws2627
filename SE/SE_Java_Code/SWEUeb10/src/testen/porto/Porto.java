package testen.porto;

public class Porto {
	
	public static int porto(int laenge, int breite, int gewicht){
		if(laenge < 100 || breite < 70  || laenge > 235 || breite > 125){
			throw new AbmessungException();
		} 
		if (gewicht <= 0 || gewicht > 50){
			throw new GewichtException();
		}
		if(laenge >= 140 && breite >= 90 &&  gewicht <= 20){
			return 85;
		}
		return 100;
	}
	
	
	
	



}
