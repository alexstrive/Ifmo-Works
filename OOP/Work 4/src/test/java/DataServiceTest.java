import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.junit.Assert.*;
import java.sql.SQLException;

public class DataServiceTest {
    private DataService dataService;

    @Before
    public void createInstance() {
        try {
            dataService = new DataService();
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Test
    /**
     * Создать магазин
     */
    public void task1() {
        String storeTitle = "New Store";
        dataService.createStore(storeTitle);
        Assert.assertTrue("Содержит соответствующий магазин после его создания.",
                dataService.hasStore(storeTitle));
    }

    @Test
    /**
     * Создать товар
     */
    public void task2() {
//        dataService.createEntity("Title", "Vendor", 123, 123, 123);
    }

    @Test
    /**
     * Завезти партию товаров в магазин (набор товар-количество с возможностью
     * установить/изменить цену)
     */
    public void task3() {
        assert false;
    }
}
