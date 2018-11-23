package io.github.novopashin.dao.strategies.custom;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

public abstract class TargetConsumerSQL extends TargetConsumer {
    private Connection connection;

    public TargetConsumerSQL(String tablename, String host, String login, String password) {
        super(tablename);

        var connectionURL = "jdbc:sqlserver://" + host + ";database=AnotherStore";

        try {
            connection = DriverManager.getConnection(connectionURL, login, password);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    protected void update(String querySQL) {
        try {
            connection.createStatement().executeUpdate(querySQL);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    protected ResultSet execute(String querySQL) {
        try {
            return connection.createStatement().executeQuery(querySQL);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    protected String getTablename() {
        return getTargetObject().toString();
    }
}
