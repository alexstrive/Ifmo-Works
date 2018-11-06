package dao;

import java.sql.SQLException;

public class DAO {
    private DAOImplementation implementation;

    public DAO(String address, String login, String password) throws SQLException, ClassNotFoundException {
        implementation = new SQLImplementation(address, login, password);
    }

    public DAO() {
        implementation = new FileImplementation();
    }

    public void createTable(String title) {
        implementation.createTable(title);
    }

    public boolean hasTable(String title) { return implementation.hasTable(title); }
}
