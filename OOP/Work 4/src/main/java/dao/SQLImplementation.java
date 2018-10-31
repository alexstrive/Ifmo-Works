import java.sql.*;

public class SQLImplementation implements DAOImplementation {
    Connection connection;

    public SQLImplementation(String address, String login, String password) {
        var connectionURL = "jdbc:sqlserver://" + address;

        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            connection = DriverManager.getConnection(connectionURL, login, password);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private ResultSet execute(String query) throws SQLException {
        ResultSet rs;
        Statement statement;
        statement =this.connection.createStatement();
        rs = statement.executeQuery(query);
        return rs;
    }
}
