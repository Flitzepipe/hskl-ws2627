package persistenz;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/*
 * Kommunikation mit der Datenbank.
 * Beim Start des Programms leert der Konstruktor die Datenbank komplett
 * und trägt Demodaten ein. Eventuell in der DB geänderte Daten werden
 * somit überschrieben.
 */
public class DataSource {
	private static DataSource dataSource = new DataSource();  // Singleton

	Connection connection = null;

	public DataSource() {

		try {
			Class.forName("org.h2.Driver");
			openConnection();

			Statement dbStatement = connection.createStatement();

			String tabelle = "STANDORT";
			String dropQ = "DROP TABLE IF EXISTS " + tabelle;
			dbStatement.executeUpdate(dropQ);

			String createQ = "CREATE TABLE IF NOT EXISTS " + tabelle + "(" + "STANDORTNR INT NOT NULL, "
					+ "BEZEICHNUNG VARCHAR(50), ORT VARCHAR(50) " + ")";
			dbStatement.executeUpdate(createQ);		
			
            String insertQ = 
               "INSERT INTO " + tabelle + " VALUES(1, 'Campus HS1', 'Zweibrücken');" 
             + "INSERT INTO " + tabelle + " VALUES(2, 'Campus HS2', 'Pirmasens');"
             + "INSERT INTO " + tabelle + " VALUES(3, 'Campus HS3', 'KL')"; 
            dbStatement.executeUpdate(insertQ); 
            
            tabelle = "GEBAEUDE";
			dropQ = "DROP TABLE IF EXISTS " + tabelle;
			dbStatement.executeUpdate(dropQ);
			
			createQ = "CREATE TABLE IF NOT EXISTS " + tabelle + "(" + "GEBAEUDENR INT NOT NULL, "
					+ "BEZEICHNUNG VARCHAR(50), ZWECK VARCHAR(50), STANDORTNR INT, VERANTWORT INT )";
			dbStatement.executeUpdate(createQ);		
            
			insertQ = 
		               "INSERT INTO " + tabelle + " VALUES(1, 'Gebäude A', 'Hörsääle', 1, 1);" 
		             + "INSERT INTO " + tabelle + " VALUES(2, 'Gebäude B', 'Audimax', 1, 1);"
		             + "INSERT INTO " + tabelle + " VALUES(3, 'Gebäude H', 'Verwaltung', 1, 2);"
		             + "INSERT INTO " + tabelle + " VALUES(4, 'Gebäude O', 'Mensa', 1, 2);"
		             + "INSERT INTO " + tabelle + " VALUES(5, 'Gebäude E', 'Rechenzentrum', 2, 3);"
		             + "INSERT INTO " + tabelle + " VALUES(6, 'Gebäude F', 'Büros', 2, 4);"
		             + "INSERT INTO " + tabelle + " VALUES(7, 'Gebäude B', 'Atrium', 3, 4);"
		             + "INSERT INTO " + tabelle + " VALUES(8, 'Gebäude', 'Bibliothek', 3, 4)";
		    dbStatement.executeUpdate(insertQ); 
            
		            
			tabelle = "PERSON";
			dropQ = "DROP TABLE IF EXISTS " + tabelle;
			dbStatement.executeUpdate(dropQ);

			createQ = "CREATE TABLE IF NOT EXISTS " + tabelle + "(" + "PERSONNR INT NOT NULL, "
					+ "VORNAME VARCHAR(50), NACHNAME VARCHAR(50) )";
			dbStatement.executeUpdate(createQ);		
		            
			insertQ = "INSERT INTO " + tabelle + " VALUES(1, 'Holger', 'Meiser');" 
					+ "INSERT INTO " + tabelle + " VALUES(2, 'Verena', 'Becker');" 
					+ "INSERT INTO " + tabelle + " VALUES(3, 'Volker', 'Schwarz');" 
					+ "INSERT INTO " + tabelle + " VALUES(4, 'Sabine', 'M�ller')";
			dbStatement.executeUpdate(insertQ);
			
            closeConnection();
			// connection.close();
		} catch (SQLException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} finally {
			if (connection != null)
				try {
					connection.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
		}

	}
	
	
	public static DataSource getDataSource() {
		return dataSource;
	}
	
	
	public void openConnection() {
		try {
			connection = DriverManager.getConnection("jdbc:h2:./database/standorte", "", "");
		} catch (SQLException e){
			e.printStackTrace();
		} 
	}
	
	public void closeConnection() {
		if (connection != null)
			try {
				connection.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
	}
	
	public ResultSet performQuery(String query) {
		ResultSet result = null;
		try {
			Statement statement = connection.createStatement(); 
			result = statement.executeQuery(query);
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return result;
	}
	
	

	

}
