package anzeige;

import java.awt.Font;
import javax.swing.JButton;
import javax.swing.JFrame;

/* Diese Klasse wird erst in der zweiten Aufgabe benötigt */

public class Bedienfeld {
	
	public Bedienfeld(Wertebasis wertebasis)  {  
		createFrame();   // Dialog öffnen
	}
	
	// Wird beim Drücken von + aufgerufen
	// Muss implementiert werden
	private void verarbeitePlusAktion() {

	}
	
	// Wird beim Drücken von - aufgerufen
	// Muss implementiert werden
	private void verarbeiteMinusAktion() {

	}
	
	
	// Der folgende Code muss nicht verändert werden
	
	private static int letzteYPosition = 100;
	private static int controllerZaehler = 1;
	
	public void createFrame() {
		JFrame frame = new JFrame("Controller " + controllerZaehler);
		controllerZaehler++;
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setBounds(400, letzteYPosition, 250, 100);
		letzteYPosition += 100;
		frame.setLayout(null);
		
		JButton plus = new JButton("+");
		plus.setBounds(40, 18, 70, 25);	
		plus.setFont(new Font("Arial", Font.PLAIN, 30));
		plus.addActionListener(e -> verarbeitePlusAktion());
		frame.add(plus);	
		
		JButton minus = new JButton("-");
		minus.setBounds(130, 18, 70, 25);
		minus.setFont(new Font("Arial", Font.PLAIN, 30));
		minus.addActionListener(e -> verarbeiteMinusAktion());
		frame.add(minus);
		
		frame.setVisible(true);
	}
	


}
