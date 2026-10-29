package persistenz;

import java.sql.ResultSet;

import fachklassen.Standort;

public class StandortDAO {
	private DataSource dataSource = null;
	
	public StandortDAO() {
		this.dataSource = DataSource.getDataSource();
	}


	/**
	 * Liest die Daten des Standorts mit der standortNr aus der Datenbank
	 * und liefert ein Standort-Objekt zurück 
	 * @param standortNr 
	 * @return Standort oder null, wenn zur standortNr kein Standort existiert
	 */
	public Standort getStandort(int standortNr) {
		System.out.println("Instanziiere Standort Nr. " + standortNr);
		dataSource.openConnection();
		String query = "SELECT * FROM STANDORT WHERE STANDORTNR=" + standortNr;
		ResultSet result = dataSource.performQuery(query);
		Standort gefundenerStandort = null;
		try {
			result.next();
			gefundenerStandort = new Standort();
			gefundenerStandort.setStandortNr(result.getInt(1));
			gefundenerStandort.setBezeichnung(result.getString(2));
			gefundenerStandort.setOrt(result.getString(3));
		} catch (Exception e) {
			e.printStackTrace();
		}
		dataSource.closeConnection();

		if(gefundenerStandort!=null) {
			GebaeudeDAO gebaeudeDAO = new GebaeudeDAO();
			gefundenerStandort.setGebaeude(gebaeudeDAO.getGebaeudeAnStandort(standortNr));
		}
		
		return gefundenerStandort;
	}
}
