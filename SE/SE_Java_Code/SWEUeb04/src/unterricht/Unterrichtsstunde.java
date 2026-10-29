package unterricht;


public class Unterrichtsstunde {
    private Wochenstunde wochenstunde;

    private Raum abweichenderRaum = null;

    public Wochenstunde getWochenstunde() {
        return this.wochenstunde;
    }

    public Unterrichtsstunde(Wochenstunde wochenstunde, Raum abweichenderRaum) {
        this.wochenstunde = wochenstunde;
        this.abweichenderRaum = abweichenderRaum;
    }

    public void print() {
        System.out.print(" - " + wochenstunde.getWochentag() + ", " + wochenstunde.getStunde() + ". Stunde");
        if(abweichenderRaum!=null) {
            System.out.print(", abweichender Raum: Nr. " + abweichenderRaum.getNr());
        }
        System.out.println();
    }

}
