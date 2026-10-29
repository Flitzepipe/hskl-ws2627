package anzeige;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Timer;


public class AnzeigeAnwendung {
	
	public static void main(String[] args) {
		Wertebasis wb = new Wertebasis(); // Anlegen einer neuen Wertebasis - startet auch eine Anzeige
		zaehleWertebasisHoch(wb);
	}
	
	/* Diese Methode dient dazu, den Wert der Wertebasis hochzuzählen - damit man sehen kann, dass die Anzeige
	 * 	 * funktioniert. Soll später durch ein Bedienfeld ersetzt werden.	 
	 */
	public static void zaehleWertebasisHoch(Wertebasis wb) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				Timer timer = new Timer(1000, new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						wb.einsHoch();
					}
				});
				timer.setInitialDelay(0);
				timer.setDelay(1000);
				timer.start();
			}
		});
	}
}

