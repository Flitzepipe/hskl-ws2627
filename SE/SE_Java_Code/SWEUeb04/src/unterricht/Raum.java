package unterricht;

public class Raum {
    private int raumnr;

    private String bezeichnung;

    public Raum(int raumnr, String bezeichnung) {
        this.raumnr = raumnr;
        this.bezeichnung = bezeichnung;
    }

    public int getNr() {
        return raumnr;
    }

}
