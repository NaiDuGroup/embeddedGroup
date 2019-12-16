import java.sql.*;

public class Adapter {


    public static final String DB_NAME = "sourceDB_SEP4A19G2";
    private static Connection connection;
    private static String dbAddress = "10.200.131.2";
    private static String dbUsername = "SEP4A19G2";
    private static String dbPassword = "SEP4A19G2";
    private static String sqlUrl = "jdbc:sqlserver://" + dbAddress + ";database=" + DB_NAME + ";user=" + dbUsername + ";password=" + dbPassword;
    Statement statement = null;
    PreparedStatement stmt = null;

    public Adapter() {
    }

    /**
     * Lazy implementation of the database connection
     *
     * @return connection
     */

    public static Connection getConnection() {
        if (connection != null)
            return connection;
        return getNewConnection();
    }

    /**
     * Creates a new database connection through JDBC driver
     *
     * @return connection
     */
    private static Connection getNewConnection() {
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            connection = DriverManager.getConnection(sqlUrl);
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("DB connected");
        return connection;
    }

    public void add(float temp, float humid, int co2,String cell) {
        try {
            stmt = connection.prepareStatement(
                    "INSERT INTO \"sourceDB_SEP4A19G2\".dbo.sourceTable(date_time, sensorType, sensorId, sensorLocation, value) "
                            + "VALUES (current_timestamp ,'Temperature', 'T_1','"+ cell +"',"+ temp + ");");
            stmt.executeUpdate();
            System.out.println("OK");
            stmt = connection.prepareStatement(
                    "INSERT INTO \"sourceDB_SEP4A19G2\".dbo.sourceTable(date_time, sensorType, sensorId, sensorLocation, value) "
                            + "VALUES (current_timestamp ,'Humidity', 'H_1','"+ cell +"'," + humid + ");");
            stmt.executeUpdate();
            stmt = connection.prepareStatement(
                    "INSERT INTO \"sourceDB_SEP4A19G2\".dbo.sourceTable(date_time, sensorType, sensorId, sensorLocation, value) "
                            + "VALUES (current_timestamp ,'CO2', 'C_1', '"+ cell +"'," + co2 + ");");
            stmt.executeUpdate();
            connection.close();
            connection = null;
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }


    }
}

