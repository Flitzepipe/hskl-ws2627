package millionaer;

public class MillionaerAnwendung {

	public static void main(String[] args) {

		Wissensgebiet wgGeographie = new Wissensgebiet("Geographie");
		Wissensgebiet wgGeschichte = new Wissensgebiet("Geschichte");
		
		Schwierigkeitsgrad s1 = new Schwierigkeitsgrad(50, 70);
		Schwierigkeitsgrad s2 = new Schwierigkeitsgrad(100, 50);
		Schwierigkeitsgrad s3 = new Schwierigkeitsgrad(10000, 10);
		
		Kandidat k1 = new Kandidat("Meyer", "Zweibrücken", "Maler", "5.5.1990");
		Kandidat k2 = new Kandidat("Mueller", "Kaiserslautern", "Student", "17.3.2002");
		
		Sendung se1 = new Sendung(1, "1.10.2022");
		Sendung se2 = new Sendung(2, "8.10.2022");
		Sendung se3 = new Sendung(3, "15.10.2022");
		
		Quizfrage f1 = new Quizfrage(1, "Hauptstadt von Frankreich?", wgGeographie, s1);
		Antwort a1 = f1.addRichtigeAntwort(1, "Paris", "Hier steht der Eifelturm");
		Antwort a2 = f1.addFalscheAntwort(2, "London", "Hauptstadt von Großbritannien");
		Antwort a3 = f1.addFalscheAntwort(3, "Marseille", "Auch in Frankreich, aber nicht die Hauptstadt");
		Antwort a4 = f1.addFalscheAntwort(4, "Madrid", "Hauptstadt von Spanien");
		
		Quizfrage f2 = new Quizfrage(2, "In welchen Fluss mündet die Saar?", wgGeographie, s2);
		Antwort a5 = f2.addFalscheAntwort(5, "Neckar", "");
		Antwort a6 = f2.addFalscheAntwort(6, "Main", "");
		Antwort a7 = f2.addFalscheAntwort(7, "Donau", "");
		Antwort a8 = f2.addRichtigeAntwort(8, "Mosel", "");
		
		Quizfrage f3 = new Quizfrage(3, "Hauptstadt von Burkina Faso?", wgGeographie, s3);
		Antwort a9 = f3.addFalscheAntwort(9, "Tunis", "");
		Antwort a10 = f3.addRichtigeAntwort(10, "Ouagadougu", "");
		Antwort a11 = f3.addFalscheAntwort(11, "Dakar", "");
		Antwort a12 = f3.addFalscheAntwort(12, "Lagos", "");
		
		
		Quizfrage f4 = new Quizfrage(4, "Welche deutsche Stadt war viele Jahre durch eine Mauer geteilt?", wgGeschichte, s1);
		Antwort a13 = f4.addFalscheAntwort(13, "Hamburg", "");
		Antwort a14 = f4.addRichtigeAntwort(14, "Berlin", "");
		Antwort a15 = f4.addFalscheAntwort(15, "München", "");
		Antwort a16 = f4.addFalscheAntwort(16, "Köln", "");
		
		Quizfrage f5 = new Quizfrage(5, "In welchem Jahr begann der erste Weltkrieg?", wgGeschichte, s2);
		Antwort a17 = f5.addFalscheAntwort(17, "1900", "");
		Antwort a18 = f5.addFalscheAntwort(18, "1933", "");
		Antwort a19 = f5.addRichtigeAntwort(19, "1914", "");
		Antwort a20 = f5.addFalscheAntwort(20, "1945", "");
		
		// "Nimm teil" oder "stelle Frage" hier nicht sinnvoll anwendbar - 
		// da keine direkte Verbindung von Kandidat zu Sendung oder Sendung zu Frage 
		
		se1.erfasseAntwort(k1, a1);
		se1.erfasseAntwort(k1, a8);
		se1.erfasseAntwort(k1, a9);
		se1.erfasseAntwort(k2, a14);
		se2.erfasseAntwort(k2, a19);
		
		se1.printUebersicht();
		se2.printUebersicht();
		
		

	}

}
