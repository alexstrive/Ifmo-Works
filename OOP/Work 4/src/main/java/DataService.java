import dao.DAO;

import java.sql.SQLException;

public class DataService {
    private DAO dao;

    DataService() throws SQLException, ClassNotFoundException {
        this.dao = new DAO("localhost:1433", "AbolrousHazem", "340$Uuxwp7Mcxo7Khy");
    }

    void createStore(String title) {
        this.dao.createTable(title);
    }

    boolean hasStore(String title) {
        return this.dao.hasTable(title);
//        return true;
    }
}
