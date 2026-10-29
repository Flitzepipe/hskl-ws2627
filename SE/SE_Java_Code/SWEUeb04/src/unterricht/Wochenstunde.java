package unterricht;


public class Wochenstunde {
    private String wochentag;

    private int stunde;

    public Wochenstunde(int stunde, String wochentag) {
        this.wochentag = wochentag;
        this.stunde = stunde;
    }

    public String getWochentag() {
        return wochentag;
    }

    public int getStunde() {
        return stunde;
    }

}
