package geraetezustand.original;

public class Geraet {
	private String bez;
	private String ser_nr;
	private String herst;
	private int insp_st; 
	private boolean freig;
	private boolean def;
	private int rep;
	private final String 	M1="Undefinierter Zustand!",
							M2="Gerät ist in Betrieb",
							M3="Gerät ist in Reparatur",
							M4="Gerät ist freigegeben",
							M5="Gerät ist in Endprüfung",
							M6="Inspektion ist fällig",
							M7="Inspektion ist überfällig",
							M8="Gerät ist in Inspektion",
							M9="Gerät ist defekt";
							
	
	public Geraet(String b, String s, String h){
		bez=b;
		ser_nr=s;
		herst=h;
		insp_st=1;
		freig=true;
		def=false;
		rep=1;
		printInfo();
		printStatus();
	}
	
	public void nimmInBetrieb(){
		insp_st = 1;
		def = false;
		rep = 1;
		printStatus();
	}
	
	public void gibFrei(){
		insp_st = 1;
		freig = true;
		rep = 3;
		printStatus();
	}
	
	public void setzeInsp_st(int insp){
		insp_st = insp;
		if(insp_st==4){
			freig=false;
		}
		printStatus();
	}
	
	public void meldeDefekt(){
		def = true;
		printStatus();
	}
	
	public void setzeRep(int r){
		rep = r;
		if (rep>1){
			def = false;
			freig = false;
			insp_st=1;
		}
		printStatus();
	}
	
	private void printInfo(){
		System.out.println("\nGeraete-Info\n");
		System.out.println("Bezeichnung: " + bez);
		System.out.println("Seriennr: " + ser_nr);
		System.out.println("Hersteller: " + herst + "\n");
	}
	
	private void printStatus(){
		String meld=M1;
		if(insp_st==4){
			meld=M8;
		} else if (rep==2){
			meld=M3;
		} else if (rep==3){
			if (freig){
				meld=M4;
			} else {
				meld=M5;
			}
		} else if (rep==1){
			if(def){
				meld=M9;
			} else if(insp_st==1){
				meld=M2;
			} else if(insp_st==2){
				meld=M6;
			} else if(insp_st==3){
				meld=M7;
			}
		}
		System.out.println(" - " + meld);
	}

}
