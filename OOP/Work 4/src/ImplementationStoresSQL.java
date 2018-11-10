import io.github.novopashin.dao.impl.Implementation;

import java.sql.*;

public final class ImplementationStoresSQL extends Implementation {
    private Connection connection;

    public ImplementationStoresSQL(String host, String login, String password) throws ClassNotFoundException, SQLException {
        super(null, null, null);
        var connectionURL = "jdbc:sqlserver://" + host;

        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
        connection = DriverManager.getConnection(connectionURL, login, password);
    }

    private ResultSet execute(String query) throws SQLException {
        return this.connection.createStatement().executeQuery(query);
    }
}
