package anzeige;

import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class Anzeige  {
	
	private JLabel label;  // Das angezeigte Label
	
	public Anzeige() {
		createFrame(); // Dialog öffnen
	}

	public void setText(String text) {
		label.setText(text);
	}
	
	
	
	// Der folgende Code muss nicht verändert werden.
	// Er spielt für die Aufgabe keine Rolle.
	
	private static int letzteYPosition = 100;
	private static int viewZaehler = 1;
	
	private void createFrame() {
		try {  
			JFrame frame = new JFrame("View " + viewZaehler);
			viewZaehler++;
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setResizable(false);
			frame.setBounds(100, letzteYPosition, 250, 100);
			letzteYPosition += 100;
			label = new JLabel("42", SwingConstants.CENTER);
			label.setFont(new Font("Arial", Font.PLAIN, 30));
			frame.getContentPane().add(label);
			frame.setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
