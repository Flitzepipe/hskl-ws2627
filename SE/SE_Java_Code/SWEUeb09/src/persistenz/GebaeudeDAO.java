package persistenz;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import fachklassen.Gebaeude;

public class GebaeudeDAO {
	private DataSource dataSource = null;
	
	public GebaeudeDAO() {
		this.dataSource = DataSource.getDataSource();
	}
	
	/**
	 * Liest die Daten der Gebäude, die sich am Standort mit der standortNr befinden,
	 * aus der Datenbank und gibt eine Liste mit den Gebäude-Objekten zurück
	 * @param standortNr
	 * @return Eine Liste mit Gebäuden an dem Standort
	 */
	public List<Gebaeude> getGebaeudeAnStandort(int standortNr){
		List<Gebaeude> gefundeneGebaeude = new ArrayList<Gebaeude>();
		dataSource.openConnection();
		String query = "SELECT * FROM GEBAEUDE WHERE STANDORTNR=" + standortNr;
		ResultSet result = dataSource.performQuery(query);
		
		try {
			while(result.next()) {
				Gebaeude gefundenesGebaeude = new Gebaeude();
				gefundenesGebaeude.setGebaeudeNr(result.getInt(1));
				gefundenesGebaeude.setBezeichnung(result.getString(2));
				gefundenesGebaeude.setZweck(result.getString(3));
				gefundeneGebaeude.add(gefundenesGebaeude);
				System.out.println(" ... instanziiere Gebäude Nr. " + gefundenesGebaeude.getGebaeudeNr());
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		dataSource.closeConnection();
		
		return gefundeneGebaeude;
	}

}
