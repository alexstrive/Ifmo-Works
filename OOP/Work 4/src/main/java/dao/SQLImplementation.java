package dao;

import java.sql.*;

public final class SQLImplementation extends DAOImplementation {
    private Connection connection;

    SQLImplementation(String address, String login, String password) throws ClassNotFoundException, SQLException {
        var connectionURL = "jdbc:sqlserver://" + address;

        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
        connection = DriverManager.getConnection(connectionURL, login, password);
    }

    private ResultSet execute(String query) throws SQLException {
        return this.connection.createStatement().executeQuery(query);
    }

    @Override
    public void createTable(String name) {

    }

    @Override
    boolean hasTable(String title) {
        return false;
    }
}
