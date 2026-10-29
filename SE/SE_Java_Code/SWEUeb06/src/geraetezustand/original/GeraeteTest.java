package geraetezustand.original;

public class GeraeteTest {

	public static void main(String[] args) {
		Geraet g = new Geraet("Fraese", "xy5", "Hardware Manuf");		
		g.setzeInsp_st(2);
		g.setzeInsp_st(4);
		g.gibFrei();
		g.nimmInBetrieb();
		System.out.println();
		
		g.setzeInsp_st(2);
		g.setzeInsp_st(3);
		g.setzeInsp_st(4);
		g.gibFrei();
		g.nimmInBetrieb();
		System.out.println();
		
		g.meldeDefekt();
		g.setzeRep(2);
		g.setzeRep(3);
		g.setzeRep(2);
		g.setzeRep(3);
		g.setzeRep(2);
		g.setzeRep(3);
		g.gibFrei();
		g.nimmInBetrieb();
		System.out.println();
		
		g.setzeInsp_st(2);
		g.setzeInsp_st(3);
		g.meldeDefekt();
		g.setzeRep(2);
		g.setzeRep(3);
		g.gibFrei();
		g.nimmInBetrieb();
		System.out.println();
		
		g.setzeInsp_st(2);
		g.meldeDefekt();
		g.setzeRep(2);
		g.setzeRep(3);
		g.gibFrei();
		g.nimmInBetrieb();
		System.out.println();
		
		g.setzeInsp_st(2);
		g.setzeInsp_st(3);
		g.meldeDefekt();
		g.setzeRep(2);
		g.setzeRep(3);
		g.gibFrei();
		g.nimmInBetrieb();
		System.out.println();
		
		g.setzeInsp_st(2);
		g.setzeInsp_st(4);
		g.setzeRep(2);
		g.setzeRep(3);
		g.gibFrei();
		g.nimmInBetrieb();
		System.out.println();

	}

}
